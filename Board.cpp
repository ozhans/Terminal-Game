#include "Board.h"
#include "Entity.h"
#include <iostream>
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/


Board::Board(uint boardSize, std::vector<Player *> *players):boardSize(boardSize){
  this->players = players;
  currR = 0;
  storm = 0;
}

Board::~Board(){
}

uint Board::getSize() const{
  return boardSize;
}

bool Board::isCoordInBoard(const Coordinate& coord) const{
  if(coord.x < boardSize && coord.y < boardSize && coord.x >=0 && coord.y >=0)
    return true;
  return false;
}

bool Board::isStormInCoord(const Coordinate &coord) const{
  uint strm = Entity::stormWidthForRound(currR);
  if(currR == 0) return false;
  if(isCoordHill(coord)) return false;
  if(coord.x >= 0 + strm && coord.x <= boardSize - strm -1 && coord.y >= 0 + strm && coord.y <= boardSize - strm -1)
    return false;
  return true;
}

bool Board::isCoordHill(const Coordinate& coord) const{
  if(coord.x == (boardSize-1)/2 && coord.y == (boardSize-1)/2)
    return true;
  return false;
}

Player *Board::operator[](const Coordinate& coord) const{
  if(!isCoordInBoard(coord)) return nullptr;
  for(Player *player: *players){
    if(player->getCoord() == coord) return player;
  }
  return nullptr;
}

Coordinate Board::calculateCoordWithMove(Move move, const Coordinate &coord) const{
  if(!isCoordInBoard(coord+move) || move == ATTACK || move == NOOP || (*this)[coord+move] != nullptr) return coord;
  return coord + move;
}

std::vector<Coordinate> Board::visibleCoordsFromCoord(const Coordinate &coord) const{
  std::vector<Coordinate> v;
  if(!isCoordInBoard(coord)) return v;
  Move q=UP;
  Move w=DOWN;
  Move e=LEFT;
  Move r=RIGHT;
  if(isCoordInBoard(coord + q)) v.push_back(coord+q);
  if(isCoordInBoard(coord + w)) v.push_back(coord+w);
  if(isCoordInBoard(coord + e)) v.push_back(coord+e);
  if(isCoordInBoard(coord + r)) v.push_back(coord+r);
  return v;
}

void Board::updateStorm(uint currentRound){
  currR = currentRound;
}
