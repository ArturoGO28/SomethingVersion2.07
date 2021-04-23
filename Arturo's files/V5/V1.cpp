#include "libs.h"
#include "Game.h"
#include <iostream>
using std::cout;

int main() {
  

  
  Game game;

  while(game.getWindow().isOpen()) {
    game.update();
    game.render();
  }
  return 0;
}
