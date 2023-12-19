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
		void setLogicValue(bool logicValue);
		void setOperator(char op);
		void setRight(ex03Node *right);
		void setLeft(ex03Node *left);
		void setNext(ex03Node *next);
		bool getLogicValue() const;
		char getOperator() const;
		ex03Node *getRight() const;
		ex03Node *getLeft() const;
		ex03Node *getNext() const;
	};

	class ex03Tree : public ex03Node
	{
	private:
		bool answer_ = 0;
		size_t size_ = 0;
		size_t numNodeList_ = 0;
		ex03Node *head_ = nullptr;

	public:
		ex03Tree();
		~ex03Tree();

		bool getAnswer() const;
		void deleteTree(ex03Node *root);
		ex03Node *createNode(char symbol);
		void appendNode(ex03Node *node);
		ex03Node *pop();
		ex03Node *bindNodes(ex03Node *root, ex03Node *left, ex03Node *right);
		void parse(const std::string& formula);
	};

	class treeNode
	{
	private:
		bool logical_ = 0;
		std::string symbol_;
		treeNode *right_ = nullptr;
		treeNode *left_ = nullptr;
		treeNode *next_ = nullptr;

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
		~Tree()
		{
			deleteTree(head_);
			countListNode_ = 0;
			countLetter_ = 0;
		}

		Tree(const std::string& formula)
		{
			parse(formula);
		}

		size_t getCountLetter() { return countLetter_; }
		size_t getCountListNode() { return countListNode_; }
		treeNode *getHead() { return head_; }

		treeNode *createNode(char symbol)
		{
			treeNode *newNode = new treeNode;
			try {
				if (!newNode)
					throw("Error: memory allocation failed.");
				if (symbol > 64 && symbol < 91)
					newNode->setLogical(false);
				else
					newNode->setLogical(true);
				newNode->setSymbol(symbol);
				newNode->setLeft(nullptr);
				newNode->setRight(nullptr);
				newNode->setNext(nullptr);

				return newNode;
			} catch (const std::exception &e) {
				std::cerr << e.what() << '\n';
				exit(EXIT_FAILURE);
			}
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

		// 1 = add parenthesis
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
				deleteTree(head_);
			}
			for (int i = 0; i < formula.size(); i++) {
				char symbol = formula.at(i);
				if (symbol > 64 && symbol < 91) {
					appendNode(createNode(symbol));
				} else if (symbol == '!') {
					treeNode *temp = pop();
					if (temp == nullptr) {
						std::cerr << "Error: wrong formula." << std::endl;
						exit(EXIT_FAILURE);
					}
					if (temp->isLogical() == false || temp->getSymbol().at(0) == '~') {
						temp->addNot();
						appendNode(temp);
					} else {
						appendNode(bindNodes(createNode(symbol), nullptr, temp, order));
					}
				} else if (symbol == '&' || symbol == '|' || symbol == '^' || symbol == '>' || symbol == '=') {
					treeNode *right = pop();
					treeNode *left = pop();
					if (right == nullptr || left == nullptr) {
						std::cerr << "Error: wrong formula." << std::endl;
						exit(EXIT_FAILURE);
					}
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
		
		/* check time complexity of this function */
		void modifySymbols(treeNode *root)
		{
			char symbol = root->getSymbol().at(0);
			if (symbol == '&')
				root->setSymbol('|');
			else if (symbol == '|')
				root->setSymbol('&');
			rightwardModifySymbols(root);
			leftwardModifySymbols(root);
		}

		void leftwardModifySymbols(treeNode *root)
		{
			treeNode *left = root->getLeft();
			char symbol;
			while (left != nullptr)
			{
				symbol = left->getSymbol().at(0);
				if (symbol == '&') {
					left->setSymbol('|');
				} else if (symbol == '|') {
					left->setSymbol('&');
				} else if (symbol == '!') {
					left->setSymbol(left->getRight()->getSymbol().at(0));
					delete left->getRight();
					left->setRight(nullptr);
				} else {
					if (root->getSymbol().at(0) != '!') {
						root->setLeft(createNode('!'));
						root->getLeft()->setRight(left);
					}
				}
				if (left->getRight() != nullptr)
					rightwardModifySymbols(left);
				root = root->getLeft();
				left = left->getLeft();
			}

		}

		void rightwardModifySymbols(treeNode *root)
		{
			treeNode *right = root->getRight();
			char symbol;
			while (right != nullptr)
			{
				symbol = right->getSymbol().at(0);
				if (symbol == '&') {
					right->setSymbol('|');
				} else if (symbol == '|') {
					right->setSymbol('&');
				} else if (symbol == '!') {
					right->setSymbol(right->getRight()->getSymbol().at(0));
					delete right->getRight();
					right->setRight(nullptr);
				} else {
					if (root->getSymbol().at(0) != '!') {
						root->setRight(createNode('!'));
						root->getRight()->setRight(right);
					}
				}
				if (right->getLeft() != nullptr)
					leftwardModifySymbols(right);
				root = root->getRight();
				right = right->getRight();
			}
		}

		treeNode *copySubTree(treeNode *sub)
		{
			
		}

		/* it takes RPN prepositional formual and turns into NNF*/
		void parseEx05(const std::string &formula)
		{
			std::cout << "Input formula : " << formula << std::endl;
			if (head_ != nullptr) {
				deleteTree(head_);
				countListNode_ = 0;
				countLetter_ = 0;
			}
			for (int i = 0; i < formula.size(); i++) {
				char symbol = formula.at(i);
				if (symbol > 64 && symbol < 91) {
					appendNode(createNode(symbol));
				} else if (symbol == '!') {
					treeNode *temp = pop();
					if (temp == nullptr) {
						std::cerr << "Error: wrong formula." << std::endl;
						exit(EXIT_FAILURE);
					}
					if (temp->getSymbol().at(0) == '!') {
						appendNode(temp->getRight());
						delete temp;
						temp = nullptr;
					} else if (temp->isLogical() == false) {
						appendNode(bindNodes(createNode(symbol), nullptr, temp, 0));
					} else {
						modifySymbols(temp);
						appendNode(temp);
					}
				} else if (symbol == '&' || symbol == '|') {
					treeNode *right = pop();
					treeNode *left = pop();
					if (right == nullptr || left == nullptr) {
						std::cerr << "Error: wrong formula." << std::endl;
						exit(EXIT_FAILURE);
					}
					appendNode(bindNodes(createNode(symbol), left, right, 0));
				} else if (symbol == '^') {
					// (p | q) & (!p | !q)
					treeNode *right = pop();
					treeNode *left = pop();
					if (right == nullptr || left == nullptr) {
						std::cerr << "Error: wrong formula." << std::endl;
						exit(EXIT_FAILURE);
					}
					// append processing '!'
					// something wrong here
					treeNode *formula1 = bindNodes(createNode('|'), left, right, 0);
					treeNode *copyRight = copySubTree(right);
					treeNode *copyLeft = copySubTree(left);
					copyRight = bindNodes(createNode('!'), nullptr, copyRight, 0);
					copyLeft = bindNodes(createNode('!'), nullptr, copyLeft, 0);
					treeNode *formula2 = bindNodes(createNode('|'), copyLeft, copyRight, 0);
					appendNode(bindNodes(createNode('&'), formula1, formula2, 0));
				} else if (symbol == '>') {
					// q | !p
					treeNode *right = pop();
					treeNode *left = pop();
					if (right == nullptr || left == nullptr) {
						std::cerr << "Error: wrong formula." << std::endl;
						exit(EXIT_FAILURE);
					}
					left = bindNodes(createNode('!'), nullptr, left, 0);
					appendNode(bindNodes(createNode('|'), left, right, 0));
				} else if (symbol == '=' ) {
					// (p & q) | (!p & !q)
					treeNode *right = pop();
					treeNode *left = pop();
					if (right == nullptr || left == nullptr) {
						std::cerr << "Error: wrong formula." << std::endl;
						exit(EXIT_FAILURE);
					}
					treeNode *formula1 = bindNodes(createNode('&'), left, right, 0);
					treeNode *copyRight = copySubTree(right);
					treeNode *copyLeft = copySubTree(left);
					copyRight = bindNodes(createNode('!'), nullptr, copyRight, 0);
					copyLeft = bindNodes(createNode('!'), nullptr, copyLeft, 0);
					treeNode *formula2 = bindNodes(createNode('&'), copyLeft, copyRight, 0);
					appendNode(bindNodes(createNode('|'), formula1, formula2, 0));
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

		void printEx05()
		{
			std::cout << "NNF : ";
			postorder(head_);
			std::cout << std::endl;
		}
	};
}