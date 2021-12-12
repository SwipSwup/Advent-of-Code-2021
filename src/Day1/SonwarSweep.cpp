#include <vector>

int sonarSweep(std::vector<int> input)
{
	int increments = 0;
	int preValue = INT16_MAX;

	for (int i : input) {
		if (i > preValue)
			increments++;

		preValue = i;
	}

	return increments;
}

int sonarSweepAdvanced(std::vector<int> input) 
{
	int increments = 0;
	int preValue = INT16_MAX;

	for (int i = 0; i < input.size() - 2; i++)
	{
		int sample = input[i] + input[i + 1] + input[i + 2];
		
		if (sample > preValue)
			increments++;

		preValue = sample;
	}

	return increments;
}

