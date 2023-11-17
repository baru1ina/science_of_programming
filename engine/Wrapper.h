#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <functional>
#include <variant>

template <typename T, typename... args>
class Wrapper {
private:
    using Func = int (T::*)(args...);

    T* subject;
    Func function;

    std::unordered_map<std::string, int> arguments;
    std::vector<int> vals;

public:
    Wrapper(T* subject, Func func, std::unordered_map<std::string, int> args);  
    int calc(std::make_index_sequence<sizeof...(args)>{});
};