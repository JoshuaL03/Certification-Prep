/** @brief Derived class of the Run interface.
 *
 *  Holds a preferredPrey (string) as a private data member.
 */

#ifndef CHEETAH_H
#define CHEETAH_H

#include "Run.h"

class Cheetah : public Run {
 private:
  std::string preferredPrey;

 public:
  explicit Cheetah(std::string prey) noexcept
      : preferredPrey(std::move(prey)) {}

  void SetPreferredPrey(std::string prey) { preferredPrey = prey; }
  auto GetPreferredPrey() -> std::string { return preferredPrey; }

  /** @brief Prints a string stating the cheetah has started running.
   *
   */
  void StartRunning() override;

  /** @brief Prints a string stating the cheetah has started running.
   *
   */
  void StopRunning() override;

  /** @brief Prints a string stating the cheetah is hunting for its preferred
   *         prey (by name).
   *
   */
  void Hunt();
};

#endif