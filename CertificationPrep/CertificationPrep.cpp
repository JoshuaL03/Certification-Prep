/** @file CertificationPrep.cpp
 *  @brief Contains all of the project's main functions.
 *
 *  It attempts to demonstrate various elements of object-oriented programming,
 *  as well as cover some topics that will be covered on the CPA exam.
 *
 *  @author Joshua Lopez
 *  @bugs   No known bugs.
 */

#include <array>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Car.h"
#include "Cheetah.h"
#include "Circle.h"
#include "Human.h"
#include "Jet.h"
#include "Run.h"
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"
#include "Vehicle.h"

/** @brief Incorporates classes and subclasses with inheritance
 *         using shapes.
 */
void DemonstrateClass();

/** @brief Uses dynamic dispatching and subtyping with vehicles.
 *
 */
void DemonstrateDynamicDispatch();

/** @brief Demonstrates interfaces with humans and cheetahs, using
 *         running as the common link/interface between the two.
 */
void DemonstrateInterface();

/** @brief Utilizes std::array as an aggregate, finding both the product
 *         and sum of all the elements with references to functions.
 */
void DemonstrateAggregate();

/** @brief Ignores excess input, clearing it out of the buffer.
 *
 */
void ignoreLine();

/** @brief Finds the sum of all elements in an array.
 *
 *  It uses a template to account for various array lengths.
 *
 *  @param array The array to have its elements added.
 *  @return The sum of the elements in the array.
 */
template <size_t length>
auto AddArray(const std::array<int, length>& array) noexcept -> int;

/** @brief Finds the product of all elements in an array.
 *
 *  It uses a template to account for various array lengths.
 *
 *  @param array The array to have its elements myltiplied.
 *  @return The product of the elements in the array.
 */
template <size_t length>
auto MultiplyArray(const std::array<int, length>& array) noexcept -> int;

/** @brief Passes an array to a reference to a function.
 *
 *  It uses a template to account for various array lengths.
 *
 *  @param array The array to be passed to the referenced function.
 *  @param operation The referenced function to be called.
 *  @return The return value of the referenced function.
 */
template <size_t length>
auto DoMath(const std::array<int, length>& array,
            int (&operation)(const std::array<int, length>&)) noexcept -> int;

/** @brief Prompts the user for the color of a shape.
 *
 *  It uses exception handling to ensure the inputted color is correct.
 *
 *  @return The color of the shape.
 */
auto SetShapeColor() -> std::string;

/** @brief Prompts the user for the dimension of a shape.
 *
 *  Dimension refers to any of a shapes' measurements, such as a square's
 *  side length or a circle's radius. It uses exception handling to ensure the
 *  inputted dimension is correct.
 *
 *  @return The dimension of the shape
 */
auto SetShapeDimension() -> double;

/**
 * @brief Starts program execution.
 * @return The exit code (normally zero).
 */
auto main() -> int {
  try {
    bool continueExecution = true;

    while (continueExecution) {
      std::cout << "What feature would you like to work with?\n\n";
      std::cout << "Enter 1 to focus on classes and subclasses with shapes.\n";
      std::cout << "Enter 2 to focus on dynamic dispatch and subtyping with "
                   "vehicles.\n";
      std::cout << "Enter 3 to focus on interfaces with running.\n";
      std::cout << "Enter 4 to focus on iterators, aggregates, and functions "
                   "as arguments.\n";
      std::cout << "Enter anything else to end execution.\n";

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
          std::cout
              << "A different input was entered. The program will now end.\n";
          continueExecution = false;
      }
    }
  } catch (...) {
    std::cout << "An error has occurred somewhere. The program will now end.\n";
    return -1;
  }
  return 0;
}

// LO1, LO2
void DemonstrateClass() {
  std::string color;

  double radius = 0;
  std::cout << "Creating a circle object...\n";
  color = SetShapeColor();
  std::cout << "Enter the radius of the circle: ";
  radius = SetShapeDimension();
  Circle circle1(radius, color);
  std::cout << std::endl;

  double side = 0;
  std::cout << "Creating a square object...\n";
  color = SetShapeColor();
  std::cout << "Enter the side length of the square: ";
  side = SetShapeDimension();
  Square square1(side, color);
  std::cout << std::endl;

  double base = 0;
  double height = 0;
  std::cout << "Creating a triangle object...\n";
  color = SetShapeColor();
  std::cout << "Enter the base of the triangle: ";
  base = SetShapeDimension();
  std::cout << "Enter the height of the triangle: ";
  height = SetShapeDimension();
  Triangle triangle1(base, height, color);
  std::cout << std::endl;

  std::cout << "Creating another circle object with default values...\n";
  Circle circle2;
  std::cout << "Editing the circle's radius...\n\n";
  circle2.SetRadius(2);

  std::cout << "Retrieving the shapes' information...\n";

  // Output the first circle's information
  std::cout << "The " << circle1.GetColor() << " circle has area "
            << circle1.CalculateArea();
  std::cout << " and circumference " << circle1.CalculateCircumference()
            << std::endl;

  // Output the square's information
  std::cout << "The " << square1.GetColor() << " square has area "
            << square1.CalculateArea();
  std::cout << " and perimeter " << square1.CalculatePerimeter() << std::endl;

  // Output the triangle's information
  std::cout << "The " << triangle1.GetColor() << " triangle has area "
            << triangle1.CalculateArea();
  std::cout << std::endl;

  // Output the second, default circle's information
  std::cout << "The default circle is " << circle2.GetColor()
            << " and has area " << circle2.CalculateArea();
  std::cout << ", and circumference " << circle2.CalculateCircumference()
            << std::endl;
  std::cout << std::endl << std::endl;
}

// LO3
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
  if (mysteryVehicle == nullptr) {
  };

  std::cout << "Altering mystery vehicle...\n";
  mysteryVehicle = &vehicle1;
  if (mysteryVehicle != nullptr) {
    std::cout << "The mystery vehicle goes " << mysteryVehicle->MakeSound()
              << std::endl;
  } else {
    std::cout
        << "The mystery vehicle does not make a sound. It must be broken!\n\n";
  }

  std::cout << "Altering the mystery vehicle again...\n";
  // Make the mysteryVehicle point to a Car object, giving it access to a
  // different MakeSound function
  mysteryVehicle = &car1;
  if (mysteryVehicle != nullptr) {
    std::cout << "The mystery vehicle goes " << mysteryVehicle->MakeSound()
              << std::endl;
  } else {
    std::cout
        << "The mystery vehicle does not make a sound. It must be broken!\n\n";
  }

  std::cout << "Altering the mystery vehicle once more...\n";
  // Make the mysteryVehicle point to a Jet object, giving it access to another
  // MakeSound function
  mysteryVehicle = &jet1;
  if (mysteryVehicle != nullptr) {
    std::cout << "The mystery vehicle goes " << mysteryVehicle->MakeSound()
              << std::endl;
  } else {
    std::cout
        << "The mystery vehicle does not make a sound. It must be broken!\n\n";
  }

  std::cout << std::endl;

  // LO5
  // Object-oriented inheritance is what allows subtyping to occur.
  // The subtype has all of the methods and fields that its supertype has (due
  // to inheritance), so it can be used in various situations where the
  // supertype is expected. Some of the supertypes functions can also be
  // overridden by functions in the subtype using virtual functions.
}

// LO6
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
  std::cout << "The cheetah has no name, but its preferred prey is "
            << cheetah1.GetPreferredPrey() << std::endl;

  std::cout << std::endl;
  cheetah1.StartRunning();
  cheetah1.StopRunning();

  std::cout << std::endl;
  cheetah1.Hunt();
  std::cout << std::endl << std::endl;
}

// LO7
void DemonstrateAggregate() {
  std::cout << "Creating an array of 5 integers...\n";
  constexpr size_t arrayLength = 5;
  // Use std::array instead of a C-style array to meet the C++ Core Guidelines
  std::array<int, arrayLength> intArray = {0, 0, 0, 0, 0};

  std::cout << "Assigning values to the array...\n";
  bool invalidInput = true;
  std::string stringInput;
  // Assign values to the array using a range-based for loop to avoid directly
  // indexing the array
  // https://stackoverflow.com/questions/47366755/how-to-eliminate-only-index-into-arrays-using-constant-expressions-warning
  for (auto& element : intArray) {
    // intArray.data() returns the address of element zero of the array
    std::cout << "Enter the value for element " << &element - intArray.data()
              << ": ";
    while (invalidInput) {
      try {
        ignoreLine();
        std::cin >> stringInput;
        // std::stoi will throw std::invalid_argument if the stringInput cannot
        // be converted to an integer.
        // https://stackoverflow.com/questions/39887496/how-to-stop-integer-variable-from-taking-double-input-digits-before-decimal-an/39888125
        // If the input is converted successfully, it will be compared to a
        // double conversion of it, and matching the two will determine whether
        // or not the input is an integer.
        if (std::stoi(stringInput) == std::stod(stringInput)) {
          element = std::stoi(stringInput);
          invalidInput = false;
        } else {
          throw 1;
        }
      } catch (int) {
        std::cout << "The value is a number, but is not an integer.\n";
        std::cout << "Please re-enter the value: ";
        std::cin.clear();
      } catch (const std::invalid_argument e1) {
        std::cout << "The value is not a number.\n";
        std::cout << "Please re-enter the value: ";
        std::cin.clear();
      } catch (const std::out_of_range e3) {
        std::cout << "The number entered was too large.\n";
        std::cout << "Please re-enter the value: ";
      } catch (...) {
        std::cout << "An error occurred while processing the value entered.\n";
        std::cout << "Please re-enter the value: ";
        std::cin.clear();
      }
    };
    invalidInput = true;
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
  std::cout << DoMath(intArray, AddArray) << std::endl;

  std::cout << "\nThe product of all the elements in the array is ";
  std::cout << DoMath(intArray, MultiplyArray) << std::endl;
  std::cout << std::endl << std::endl;
}

// The code is stored in a function for ease of use.
// https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// A template is used to keep the function general and increase reusability
// https://stackoverflow.com/questions/17156282/passing-a-stdarray-of-unknown-size-to-a-function
template <size_t length>
auto AddArray(const std::array<int, length>& array) noexcept -> int {
  int sum = 0;
  for (auto& element : array) {
    sum += element;
  }
  return sum;
}

template <size_t length>
auto MultiplyArray(const std::array<int, length>& array) noexcept -> int {
  int product = 1;
  for (auto& element : array) {
    product *= element;
  }
  return product;
}

// LO7
// Take the AddArray or MultiplyArray functions as arguments
template <size_t length>
auto DoMath(const std::array<int, length>& array,
            int (&operation)(const std::array<int, length>&)) noexcept -> int {
  return operation(array);
}

auto SetShapeColor() -> std::string {
  bool invalidInput = true;
  std::string color;
  std::cout << "Enter the color (red, blue, yellow, or black): ";
  while (invalidInput) {
    try {
      ignoreLine();
      std::cin >> color;
      if (!(color == "red" || color == "blue" || color == "yellow" ||
            color == "black")) {
        throw 1;
      }
      invalidInput = false;
    } catch (int) {
      std::cout << "The color entered is not valid.\n";
      std::cout << "Please re-enter the color (red, blue, yellow, or black): ";
    } catch (...) {
      std::cout << "An error occurred while processing the color entered.\n";
      std::cout << "Please re-enter the color (red, blue, yellow, or black): ";
    }
  }
  return color;
}

auto SetShapeDimension() -> double {
  bool invalidInput = true;
  double dimension = 0;
  while (invalidInput) {
    try {
      ignoreLine();
      std::cin >> dimension;
      if (std::cin.fail()) {
        throw std::runtime_error("The dimension is not a number.");
      }
      invalidInput = false;
    } catch (const std::runtime_error& e) {
      std::cout << e.what() << std::endl;
      std::cout << "Please re-enter the dimension as a number (e.g. 1): ";
      std::cin.clear();
    } catch (...) {
      std::cout
          << "An error occurred while processing the dimension entered.\n";
      std::cout << "Please re-enter the dimension as a number (e.g. 1): ";
      std::cin.clear();
    }
  }
  return dimension;
}