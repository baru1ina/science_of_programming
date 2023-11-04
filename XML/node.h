#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include <functional>
#include <memory>

class node {
public:
	node(const std::string& tagName, const std::string& tagValue) : key(tagName), value(tagValue) {};

	node() = default;
	~node() = default;

	std::string getKey() const { return this->key; };
	std::string getValue() const { return this->value; };
	std::shared_ptr<node> getChild(int& ind) const { return this->children[ind]; };

	void push_back(std::shared_ptr<node> node) { children.push_back(node); };
	int childrenSize() { return this->children.size(); };

	void for_each(std::function<void(const node&)> function);

private:
	std::string key; // tag_name
	std::string value; // tag_value
	std::vector<std::shared_ptr<node>> children;
};