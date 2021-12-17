/** @brief Base class for Jet and Car.
 *
 *  It has no fields. It has a virtual function, MakeSound, that is overridden
 *  in each derived class.
 */

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {
 private:
  // No fields used for this example.

 public:
  Vehicle() = default;

  // A virtual destructor is necessary to ensure that pointers to the Vehicle
  // class do not delete an object of one of its derived class types using the
  // wrong destructor, which would result in undefined behavior.
  // https://www.geeksforgeeks.org/virtual-destructor/
  virtual ~Vehicle() = default;

  // The other four special member functions are also defined to ensure the rule
  // of five is followed.
  // https://en.cppreference.com/w/cpp/language/rule_of_three
  // Additionally, the move and copy functions (the other four) should be
  // prohibited to prevent slicing.
  // https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md
  Vehicle(const Vehicle&) = delete;
  Vehicle(Vehicle&&) = delete;
  auto operator=(const Vehicle&) -> Vehicle& = delete;
  auto operator=(Vehicle&&) -> Vehicle& = delete;

  /** @brief Makes/outputs a vehicle sound.
   *
   *  It is also virtual, so it can be overridden in derived classes.
   *
   *  @return The sound the vehicle makes.
   */
  virtual auto MakeSound() -> std::string;
};

#endif