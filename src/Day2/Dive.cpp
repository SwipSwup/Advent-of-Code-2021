#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "Dive.h"
#include "../Main.h"

int dive(std::vector<std::string> commands)
{
	int x = 0, y = 0;

	for (std::string command : commands)
	{
		std::vector<std::string> tokens = tokenize(command, ' ');
		//std::cout << command << std::endl;
		//std::cout << tokens[0] << std::endl;

		if (tokens[0] == "forward")
			x += std::stoi(tokens[1]);
		else if (tokens[0] == "down")
			y += std::stoi(tokens[1]);
		else if (tokens[0] == "up")
			y -= std::stoi(tokens[1]);
	}

	return x * y;
}

int diveAdvanced(std::vector<std::string> commands)
{
	int x = 0, y = 0, a = 0;
	for (std::string command : commands)
	{
		std::vector<std::string> tokens = tokenize(command, ' ');
		//std::cout << command << std::endl;
		//std::cout << tokens[0] << std::endl;


		std::string com = tokens[0];
		int val = std::stoi(tokens[1]);

		if (com == "forward")
		{
			x += val;
			y += a * val;
		}
		else if (com == "down")
			a += val;
		else if (com == "up")
			a -= val;
	}

	return x * y;
}

