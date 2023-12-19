#include "Parse.hpp"

void PARSE::ex03Node::setLogicValue(bool logicValue) { logicValue_ = logicValue; }
void PARSE::ex03Node::setOperator(char op) { operator_ = op; }
void PARSE::ex03Node::setRight(ex03Node *right) { right_ = right; }
void PARSE::ex03Node::setLeft(ex03Node *left) { left_ = left; }
void PARSE::ex03Node::setNext(ex03Node *next) { next_ = next; }
bool PARSE::ex03Node::getLogicValue() const { return logicValue_; }
char PARSE::ex03Node::getOperator() const { return operator_; }
PARSE::ex03Node *PARSE::ex03Node::getRight() const { return right_; }
PARSE::ex03Node *PARSE::ex03Node::getLeft() const { return left_; }
PARSE::ex03Node *PARSE::ex03Node::getNext() const { return next_; }

PARSE::ex03Tree::ex03Tree()
	: answer_(0), size_(0), numNodeList_(0), head_(nullptr) { }
PARSE::ex03Tree::~ex03Tree()
{
	deleteTree(head_);
	size_ = 0;
	numNodeList_ = 0;
}
bool PARSE::ex03Tree::getAnswer() const { return answer_; }

void PARSE::ex03Tree::deleteTree(ex03Node *root)
{
	if (root == nullptr)
		return;
	deleteTree(root->getLeft());
	deleteTree(root->getRight());

	delete root;
	root = nullptr;
}

PARSE::ex03Node *PARSE::ex03Tree::createNode(char symbol)
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
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
		exit(EXIT_FAILURE);
	}
}

void PARSE::ex03Tree::appendNode(ex03Node *node)
{
	node->setNext(head_);
	head_ = node;
	size_++;
	numNodeList_++;
}

PARSE::ex03Node *PARSE::ex03Tree::pop()
{
	ex03Node *popNode = head_;
	head_ = head_->getNext();
	popNode->setNext(nullptr);
	numNodeList_--;
	return popNode;
}

PARSE::ex03Node *PARSE::ex03Tree::bindNodes(ex03Node *root, ex03Node *left, ex03Node *right)
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

void PARSE::ex03Tree::parse(const std::string &formula)
{
	for (int i = 0; i < formula.size(); i++)
	{
		char symbol = formula.at(i);
		if (symbol == '0' || symbol == '1') {
			appendNode(createNode(symbol));
		}
		else if (symbol == '!') {
			ex03Node *right = pop();
			if (right == nullptr) {
				std::cerr << "Error: wrong formula" << std::endl;
				exit(EXIT_FAILURE);
			}
			appendNode(bindNodes(createNode(symbol), nullptr, right));
		}
		else if (symbol == '&' || symbol == '|' || symbol == '^' || symbol == '>' || symbol == '=') {
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