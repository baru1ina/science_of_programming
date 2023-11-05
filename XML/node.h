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
	node(const std::string& tagName, const std::string& tagValue) :
		key(tagName),
		value(tagValue) {};

	node() = default;
	~node() = default;

	std::string getKey() const { return this->key; };
	std::string getValue() const { return this->value; };

	std::shared_ptr<node> getChild(int ind) const { return this->children[ind]; };
	void push_back(std::shared_ptr<node> node) { children.push_back(node); };
	size_t childrenSize() { return this->children.size(); };

	std::shared_ptr<node> getParent() const { return this->parent.lock(); };
	void setParent(std::shared_ptr<node> node) { this->parent = node; };

	void for_each(std::function<void(const node&)> function);

	void print();

	node* begin();
	node* end();
	node* prefix_inc();

	bool checkChildren(node* current);

	friend bool operator== (const node& a, const node& b) {
		return (a.key == b.key) && (a.value == b.value) && (a.children == b.children) && (a.parent.lock() == b.parent.lock());
	};

private:
	std::string key;
	std::string value; 
	std::vector<std::shared_ptr<node>> children;

	std::weak_ptr<node> parent;
};