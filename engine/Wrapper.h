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
    Wrapper(T* _subject, Func _func, std::unordered_map<std::string, int> _args) {
        if (!_subject || !_func) {
            throw std::runtime_error("nullptr instead of a method or object");
        }
        else {
            subject = _subject;
            function = _func;
        }

        for (const auto& pair : _args) {
            if (_args.count(pair.first) > 1) {
                arguments.clear();
                throw std::runtime_error("two arguments with the same name");
            }

            arguments[pair.first] = pair.second;
        }
    }

    template<size_t... idx>
    int call(std::index_sequence<idx...>) {
        return (subject->*function)(vals[idx]...);
    }

    int execute(std::unordered_map<std::string, int> _args) {
        for (const auto& pair : _args) {
            if (sizeof...(args) != _args.size()) {
                throw std::runtime_error("invalid number of arguments");
            }
            vals.push_back(pair.second);

        }

        int result;

        try {
            result = call(std::make_index_sequence<sizeof...(args)>{});
        }
        catch (std::exception& ex) {
            std::cout << ex.what();
        }
        return result;
    }
};

//std::unordered_map<std::string, int> args_