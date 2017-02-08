#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "DrawText.hpp"

using namespace std;
using namespace sf;

void DrawError(string text, RenderWindow &window)
{
	RectangleShape rectangle;
	rectangle.setPosition(400, 400);
	rectangle.setSize(Vector2f(450, 75));
	rectangle.setFillColor(Color::Yellow);
	window.draw(rectangle);
	RectangleShape rect;
	rect.setPosition(525, 500);
	rect.setSize(Vector2f(100, 50));
	rect.setFillColor(Color::Green);
	window.draw(rect);
	DrawText(400, 400, 50, text, Color::Red, false, window);
	DrawText(525, 500, 50, "OK", Color::Blue, false, window);
}
