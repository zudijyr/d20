#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "../character/character.hpp"
#include "../action/action.hpp"
#include "../action/ability.hpp"
#include "../action/effect.hpp"
#include "../dice/dice.hpp"
#include <iostream>
#include <string>

#include "characters/warrior.hpp"
#include "characters/redmage.hpp"
#include "abilities/cleave.hpp"

void testGame1(void);
void testGame2(void);
void genericTestGame(Character::character, Character::character);
void testGame3(void);
void print_messages(Character::character, Character::character);

#endif
