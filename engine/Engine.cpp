#include "Engine.h"

template <typename T, typename... args>
void Engine::register_command(Wrapper<T, args...>* wrapper, const std::string& command) {
    if (commands.find(command) != commands.end()) {
        throw std::runtime_error("command named" + command + "already exists");
    }
    else {
        commands[command] = [wrapper](std::unordered_map<std::string, int> args);
    }
}

int Engine::execute(const std::string& command, std::unordered_map<std::string, int> args) {
    if (commands.find(command) == commands.end()) {
        throw std::runtime_error("command not found");
    }
    return (commands.find(command)->second)(args);
}