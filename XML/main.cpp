#include "resource.h"

int main() {
	std::unique_ptr<resource> xml = resource::create();
	try {
		xml->load("inputTree.xml");
		xml->print(xml->getRoot(), 0);
	
		std::cout << std::endl;
	
		xml->save("outputTree.xml");
	
		(*(xml->begin())).print();
		std::cout << std::endl;
	
		iterator itr = xml->findKey("child1");
		(*itr).print();
		std::cout << std::endl;
	
		if (xml->erase(itr))
			xml->print(xml->getRoot(), 0);
		std::cout << std::endl;
	
		itr = xml->findValue("9");
		(*itr).print();
		std::cout << std::endl;
	
		itr = xml->findValue("1");
		(*itr).print();
		std::cout << std::endl;
	
		itr = xml->add("child4", "ya rodilsya", itr);
		(*itr).print();
		xml->print(xml->getRoot(), 0);
		std::cout << std::endl;

		itr = xml->findValue("1");
		if (xml->erase(itr))
			xml->print(xml->getRoot(), 0);
		std::cout << std::endl;
	
	}
	catch (std::exception& err) {
		std::cout << err.what() << std::endl;
	}
	return 0;
}