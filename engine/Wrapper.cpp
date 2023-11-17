#include "Wrapper.h"

template <typename T, typename... args>
Wrapper<T, args...>::Wrapper(T* _subject, Func _func, std::unordered_map<std::string, int>& _args): subject(_subject), function(_func) {
    if (!_subject || !_func) {
        throw std::runtime_error("nullptr instead of a method or object");
    }

    for (const auto& pair : _args) {
        if (_args.count(pair.first) > 1) { 
            arguments.clear();
            throw std::std::runtime_error("two arguments with the same name");
        }
        
        arguments[pair.first] = pair.second;

        if (sizeof...(args) != _args.size()) {
            throw std::std::runtime_error("invalid number of arguments");
        }

        vals.push_back(pair.second);
    }
}

template <typename T, typename... args>
int Wrapper<T, args...>::execute() {
    int result;
    try {
        result = call(std::make_index_sequence<sizeof...(args)>{});;
    }
    catch (std::exception& ex) {
        std::cout << ex.what();
    }
    return result;
}