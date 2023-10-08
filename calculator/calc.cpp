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

bool calc::operatorCheck(char token) {
	if (myOperations.getKeyCoincidence(token) != 0 && !funcCheck(token)) return true;
	else return false;
}

bool calc::funcCheck(char token) {
	if (myOperations.getKeyCoincidence(token) != 0 && token != '-' && myOperations.getPrecedence(token) == 4) return true;
	else return false;
}

void calc::toPostfix(const std::string& input) { 

	this->input = delSpace(input);
	
	std::vector<std::string> postfixVec;
	std::stack<char> operators;

	int i = 0;
	while (i < this->input.length()) {
		char token = this->input[i];
		if (isdigit(token)) { 
			postfixVec.push_back(pickNum(i, this->input));
		}
		else if (funcCheck(token)) {
			operators.push(token);
			if (token == 's' || token == 'c') i += 3;
			else if (token == 'l' || token == 't') i += 2;
		}
		else if (token == '(') {
			operators.push(token); i++;
		}
		else if (token == ')') {
			while (!operators.empty() && operators.top() != '(') {
				postfixVec.push_back(toString(operators.top()));
				operators.pop();
			}
			operators.pop();
			i++;
		}
		else if (operatorCheck(token)) {
			if (token == '-' && (i == 0 || (i > 0 && operatorCheck(this->input[i-1])))) token = '~';
			while (!operators.empty() && (myOperations.getPrecedence(operators.top()) >= myOperations.getPrecedence(token))) {
				postfixVec.push_back(toString(operators.top()));
				operators.pop();
			}
			operators.push(token);
			i++;
		}
	}
	while (!operators.empty()) {
		postfixVec.push_back(toString(operators.top()));
		operators.pop();
	} 

	this->parsedVec = postfixVec;
	this->sampleOperators = operators;

	/*for (int i = 0; i < parsedVec.size(); i++) {
		std::cout << parsedVec[i];
	}*/
}

void calc::calculate(const std::string& input) {
	/*std::string str{ "52^ 4 + 1^(1/2) - sin(0)" };*/

	toPostfix(input);

	std::stack<double> result;
	int iterCount = 0;

	for (int i = 0; i < parsedVec.size(); i++) {
		std::string token = parsedVec[i];
		if (isdigit(token[0])) result.push(std::stod(token));
		else if (operatorCheck(token[0]) && token != "^") {
			iterCount++;
			if (token == "~") {
				double negativeNum = 0;
				if (!result.empty()) { negativeNum = result.top(); result.pop(); }
				result.push(myOperations.evaluate(0, negativeNum, "-"));
				std::cout << "[" << iterCount << "]  " << "-" << negativeNum << " = " << result.top() << std::endl;
				continue;
			}
			//    operand1 | operator | operand2    //
			double operand2 = 0;
			if (!result.empty()) { operand2 = result.top(); result.pop(); }
			double operand1 = 0;
			if (!result.empty()) { operand1 = result.top(); result.pop(); }
			result.push(myOperations.evaluate(operand1, operand2, token));
			std::cout << "[" << iterCount << "]  " << operand1 << token << operand2 << " = " << result.top() << std::endl;
		}
		//    function | (operand)   //    base | function | (operand)   //
		else if (funcCheck(token[0]) || token == "^") {
			iterCount++;
			double operand = 0;
			if (!result.empty()) { operand = result.top(); result.pop(); }
			if (token != "^") {
				//token = myOperations.getInterp(token);
			//}
				if (token == "s") { token = "sin"; result.push(sin(operand)); }
				else if (token == "c") { token = "cos"; result.push(cos(operand)); }
				else if (token == "l") { token = "ln"; result.push(log(operand)); }
				else if (token == "s") { token = "tg"; result.push(tan(operand)); }
				std::cout << "[" << iterCount << "]  " << token << "(" << operand << ")" << " = " << result.top() << std::endl;
			}
			else {
				double base = 0;
				if (!result.empty()) { base = result.top(); result.pop(); }
				result.push(pow(base, operand));
				std::cout << "[" << iterCount << "]  " << base << token << "(" << operand << ")" << " = " << result.top() << std::endl;
			}
		}
	}

	this->output = toString(result.top());
}

