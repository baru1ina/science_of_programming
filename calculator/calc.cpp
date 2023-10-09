#include "calc.h"

template<class T>
std::string toString(T c) {
	std::stringstream stringstream;
	std::string str;
	stringstream << c;
	stringstream >> str;
	return str;
}

std::string calc::delSpace(const std::string& input) {
	std::string nospaces = input;
	std::string::size_type ptr;
	while ((ptr = nospaces.find(' ')) != std::string::npos) nospaces.erase(ptr, 1);
	return nospaces;
}

std::string calc::pickNum(int& ptr, const std::string& input) {
	std::string num = "";
	while ((isdigit(input[ptr]) || input[ptr] == '.')){
		num += input[ptr];
		ptr++;
	}
	return num;
}

std::string calc::pickFunc(int& ptr, const std::string& input) {
	std::string func = "";
	while ((isalpha(input[ptr]))) {
		func += input[ptr];
		ptr++;
	}
	return func;
}

bool calc::operatorCheck(std::string token) {
	if (myOperations.getKeyCoincidence(token, 1) != 0) return true;
	else return false;
}

bool calc::funcCheck(std::string token) {
	if (myOperations.getKeyCoincidence(token, 2) != 0) return true;
	else return false;
}

void calc::toPostfix(const std::string& input) { 

	this->input = delSpace(input);
	
	std::vector<std::string> postfixVec;
	std::stack<std::string> operators;
	int i = 0;
	while (i < this->input.length()) {
		char token = this->input[i];
		if (isdigit(token)) { 
			postfixVec.push_back(pickNum(i, this->input));
		}
		else if (isalpha(token)) {
			operators.push(pickFunc(i, this->input));
		}
		/*else if (funcCheck(token)) {

			operators.push(token);
			if (token == 's' || token == 'c') i += 3;
			else if (token == 'l' || token == 't') i += 2;
		}*/
		else if (token == '(') {
			operators.push(toString(token)); i++;
		}
		else if (token == ')') {
			while (!operators.empty() && operators.top() != "(") {
				postfixVec.push_back(toString(operators.top()));
				operators.pop();
			}
			operators.pop();
			i++;
		}
		else if (operatorCheck(toString(token)) || myOperations.Xnarity(toString(token)) == 2) {
			if (token == '-' && (i == 0 || (i > 0 && operatorCheck(toString(this->input[i-1]))))) token = '~';
			while (!operators.empty() && (myOperations.getPrecedence(toString(operators.top())) >= myOperations.getPrecedence(toString(token)))) {
				postfixVec.push_back(toString(operators.top()));
				operators.pop();
			}
			operators.push(toString(token));
			i++;
		}
	}
	while (!operators.empty()) {
		postfixVec.push_back(toString(operators.top()));
		operators.pop();
	} 

	this->parsedVec = postfixVec;
	this->sampleOperators = operators;

	for (int i = 0; i < parsedVec.size(); i++) {
		std::cout << parsedVec[i];
	}
	std::cout << std::endl;
}

void calc::calculate(const std::string& input) {

	toPostfix(input);

	std::stack<double> result;
	int iterCount = 0;

	for (int i = 0; i < parsedVec.size(); i++) {
		std::string token = parsedVec[i];
		if (isdigit(token[0])) result.push(std::stod(token)); 
		else if (operatorCheck(token) || token == "~") {
			//    operand1 | operator | operand2    //
			iterCount++;
			if (token == "~") {
				double negativeNum = 0;
				if (!result.empty()) { negativeNum = result.top(); result.pop(); }
				result.push(myOperations.Oevaluate(0, negativeNum, "-"));
				std::cout << "[" << iterCount << "]  " << "-" << negativeNum << " = " << result.top() << std::endl;
				continue;
			}
			double operand2 = 0;
			if (!result.empty()) { operand2 = result.top(); result.pop(); }
			double operand1 = 0;
			if (!result.empty()) { operand1 = result.top(); result.pop(); }
			result.push(myOperations.Oevaluate(operand1, operand2, token));
			std::cout << "[" << iterCount << "]  " << operand1 << token << operand2 << " = " << result.top() << std::endl;
		}
		//    function | (operand)   //    (base) | function | (operand)   //
		else if (funcCheck(token)) {
			iterCount++;
			double operand = 0;
			if (!result.empty()) { operand = result.top(); result.pop(); }
			if (myOperations.Xnarity(token) == 1) {
				result.push(myOperations.FUevaluate(operand, token));
				std::cout << "[" << iterCount << "]  " << token << "(" << operand << ")" << " = " << result.top() << std::endl;
			}
			else if (myOperations.Xnarity(token) == 2) {
				double base = 0;
				if (!result.empty()) { base = result.top(); result.pop(); }
				result.push(myOperations.FBevaluate(base, operand, token));
				std::cout << "[" << iterCount << "]  " << "(" << base << ")" << token << "(" << operand << ")" << " = " << result.top() << std::endl;
			}
		}
	} 

	this->output = toString(result.top());
}

