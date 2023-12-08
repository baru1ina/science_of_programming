#include "Engine.h"

int Engine::execute(const std::string& command, std::unordered_map<std::string, int> args) {
    if (commands.find(command) == commands.end()) {
        throw std::runtime_error("command not found");
    }
    return (commands.find(command)->second)(args);
}