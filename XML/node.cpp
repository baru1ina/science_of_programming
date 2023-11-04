#include "node.h"

void node::for_each(std::function<void(const node&)> function) {
    function(*this);
    for (auto&& child : children)
        child->for_each(function);
}