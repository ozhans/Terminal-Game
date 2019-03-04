#include "GameEngine.h"
#include "Entity.h"
#include <iostream>
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

GameEngine::GameEngine(uint boardSize, std::vector<Player *> *players):board(Board(boardSize,players)){
  currentRound = 1;
  this->players = players;
}

GameEngine::~GameEngine(){
    for(Player *player : *players) {
        delete player;
    }
    players->clear();
    delete players;

}

const Board& GameEngine::getBoard() const{
  return board;
}

Player* GameEngine::operator[](uint id) const{
  for(Player* player: *players){
    if(id == player->getID()) return player;
  }return nullptr;
}

bool GameEngine::isFinished() const{
  if(players->size() == 0 || (players->size() == 1 && board.isCoordHill((*players)[0]->getCoord()))) return true;
  return false;
}

void GameEngine::takeTurn(){
  std::cout << "-- START ROUND " << currentRound << " --" << std::endl;
  board.updateStorm(currentRound);
  /*for(Player *player: *players){
    takeTurnForPlayer(player->getID());
  }*/
  std::vector<Player *>::size_type size = players->size();
  for(int i = 0; i<size;i++){
    takeTurnForPlayer((*players)[i]->getID());
    if(flag && (*players)[i]->getID() > dead) {
      i--;
      size--;
      flag = 0;
    }else if(flag){
      size--;
      flag =0;
    }
  }
  std::cout << "-- END ROUND " << currentRound << " --" << std::endl;
  currentRound++;
}

Move GameEngine::takeTurnForPlayer(uint playerID){
  Player* p = (*this)[playerID];
  if (p == nullptr) return NOOP;
  std::vector<Move> pri = p->getPriorityList();
  std::vector<Coordinate> coo = board.visibleCoordsFromCoord(p->getCoord());
  if(board.isStormInCoord(p->getCoord())){
    int d = Entity::stormDamageForRound(currentRound);
    std::cout << p->getFullName() << "(" << p->getHP() << ") is STORMED! (-" << d << ")" << std::endl;
    p->stormD(currentRound);
    if(p->isDead()) {
      std::cout << p->getFullName() << "(" << p->getHP() << ") is DIED." << std::endl;
      dead = p->getID();
      flag = 1;
      removeP(p);
      return NOOP;
    }
  }
  for(Move move : pri){
    if (move == NOOP) return NOOP;
    else if(move == ATTACK){
      std::vector<Player *> att;
      for(Coordinate c : coo){
        if(board[c] != nullptr) att.push_back(board[c]);
      }
      if(att.empty()) continue;
      else{
        Player* temp = att[0];
        for(Player * l: att){
          if(temp->getID() > l->getID()) temp = l;
        }
        bool isPlayerDead = p->attackTo(temp);
        if(isPlayerDead){
          std::cout << temp->getFullName() << "(" << temp->getHP() << ") is DIED." << std::endl;
          dead = temp->getID();
          flag = 1;
          removeP(temp);
        }
        return ATTACK;
      }
    }
    else{
      Coordinate t = board.calculateCoordWithMove(move,p->getCoord());
      Coordinate hill((board.getSize()-1)/2,(board.getSize()-1)/2);
      if(t != p->getCoord() && (t-hill) < (p->getCoord()-hill)){
        p->executeMove(move);
        return move;
      }
      else continue;
    }
  }return NOOP;
}

Player *GameEngine::getWinnerPlayer() const{
  if(players->empty() || !isFinished()) return nullptr;
  return (*players)[0];
}

void GameEngine::removeP(Player * p){
  int i = 0;
  for(std::vector<Player *>::iterator it = players->begin(); it !=players->end(); it++,i++){
    if(*it == p){
      delete (*players)[i];
      players->erase(it);
      break;
    }
  }
}
