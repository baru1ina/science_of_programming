#pragma once 
#include "operations.h"

class calc {
private:
	std::string input;
	std::string output;

	operations myOperations;

	std::vector<std::string> parsedVec;
	
public:
	calc() = default;

	std::string getOutput() { return this->output; }

	bool operatorCheck(std::string token);
	bool funcCheck(std::string token);

	std::string delSpace(const std::string& input);
	std::string pickNum(int& ptr, const std::string& input);
	std::string pickFunc(int& ptr, const std::string& input);

	void toPostfix(const std::string& input);
	void calculate(const std::string& input); 
};