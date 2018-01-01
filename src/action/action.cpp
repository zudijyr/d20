#include "action.hpp"

namespace Action {

  action::action() {
    a = ability();
    numbers = std::vector<int>();
  }

  action::action(const ability& ab){
    a = ability(ab);
    numbers = std::vector<int>(); //maybe use d20
  }
/*
  action::action(const action& ac) {
    a = ability(ac.getAbility());
    numbers = std::vector<int>(ac.getNumbers());
  }
*/
  bool action::checkNum(int i) const {
    for(const int& it : numbers) {
      if( it == i) {
        return true;
      }
    }
    return false;
  }

  void action::addNum(int i) {
    numbers.push_back(i);
  }

  void action::delNum(int i) {
    numbers.erase(std::remove(numbers.begin(), numbers.end(), i));
  }

  bool action::isEqual(const action& b) const {
    const ability& abb = b.getAbility();
    return(a.isEqual(abb));
  }

  actions::actions() {
    as = std::vector<action>();
  }

  actions::actions(const actions& a) {
    as = std::vector<action>(a.getActions());
  }

  void actions::insert(action& a) {
    as.push_back(a);
  }

  void actions::remove(action& a) {
    std::vector<action>::iterator it;
    for(it = as.begin(); it != as.end(); ++it) {
      if(it->isEqual(a)) {
        as.erase(it);
        return;
      }
    }
  }

  std::vector<ability> actions::getRoll(int i) {
    auto r = std::vector<ability>();
    for(auto it : as) {
      if(it.checkNum(i)) {
        r.push_back(it.getAbility());
      }
    }
    return r;
  }

  layout actions::getLayout(void) {
    auto l = std::vector<std::vector<ability> >();
    auto g = std::vector<ability>();
    l.push_back(g);
    for(int i = 1; i <= 20; ++i) {
      auto s = getRoll(i);
      l.push_back(s);
    }
    return l;
  }

  void action::print(void) {
    std::cout << "action: ";
    a.print();
    std::cout << "rolls: ";
    for(auto it : numbers) {
      std::cout << it << " ";
    }
    std::cout << std::endl;
  }
  void actions::print(void) {
    std::cout << "ACTIONS: ";
    for(auto it : as) {
      it.print();
    }
  }

}
