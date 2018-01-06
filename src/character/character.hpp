#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <list>
#include <iostream>
#include <string>

#include "../action/action.hpp"
#include "../action/effect.hpp"
#include "../action/ability.hpp"
#include "../dice/dice.hpp"

namespace Character {

  using namespace Action;

class character {
private:
  Dice::dice dice;
  std::string name;
  int hp;
  int st;
  int dx;
  int ws;
  //weapon wp;
  //armor ar;
  //relic rl
  actions act;
  std::vector<effect> effects;
  void actEffect(effect);


public:
  character(void);
  character(std::string, int, int, int, int, const actions&);
  bool isAlive(void) { return (hp > 0); };
  int getHp(void) { return hp; };
  int getSt(void) { return st; };
  int getDx(void) { return dx; };
  int getWs(void) { return ws; };
  void setHp(int h) { hp = h; };
  void setSt(int s) { st = s; };
  void setDx(int d) { dx = d; };
  void setWs(int w) { ws = w; };
  void setActions(actions& a) { act = a; };
  void setName(std::string n) { name = n; };
  std::string getName(void) { return name; };
  void procEffects(void);
  void addEffect(effect&);
  void addEffects(std::vector<effect>&);
  std::vector<effect> roll(void);
  void printActions(void);




};
}
#endif
