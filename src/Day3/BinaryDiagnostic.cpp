#include <vector>
#include <string>
#include <iostream>
#include "BinaryDiagnostic.h"

int binaryDiagnostic(std::vector<std::string> data)
{
	std::vector<int> tmp(data[0].length());
	int gamma = 0, epsilon = 0;

	for (std::string s : data)
	{
		for (int i = 0; i < data[0].length(); i++)
			tmp[i] += s.at(i) - 48;
	}

	for (int i : tmp)
	{
		//std::cout << i << std::endl;
		//std::cout << (i >= data.size() - i);
		gamma = (gamma << 1) | (i >= data.size() - i);
		epsilon = (epsilon << 1) | (i <= data.size() - i);
	}

	return gamma * epsilon;
}

int binaryDiagnosticAdvanced(std::vector<std::string> data)
{
	int generator = 0, scrubber = 0;

	//std::cout << calculateGeneratorRating(data, 0) << std::endl;
	std::cout << calculateScrubberRating(data, 0) << std::endl;

	return 0;
}

int calculateGeneratorRating(std::vector<std::string> data, int bitPosition)
{
	int tmp = 0;
	std::vector<std::string> out;
	for (std::string s : data)
	{
		tmp += s.at(bitPosition) - 48;
	}

	//std::cout << tmp << std::endl;
	for (std::string s : data)
	{
		if (s.at(bitPosition) - 48 == (tmp >= data.size() - tmp))
		{
			out.push_back(s);
			//std::cout << s << std::endl;
		}
	}

	if (out.size() <= 1)
	{
		//return std::stoi(out[0]);
		return std::stoi(out[0], nullptr, 2);
	}

	//std::cout << out.size() << std::endl;

	return calculateGeneratorRating(out, ++bitPosition);
}

int calculateScrubberRating(std::vector<std::string> data, int bitPosition)
{
	int tmp = 0;
	std::vector<std::string> out;
	for (std::string s : data)
	{
		tmp += s.at(bitPosition) - 48;
	}

	//std::cout << tmp << std::endl;
	for (std::string s : data)
	{
		//std::cout << (tmp >= data.size() - tmp) << std::endl;

		if (tmp >= data[0].length() - tmp)
		{
			if (s.at(bitPosition) - 48 == 0)
				out.push_back(s);
		}
		else
			out.push_back(s);
	}

	if (out.size() <= 1)
	{
		//return std::stoi(out[0]);
		return std::stoi(out[0], nullptr, 2);
	}

	//std::cout << out.size() << std::endl;

	return calculateGeneratorRating(out, ++bitPosition);
}
