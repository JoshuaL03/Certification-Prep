#include <iostream>
#include <string>
#include <array>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Vehicle.h"
#include "Car.h"
#include "Jet.h"
#include "Run.h"
#include "Human.h"
#include "Cheetah.h"

void DemonstrateClass();
void DemonstrateDynamicDispatch();
void DemonstrateInterface();
void DemonstrateAggregate();

template<size_t length>
auto AddArray(std::array<int, length> array) noexcept -> int;

template<size_t length>
auto MultiplyArray(std::array<int, length> array) noexcept -> int;

template<size_t length>
auto DoMath(std::array<int, length> array, int (*operation)(std::array<int, length>)) noexcept -> int;

auto main() -> int
{
	std::cout << "What feature would you primarily like to work with?\n\n";
	std::cout << "Enter 1 to focus on classes and subclasses with shapes.\n";
	std::cout << "Enter 2 to focus on dynamic dispatch and subtyping with vehicles.\n";
	std::cout << "Enter 3 to focus on interfaces with running.\n";
	std::cout << "Enter 4 to focus on iterators, aggregates, and functions as arguments.\n";

	int feature = 0;
	std::cin >> feature;
	std::cout << std::endl;

	switch (feature) {
	case 1:
		DemonstrateClass();
		break;
	case 2:
		DemonstrateDynamicDispatch();
		break;
	case 3:
		DemonstrateInterface();
		break;
	case 4:
		DemonstrateAggregate();
		break;
	default:
		std::cout << "An invalid number was entered. The program will now end.\n";
	}
}

void DemonstrateClass() {
	std::string color;

	int radius = 0;
	std::cout << "Creating a circle object...\n";
	std::cout << "Enter the color of the circle: ";
	std::cin >> color;
	std::cout << "Enter the radius of the circle: ";
	std::cin >> radius;
	Circle circle1(radius, color);
	std::cout << std::endl;

	int side = 0;
	std::cout << "Creating a square object...\n";
	std::cout << "Enter the color of the square: ";
	std::cin >> color;
	std::cout << "Enter the side length of the square: ";
	std::cin >> side;
	Square square1(side, color);
	std::cout << std::endl;

	int base = 0;
	int height = 0;
	std::cout << "Creating a triangle object...\n";
	std::cout << "Enter the color of the triangle: ";
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

	std::cout << "Retrieving the shapes' information...\n";

	// Output the first circle's information
	std::cout << "The " << circle1.GetColor() << " circle has area " << circle1.CalculateArea();
	std::cout << " and circumference " << circle1.CalculateCircumference() << std::endl;

	// Output the square's information
	std::cout << "The " << square1.GetColor() << " square has area " << square1.CalculateArea();
	std::cout << " and perimeter " << square1.CalculatePerimeter() << std::endl;

	// Output the triangle's information
	std::cout << "The " << triangle1.GetColor() << " triangle has area " << triangle1.CalculateArea();
	std::cout << std::endl;

	// Output the second, default circle's information
	std::cout << "The default circle is " << circle2.GetColor() << " and has area " << circle2.CalculateArea();
	std::cout << ", and circumference " << circle2.CalculateCircumference() << std::endl;
}

void DemonstrateDynamicDispatch() {
	
	std::cout << "Creating a vehicle...\n";
	Vehicle vehicle1;
	std::cout << "The vehicle goes " << vehicle1.MakeSound() << std::endl;

	std::cout << "Creating a car...\n";
	Car car1;
	std::cout << "The car goes " << car1.MakeSound() << std::endl;

	std::cout << "Creating a jet...\n";
	Jet jet1;
	std::cout << "The jet goes " << jet1.MakeSound() << std::endl;

	std::cout << "Creating a mystery vehicle...\n\n";
	Vehicle* mysteryVehicle = nullptr;
	// Test the mysteryvehicle for nullness to prevent the need for gsl::not_null
	if (mysteryVehicle == nullptr) {};

	std::cout << "Altering mystery vehicle...\n";
	mysteryVehicle = &vehicle1;
	if (mysteryVehicle != nullptr) {
		std::cout << "The mystery vehicle goes " << mysteryVehicle->MakeSound() << std::endl;
	}
	else {
		std::cout << "The mystery vehicle does not make a sound. It must be broken!\n\n";
	}


	std::cout << "Altering the mystery vehicle again...\n";
	// Make the mysteryVehicle point to a Car object, giving it access to a different MakeSound function
	mysteryVehicle = &car1;
	if (mysteryVehicle != nullptr) {
		std::cout << "The mystery vehicle goes " << mysteryVehicle->MakeSound() << std::endl;
	}
	else {
		std::cout << "The mystery vehicle does not make a sound. It must be broken!\n\n";
	}

	std::cout << "Altering the mystery vehicle once more...\n";
	// Make the mysteryVehicle point to a Jet object, giving it access to another MakeSound function
	mysteryVehicle = &jet1;
	if (mysteryVehicle != nullptr) {
		std::cout << "The mystery vehicle goes " << mysteryVehicle->MakeSound() << std::endl;
	}
	else {
		std::cout << "The mystery vehicle does not make a sound. It must be broken!\n\n";
	}

	// Object-oriented inheritance is what allows subtyping to occur.
	// The subtype has all of the methods and fields that its supertype has (due to inheritance),
	// so it can be used in various situations where the supertype is expected.
	// Some of the supertypes functions can also be overridden by functions in the subtype using virtual functions.
}

void DemonstrateInterface() {
	// Humans and cheetahs are not very similar, but they both run.
	// They can both inherit from an interface class called Run.
	// Note that no object of the Run class can be instantiated.

	std::cout << "Choosing a human...\n";
	Human Steven("Steven");
	std::cout << "The human's name is " << Steven.GetName() << std::endl;
	
	std::cout << std::endl;
	Steven.StartRunning();
	Steven.StopRunning();
	
	std::cout << std::endl;
	Steven.WatchTV();

	std::cout << "\nChoosing a cheetah...\n";
	Cheetah cheetah1("gazelles");
	std::cout << "The cheetah has no name, but its preferred prey is " << cheetah1.GetPreferredPrey() << std::endl;
	
	std::cout << std::endl;
	cheetah1.StartRunning();
	cheetah1.StopRunning();

	std::cout << std::endl;
	cheetah1.Hunt();
}

void DemonstrateAggregate() {

	std::cout << "Creating an array of 5 integers...\n";
	constexpr size_t arrayLength = 5;
	// Use std::array instead of a C-style array to meet the C++ Core Guidelines
	std::array<int, arrayLength> intArray = { 0, 0, 0, 0, 0 };

	std::cout << "Assigning values to the array...\n";
	// Assign values to the array using a range-based for loop to avoid directly indexing the array
	// https://stackoverflow.com/questions/47366755/how-to-eliminate-only-index-into-arrays-using-constant-expressions-warning
	for (auto& element : intArray) {
		std::cout << "Enter the value for element " << &element - intArray.data() << ": "; // intArray.data() returns the address of element zero of the array
		std::cin >> element;
	}

	std::cout << "\nThe finished array is {";
	for (auto& element : intArray) {
		std::cout << element;
		if (&element - intArray.data() < arrayLength - 1) {
			std::cout << ", ";
		}
	}
	std::cout << "}\n";

	std::cout << "\nThe sum of all the elements in the array is ";
	std::cout << DoMath(intArray, &AddArray) << std::endl;

	std::cout << "\nThe product of all the elements in the array is ";
	std::cout << DoMath(intArray, &MultiplyArray) << std::endl;
}

// A template is used to keep the function general and increase reusability
// https://stackoverflow.com/questions/17156282/passing-a-stdarray-of-unknown-size-to-a-function
template<size_t length>
auto AddArray(std::array<int, length> array) noexcept -> int {
	int sum = 0;
	for (auto& element : array) {
		sum += element;
	}
	return sum;
}

template<size_t length>
auto MultiplyArray(std::array<int, length> array) noexcept -> int {
	int product = 1;
	for (auto& element : array) {
		product *= element;
	}
	return product;
}

// Take the AddArray or MultiplyArray functions as arguments
template<size_t length>
auto DoMath(std::array<int, length> array, int (*operation)(std::array<int, length>)) noexcept -> int{
	return (*operation)(array);
}