#include <iostream>
#include <time.h>
#include <chrono>
#include <ctime>
#include <glm/vec3.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>
float A = 90;
float M = 10;
float COF = 1.6;
float FOF;
float F = 400;
float D = 2;
float r = 0;
long double dt = 0.01;

glm::vec3 p1 = glm::vec3(1);
glm::vec3 p2 = glm::vec3(1);
int main()
{
	while (1)
	{
		FOF = COF * (M * 9.8);
		float CF = F - FOF;
		float AV = (F * D * sinf(A)) / (M * (D * D));
		r += AV * dt;
		glm::mat3 TP1 = glm::mat3(1);
		TP1 = glm::rotate(TP1, r);
		TP1 = glm::translate(TP1, glm::vec2(200, 0));
		p1 = TP1 * p1;

		p2 = glm::vec3(200, 0, 0);

		std::cout << "wheel rotation: " << r << std::endl;
		std::cout << "axel p1: " << p1.x << ", " << p1.y << std::endl;
		std::cout << "axel p2: " << p2.x << ", " << p2.y << std::endl;
		system("cls");
	}
}