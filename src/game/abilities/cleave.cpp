#include "cleave.hpp"

namespace Action {

cleave::cleave(int n) {
  auto hit = effect(std::string("cleave hit"), Hit, n, 1);
  ability();
  setName("Cleave");
  addEffect(hit);
}

}
