#include "GameParser.h"
#include <fstream>
#include <sstream>
#include <string>
#include "Berserk.h"
#include "Ambusher.h"
#include "Pacifist.h"
#include "Dummy.h"
#include "Tracer.h"
#include <iostream>
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

std::pair<int,std::vector<Player *> *> GameParser::parseFileWithName(const std::string& filename){
  int boardSize;
  std::vector<std::string> str;
  std::ifstream infile(filename);
  std::vector<Player *> *pl = new std::vector<Player *>;
  std::string line;
  std::string::size_type sz;
  std::getline(infile, line);
  boardSize = std::stoi(line.substr(12),&sz);
  std::getline(infile,line);
  int count = std::stoi(line.substr(14),&sz);
  while(std::getline(infile, line)){
    std::string s;
    for (int j = 0; line[j] != '\0'; j++) {
      if(line[j] != ':') s += line[j];
      else{
        str.push_back(s);
        s="";
      }
      if(line[j+1] == '\0') {
        str.push_back(s); s = "";
      }
    }

    Player *temp;
    if(str[2] == "Berserk") temp = new Berserk(std::stoi(str[0],&sz),std::stoi(str[4],&sz),std::stoi(str[6],&sz));
    else if(str[2] == "Ambusher") temp = new Ambusher(std::stoi(str[0],&sz),std::stoi(str[4],&sz),std::stoi(str[6],&sz));
    else if(str[2] == "Dummy") temp = new Dummy(std::stoi(str[0],&sz),std::stoi(str[4],&sz),std::stoi(str[6],&sz));
    else if(str[2] == "Pacifist") temp = new Pacifist(std::stoi(str[0],&sz),std::stoi(str[4],&sz),std::stoi(str[6],&sz));
    else if(str[2] == "Tracer") temp = new Tracer(std::stoi(str[0],&sz),std::stoi(str[4],&sz),std::stoi(str[6],&sz));
    pl->push_back(temp);
    str.clear();
  }
  std::pair<int, std::vector<Player *> *> result (boardSize,pl);
  return result;
}
