#pragma once
#include "loader.h"

class operations {
private:
	std::map<std::string, std::function<double(double, double)>> operators;
	std::map<std::string, unaryf> functionsU;
	std::map<std::string, binaryf> functionsB;

	std::map<std::string, int> operationsPrecedence;

	loader DLL;

public:
	operations();

	int getKeyCoincidence(std::string token, int i);
	int getPrecedence(std::string token);
	int Xnarity(const std::string& token);

	double Oevaluate(const double& a, const double& b, const std::string& name);
	double FUevaluate(const double& a, std::string name);
	double FBevaluate(const double& a, const double& b, std::string name);
};