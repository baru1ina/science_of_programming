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
    return nullptr;
}

node* node::bypass(node* current) { 
    if (current->parent.lock().get() == nullptr)
        current = nullptr;
    else if (current->parent.lock()->childrenSize() > 1) {
        for (int i = 0; i < current->parent.lock()->childrenSize(); i++) {
            if (current == current->parent.lock()->getChild(i).get())
                if (i + 1 <= current->parent.lock()->childrenSize() - 1) {
                    current = current->parent.lock()->getChild(i + 1).get();
                    break;
                }
                else 
                    current = bypass(current->parent.lock().get());
        }
    }
    else
       current = bypass(current->parent.lock().get());
    return current;
}

node* node::prefix_inc() {
    node* current = this;
    if (current->childrenSize() != 0)
        return current->getChild(0).get();
    else 
        return bypass(current);
}

void node::add(const std::string& tagName, const std::string& tagValue) {
    std::shared_ptr<node> newNode(new node(tagName, tagValue));
    children.push_back(newNode);
    newNode->parent = shared_from_this();
    //newNode->getParent()->print();
}

void node::erase() {
    for (auto& child : children) {
        child->parent = parent;
        child->parent.lock()->push_back(child);
    }
    for (int ind = 0; ind < parent.lock()->children.size(); ind++) {
        if (parent.lock()->children[ind].get() == this) {
            parent.lock()->children.erase(parent.lock()->children.begin() + ind);
            break;
        }
    }
}

void node::print() {
    std::cout << key << ":  value = " << value << std::endl;
}