#pragma once

#include <iostream>
#include <map>
#include <functional>
#include <iostream>
#include <stack>
#include <cctype>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>

class operations {
private:
	std::map<std::string, std::function<double(double, double)>> operators;
	std::map<char, int> operatorsPrecedence;
	std::map<std::string, std::string> funcAbbreviaton;
public:
	operations();
	~operations() = default;
	operations(const operations& A) = default;
	operations(operations&&) = default;
	operations& operator = (const operations& A) = default;
	operations& operator = (operations&&) = default;

	int getKeyCoincidence(const char& token);
	int getPrecedence(const char& token);
	std::string getInterp(std::string& token);

	double evaluate(double const& a, double const& b, std::string const& name);
};