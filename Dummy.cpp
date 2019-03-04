#include "Dummy.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Dummy::Dummy(uint id, int x, int y):Player(id,x,y){
  d = {NOOP};
  Player::HP = 1000;
}

Weapon Dummy::getWeapon() const{
  return NOWEAPON;
}

Armor Dummy::getArmor() const{
  return NOARMOR;
}

std::vector<Move> Dummy::getPriorityList() const{
  return d;
}

const std::string Dummy::getFullName() const {
  return "Dummy" + Player::getBoardID();
}
