#include "Tree.hpp"

void EX03::TreeNode::setLogicValue(bool logicValue) { logicValue_ = logicValue; }
void EX03::TreeNode::setOperator(char op) { operator_ = op; }
void EX03::TreeNode::setRight(TreeNode *right) { right_ = right; }
void EX03::TreeNode::setLeft(TreeNode *left) { left_ = left; }
void EX03::TreeNode::setNext(TreeNode *next) { next_ = next; }
bool EX03::TreeNode::getLogicValue() const { return logicValue_; }
char EX03::TreeNode::getOperator() const { return operator_; }
EX03::TreeNode *EX03::TreeNode::getRight() const { return right_; }
EX03::TreeNode *EX03::TreeNode::getLeft() const { return left_; }
EX03::TreeNode *EX03::TreeNode::getNext() const { return next_; }

EX03::Tree::Tree()
	: answer_(0), size_(0), numNodeList_(0), head_(nullptr) { }
EX03::Tree::~Tree()
{
	deleteTree(head_);
	size_ = 0;
	numNodeList_ = 0;
}
bool EX03::Tree::getAnswer() const { return answer_; }

void EX03::Tree::deleteTree(TreeNode *root)
{
	if (root == nullptr)
		return;
	deleteTree(root->getLeft());
	deleteTree(root->getRight());

	delete root;
	root = nullptr;
}

EX03::TreeNode *EX03::Tree::createNode(char symbol)
{
	TreeNode *newNode = new TreeNode;
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
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
		exit(EXIT_FAILURE);
	}
}

void EX03::Tree::appendNode(TreeNode *node)
{
	node->setNext(head_);
	head_ = node;
	size_++;
	numNodeList_++;
}

EX03::TreeNode *EX03::Tree::pop()
{
	TreeNode *popNode = head_;
	head_ = head_->getNext();
	popNode->setNext(nullptr);
	numNodeList_--;
	return popNode;
}

EX03::TreeNode *EX03::Tree::bindNodes(TreeNode *root, TreeNode *left, TreeNode *right)
{
	switch (root->getOperator()) {
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

void EX03::Tree::parse(const std::string &formula)
{
	for (int i = 0; i < formula.size(); i++)
	{
		char symbol = formula.at(i);
		if (symbol == '0' || symbol == '1') {
			appendNode(createNode(symbol));
		}
		else if (symbol == '!') {
			TreeNode *right = pop();
			if (right == nullptr) {
				std::cerr << "Error: wrong formula" << std::endl;
				exit(EXIT_FAILURE);
			}
			appendNode(bindNodes(createNode(symbol), nullptr, right));
		}
		else if (symbol == '&' || symbol == '|' || symbol == '^' || symbol == '>' || symbol == '=') {
			TreeNode *right = pop();
			TreeNode *left = pop();
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