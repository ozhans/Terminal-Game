#include "Tracer.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Tracer::Tracer(uint id, int x, int y):Player(id,x,y){
  t = { UP, LEFT, DOWN, RIGHT, ATTACK };
}

Weapon Tracer::getWeapon() const {
  return SHOVEL;
}

Armor Tracer::getArmor() const {
  return BRICK;
}

std::vector<Move> Tracer::getPriorityList() const {
  return t;
}

const std::string Tracer::getFullName() const {
  return "Tracer" + Player::getBoardID();
}
