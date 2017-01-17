#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void DrawBackground()
{
	Sprite sprite;
	Texture texture;
	texture.loadFromFile("background.png");
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	sprite.setScale(934, 700);
	window.draw(sprite);
}
