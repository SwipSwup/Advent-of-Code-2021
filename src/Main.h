#pragma once
#include <vector>

std::vector<int> readFileAsInt(const char* file);
std::vector<std::string> readFileAsString(const char* file);
std::vector<std::string> tokenize(std::string s, const char del);