#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <Windows.h>
#include "Node.h"
#include "Button.h"
#include"Algorithm.h"

// MAIN FUNCTION
int main()
{
	//Rendering Main Window
	sf::RenderWindow win(sf::VideoMode(1200, 600), "Main Window", sf::Style::Default);


	//Texture for Main window
	sf::RectangleShape photo;
	photo.setSize(sf::Vector2f(700, 500));
	photo.setPosition(sf::Vector2f(-50, 50));
	sf::Texture texture;
	texture.loadFromFile("project.png");
	photo.setTexture(&texture);

	//Declaring the required buttons
	Button* btn[5];

	//Bubble Sort Button
	btn[0] = new Button(850, 100.f, "Bubble Sort", &win);
	sf::RectangleShape* button1 = btn[0]->getShape();
	sf::Text* text1 = btn[0]->getText();

	//Insertion Sort Button
	btn[1] = new Button(850, 200, "Insertion Sort", &win);
	sf::RectangleShape* button2 = btn[1]->getShape();
	sf::Text* text2 = btn[1]->getText();

	//Selection Sort Button
	btn[2] = new Button(850, 300, "Selection Sort", &win);
	sf::RectangleShape* button3 = btn[2]->getShape();
	sf::Text* text3 = btn[2]->getText();

	//Merge sort button
	btn[3] = new Button(850, 400, "Merge Sort", &win);
	sf::RectangleShape* button4 = btn[3]->getShape();
	sf::Text* text4 = btn[3]->getText();

	//Exit Button
	btn[4] = new Button(850, 500, "EXIT", &win);
	sf::RectangleShape* button5 = btn[4]->getShape();
	sf::Text* text5 = btn[4]->getText();

	//Loop till the window is open
	while (win.isOpen())
	{
		//Event in the window
		sf::Event evnt;
		while (win.pollEvent(evnt))
		{
			//Window CLose Condition
			if (evnt.type == sf::Event::Closed)
				win.close();

			//Button Pressed Conditions
			if (btn[0]->buttonPressed())
			{
				sortingWindow("BubbleSort", 1);
			}
			else if (btn[1]->buttonPressed())
			{
				sortingWindow("InsertionSort", 2);
			}
			else if (btn[2]->buttonPressed())
			{
				sortingWindow("SelectionSort", 3);
			}
			else if (btn[3]->buttonPressed())
			{
				sortingWindow("MergeSort", 4);
			}


			else if (btn[4]->buttonPressed())
			{
				win.close();
			}
		}

		//Drwaing all the entities
		win.clear(sf::Color::Black);
		win.draw(photo);
		win.draw(*button1);
		win.draw(*button2);
		win.draw(*button3);
		win.draw(*button4);
		win.draw(*button5);
		win.draw(*text1);
		win.draw(*text2);
		win.draw(*text3);
		win.draw(*text4);
		win.draw(*text5);

		//Displaying the window
		win.display();
	}
	return 0;
}
