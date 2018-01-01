#ifndef __EFFECT_HPP__
#define __EFFECT_HPP__

#include <string>
#include <iostream>

namespace Action {

typedef enum fx_t {
  Hit,
  Heal
} fx;

class effect {
  private:
    std::string name;
    fx f;
    int power;
    int time;

  public:
    effect(std::string, fx, int, int);
    std::string getName(void) { return name; };
    fx getType(void) { return f; };
    bool nameEq(std::string);
    int getPower(void) { return power; };
    bool tick(void);
    void print(void);
};

}

#endif
