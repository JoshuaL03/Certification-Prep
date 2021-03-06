/** @brief Base class for Circle, Square, and Triangle.
 * 
 *  Holds a color (string) as a private data member.
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

// LO4
// The procedural/functional approach uses functions to handle data, while the
// object-oriented approach uses objects to contain and handle data
// (encapsulation). Unlike the procedural approach, the object-oriented approach
// also features access specifiers, which allows for information hiding and more
// secure code.

class Shape {
 private:
  std::string color = "black";

 public:
  // LO1b
  Shape() = default;
  explicit Shape(const std::string c) : color(c){};

  auto GetColor() -> std::string { return color; }
  void SetColor(std::string c) { color = c; }
};

#endif