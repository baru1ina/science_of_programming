#pragma once
#include "Wrapper.h"


class Engine {
private:
	std::unordered_map<std::string, std::function<int(std::unordered_map<std::string, int>)>> commands;

public:
	template <typename T, typename... args>
	void register_command(Wrapper<T, args...>* wrapper, const std::string& command);
	int execute(const std::string& command, std::unordered_map<std::string, int> args);
};