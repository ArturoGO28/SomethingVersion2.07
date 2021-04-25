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
  bool end;

  Player* player;
  Tile* tile;

  void initVariables();
  void initWindow();
  void initPlayer();
  void initTile(std::vector <int *> );
  void initLevels();

public:

  //Functions

  Game();
  virtual ~Game();

  //Functions
  void updatePlayer();
  void updateCollision();
  void updateTileMap();
  void updateLevel();
  void update();
  void renderPlayer();
  void renderTileMap();
  void render();
  const sf::RenderWindow& getWindow() const;
};

#endif