#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

bool IsOnSquare(int x, int y, int s, int s2, int yourX, int yourY)
{
	if (yourY < y + s2 && yourY > y && yourX > x && yourX < x + s)
		return true;
	else
		return false;
}
