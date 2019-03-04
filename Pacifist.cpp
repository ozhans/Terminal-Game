#include "Pacifist.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Pacifist::Pacifist(uint id ,int x,int y):Player(id,x,y){
  p = { UP, LEFT, DOWN, RIGHT };
}

Weapon Pacifist::getWeapon() const{
  return NOWEAPON;
}

Armor Pacifist::getArmor() const{
  return METAL;
}

std::vector<Move> Pacifist::getPriorityList() const{
  return p;
}

const std::string Pacifist::getFullName() const {
  return "Pacifist" + Player::getBoardID();
}
