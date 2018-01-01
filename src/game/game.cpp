#include "game.hpp"

using namespace Action;
using namespace Character;

void testGame(void) {
  std::cout << "test game\n";
  int warhp = 7;
  int warst = 5;
  int wardx = 3;
  int warws = 2;
  int gobhp = 6;
  int gobst = 3;
  int gobdx = 2;
  int gobws = 1;
  auto WarHit = effect(std::string("warrior hit"), Hit, warst, 1);
  auto WarHeal = effect(std::string("potion"), Heal, 1, 1);
  auto GobHit = effect(std::string("goblin hit"), Hit, gobst, 1);
  auto WarAbl = ability();
  auto WarPot = ability();
  auto GobAbl = ability();
  WarAbl.setName(std::string("warrior cleave"));
  WarPot.setName(std::string("potionnn"));
  GobAbl.setName(std::string("goblin swipe"));
  WarAbl.addEffect(WarHit);
  WarPot.addEffect(WarHeal);
  GobAbl.addEffect(GobHit);
  WarHit.print();
  GobHit.print();
  WarAbl.print();
  GobAbl.print();
  auto WarAct = action(WarAbl);
  auto WarPota = action(WarPot);
  auto GobAct = action(GobAbl);
  WarPota.addNum(5); WarPota.addNum(7);
  WarAct.addNum(20); WarAct.addNum(19); WarAct.addNum(18); WarAct.addNum(17);
  GobAct.addNum(20); GobAct.addNum(19);
  WarAct.print();
  GobAct.print();
  auto WarActs = actions();
  auto GobActs = actions();
  WarActs.insert(WarAct);
  WarActs.insert(WarPota);
  GobActs.insert(GobAct);
  WarActs.print();
  GobActs.print();
  character Warrior = character( "warrior",
    warhp, warst, wardx, warws,
    WarActs
  );
  character Goblin = character( "goblin",
    gobhp, gobst, gobdx, gobws,
    GobActs
  );
  Warrior.printActions();
  Goblin.printActions();
  while(Warrior.isAlive() && Goblin.isAlive()) {
      std::cout << Warrior.getName() << Warrior.getHp() << "; ";
      std::cout << Goblin.getName() << Goblin.getHp() << std::endl;
      std::cout << "rolling: " << std:: endl;
    auto warl = Warrior.roll();
    for(auto i : warl) {
      i.print();
    }
    auto gobl = Goblin.roll();
    for(auto i : gobl) {
      i.print();
    }
    Warrior.addEffects(gobl);
    Goblin.addEffects(warl);
    Warrior.procEffects();
    Goblin.procEffects();
    std::getchar();
  }
  if(Warrior.isAlive()) {
    std::cout << "Warrior wins!" << std::endl;
  }
  else {
    std::cout << "Goblin wins!" << std::endl;
  }
}
