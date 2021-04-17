#ifndef GAME_H
#define GAME_H

#include "libs.h"
#include "Player.h"
#include "Collider.h"
#include "Platform.h"

class Game {

private:
  sf::RenderWindow window;
  sf::Event event;
  sf::Texture mapSheet;

  Player* player;
  Platform* platform;

  void initWindow();
  void initPlayer();
  void initPlatform();

public:

  //Functions

  Game();
  virtual ~Game();

  //Functions
  void updatePlayer();
  void update();
  void renderPlayer();
  void renderPlatform();
  void render();
  const sf::RenderWindow& getWindow() const;
};

#endif