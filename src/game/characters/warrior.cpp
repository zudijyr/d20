#include "warrior.hpp"

namespace Character {

warrior::warrior(int level) {
  if(level == 1) {
    int warhp = 7;
    int warst = 5;
    int wardx = 3;
    int warws = 2;
    auto WarCleave = cleave(warst);
    auto WarAct = action(WarCleave);
    WarAct.addNum(20); WarAct.addNum(19); WarAct.addNum(18); WarAct.addNum(17);
    auto WarActs = actions();
    WarActs.insert(WarAct);
    character( "Warrior",
      warhp, warst, wardx, warws,
      WarActs
    );
  }
}

}
