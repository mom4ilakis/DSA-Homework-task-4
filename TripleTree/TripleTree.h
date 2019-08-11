#pragma once
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
#include <vector>
#include <unordered_map>
#include <utility>

class TripleTree
{
	struct node
	{

		node* left_chl, *right_chl, *center_cld;
		char data;

		node(char data, node* left_c = nullptr, node* center_c  = nullptr, node* right_c = nullptr);

	};



public:
	
	TripleTree(const std::string& filename = "DefInput.txt");
	TripleTree(const TripleTree& src) = delete;
	TripleTree& operator=(const TripleTree& src) = delete;
	~TripleTree();


	void loadFromFile(const std::string& Filename);
	
	void NormalPrint() const;
	void PrintByLevels() const;
private:
	void preorder(const node* ptr, unsigned level, std::unordered_map<int, std::vector<node>>& lev) const;

	void WeirdPrint() const;

	void MyPrint(const node* tmp,unsigned level=0) const;


	void printRRL(const node* tmp)const;

	//creates a node, returns nullptr if an empthy node is created
	node* createNode(std::ifstream& is, char cld ='E');
	//removes whitespaces and ( , ) form stream
	void eatFiller(std::ifstream& is);

	void clear(node* tmp);
private:
	node* root;
	
};

