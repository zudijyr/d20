#ifndef __D20_HPP__
#define __D20_HPP__

namespace Action {
  /*
  typedef enum d20_t {
    One = 1,
    Two = 2,
    Three = 3,
    Four = 4,
    Five = 5,
    Six = 6,
    Seven = 7,
    Eight = 8,
    Nine = 9,
    Ten = 10,
    Eleven = 11,
    Twelve = 12,
    Thirteen = 13,
    Fourteen = 14,
    Fifteen = 15,
    Sixteen = 16,
    Seventen = 17,
    Eighteen = 18,
    Nineteen = 19,
    Twenty = 20
  } d20;
*/
  bool check20(int i) {
    if ( i < 1 || i > 20) {
      return false;
    } else {
      return true;
    }
  }
}

#endif
