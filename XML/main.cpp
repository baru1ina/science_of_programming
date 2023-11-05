#include "tree.h"

int main() {
	//std::string a = "asdfghjklxcvbnm";
	//std::string::iterator i = a.end();
	////*a.begin() = 'b';
	//std::cout << *a.begin() << *(i-1) << std::endl;
	//a.insert(i - 1, 'a');
	//std::cout << a << std::endl;

	/*std::shared_ptr<node> root(new node("0", "123456"));
	std::shared_ptr<node> node1(new node("1", "21234"));
	std::shared_ptr<node> node2(new node("1.1", "23456"));
	node1->push_back(node2);
	std::shared_ptr<node> node3(new node("2", "12345"));
	root->push_back(node1);
	root->push_back(node3);
	
	std::shared_ptr<tree> tree1(new tree(root));
	tree1->print(tree1->getRoot(), 0);*/

	std::shared_ptr<tree> tree1(new tree());
	tree1->load("inputTree.xml");
	tree1->print(tree1->getRoot(), 0);
	
	int i = 0;
	
	iterator it(tree1->getRoot()->getChild(i).get());
	(*it).print();
	node* p = (*it).getParent().get();
	//p->print();
	it++;
	it++;
	it++;
	(*it).print();
	

	std::shared_ptr<tree> _tree(new tree());
	
	/*try {
		_tree->load("inputTree.xml");
		_tree->print(_tree->getRoot(), 0);

		std::cout << std::endl;

		(*(_tree->begin())).print();

		std::cout << std::endl;

		(*(_tree->end())).print();

		iterator itr = _tree->findKey("child12");
		itr = _tree->findKey("child1");

		itr = _tree->findValue("100");
		itr = _tree->findValue("1");

		save(_tree, "outputTree.xml");
	}
	catch (std::exception& err) {
		std::cout << err.what() << std::endl;
	}*/

	return 0;
}