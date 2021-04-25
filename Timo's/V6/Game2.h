#ifndef GAME2_H
#define GAME2_H

#include "libs.h"
#include "Player2.h"
#include "Tile2.h"


class Game2 {

private:
  sf::RenderWindow window;
  sf::Event event;
  sf::Texture mapSheet;

  Player2* player;
  Tile2* tile;
  // Platform* platform;

  void initWindow();
  void initPlayer();
  void initTile();

public:

  //Functions

  Game2();
  virtual ~Game2();

  //Functions
  void updatePlayer();
  void updateCollision();
  void updateTileMap();
  void update();
  void renderPlayer();
  void renderTileMap();
  void render();
  const sf::RenderWindow& getWindow() const;
};

#endif