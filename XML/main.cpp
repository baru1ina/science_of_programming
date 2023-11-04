#include "tree.h"

int main() {
	std::shared_ptr<tree> _tree(new tree());
	
	try {
		_tree->load("inputTree.xml");
		_tree->print(_tree->getRoot(), 0);

		save(_tree, "outputTree.xml");
	}
	catch (std::exception& err) {
		std::cout << err.what() << std::endl;
	}

	return 0;
}