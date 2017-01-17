#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

void Save(vector<vector<int> > tmap, string path)
{
	ofstream out;
	out.open(path);
	out << tmap.size() << ' ' << tmap[0].size() << ' ';
	for (size_t i = 0; i < tmap.size(); i++)
	{
		for (size_t j = 0; j < tmap[i].size(); j++)
		{
			out << tmap[i][j] << ' ';
		}
		out << endl;
	}
	out.close();
}
