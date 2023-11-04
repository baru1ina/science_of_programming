#pragma once
#include "node.h"

struct iterator {
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = node;

	using pointer = node*;
	using reference = node&;

	iterator(pointer _ptr) : ptr(_ptr) {}

	reference operator*() const { return *ptr; }
	pointer operator->() { return ptr; }

	iterator& operator++() { ptr++; return *this; }
	iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }

	friend bool operator== (const iterator& a, const iterator& b) { return a.ptr == b.ptr; };
	friend bool operator!= (const iterator& a, const iterator& b) { return a.ptr != b.ptr; };

private:
	pointer ptr;
};