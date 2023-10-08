#include "operations.h"

operations::operations() {

	operators["+"] = [](double a, double b)->double { return a + b; }; // core
	operators["-"] = [](double a, double b)->double { return a - b; };
	operators["*"] = [](double a, double b)->double { return a * b; };
	operators["/"] = [](double a, double b)->double {
		if (b) return a / b;
		std::cerr << std::endl << "division by zero" << std::endl;
		return std::numeric_limits<double>::infinity();
	};


	operatorsPrecedence.insert(std::make_pair('(', 0)); //left parenth 
	operatorsPrecedence.insert(std::make_pair(')', 0)); //right parenth

	operatorsPrecedence.insert(std::make_pair('+', 1)); //binary op-n sum
	operatorsPrecedence.insert(std::make_pair('-', 1)); //binary op-n sub

	operatorsPrecedence.insert(std::make_pair('*', 2)); //binary op-n mult
	operatorsPrecedence.insert(std::make_pair('/', 2)); //binary op-n div

	operatorsPrecedence.insert(std::make_pair('^', 3)); //binary op-n deg

	operatorsPrecedence.insert(std::make_pair('~', 4)); //unary '-'

	operatorsPrecedence.insert(std::make_pair('s', 4)); //unary op-n sin
	operatorsPrecedence.insert(std::make_pair('c', 4)); //unary op-n cos
	operatorsPrecedence.insert(std::make_pair('t', 4)); //unary op-n tg
	operatorsPrecedence.insert(std::make_pair('l', 4)); //unary op-n ln


	funcAbbreviaton.insert(std::make_pair("s", "sin")); //unary op-n sin // dll funcs
	funcAbbreviaton.insert(std::make_pair("c", "cos")); //unary op-n cos
	funcAbbreviaton.insert(std::make_pair("t", "tg")); //unary op-n tg
	funcAbbreviaton.insert(std::make_pair("l", "ln")); //unary op-n ln
}

int operations::getKeyCoincidence(const char& token) { return this->operatorsPrecedence.count(token); }

int operations::getPrecedence(const char& token) {
	if (this->operatorsPrecedence.find(token) != operatorsPrecedence.end()) return (this->operatorsPrecedence.find(token)->second);
	else throw std::string{ "unknown operator" };
}

std::string operations::getInterp(std::string& token) {
	if (this->funcAbbreviaton.find(token) != funcAbbreviaton.end()) return (this->funcAbbreviaton.find(token)->second);
	else throw std::string{ "unknown function" };
}

double operations::evaluate(double const& a, double const& b, std::string const& name) { 
	return operators[name](a, b); 
}