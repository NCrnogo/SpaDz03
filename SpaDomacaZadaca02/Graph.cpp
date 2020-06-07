#include "Graph.h"
#include <iostream>
using namespace std;
using namespace sf;

Graph::Graph(sf::RenderWindow* window)
{
	this->window = window;
}

void Graph::connect()
{
	if (once) {
		fill();
	}
	createG();
	drawBoard();
	Time counter = frameClock.getElapsedTime();
	if (counter >= stop) {
		calculate();
		frameClock.restart();
	}
}


void Graph::calculate()
{
	if (a.x < b.x) a.x++;
	else if (a.x > b.x) a.x--;
	else if (a.y < b.y) a.y++;
	else if (a.y > b.y) a.y--;
}

void Graph::drawBoard()
{
	float row = 50;
	float column = 50;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			rectangle[i][j].setOutlineThickness(1);
			rectangle[i][j].setOutlineColor(Color(255, 0, 0));
			rectangle[i][j].setSize(Vector2f(20, 20));
			rectangle[i][j].setPosition(row, column);
			if (field[i][j] == 0)rectangle[i][j].setFillColor(Color(255, 255, 255));
			else if(field[i][j] == 1)rectangle[i][j].setFillColor(Color(0,0,0));
			else if (field[i][j] == 2)rectangle[i][j].setFillColor(Color(0, 0, 255));
			window->draw(rectangle[i][j]);
			row += 20;
		}

		row = 50;
		column += 20;
	}
}

void Graph::fill()
{
	cout << "Koordinata x pocetne tocke:";
	cin >> a.x;
	if (a.x < 0) a.x = 0;
	if (a.x > 19) a.x = 19;
	cout << "Koordinata y pocetne tocke:";
	cin >> a.y;
	if (a.y < 0) a.y = 0;
	if (a.y > 39) a.y = 39;
	cout << "Koordinata x zavrsne tocke:";
	cin >> b.x;
	if (b.x < 0) b.x = 0;
	if (b.x > 19) b.x = 19;
	cout << "Koordinata y zavrsne tocke:";
	cin >> b.y;
	if (b.y < 0) b.y = 0;
	if (b.y > 39) b.y = 39;
}

void Graph::createG()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			if (a.x == i && a.y == j) field[i][j] = 1;
			else if (b.x == i && b.y == j) field[i][j] = 2;
			else field[i][j] = 0;
		}
	}
	once = false;
}
