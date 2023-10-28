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


	operationsPrecedence.insert(std::make_pair("(", 0)); //left parenth 
	operationsPrecedence.insert(std::make_pair(")", 0)); //right parenth

	operationsPrecedence.insert(std::make_pair("+", 1)); //binary op-n sum
	operationsPrecedence.insert(std::make_pair("-", 1)); //binary op-n sub

	operationsPrecedence.insert(std::make_pair("*", 2)); //binary op-n mult
	operationsPrecedence.insert(std::make_pair("/", 2)); //binary op-n div

	operationsPrecedence.insert(std::make_pair("~", 4)); //unary '-'


	DLL.loadDll(operationsPrecedence, functionsU, functionsB); // plugins
} 

size_t operations::getKeyCoincidence(std::string token, int i) { 
	if (i == 1) return this->operators.count(token);
	else return this->functionsU.count(token) + this->functionsB.count(token);
}

int operations::getPrecedence(std::string token) {
	if (this->operationsPrecedence.find(token) != operationsPrecedence.end())
		return (this->operationsPrecedence.find(token)->second);
	return 0;
}

int operations::Xnarity(const std::string& token) {
	if (this->functionsU.find(token) != functionsU.end()) return 1;
	else if (this->functionsB.find(token) != functionsB.end()) return 2;
	return 0;
}

double operations::Oevaluate(const double& a, const double& b, const std::string& name) {
	return operators[name](a, b); 
}

double operations::FUevaluate(const double& a, std::string name) {
	return functionsU[name](a);
}

double operations::FBevaluate(const double& a, const double& b, std::string name) {
	return functionsB[name](a, b);
}