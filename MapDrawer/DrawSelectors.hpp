#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "DrawText.hpp"

using namespace std;
using namespace sf;

void DrawSelectors()
{
	RectangleShape rectangle;
	rectangle.setPosition(800, 500);
	rectangle.setSize(Vector2f(350, 75));
	rectangle.setFillColor(Color::Yellow);
	window.draw(rectangle);
	RectangleShape rect;
	rect.setPosition(200, 500);
	rect.setSize(Vector2f(350, 75));
	rect.setFillColor(Color::Yellow);
	window.draw(rect);
	DrawText(200, 500, 50, "New config", Color::Red, false);
	DrawText(800, 500, 50, "Load config", Color::Red, false);
}