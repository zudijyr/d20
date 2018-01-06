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
  auto WarHit = effect(std::string("Warrior hit"), Hit, warst, 1);
  auto WarHeal = effect(std::string("potion"), Heal, 1, 1);
  auto GobHit = effect(std::string("Goblin hit"), Hit, gobst, 1);
  auto WarAbl = ability();
  auto WarPot = ability();
  auto GobAbl = ability();
  WarAbl.setName(std::string("Warrior cleave"));
  WarPot.setName(std::string("potionnn"));
  GobAbl.setName(std::string("Goblin swipe"));
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
  character Warrior = character( "Warrior",
    warhp, warst, wardx, warws,
    WarActs
  );
  character Goblin = character( "Goblin",
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
    /*Assign hits and heals correctly*/
    for(auto i : warl) {
      if(i.getType() == Hit) {
        Goblin.addEffect(i);
      } else {
        Warrior.addEffect(i);
      }
    }
    for(auto i : gobl) {
      if(i.getType() == Hit) {
        Warrior.addEffect(i);
      } else {
        Goblin.addEffect(i);
      }
    }
    Warrior.procEffects();
    Goblin.procEffects();
    std::getchar();
  }
  if(Warrior.isAlive()) {
    std::cout << "Warrior wins!" << std::endl;
  }
  else if (Goblin.isAlive()) {
    std::cout << "Goblin wins!" << std::endl;
  } else {
    std::cout << "Tie???" << std::endl;
  }
      std::getchar();
}

void testGame2(void) {
  std::cout << "test game2\n";
  int rmhp = 5;
  int rmst = 2;
  int rmdx = 3;
  int rmws = 2;
  int fshp = 6;
  int fsst = 3;
  int fsdx = 2;
  int fsws = 1;
  auto RmHit = effect(std::string("red mage hit"), Hit, rmst, 1);
  auto RmHeal = effect(std::string("red mage heal"), Heal, rmws, 1);
  auto FsHit = effect(std::string("fire slime hit"), Hit, fsst, 1);
  auto FsFir = effect(std::string("fire slime burn"), Hit, 1, 3);
  auto RmAbl = ability();
  auto RmHa = ability();
  auto RmCrit = ability();
  auto FsAbl = ability();
    auto FsFa = ability();
  RmCrit.setName(std::string("Red Mage Crit"));
  RmAbl.setName(std::string("Red Mage Hit"));
  RmHa.setName(std::string("Red Mage Heal"));
  FsAbl.setName(std::string("Fire Slime Hit"));
  FsFa.setName(std::string("Fire Burn"));

  RmCrit.addEffect(RmHit);
  RmCrit.addEffect(RmHeal);
  RmAbl.addEffect(RmHit);
  RmHa.addEffect(RmHeal);
  FsAbl.addEffect(FsHit);
  FsFa.addEffect(FsFir);

  auto RmAct = action(RmAbl);
  RmAct.addNum(19); RmAct.addNum(18);
  auto RmCritAct = action(RmCrit);
  RmCritAct.addNum(20);
  auto RmHAct = action(RmHa);
  RmHAct.addNum(5); RmHAct.addNum(6); RmHAct.addNum(7);
  auto FsAct = action(FsAbl);
  FsAct.addNum(20); FsAct.addNum(19); FsAct.addNum(18); FsAct.addNum(17);
  auto FsFAct = action(FsFa);
  FsFAct.addNum(16); FsFAct.addNum(15);
  auto RmActs = actions();
  auto FsActs = actions();
  RmActs.insert(RmAct);
  RmActs.insert(RmCritAct);
  RmActs.insert(RmHAct);
  FsActs.insert(FsAct);
  FsActs.insert(FsFAct);
  RmActs.print();
  FsActs.print();
  character RedMage= character( "red mage",
    rmhp, rmst, rmdx, rmws,
    RmActs
  );
  character FireSlime = character( "fire slime",
    fshp, fsst, fsdx, fsws,
    FsActs
  );
  RedMage.printActions();
  FireSlime.printActions();
  while(RedMage.isAlive() && FireSlime.isAlive()) {
      std::cout << RedMage.getName() << RedMage.getHp() << "; ";
      std::cout << FireSlime.getName() << FireSlime.getHp() << std::endl;
      std::cout << "rolling: " << std:: endl;
    auto rml = RedMage.roll();
    for(auto i : rml) {
      i.print();
    }
    auto fsl = FireSlime.roll();
    for(auto i : fsl) {
      i.print();
    }
    /*Assign hits and heals correctly*/
    for(auto i : rml) {
      if(i.getType() == Hit) {
        FireSlime.addEffect(i);
      } else {
        RedMage.addEffect(i);
      }
    }
    for(auto i : fsl) {
      if(i.getType() == Hit) {
        RedMage.addEffect(i);
      } else {
        FireSlime.addEffect(i);
      }
    }
    RedMage.procEffects();
    FireSlime.procEffects();
    std::getchar();
  }
  if(RedMage.isAlive()) {
    std::cout << "RedMage wins!" << std::endl;
  }
  else if(FireSlime.isAlive()){
    std::cout << "FireSlime wins!" << std::endl;
  } else {
    std::cout << "Tie???" << std::endl;
  }
      std::getchar();
}

void testGame3(void) {
  auto WarOne = warrior(1);
  auto WarTwo = warrior(1);
}
