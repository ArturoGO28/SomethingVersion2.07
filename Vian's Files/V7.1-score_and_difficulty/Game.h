// Copyright 2021 Timothy Borunov timobohr@bu.edu

// Game.h: This file defines the Game class. Overall
// within this class is contained the entirety of the levels game itself
// as with the initialization of this class, the SFML Window,
// the Player model, all the tiles, Levels, and variables will
// be rendered.

// This file is linked with Game.cpp which contains all of the
// actual code behind all of these functions. Calling one of them
// results in a call to this class, which in turn forwards it to the
// .cpp file and executes them.

#ifndef GAME_H
#define GAME_H

#include "libs.h"
#include "Player.h"
#include "Tile.h"

class Game {

private:
  sf::RenderWindow window; // defines variable for window
  sf::Event event; // defines variable for event
  sf::Texture mapSheet; // defines variable for texturesheet used.
  bool end; // defines boolean for level end.

  Player* player; // defines pointer to the Player Class
  Tile* tile; // defines pointer to Tile Class

  // The following functions are only utilized at the initializing
  // stage of the Game class. Further documentation of each function
  // can be found in Game.cpp.
  void initVariables(); 
  void initWindow();
  void initPlayer();
  void initTile(std::vector <int *> );
  void initLevels();

public:
  Game(); // Constructor for Game Class (called when Game class is created)
  virtual ~Game(); //Deconstructor for Game Class

  // These functions are functions that can be called through
  // the Game class which modify the Game. Further documentation of each
  // function can be found in Game.cpp.
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