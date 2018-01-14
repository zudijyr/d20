#include "warrior.hpp"

namespace Character {

Warrior::Warrior(int level, std::string name) {
    int warhp = 7*level;
    int warst = 5*level;
    int wardx = 3*level;
    int warws = 2*level;

	//TODO gain abilities with levels
    auto WarCleave = cleave(warst);
    WarCleave.print();
    auto WarAct = action(WarCleave);
    WarAct.addNum(20); WarAct.addNum(19); WarAct.addNum(18); WarAct.addNum(17);
    auto WarActs = actions();
    WarActs.insert(WarAct);
    setName(name);
    setHp(warhp); setSt(warst); setDx(wardx); setWs(warws);
    setActions(WarActs);
}

}
