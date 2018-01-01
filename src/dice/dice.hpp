#ifndef __DICE_HPP__
#define __DICE_HPP__

#include <random>

namespace Dice {
  enum Side {
    Twenty = 20,
    Six = 6,
    Two = 2,
    Four = 4,
    Eight = 8,
    Ten = 10,
    Twelve = 12
  };

  class dice {
  private:
    //std::random_device rd;
    std::mt19937_64 generator;

  public:
    dice(void);
  //  dice(const dice&);
    int roll(Side);
  };

}

#endif
