#ifndef __ACTION_HPP__
#define __ACTION_HPP__

#include <memory>
#include <set>
#include <list>
#include <vector>
#include <iostream>

#include "ability.hpp"
//#include "d20.hpp"

namespace Action {

typedef std::vector<std::vector<ability> > layout;

class action {
private:
  ability a;
  std::vector<int> numbers;
public:
  action();
//  action(const action&);
  action(const ability&);
  bool checkNum(int) const;
  void addNum(int);
  void delNum(int);
  //std::vector<int>& getNumbers(void) { return numbers; };
  const ability& getAbility(void) const { return a; };
  bool isEqual(const action&) const;
  void print(void);
};

class actions {
private:
  std::vector<action> as;

public:
  actions();
  actions(const actions& a);
  const std::vector<action>& getActions(void) const { return as; };
  void insert(action&);
  void remove(action&);
  std::vector<ability> getRoll(int);
  layout getLayout(void);
  void print(void);
};

}
#endif
