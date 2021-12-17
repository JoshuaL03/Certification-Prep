/** @brief Derived class of the Run interface.
 *
 *  Holds a name (string) as a private data member.
 */

#ifndef HUMAN_H
#define HUMAN_H

#include "Run.h"

class Human : public Run {
 private:
  std::string name;

 public:
  explicit Human(std::string n) noexcept : name(std::move(n)) {}

  void SetName(std::string n) { name = n; }
  auto GetName() -> std::string { return name; }

  /** @brief Prints a string stating the person (by name) has started running.
   *
   */
  void StartRunning() override;

  /** @brief Prints a string stating the person (by name) has stopped running.
   *
   */
  void StopRunning() override;

  /** @brief Prints a string stating the person (by name) is watching TV.
   *
   */
  void WatchTV();
};

#endif