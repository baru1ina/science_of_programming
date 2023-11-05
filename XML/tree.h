#pragma once
#include "iterator.h"

class tree {
public:
	tree() : root(nullptr) {};
	tree(std::shared_ptr<node> root) : root(root) {};
	~tree() = default;

	iterator begin();
	iterator end();

	void load(const std::string& infilename);
	void save(std::shared_ptr<node> root, int hight, std::ofstream& outfilename);

	iterator findKey(const std::string& tagName);
	iterator findValue(const std::string& tagValue);
	iterator add(const std::string& tagName, const std::string& tagValue, iterator& itr);

	bool erase(iterator& itr);

	std::shared_ptr<node> getRoot() { return this->root; };
	void print(std::shared_ptr<node> root, int hight);
	

private:
	std::shared_ptr<node> root;
};

void save(std::shared_ptr<tree> tree, const std::string outfilename);
