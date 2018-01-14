#include "game.hpp"

using namespace Action;
using namespace Character;

void print_messages(Character::character char1, Character::character char2) {
  std::cout << char1.getName() << " " << char1.getHp() << "HP" << "; ";
  std::cout << char2.getName() << " " << char2.getHp() << "HP" << std::endl;
  std::cout << "rolling: " << std:: endl;
}

void genericTestGame(Character::character friendly, Character::character enemy) {
  friendly.printActions();
  enemy.printActions();
  while(friendly.isAlive() && enemy.isAlive()) {
	print_messages(friendly, enemy);
    auto warl = friendly.roll();
    for(auto i : warl) {
      i.print();
    }
    auto gobl = enemy.roll();
    for(auto i : gobl) {
      i.print();
    }
    /*Assign hits and heals correctly*/
    for(auto i : warl) {
      if(i.getType() == Hit) {
        enemy.addEffect(i);
      } else {
        friendly.addEffect(i);
      }
    }
    for(auto i : gobl) {
      if(i.getType() == Hit) {
        friendly.addEffect(i);
      } else {
        enemy.addEffect(i);
      }
    }
    friendly.procEffects();
    enemy.procEffects();
    std::getchar();
  }
  if(friendly.isAlive()) {
    std::cout << friendly.getName() << " wins!" << std::endl;
  }
  else if (enemy.isAlive()) {
    std::cout << enemy.getName() << " wins!" << std::endl;
  } else {
    std::cout << "Tie???" << std::endl;
  }
      std::getchar();
}

void testGame1(void) {
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
  genericTestGame(Warrior, Goblin);
}

void testGame2(void) {
  std::cout << "test game2\n";
  int fshp = 6;
  int fsst = 3;
  int fsdx = 2;
  int fsws = 1;
  auto FsHit = effect(std::string("fire slime hit"), Hit, fsst, 1);
  auto FsFir = effect(std::string("fire slime burn"), Hit, 1, 3);
  auto FsAbl = ability();
    auto FsFa = ability();
  FsAbl.setName(std::string("Fire Slime Hit"));
  FsFa.setName(std::string("Fire Burn"));

  FsAbl.addEffect(FsHit);
  FsFa.addEffect(FsFir);

  auto FsAct = action(FsAbl);
  FsAct.addNum(20); FsAct.addNum(19); FsAct.addNum(18); FsAct.addNum(17);
  auto FsFAct = action(FsFa);
  FsFAct.addNum(16); FsFAct.addNum(15);
  auto FsActs = actions();
  FsActs.insert(FsAct);
  FsActs.insert(FsFAct);
  //RmActs.print();
  //FsActs.print();
  character FireSlime = character( "fire slime",
    fshp, fsst, fsdx, fsws,
    FsActs
  );
  auto redmage = RedMage(1, "red mage");
  genericTestGame(redmage, FireSlime);
}

void testGame3(void) {
  auto warrior = Warrior(1, "wr");
  auto goblin = Warrior(1, "gob");
  genericTestGame(warrior, goblin);
}
