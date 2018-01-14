#include "redmage.hpp"

using namespace Action;
using namespace Character;

RedMage::RedMage(int level, std::string name) {
    int rmhp = 5*level;
    int rmst = 2*level;
    int rmdx = 3*level;
    int rmws = 2*level;
    auto rmHit = effect(std::string("red mage hit"), Hit, rmst, 1);
    auto rmHeal = effect(std::string("red mage heal"), Heal, rmws, 1);
    auto rmAbl = ability();
    auto rmHealAbility = ability();
    auto rmCritAbility = ability();
    rmCritAbility.setName(std::string("Red Mage Crit"));
    rmAbl.setName(std::string("Red Mage Hit"));
    rmHealAbility.setName(std::string("Red Mage Heal"));
    rmCritAbility.addEffect(rmHit);
    rmCritAbility.addEffect(rmHeal);
    rmAbl.addEffect(rmHit);
    rmHealAbility.addEffect(rmHeal);
  
    auto rmAct = action(rmAbl);
    rmAct.addNum(19); rmAct.addNum(18);
    auto rmCritAct = action(rmCritAbility);
    rmCritAct.addNum(20);
    auto rmHAct = action(rmHealAbility);
    rmHAct.addNum(5); rmHAct.addNum(6); rmHAct.addNum(7);
  
    auto rmActs = actions();
    rmActs.insert(rmAct);
    rmActs.insert(rmCritAct);
    rmActs.insert(rmHAct);
  
    setName(name);
    setHp(rmhp); setSt(rmst); setDx(rmdx); setWs(rmws);
    setActions(rmActs);

}
