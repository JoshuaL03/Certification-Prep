/** @brief Derived class of vehicle.
 *
 *  It has no fields. It has a function, MakeSound, that overrides a virtual
 *  function in the base class.
 */

#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
 private:
  // No fields used for this example.

 public:
  /** @brief Makes/outputs a car sound.
   *
   *  It overrides the function of the same name in the base class.
   *
   *  @return The sound the car makes.
   */
  auto MakeSound() -> std::string override;
};

#endif