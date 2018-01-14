#ifndef __REDMAGE_HPP__
#define __REDMAGE_HPP__

#include "../../character/character.hpp"
#include "../../action/action.hpp"
#include "../../action/ability.hpp"
#include "../../action/effect.hpp"
#include "../../dice/dice.hpp"
#include <iostream>
#include <string>

namespace Character {

class RedMage: public Character::character {
public:
  RedMage(int, std::string);
};

}

#endif
