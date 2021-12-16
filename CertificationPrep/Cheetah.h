#ifndef CHEETAH_H
#define CHEETAH_H

#include "Run.h"

class Cheetah : public Run {
 private:
  std::string preferredPrey;

 public:
  explicit Cheetah(std::string prey) noexcept : preferredPrey(std::move(prey)) {}

  void SetPreferredPrey(std::string prey) { preferredPrey = prey; }
  auto GetPreferredPrey() -> std::string { return preferredPrey; }

  void StartRunning() override;
  void StopRunning() override;

  void Hunt();
};

#endif