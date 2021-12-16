/** @brief Derived class of Shape. 
 * 
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

// LO2a
// Classes inherited in public visibility mode have their public members visible
// to all, their protected members visible to the derived class, and their
// private members invisible to all

// Classes inherited in protected visibility mode have their public and
// protected members visible to the derived class, and their private members
// invisible to all

// Classes inherited in private visibility mode have their public and protected
// members visible only to the directly derived class (they become private
// members of that class), and private members invisible to all

// LO2
class Circle : public Shape {
 private:
  double radius;

 public:
  Circle() noexcept { radius = 1; }
  explicit Circle(double r) noexcept { radius = r; }
  Circle(double r, std::string c) : Shape(c), radius(r){};

  [[nodiscard]] auto GetRadius() const noexcept -> double { return radius; }
  void SetRadius(double r) noexcept { radius = r; }

  // LO1a
  [[nodiscard]] auto CalculateArea() const noexcept -> double;
  [[nodiscard]] auto CalculateCircumference() const noexcept -> double;
};

#endif