#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


void DrawText(int x, int y, int char_size, string stext, Color color, bool Underline)
{
	Text text;
	Font font;
	font.loadFromFile("raleway/Raleway-Italic.ttf");
	text.setFont(font);
	text.setCharacterSize(char_size);
	if (Underline)
		text.setStyle(Text::Underlined);
	text.setFillColor(color);
	text.setPosition(x, y);
	text.setString(stext);
	window.draw(text);
}

