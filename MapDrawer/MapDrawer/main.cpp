#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "all.hpp"

using namespace std;
using namespace sf;

RenderWindow window(VideoMode(500, 500), "Your map is here!", Style::Fullscreen);

vector<int> FoundNumbers(vector<vector<int> > tmap)
{
	vector<int> numbers;
	for (size_t i = 0; i < tmap.size(); i++)
	{
		for (size_t j = 0; j < tmap[i].size(); j++)
		{
			if (!IsOnArray(numbers, tmap[i][j]))
				numbers.push_back(tmap[i][j]);
		}
	}
	return numbers;
}

vector<Color> GetColors(vector<int> numbers, vector<Color> allcolors)
{
	vector<Color> colors;
	colors.resize(numbers.size());
	for (size_t i = 0; i < colors.size(); i++)
	{
		colors[i] = allcolors[0];
	}
	int last = 0;
	int colors_rect_width = 150;
	int colors_rect_height = 50;
	int colors_rect_width_go = 150;
	int colors_rect_height_go = 50;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			Vector2i position = Mouse::getPosition();
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
			if (Mouse::isButtonPressed(Mouse::Button::Left))
			{
				for (size_t i = 0; i < numbers.size(); i++)
				{
					if (IsOnSquare(300, 100 + (i + 1) * 50, colors_rect_width, colors_rect_height, position.x, position.y))
					{
						if (last == 0)
						{
							auto index = GetByIndexC(allcolors, colors[i]) + 1;
							if (index == allcolors.size())
								index = 0;
							colors[i] = allcolors[index];
						}
						last = 10;
					}
				}
				if (IsOnSquare(600, 700, colors_rect_width_go, colors_rect_height_go, position.x, position.y))
				{
					return colors;
				}
			}
		}
		window.clear();
		DrawText(100, 100, 40, "Founded numbers:", Color::Green, false, window);
		RectangleShape rectangle;
		rectangle.setPosition(600, 700);
		rectangle.setSize(sf::Vector2f(colors_rect_width_go, colors_rect_height_go));
		rectangle.setFillColor(Color::Blue);
		window.draw(rectangle);
		if (last > 0)
		{
			last--;
		}
		for (size_t i = 0; i < numbers.size(); i++)
		{
			DrawText(100, 100 + (i + 1) * 50, 40, to_string(numbers[i]), Color::Magenta, false, window);
			RectangleShape rectangle;
			rectangle.setPosition(300, 100 + (i + 1) * 50);
			rectangle.setSize(sf::Vector2f(colors_rect_width_go, colors_rect_height_go));
			rectangle.setFillColor(colors[i]);
			window.draw(rectangle);
		}
		window.display();
	}
	return colors;
}

string GetPath()
{
  string path = "";
  while (window.isOpen())
  {
    Event event;
    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed)
        window.close();
      Vector2i position = Mouse::getPosition();
      if (Keyboard::isKeyPressed(Keyboard::Escape))
        window.close();
      if (Keyboard::isKeyPressed(Keyboard::BackSpace))
        if (path.size() != 0)
          path.resize(path.size() - 1);
      if (Keyboard::isKeyPressed(Keyboard::Return))
      {
        return path;
      }
      if (event.type == sf::Event::TextEntered)
      {
        if (event.text.unicode < 128)
          path += static_cast<char>(event.text.unicode);
      }
    }
    window.clear();
    DrawText(100, 100, 40, path, Color::Red, false, window);
    window.display();
  }
  return path;
}

bool GetConfigSelect()
{
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			Vector2i position = Mouse::getPosition();
			if (Mouse::isButtonPressed(Mouse::Button::Left))
			{
				
				if (IsOnSquare(800, 500, 350, 75, position.x, position.y))
				{
					return true;
				}
				if (IsOnSquare(200, 500, 350, 75, position.x, position.y))
				{
					return false;
				}
			}
		}
		window.clear();
		DrawSelectors(window);
		window.display();
	}
}

int Error(string text)
{
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
			Vector2i position = Mouse::getPosition();
			if (Mouse::isButtonPressed(Mouse::Button::Left))
			{
				if (IsOnSquare(525, 500, 100, 50, position.x, position.y))
				{
					ofstream out;
					out.open("map_s.txt");
					out << 2 << ' ' << 2 << ' ' << 0 << ' ' << 1 << '\n' << 2 << ' ' << 3;
					window.close();
          exit(0);
				}
			}
		}
		window.clear();
		DrawError(text, window);
		window.display();
	}
	return 0;
}

/*int getMaxElement(vector<int> numbers)
{
	int max = 0;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] > max)
			max = numbers[i];
	}
	return max;
}*/

int main()
{
  vector<Color> allcolors;
  allcolors.push_back(Color::Green);
  allcolors.push_back(Color::Yellow);
  allcolors.push_back(Color::Red);
  allcolors.push_back(Color::Cyan);
  allcolors.push_back(Color::Magenta);
  allcolors.push_back(Color::White);
  vector<vector<int> > tmap;
  vector<int> numbers;
  vector<Color> colors;
  string path = GetPath();
  if (ifstream(path))
  {
    if (GetConfigSelect())
    {
      if (ifstream("config.cfg"))
      {
        ifstream i;
        i.open("config.cfg");
        int size;
        i >> size;
        for (size_t j = 0; j < size; j++)
        {
          int n;
          i >> n;
          numbers.push_back(n);
        }
        for (size_t j = 0; j < size; j++)
        {
          int n;
          i >> n;
          colors.push_back(allcolors[n]);
        }
        i.close();
      }
    }
    else
    {
      tmap = GetMapFromFile(path);
      numbers = FoundNumbers(tmap);
      colors = GetColors(numbers, allcolors);
    }
  }
  else
  {
    Error("File " + path + " does not exits!");
  }
  tmap = GetMapFromFile(path);
  int last_x = -1, last_y = -1;
  int last = 0;
  string text;
  while (window.isOpen())
  {
    Event event;
    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed)
      {
        SaveConfigure(numbers, colors, allcolors);
        window.close();
      }
      Vector2i position = Mouse::getPosition();
      if (Keyboard::isKeyPressed(Keyboard::Escape))
      {
        SaveConfigure(numbers, colors, allcolors);
        window.close();
      }
      if (Keyboard::isKeyPressed(Keyboard::S))
        Save(tmap, path);
      if (Mouse::isButtonPressed(Mouse::Button::Left))
      {
        for (size_t i = 0; i < tmap.size(); i++)
        {
          for (size_t j = 0; j < tmap[i].size(); j++)
          {
            if (IsOnSquare(j * 50, i * 50, 50, 50, position.x, position.y))
            {
              if (last == 0)
              {
                int index = GetByIndexI(numbers, tmap[i][j]);
                index++;
                if (index == numbers.size())
                  index = 0;
                tmap[i][j] = numbers[index];
                last_x = i;
                last_y = j;
                last = 10;
              }
            }
          }
        }
        if (IsOnSquare(800, 500, 350, 75, position.x, position.y))
        {
          if (last == 0)
          {
            numbers.push_back(getMaxElement(numbers) + 1);
            colors.push_back(Color::Green);
            last = 10;
          }
        }
      }
    }
    if (last > 0)
      last--;
    window.clear();
    //DrawBackground();
    DrawMap(tmap, colors, numbers, window); // Error
    window.display();
  }

  return 0;
}