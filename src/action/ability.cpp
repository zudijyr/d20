#include "ability.hpp"

namespace Action {
  ability::ability() {
    name = std::string();
    effects = std::vector<effect>();
  }
  ability::ability(std::string n) {
    name = std::string();
    name.append(n);
    effects = std::vector<effect>();
  }
  ability::ability(const ability& a) {
    name = std::string(a.getName());
    effects = std::vector<effect>(a.getEffects());
  }
  void ability::setName(std::string n) {
    name.clear();
    name.append(n);
  }
  void ability::addEffect(effect& e) {
    effects.push_back(e);
  }

  bool ability::isEqual(const ability& ab) const {
    if(name.compare(ab.getName())) {
      return false;
    }
      //add effects test
    return true;
  }

  void ability::print(void) {
    std::cout << "Ability name: " << name << "; ";
    std::cout << "effects: ";
    for(auto it : effects) {
      it.print();
    }
    std::cout << std::endl;
  }
}
