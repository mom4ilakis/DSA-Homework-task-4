#include "TripleTree.h"


int main()
{
	std::string filename;
	std::string choice;
	TripleTree tree;

	std::cout << "Enter filename ? (y/n)\n";
	std::cin >> choice;
	if (choice == "y")
	{
		std::cout << "Enter filename\n";
		std::cin >> filename;
		tree.loadFromFile(filename);
	}
	else
		tree.PrintByLevels();


	return 0;
}