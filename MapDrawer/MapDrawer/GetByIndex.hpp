#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int GetByIndexC(vector<Color> colors, Color color)
{
	for (size_t i = 0; i < colors.size(); i++)
		if (color == colors[i])
			return i;
}

int GetByIndexI(vector<int> numbers, int number)
{
	for (size_t i = 0; i < numbers.size(); i++)
		if (number == numbers[i])
			return i;
}
