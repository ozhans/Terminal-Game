#include "Berserk.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Berserk::Berserk(uint id, int x, int y):Player(id,x,y){
  b = { ATTACK, UP, LEFT, DOWN, RIGHT };
}

Armor Berserk::getArmor() const {
  return WOODEN;
}

Weapon Berserk::getWeapon() const{
  return PISTOL;
}

std::vector<Move> Berserk::getPriorityList() const{
  return b;
}

const std::string Berserk::getFullName() const {
  return "Berserk" + Player::getBoardID();
}
