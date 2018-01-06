#include "warrior.hpp"

namespace Character {

warrior::warrior(int level, std::string name) {
  if(level == 1) {
    int warhp = 7;
    int warst = 5;
    int wardx = 3;
    int warws = 2;

    auto WarCleave = cleave(warst);
    WarCleave.print();
    auto WarAct = action(WarCleave);
    WarAct.addNum(20); WarAct.addNum(19); WarAct.addNum(18); WarAct.addNum(17);
    auto WarActs = actions();
    WarActs.insert(WarAct);
    setName("Warrior");
    setHp(warhp); setSt(warst); setDx(wardx); setWs(warws);
    setActions(WarActs);
  }
}

}
