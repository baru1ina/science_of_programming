#include "calc.h"

int main() {
	std::cout << "press Enter to escape\n" <<std::endl;
	std::cout << "operations available: +    -    *    /    ()    ^\nfunctions available: sin(x)  cos(x)  tg(x)  ln(x) \n\nput the expression to calculate:\n" << std::endl;

	std::string input;
	std::getline(std::cin, input);
	std::cout << "\n"  << std::endl;

	calc* sample = new calc();

	while (input != "") {
		try { sample->calculate(input); }
		catch (std::string error_message) { std::cout << error_message << std::endl; }

		std::string result = sample->getOutput();

		std::cout << "\nresult: " << result << std::endl;

		std::cout << "\nput the expression to calculate:\n" << std::endl;
		std::getline(std::cin, input);
	}

	delete sample;

	return 0;
}
