#pragma once

#include <iostream>
#include <bitset>
#include <string>
#include <stack>
#include <cstdint>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>

namespace PARSE
{
	class ex03Node
	{
	private:
		bool logicValue_;
		char operator_;
		ex03Node *right_;
		ex03Node *left_;
		ex03Node *next_;
	public:
		void setLogicValue(bool logicValue) { logicValue_ = logicValue; }
		void setOperator(char op) { operator_ = op; }
		void setRight(ex03Node *right) { right_ = right; }
		void setLeft(ex03Node *left) { left_ = left; }
		void setNext(ex03Node *next) { next_ = next; }
		bool getLogicValue() const { return logicValue_; }
		char getOperator() const { return operator_; }
		ex03Node *getRight() const { return right_; }
		ex03Node *getLeft() const { return left_; }
		ex03Node *getNext() const { return next_; }
	};

	class ex03Tree : public ex03Node
	{
	private:
		bool answer_ = 0;
		size_t size_ = 0;
		size_t numNodeList_ = 0;
		ex03Node *head_ = nullptr;

	public:
		ex03Tree()
			: answer_(0), size_(0), numNodeList_(0), head_(nullptr)
		{ }

		~ex03Tree()
		{
			deleteTree(head_);
			size_ = 0;
			numNodeList_ = 0;
		}

		bool getAnswer() const { return answer_; }

		void deleteTree(ex03Node *root)
		{
			if (root == nullptr)
				return;
			deleteTree(root->getLeft());	
			deleteTree(root->getRight());	

			delete root;
			root = nullptr;
		}

		ex03Node *createNode(char symbol)
		{
			ex03Node *newNode = new ex03Node;
			try {
				if (newNode) {
					if (symbol == '0' || symbol == '1') {
						newNode->setOperator(symbol);
						newNode->setOperator(0);
						newNode->setLogicValue(symbol - '0');
					} else {
						newNode->setOperator(symbol);
						newNode->setLogicValue(0);
					}
					newNode->setRight(nullptr);
					newNode->setLeft(nullptr);
					newNode->setNext(nullptr);
					return newNode;
				} else {
					throw("Error: memorry allocation failed.");
				}
			} catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
				exit(EXIT_FAILURE);
			}
		}

		void appendNode(ex03Node *node)
		{
			node->setNext(head_);
			head_ = node;
			size_++;
			numNodeList_++;
		}

		ex03Node *pop()
		{
			ex03Node *popNode = head_;
			head_ = head_->getNext();
			popNode->setNext(nullptr);
			numNodeList_--;
			return popNode;
		}

		ex03Node *bindNodes(ex03Node *root, ex03Node *left, ex03Node *right)
		{
			switch (root->getOperator())
			{
			case '!':
				root->setLogicValue(!(right->getLogicValue()));
				break;
			case '&':
				root->setLogicValue(left->getLogicValue() & right->getLogicValue());
				break;
			case '|':
				root->setLogicValue(left->getLogicValue() | right->getLogicValue());
				break;
			case '^':
				root->setLogicValue(left->getLogicValue() ^ right->getLogicValue());
				break;
			case '>':
				root->setLogicValue(left->getLogicValue() | !(right->getLogicValue()));
				break;
			case '=':
				root->setLogicValue((left->getLogicValue() & right->getLogicValue()) |
									!(left->getLogicValue()) & !(right->getLogicValue()));
				break;
			}
			root->setLeft(left);
			root->setRight(right);
			return root;
		}

		void parse(const std::string& formula)
		{
			for (int i = 0; i < formula.size(); i++) {
				char symbol = formula.at(i);
				if (symbol == '0' || symbol == '1') {
					appendNode(createNode(symbol));
				} else if (symbol == '!') {
					ex03Node *right = pop();
					if (right == nullptr) {
						std::cerr << "Error: wrong formula" << std::endl;
						exit(EXIT_FAILURE);
					}
					appendNode(bindNodes(createNode(symbol), nullptr, right));
				} else if (symbol == '&' || symbol == '|' || symbol == '^' || symbol == '>' || symbol == '=') {
					ex03Node *right = pop();
					ex03Node *left = pop();
					if (right == nullptr || left == nullptr) {
						std::cerr << "Error: wrong formula" << std::endl;
						exit(EXIT_FAILURE);
					}
					appendNode(bindNodes(createNode(symbol), left, right));
				} else {
					std::cerr << "Error: wrong formula" << std::endl;
					exit(EXIT_FAILURE);
				}
			}
			if (numNodeList_ != 1) {
				std::cerr << "Error: wrong formula" << std::endl;
				exit(EXIT_FAILURE);
			}
			answer_ = head_->getLogicValue();
		}
	};

	class treeNode
	{
	private:
		bool logical_;
		std::string symbol_;
		treeNode *right_;
		treeNode *left_;
		treeNode *next_;

	public:
		void setLogical(bool which) { logical_ = which; }
		void setSymbol(char symbol) { symbol_ = symbol; }
		void setRight(treeNode *right) { right_ = right; }
		void setLeft(treeNode *left) { left_ = left; }
		void setNext(treeNode *next) { next_ = next; }
		bool isLogical() const { return logical_; }
		std::string getSymbol() const { return symbol_; }
		treeNode *getRight() const { return right_; }
		treeNode *getLeft() const { return left_; }
		treeNode *getNext() const { return next_; }
		void addNot() { symbol_.insert(0, "~"); }
		void addOpenParen() { symbol_.insert(0, "("); }
		void addCloseParen() { symbol_.append(")"); }
	};

	class Tree : public treeNode
	{
	private:
		size_t countListNode_ = 0;
		size_t countLetter_ = 0;
		treeNode *head_;

	public:
		Tree()
			: countListNode_(0), countLetter_(0), head_(nullptr)
		{ }
		~Tree() { deleteTree(head_); }

		size_t getCountLetter() { return countLetter_; }
		size_t getCountListNode() { return countListNode_; }
		treeNode *getHead() { return head_; }

		treeNode *createNode(char symbol)
		{
			treeNode *newNode = new treeNode;
			if (!newNode)
			{
				std::cerr << "Error: memory allocation failed." << std::endl;
				exit(EXIT_FAILURE);
			}
			if (symbol > 64 && symbol < 91)
				newNode->setLogical(false);
			else
				newNode->setLogical(true);
			newNode->setSymbol(symbol);
			newNode->setLeft(nullptr);
			newNode->setRight(nullptr);
			newNode->setNext(nullptr);

			return newNode;
		}

		void appendNode(treeNode *newNode)
		{
			if (newNode->isLogical() == false && newNode->getSymbol().at(0) != '~')
				countLetter_++;
			countListNode_++;
			newNode->setNext(head_);
			head_ = newNode;
		}

		treeNode *pop()
		{
			if (countListNode_ == 0) {
				std::cerr << "Error: Nothing to pop." << std::endl;
				exit(EXIT_FAILURE);
			}
			treeNode *popNode;
			popNode = head_;
			head_ = head_->getNext();
			countListNode_--;
			popNode->setNext(nullptr);
			return popNode;
		}

		treeNode *bindNodes(treeNode *root,treeNode *left, treeNode *right, int order = 1)
		{
			if (order == 1) {
				if (left == nullptr) {
					root->addOpenParen();
					findLeaf(right, 1)->addCloseParen();
				} else {
					findLeaf(right, 1)->addCloseParen();
					findLeaf(left, 0)->addOpenParen();
				}
			}
			root->setLeft(left);
			root->setRight(right);
			return root;
		}

		treeNode *findLeaf(treeNode *node, bool which)
		{
			treeNode *leaf;
			if (which == true)
				for (leaf = node; leaf->getRight() != nullptr; leaf = leaf->getRight())
					;
			else 
				for (leaf = node; leaf->getLeft() != nullptr; leaf = leaf->getLeft())
					;
			return leaf;
		}

		void parse(const std::string& formula, int order = 1)
		{
			if (head_ != nullptr) {
				deleteAll(head_);
				countLetter_ = 0;
			}
			for (int i = 0; i < formula.size(); i++) {
				char symbol = formula.at(i);
				if (symbol > 64 && symbol < 91) {
					appendNode(createNode(symbol));
				} else if (symbol == '!') {
					treeNode *temp = pop();
					if (temp->isLogical() == false || temp->getSymbol().at(0) == '~') {
						temp->addNot();
						appendNode(temp);
					} else {
						appendNode(bindNodes(createNode(symbol), nullptr, temp, order));
					}
				} else if (symbol == '&' || symbol == '|' || symbol == '^' || symbol == '>' || symbol == '=') {
					treeNode *right = pop();
					treeNode *left = pop();
					appendNode(bindNodes(createNode(symbol), left, right, order));
				} else {
					std::cerr << "Error: wrong formula." << std::endl;
					exit(EXIT_FAILURE);
				}
			}
			if (countListNode_ != 1) {
				std::cerr << "Error: wrong formula." << std::endl;
				exit(EXIT_FAILURE);
			}
		}

		void deleteTree(treeNode *root)
		{
			if (root == nullptr)
				return;
			deleteTree(root->getLeft());	
			deleteTree(root->getRight());	

			delete root;
			root = nullptr;
		}

		// check this function.
		void deleteAll(treeNode *head)
		{
			if (head == nullptr)
				return;
			deleteAll(head->getNext());
			deleteTree(head);
			countListNode_--;
		}

		std::string getLetters()
		{
			std::string letters = "";
			getLeafSymbol(head_, letters);
			return letters;
		}

		void getLeafSymbol(treeNode *root, std::string &letters)
		{
			if (root == nullptr)
				return;
			getLeafSymbol(root->getLeft(), letters);
			if (root->isLogical() == false)
				letters.push_back(findLetter(root->getSymbol()));
			getLeafSymbol(root->getRight(), letters);
		}

		char findLetter(std::string str)
		{
			for (auto it = str.begin(); it != str.end(); it++)
			{
				if (*it > 64 && *it < 91)
					return *it;
			}
			return 0;
		}

		std::string getFormula(int order = 2)
		{
			treeNode *root = head_;
			std::string formula;
			switch (order) {
			case 1:
				preorder(root, formula);
				break;
			case 2:
				inorder(root, formula);
				break;
			case 3:
				postorder(root, formula);
				break;
			default :
				std::cerr << "You put wrong numbers. Input value must be between 1 to 3." << std::endl;
				return nullptr;
			}
			return formula;
		}

		void preorder(treeNode *root, std::string& formula)
		{
			if (root == nullptr)
				return;
			formula.append(root->getSymbol());
			preorder(root->getLeft(), formula);
			preorder(root->getRight(), formula);
		}

		void inorder(treeNode *root, std::string& formula)
		{
			if (root == nullptr)
				return;
			inorder(root->getLeft(), formula);
			formula.append(root->getSymbol());
			inorder(root->getRight(), formula);
		}

		void postorder(treeNode *root, std::string& formula)
		{
			if (root == nullptr)
				return;
			postorder(root->getLeft(), formula);
			postorder(root->getRight(), formula);
			formula.append(root->getSymbol());
		}

		void print(int order = 2)
		{
			treeNode *root = head_;
			switch (order) {
			case 1:
				preorder(root);
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				postorder(root);
				break;
			default :
				std::cerr << "You put wrong numbers. Input value must be between 1 to 3." << std::endl;
			}
		}

		void preorder(treeNode *root)
		{
			if (root == nullptr)
				return;
			std::cout << root->getSymbol() << " ";
			preorder(root->getLeft());
			preorder(root->getRight());
		}

		void inorder(treeNode *root)
		{
			if (root == nullptr)
				return;
			inorder(root->getLeft());
			std::cout << root->getSymbol() << " ";
			inorder(root->getRight());
		}

		void postorder(treeNode *root)
		{
			if (root == nullptr)
				return;
			postorder(root->getLeft());
			postorder(root->getRight());
			std::cout << root->getSymbol() << " ";
		}

		// ex03
		bool solveEx03(const std::string& formula)
		{
			bool result = 0;
			for (int i = 0; i < formula.size(); i++) {
				char symbol = formula.at(i);
				if (symbol == '0' || symbol == '1') {
					appendNode(createNode(symbol));
				} else if (symbol == '!') {
					treeNode *temp = pop();
					if (temp->isLogical() == false || temp->getSymbol().at(0) == '~') {
						temp->addNot();
						appendNode(temp);
					} else {
						appendNode(bindNodes(createNode(symbol), nullptr, temp, 0));
					}
				} else if (symbol == '&' || symbol == '|' || symbol == '^' || symbol == '>' || symbol == '=') {
					treeNode *right = pop();
					treeNode *left = pop();
					appendNode(bindNodes(createNode(symbol), left, right, 0));
				} else {
					std::cerr << "Error: wrong formula." << std::endl;
					exit(EXIT_FAILURE);
				}
			}
			if (countListNode_ != 1) {
				std::cerr << "Error: wrong formula." << std::endl;
				exit(EXIT_FAILURE);
			}
		}
	};
}