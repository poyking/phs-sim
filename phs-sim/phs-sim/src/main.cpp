#include <iostream>
#include <time.h>
#include <chrono>
#include <ctime>
#include <glm/vec3.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#pragma comment(lib, "sfml-graphics-d.lib")
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
float A = 90;
float M = 5;
float COF = 0.3;
float FOF;
float F = 1000;
float D = 10;
float r = 0;
long double dt = 1;
int main()
{
	int loops = 0;
	sf::RenderWindow win(sf::VideoMode(500, 500), "simple sim");
	sf::Clock dc;
	glm::vec3 p1 = glm::vec3(1);
	while (win.isOpen())
	{
		sf::Event event;
		while (win.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				win.close();
		}
		FOF = COF * (M * 9.8);
		float CF = F - FOF;
		float AV = (F * D * sinf(A)) / (M * (D * D));
		r += AV * dt;

		glm::mat3 tp1 = glm::mat3(1);
		tp1 = glm::translate(tp1, glm::vec2(100, 100));
		tp1 = glm::rotate(tp1, r);
		tp1 = glm::translate(tp1, glm::vec2(15, 15));

		p1 = tp1 * p1;

		win.clear(sf::Color::White);

		sf::CircleShape shape(25);
		shape.setOrigin(25, 25);
		shape.setPosition(100, 100);
		shape.setRotation(glm::degrees(r));
		shape.setFillColor(sf::Color(145, 46, 23));
		win.draw(shape);

		sf::RectangleShape Rshape(sf::Vector2f(25, 25));
		Rshape.setOrigin(25 / 2, 25 / 2);
		Rshape.setPosition(100, 100);
		Rshape.setRotation(glm::degrees(r));
		Rshape.setFillColor(sf::Color(100, 100, 100));
		win.draw(Rshape);

		sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f(p1.x, p1.y), sf::Color(67, 70, 75)),
			sf::Vertex(sf::Vector2f(200, 0), sf::Color(67, 70, 75)),
		};
		win.draw(line, 2, sf::Lines);

		win.display();

		dt = dc.restart().asSeconds();
		p1 = glm::vec3(1);
		loops++;
	}
}