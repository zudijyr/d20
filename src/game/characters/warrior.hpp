#ifndef __WARRIOR_HPP__
#define __WARRIOR_HPP__

#include "../../character/character.hpp"
#include "../abilities/cleave.hpp"

namespace Character {

class Warrior: public Character::character {
public:
  Warrior(int, std::string);
};

}

#endif
