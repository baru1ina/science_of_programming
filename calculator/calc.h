#include "operations.h"

class calc {
private:
	std::string input;
	std::string output;
	operations myOperations;

	std::vector<std::string> parsedVec;
	std::stack<char> sampleOperators;
	
public:
	calc() = default;
	~calc() = default;
	calc(const calc&) = default;
	calc(calc&&) = default;
	calc& operator=(calc const&) = default;
	calc& operator=(calc&&) = default;

	std::string getOutput() { return this->output; }

	bool operatorCheck(char token);
	bool funcCheck(char token);

	std::string delSpace(const std::string& input);
	std::string pickNum(int& ptr, const std::string& input);

	void toPostfix(const std::string& input);
	void calculate(const std::string& input); 
};