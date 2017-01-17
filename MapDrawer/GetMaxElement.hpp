#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int getMaxElement(vector<int> numbers)
{
	int max = 0;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] > max)
			max = numbers[i];
	}
	return max;
}