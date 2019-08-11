#include "TripleTree.h"



//TripleTree::TripleTree()
//{
//}

TripleTree::TripleTree(const std::string & filename):root(nullptr)
{

	loadFromFile(filename);

}


TripleTree::~TripleTree()
{
	clear(root);
}

void TripleTree::loadFromFile(const std::string & Filename)
{

	std::ifstream inputFile;

	inputFile.open(Filename);
	
	if (inputFile.is_open())
	{
		clear(root);

		std::cout << "Loading from... " << Filename << '\n';

		char symbol;

		eatFiller(inputFile);

		symbol = inputFile.get();

		if (symbol != '*')
		{
			node * left = createNode(inputFile, 'l');
			node * center = createNode(inputFile, 'c');
			node * right = createNode(inputFile, 'r');

			root = new node(symbol, left, center, right);
		}
	}
	else
		std::cout << "Failed to load from: " << Filename << '\n';

	inputFile.close();
}

void TripleTree::NormalPrint() const
{
	printRRL(root);
}

void TripleTree::PrintByLevels() const
{
	WeirdPrint();
}

void TripleTree::WeirdPrint() const
{
	unsigned cur_level = 0;
	std::unordered_map<int, std::vector<node>> levels;

	preorder(root, 1, levels);

	std::unordered_map<int, std::vector<node>>::iterator it = levels.begin(), end = levels.end();

	while (it != end)
	{
		for (const node& n : it->second)
			std::cout << n.data;

		std::cout << '\n';
		++it;
	}

	


	//MyPrint(root);
}

void TripleTree::preorder(const node * ptr, unsigned level, std::unordered_map<int, std::vector<node>>& lev) const
{
	if (ptr == nullptr)
		return;

	lev[level].push_back(*ptr);

	preorder(ptr->left_chl, level + 1, lev);
	preorder(ptr->center_cld, level + 1, lev);
	preorder(ptr->right_chl, level + 1, lev);

}

void TripleTree::MyPrint(const node * tmp, unsigned level) const
{
	if (tmp == nullptr)
		return;

	level++;

	std::cout << tmp->data;

	MyPrint(tmp->left_chl);
	MyPrint(tmp->center_cld);
	MyPrint(tmp->right_chl);

	
	
}

void TripleTree::printRRL(const node* tmp) const
{
	if (tmp == nullptr)
		return;

	std::cout << tmp->data;
	printRRL(tmp->left_chl);
	printRRL(tmp->center_cld);
	printRRL(tmp->right_chl);
	

}

TripleTree::node * TripleTree::createNode(std::ifstream & is, char cld)
{
	unsigned number_stars = 0;
	char symbol;
	node* tmp = nullptr, *left = nullptr, *center = nullptr, *right = nullptr;
	eatFiller(is);

	symbol = is.get();

	if (symbol != '*')
	{
		left = createNode(is, 'l');
		center = createNode(is, 'c');
		right = createNode(is, 'r');

		tmp = new node(symbol, left, center, right);

	}
	



	return tmp;

}

void TripleTree::eatFiller(std::ifstream & is)
{

	while(is.good() && (is.peek() == '(' || is.peek() == ')' || is.peek() == ' '))
		is.get();


}

void TripleTree::clear(node * tmp)
{
	if (tmp != nullptr)
	{
		clear(tmp->left_chl);
		clear(tmp->right_chl);
		clear(tmp->center_cld);
		delete tmp;
	}
}

TripleTree::node::node(char data, node * left_c, node * center_c, node *  right_c) :data(data), left_chl(left_c), right_chl(right_c), center_cld(center_c)
{
	;
}

