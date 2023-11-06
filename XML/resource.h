#pragma once
#include "tree.h"

class resource {
public:
	resource() : _tree(std::make_unique<tree>()) {};

	~resource() = default;
	resource(const resource&) = delete;
	resource(resource&&) = delete;
	resource& operator = (const resource&) = delete;
	resource& operator = (resource&&) = delete;

	static std::unique_ptr<resource> create();
	
	iterator begin();
	iterator end();

	void load(const std::string& infilename);
	void save(const std::string& outfilename);

	bool erase(iterator& it);

	std::shared_ptr<node> getRoot();

	void print(std::shared_ptr<node> root, int hight);
	
	iterator findKey(const std::string& tagName);
	iterator findValue(const std::string& tagValue);
	iterator add(const std::string& tagName, const std::string& tagValue, iterator& itr);


private:
	std::unique_ptr<tree> _tree;
};
	