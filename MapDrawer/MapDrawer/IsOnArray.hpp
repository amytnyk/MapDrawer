#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

bool IsOnArray(vector<int> numbers, int number)
{
	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == number)
			return true;
	}
	return false;
}