#ifndef GAME_H
#define GAME_H

#include "libs.h"
#include "Player.h"
#include "Tile.h"


class Game {

private:
  sf::RenderWindow window;
  sf::Event event;
  sf::Texture mapSheet;

  Player* player;
  Tile* tile;
  // Platform* platform;

  void initWindow();
  void initPlayer();
  void initTile();

public:

  //Functions

  Game();
  virtual ~Game();

  //Functions
  void updatePlayer();
  void updateCollision();
  void updateTileMap();
  // void updatePlatform(); 
  void update();
  void renderPlayer();
  // void renderPlatform();
  void renderTileMap();
  void render();
  const sf::RenderWindow& getWindow() const;
};

#endif