#ifndef __WARRIOR_HPP__
#define __WARRIOR_HPP__

#include "../../character/character.hpp"
#include "../abilities/cleave.hpp"

namespace Character {

class warrior: public Character::character {
public:
  warrior(int, std::string);
};

}

#endif
