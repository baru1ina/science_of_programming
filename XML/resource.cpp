#include "resource.h"

std::unique_ptr<resource> resource::create() {
	return std::unique_ptr<resource>(new resource());
}

iterator resource::begin() {
	return _tree->begin();
};

iterator resource::end() {
	return _tree->end();
};

void resource::load(const std::string& infilename) {
	return _tree->load(infilename);
};

iterator resource::findKey(const std::string& tagName) {
	return _tree->findKey(tagName);
};

iterator resource::findValue(const std::string& tagValue) {
	return _tree->findValue(tagValue);
};

iterator resource::add(const std::string& tagName, const std::string& tagValue, iterator& itr) {
	return _tree->add(tagName, tagValue, itr);

};

bool resource::erase(iterator& itr) {
	return _tree->erase(itr);
};

std::shared_ptr<node> resource::getRoot() {
	return _tree->getRoot();
}

void resource::print(std::shared_ptr<node> root, int hight) {
	return _tree->print(root, hight);
};

void resource::save(const std::string& outfilename) {
	std::ofstream file(outfilename);
	if (!file)
		throw std::runtime_error("file opening error\n");
	if (!_tree) {
		throw std::runtime_error("tree's empty\n");
	}
	file << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << std::endl;
	_tree->save(_tree->getRoot(), file, 0);
	std::cout << "saving successful\n" << std::endl;
	file.close();
};