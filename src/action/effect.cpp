#include "effect.hpp"

namespace Action {

    effect::effect(std::string s, fx g, int p, int t) {
      name = std::string(s);
      power = p;
      time = t;
      f = g;
    }

    bool effect::nameEq(std::string s) {
      if( name.compare(s)) {
        return false;
      } else {
        return true;
      }
    }

    bool effect::tick(void) {
      time -= 1;
      if( time <= 0) {
        return true;
      } else {
        return false;
      }
    }

    void effect::print(void) {
      std::cout << "name: " << name << "; ";
      std::cout << "power: " << power << "; ";
      std::cout << "time: " << time << "; ";
      std::cout << "fx: " << f << std::endl;
    }

}
