#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

vector<vector<int> > GetMapFromFile(string path)
{
	vector<vector<int> > tmap;
	ifstream in;
	in.open(path);
	int h, w;
	in >> h >> w;
	int i = 0;
	tmap.resize(h);
	for (size_t i = 0; i < h; i++)
	{
		tmap[i].resize(w);
		for (size_t j = 0; j < w; j++)
			in >> tmap[i][j];
	}
	in.close();
	return tmap;
}