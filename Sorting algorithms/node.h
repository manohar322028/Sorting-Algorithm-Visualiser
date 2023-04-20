#pragma once
#include <SFML/Graphics.hpp>
#include <string>

//NODE CLASS

class Node
{
private:
	//Private Node Variables
	sf::RectangleShape* nodeShape;
	float width;
	float height;
	//float data;
	sf::Color color;

public:

	//Constructor and Destructor
	Node(float x, float y, float width, float height, float data);
	~Node();

	//Node Functions
	sf::RectangleShape* getShape();
	sf::Vector2f getNodePosition();
	void changeNodeColor(sf::Color color);
	void setNode(int a);
	//float getdata();
};