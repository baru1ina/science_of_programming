cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)

project ("calculator")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (calculator "main.cpp" "calc.cpp" "calc.h" "loader.h" "loader.cpp" "operations.cpp")

add_custom_target(AddPlugins ALL)

add_custom_command(
TARGET AddPlugins
COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/plugins
COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/plugins ${CMAKE_BINARY_DIR}/plugins 
)

add_dependencies("calculator" AddPlugins)
