#ifndef __ABILITY_HPP__
#define __ABILITY_HPP__

#include "effect.hpp"
#include <string>
#include <vector>
#include <iostream>

namespace Action {

class ability {

private:
  std::string name;
  std::vector<effect> effects;
public:
  ability();
  ability(std::string);
  ability(const ability&);
  void setName(std::string);
  void addEffect(effect&);
  const std::vector<effect>& getEffects(void) const { return effects; };
  std::string getName(void) const { return name; };
  bool isEqual(const ability&) const;
  void print(void);
};

}

#endif
