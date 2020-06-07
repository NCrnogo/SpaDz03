#pragma once
#include <SFML/Graphics.hpp>

struct tocka {
	int x, y;
};

class Graph
{
public:
	Graph(sf::RenderWindow* window);
	void connect();
private:
	void calculate();
	void drawBoard();
	void fill();
	void createG();
	sf::RenderWindow* window;
	sf::RectangleShape rectangle[20][40];
	int field[20][40];
	tocka a;
	tocka b;
	bool once = true;
	sf::Clock frameClock;
	sf::Time stop = sf::seconds(0.20f);
};


