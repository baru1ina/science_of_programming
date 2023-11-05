#pragma once
#include "node.h"

struct iterator {
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = node;

	iterator(node* _ptr) : ptr(_ptr) {}

	node& operator*() const { return *ptr; }

	node* operator->() { return ptr; }

	iterator& operator++() {
		this->ptr = this->ptr->prefix_inc();
		return *this;
	}

	iterator operator++(int) {
		iterator tmp = *this; ++(*this); return tmp;
	}

	friend bool operator== (const iterator& a, const iterator& b) {
		return a.ptr == b.ptr;
	};
	friend bool operator!= (const iterator& a, const iterator& b) {
		return a.ptr != b.ptr;
	}

private:
	node* ptr;
};