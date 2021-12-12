#include <string>
#include <sstream>
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include "main.h"
#include "Day1/SonarSweep.h"
#include "Day2/Dive.h"
#include "Day3/BinaryDiagnostic.h"

int main()
{

	//std::vector<int> intData = readFileAsInt("Resources/day1.txt");

	//std::cout << intData.size() << std::endl;
	//std::cout << dayOne(readFileAsInt("../Resources/day1.txt")) << std::endl;
	//std::cout << sonarSweepAdvanced(intData) << std::endl;
	//std::cout << dive(readFileAsString("Resources/day2.txt")) << std::endl;
	//std::cout << diveAdvanced(readFileAsString("Resources/day2.txt")) << std::endl;

	//std::cout << binaryDiagnostic(readFileAsString("Resources/day3.txt")) << std::endl;
	std::cout << binaryDiagnosticAdvanced(readFileAsString("Resources/day3.txt")) << std::endl;

	/*for (std::string i : readFileAsString("Resources/day2.txt")) {
		std::cout << i << std::endl;
	}*/

	//std::cin.get();
}

std::vector<int> readFileAsInt(const char* file) 
{
	std::string filename(file);
	std::vector<int> data = {};
	std::string line;

	std::ifstream input_file(filename);
	if (!input_file.is_open()) {
		std::cerr << "Could not open the file - '"
			<< filename << "'" << std::endl;
		return data;
	}

	while (getline(input_file, line)) {
		data.push_back(std::stoi(line));
	}
	input_file.close();

	return data;
}

std::vector<std::string> readFileAsString(const char* file)
{
	std::string filename(file);
	std::vector<std::string> data = {};
	std::string line;

	std::ifstream input_file(filename);
	if (!input_file.is_open()) {
		std::cerr << "Could not open the file - '"
			<< filename << "'" << std::endl;
		return data;
	}

	while (getline(input_file, line)) {
		data.push_back(line);
	}
	input_file.close();

	return data;
}

std::vector<std::string> tokenize(std::string s, const char del)
{
	std::vector<std::string> tokens;

	std::stringstream streamData(s);
	std::string val;
	while (std::getline(streamData, val, del))
	{
		//std::cout << val << std::endl;
		tokens.push_back(val);
	}

	return tokens;
}