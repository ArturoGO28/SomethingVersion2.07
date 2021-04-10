#ifndef GAME_H
#define GAME_H

#include "libs.h"

class Game {

private:
  sf::RenderWindow window;
  sf::Event event;
  void initWindow();

public:

  //Functions

  Game();
  virtual ~Game();

  //Functions
  void update();
  void render();
  const sf::RenderWindow& getWindow() const;
};

#endif