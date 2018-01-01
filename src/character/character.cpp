#include "character.hpp"

namespace Character {

  using namespace Action;

  character::character(void) {
    dice = Dice::dice();
    name = std::string();
    hp = 1;
    st = 1;
    dx = 1;
    ws = 1;
    act = actions();
    effects = std::vector<effect>();
  }

  character::character(
    std::string n,
    int h,
    int s,
    int d,
    int w,
    const actions& a
  ) {
    dice = Dice::dice();
    name = std::string(n);
    hp = h;
    st = s;
    dx = d;
    ws = w;
    act = actions(a);
  }

  void character::actEffect(effect e) {
    switch(e.getType()) {
      case Hit: {
        hp -= e.getPower();
        break;
      }
      case Heal: {
        hp += e.getPower();
        break;
      }
      default: break;
    }


  }
  void character::procEffects(void) {
    std::vector<effect>::iterator it;
    for(auto it : effects) {
      actEffect(it);
    }
    for(it = effects.begin(); it!= effects.end(); ) {
      if(it->tick()) {
        effects.erase(it);
      } else {
        ++it;
      }
    }
  }
  void character::addEffect(effect& e) {
    effects.push_back(e);
  }
  void character::addEffects(std::vector<effect>& es) {
    for(auto i : es) {
      addEffect(i);
    }
  }

  std::vector<effect> character::roll(void) {
    auto ret = std::vector<effect>();
    int r = dice.roll(Dice::Twenty);
    std::cout << "\t" << name << " rolls " << r << std::endl;
    auto ab = act.getRoll(r);
    std::vector<ability>::iterator it;
    for(it = ab.begin(); it != ab.end(); ++it) {
      std::cout << it->getName() << std::endl;
    }
    for(it = ab.begin(); it != ab.end(); ++it) {
      auto es = it->getEffects();
      std::vector<effect>::iterator eit;
      for(eit = es.begin(); eit != es.end(); ++eit) {
        ret.push_back(*eit);
      }
    }
    return ret;
  }

  void character::printActions(void) {
    layout l = act.getLayout();

    for(int i = 0; i <= 20; ++i) {
      std::cout << i << ": ";
      std::vector<ability>::iterator it;
      auto ll = std::vector<ability>(l[i]);
      for(it = ll.begin(); it != ll.end(); ++it) {
        it->print();
      }
      std::cout << std::endl;
    }
  }
}
