/** @brief Interface class for Human and Cheetah.
 *
 *  It has no fields. It also contains two pure virtual functions, StartRunning
 *  and StopRunning, that must be overridden in the derived classes to
 *  instantiate them.
 */

#ifndef RUN_H
#define RUN_H

#include <iostream>
#include <string>

// LO6
// Run is an interface with no fields and only pure virtual methods
class Run {
 private:
  // An interface has no fields.

 public:
  Run() = default;

  // Define all five special member functions to follow the rule of five
  virtual ~Run() = default;
  Run(const Run&) = delete;
  Run(Run&&) = delete;
  auto operator=(const Run&) -> Run& = delete;
  auto operator=(Run&&) -> Run& = delete;

  /** @brief Pure virtal function to be overridden.
   *
   */
  virtual void StartRunning() = 0;

  /** @brief Pure virtal function to be overridden.
   *
   */
  virtual void StopRunning() = 0;
};

#endif