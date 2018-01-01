#include "dice.hpp"

namespace Dice {
  dice::dice(void) {
    std::random_device rd;
    generator = std::mt19937_64(rd());
  }

  int dice::roll(Side side) {
    std::uniform_int_distribution<int> distribution(1, side);
    return distribution(generator);
  }
}
