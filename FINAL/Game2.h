// Copyright 2021 Timothy Borunov timobohr@bu.edu

// Game2.h: This file defines the Game2 class. Overall
// within this class is contained the entirety of the jump game itself
// as with the initialization of this class, the SFML Window,
// the Player model, all the tiles, Levels, and variables will
// be rendered.

// This file is linked with Game2.cpp which contains all of the
// actual code behind all of these functions. Calling one of them
// results in a call to this class, which in turn forwards it to the
// .cpp file and executes them.


#ifndef GAME2_H
#define GAME2_H

#include "libs.h"
#include "Player2.h"
#include "Tile2.h"


class Game2 {

private:
  sf::RenderWindow window; // defines variable for window
  sf::Event event; // defines variable for event
  sf::Texture mapSheet; // defines variable for texturesheet used.
  bool end; // defines boolean for level end.
  bool done; // defines boolean for level done.

  Player2* player; // defines pointer to the Player Class
  Tile2* tile; // defines pointer to Tile Class

  // The following functions are only utilized at the initializing
  // stage of the Game2 class. Further documentation of each function
  // can be found in Game2.cpp.
  void initWindow();
  void initPlayer();
  void initTile(int * level);
  void initVariables();

public:
  Game2(); // Constructor for Game2 Class (called when Game class is created)
  virtual ~Game2(); //Deconstructor for Game Class

  // These functions are functions that can be called through
  // the Game class which modify the Game. Further documentation of each
  // function can be found in Game.cpp.
  void updatePlayer();
  void updateLevel();
  void updateCollision();
  void updateTileMap();
  void update();
  void renderPlayer();
  void renderTileMap();
  void render();
  const sf::RenderWindow& getWindow() const;
};

#endif