#include "Player.h"
#include <string>
#include <iostream>
#include "Entity.h"
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Player::Player(uint id, int x, int y):id(id),coordinate(Coordinate(x,y)){
  HP = 100;
}

Player::~Player(){}

uint Player::getID() const {
  return id;
}

const Coordinate& Player::getCoord() const {
  return coordinate;
}

int Player::getHP() const {
  return HP;
}

std::string Player::getBoardID() const {
  if(id < 10 && id>= 0){
    return "0" + std::to_string(id);
  }
  return std::to_string(id);
}




bool Player::isDead() const {
  if (HP <= 0) return true;
  return false;
}

void Player::executeMove(Move move){
  coordinate = coordinate + move;
  if(move == 1)   std::cout << getFullName() << "(" << HP << ") moved UP" << std::endl;
  if(move == 2)   std::cout << getFullName() << "(" << HP << ") moved DOWN" << std::endl;
  if(move == 3)   std::cout << getFullName() << "(" << HP << ") moved LEFT" << std::endl;
  if(move == 4)   std::cout << getFullName() << "(" << HP << ") moved RIGHT" << std::endl;
}

bool Player::attackTo(Player *player){
  int x = Entity::damageForWeapon(getWeapon()) - Entity::damageReductionForArmor(player->getArmor());
  int temp;
  if (x > 0 && this!=player) temp = x;
  else temp = 0;
  std::cout << getFullName() << "(" << HP << ") ATTACKED " << player->getFullName() << "(" << player->getHP() << ")!" << "(-" << temp << ")\n";
  player->HP -= temp;
  return player->isDead();
}

bool Player::stormD(uint r){
  HP -= Entity::stormDamageForRound(r);
  return isDead();
}
