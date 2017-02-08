#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void SaveConfigure(vector<int> numbers, vector<Color> colors, vector<Color> allcolors)
{
	ofstream out;
	out.open("config.cfg");
	out << numbers.size() << ' ';
	for (size_t i = 0; i < numbers.size(); i++)
	{
		out << numbers[i] << ' ';
	}
	out << '\n';
	for (size_t i = 0; i < colors.size(); i++)
	{
		out << GetByIndexC(allcolors, colors[i]) << ' ';
	}
	out.close();
}
