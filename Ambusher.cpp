#include "Ambusher.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Ambusher::Ambusher(uint id , int x, int y):Player(id,x,y){
  a = {ATTACK};
}

Weapon Ambusher::getWeapon() const{
  return SEMIAUTO;
}

Armor Ambusher::getArmor() const{
  return NOARMOR;
}

std::vector<Move> Ambusher::getPriorityList() const{
  return a;
}

const std::string Ambusher::getFullName() const {
  return "Ambusher" + Player::getBoardID();
}
