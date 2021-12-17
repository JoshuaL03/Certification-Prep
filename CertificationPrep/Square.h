/** @brief Derived class of Shape.
 *
 *  It holds a side (double) as a private data member.
 */

#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
 private:
  double side;

 public:
  Square() noexcept { side = 1; }
  explicit Square(double s) noexcept : side(s){};
  Square(double s, std::string c) : Shape(c), side(s){};

  [[nodiscard]] auto GetSide() const noexcept -> double { return side; }
  void SetSide(double s) noexcept { side = s; }

  /** @brief Calculates the area of the square object.
   *  @return The area of the square.
   */
  [[nodiscard]] auto CalculateArea() const noexcept -> double;

  /** @brief Calculates the perimeter of the square object.
   *  @return The perimeter of the square.
   */
  [[nodiscard]] auto CalculatePerimeter() const noexcept -> double;
};

#endif