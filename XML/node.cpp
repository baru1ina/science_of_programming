#include "node.h"

void node::for_each(std::function<void(const node&)> function) {
    function(*this);
    for (auto&& child : children)
        child->for_each(function);
}

node* node::begin() { 
    return this;
}

node* node::end() {
    std::shared_ptr<node> endNode;
    for (auto& child : children) {
        (*child).print();
      /*  if (child->childrenSize() == 0)
            endNode = child;*/
        child->end();
        endNode = child;
    }
    return endNode.get();
}

bool node::checkChildren(node* current) {
    return true;
}

node* node::prefix_inc() {
    node* current = this;
    if (current->parent.lock()->childrenSize() != 0) { 
        for (int i = 0; i < current->parent.lock()->childrenSize(); i++) {
            if (current == current->parent.lock()->getChild(i).get() && ((i + 1) <= current->parent.lock()->childrenSize())) {
                current = current->parent.lock()->getChild(i + 1).get();
            }
            else {
                current = current->parent.lock()->parent.lock()->prefix_inc();
            }
        }
    } 
    return current;
}

void node::print() {
    std::cout << key << ":  value = " << value << std::endl;
}