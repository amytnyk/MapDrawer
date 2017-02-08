#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


void DrawMap(vector<vector<int> > tmap, vector<Color> colors, vector<int> numbers, RenderWindow &window)
{
	float size = 50;
	RectangleShape rectangle;
	rectangle.setPosition(800, 500);
	rectangle.setSize(sf::Vector2f(350, 75));
	rectangle.setFillColor(Color::Yellow);
	window.draw(rectangle);
	DrawText(800, 500, 50, "Add number", Color::Blue, true, window);
	for (size_t i = 0; i < tmap.size(); i++)
	{
		for (size_t j = 0; j < tmap[i].size(); j++)
		{
			RectangleShape rectangle;
			rectangle.setPosition(j * size, i * size);
			rectangle.setSize(sf::Vector2f(50, 50));
			for (size_t k = 0; k < colors.size(); k++)
			{
				if (tmap[i][j] == numbers[k])
				{
					rectangle.setFillColor(colors[k]);
				}
			}
			window.draw(rectangle);
		}
	}
}