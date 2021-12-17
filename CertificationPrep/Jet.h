/** @brief Derived class of Vehicle.
 *
 *  It has no fields. It has a function, MakeSound, that overrides a virtual
 *  function in the base class.
 */

#ifndef JET_H
#define JET_H

#include "Vehicle.h"

class Jet : public Vehicle {
 private:
  // No fields used for this example.

 public:
  /** @brief Makes/outputs a jet sound.
   *
   *  It overrides the function of the same name in the base class.
   *
   *  @return The sound the jet makes.
   */
  auto MakeSound() -> std::string override;
};

#endif