#include <iostream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"

void DemonstrateClass();

int Shape::count = 0;

int main()
{
	std::cout << "What feature would you primarily like to work with?\n\n";
	// Additional options will be added as more topics are covered
	std::cout << "Enter 1 to focus on classes and subclasses with shapes.\n";
	
	int feature;
	std::cin >> feature;
	std::cout << std::endl;

	switch (feature) {
	case 1:
		DemonstrateClass();
		break;
	default:
		std::cout << "An invalid number was entered. The program will now end.\n";
	}
}

void DemonstrateClass() {
	std::string color;

	int radius;
	std::cout << "Creating a circle object...\n";
	std::cout << "Enter the color of the circle: ";
	std::cin >> color;
	std::cout << "Enter the radius of the circle: ";
	std::cin >> radius;
	Circle circle1(radius, color);
	std::cout << std::endl;

	int side;
	std::cout << "Creating a square object...\n";
	std::cout << "Enter the color of the square: ";
	std::cin >> color;
	std::cout << "Enter the side length of the square: ";
	std::cin >> side;
	Square square1(side, color);
	std::cout << std::endl;

	int base;
	int height;
	std::cout << "Creating a triangle object...\n";
	std::cout << "Enter the color of the square: ";
	std::cin >> color;
	std::cout << "Enter the base of the triangle: ";
	std::cin >> base;
	std::cout << "Enter the height of the triangle: ";
	std::cin >> height;
	Triangle triangle1(base, height, color);
	std::cout << std::endl;

	std::cout << "Creating another circle object with default values...\n";
	Circle circle2;
	std::cout << "Editing the circle's radius...\n\n";
	circle2.SetRadius(2);

	std::cout << "There are currently " << Shape::GetCount() << " shapes:\n";

	std::cout << "The " << circle1.GetColor() << " circle has area " << circle1.CalculateArea();
	std::cout << " and circumference " << circle1.CalculateCircumference() << std::endl;

	std::cout << "The " << square1.GetColor() << " square has area " << square1.CalculateArea();
	std::cout << " and perimeter " << square1.CalculatePerimeter() << std::endl;

	std::cout << "The " << triangle1.GetColor() << " triangle has area " << triangle1.CalculateArea();
	std::cout << std::endl;

	std::cout << "The default circle is " << circle2.GetColor() << " and has area " << circle2.CalculateArea();
	std::cout << ", and circumference " << circle2.CalculateCircumference() << std::endl;
}