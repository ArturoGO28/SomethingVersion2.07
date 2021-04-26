// Copyright 2021 Timothy Borunov timobohr@bu.edu

// Game.cpp: This file contains all of the functions for Game.h
// in their executable form. All functions called using Game class,
// are executed from here.

#include "Game.h"
#include "libs.h"
using std::vector;

// These Level Arrays are the actual level rooms designating which tiles
// are to be positioned in our 1024 x 768 pixel window.
int level1[] = {
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 13,
    12, 12, 12, 12, 12, 12, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 12, 12, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12,
    12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12,
    12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 
    12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 
    12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12,
};

int level2[] = {
    11, 11, 11, 11, 11, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 12, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 12, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11,
    11, 11, 12, 11, 11, 12, 11, 11, 12, 12, 12, 12, 12, 11, 11, 11,
    11, 11, 12, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 11, 11,
    11, 11, 12, 12, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12,
    11, 11, 12, 12, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12,
    11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 13, 
    12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
};

int level3[] = {
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 13,
    11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11,
    11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
};

int level4[] = {
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 12, 12, 12,
    11, 11, 12, 12, 12, 12, 12, 12, 11, 11, 12, 11, 11, 12, 12, 12,
    11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 12, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 12, 11, 11, 11, 11, 11,
    12, 12, 11, 11, 11, 11, 11, 12, 11, 13, 12, 12, 12, 12, 12, 11,
    12, 12, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 11, 11, 11,
    12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
};

int level5[] = {
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 13,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 12, 12, 12, 12, 12,
    11, 11, 11, 11, 12, 11, 11, 12, 12, 11, 11, 12, 12, 12, 12, 12,
    11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 12, 12, 12, 12, 12,
    11, 11, 12, 11, 11, 11, 11, 11, 12, 11, 11, 11, 11, 11, 11, 12,
    11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 11, 11, 11, 11, 12,
    12, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 11, 11, 12,
    12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 
    12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 
    12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
};

int level6[] = {
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12,
    11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 11, 11, 12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11,
    12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 13,
};

int final[] = {
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 12, 12, 12, 11, 12, 11, 12, 11, 11, 12, 11, 11, 11,
    11, 11, 11, 12, 11, 11, 11, 12, 11, 12, 12, 11, 12, 11, 11, 11,
    11, 11, 11, 12, 11, 11, 11, 12, 11, 12, 11, 12, 12, 11, 11, 11,
    11, 11, 11, 12, 12, 11, 11, 12, 11, 12, 11, 11, 12, 11, 11, 11,
    11, 11, 11, 12, 11, 11, 11, 12, 11, 12, 11, 11, 12, 11, 11, 11,
    11, 11, 11, 12, 11, 11, 11, 12, 11, 12, 11, 11, 12, 11, 11, 11,
    11, 11, 11, 12, 11, 11, 11, 12, 11, 12, 11, 11, 12, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
};

// This variable designates which level the player is in.
int i = 0;

// This vector, once initiallized, contains all the level arrays.
vector <int *> levels;

// Initializes variable bool end, which defines whether the end of
// a level has been reached.
void Game::initVariables() {
  this->end = false;
}

// Initializes vector of levels with int level arrays.
void Game::initLevels() {
  levels.push_back(level1);
  levels.push_back(level2);
  levels.push_back(level3);
  levels.push_back(level4);
  levels.push_back(level5);
  levels.push_back(level6);
  levels.push_back(final);
}

// Initializes the window for the game, close button, titlebar, and frame limit.
void Game::initWindow() {
  this->window.create(sf::VideoMode(1024, 768), "Project: SOMETHING",
                      sf::Style::Close | sf::Style::Titlebar);
  this->window.setFramerateLimit(60);
}

// Initializes Player Class within Game Class
void Game::initPlayer() { this->player = new Player(); }

// Initializes Tile Class for a particular level array. Expects an input
// of a vector of int arrays for levels.
void Game::initTile(vector <int *> levels) { 
  this->tile = new Tile(levels.at(i)); 
}

// Constructor for game class; Initializes the Game class by initializing
// each separate aspect of the Game class: Player, Tile, Levels, Window, and
// Variables.
Game::Game() {
  this->initWindow();
  this->initPlayer();
  this->initLevels();
  this->initTile(levels);
  this->initVariables();
}

// Deletes player class and tile class references in game class.
Game::~Game() {
  delete this->player;
  delete this->tile;
}

// Calls the update function in player class causing the player
// class to update.
void Game::updatePlayer() { this->player->update(); }

// Calls the update function in tile class causing the tile
// class to update.
void Game::updateTileMap() { this->tile->updateTilemap(); }

// Checks for collision between player, sides of the screens, and tiles. This function
// Causes specific blocks to be impassible for the player or check if player has reached end block.
void Game::updateCollision() {
  // Collision bottom of screen
  if (this->player->getPosition().y + this->player->getGlobalBounds().height >
      this->window.getSize().y) {
    this->player->resetVelocityY();
    this->player->jumping = false;
    this->player->setPosition(
        this->player->getPosition().x,
        this->window.getSize().y - this->player->getGlobalBounds().height);
  }

  // Collision top of screen
  if (this->player->getPosition().y < 0.f) {
    this->player->resetVelocityY();
    this->player->setPosition(this->player->getPosition().x, 0.f);
  }

  // Collision right of screen
  if (this->player->getPosition().x + this->player->getGlobalBounds().width >
      this->window.getSize().x) {
    this->player->resetVelocityX();
    this->player->setPosition(
        this->window.getSize().x - this->player->getGlobalBounds().width,
        this->player->getPosition().y);
  }

  // Collision left of screen
  if (this->player->getPosition().x < 0.f) {
    this->player->resetVelocityX();
    this->player->setPosition(0.f, this->player->getPosition().y);
  }

  // Collision with tile
  std::vector<sf::RectangleShape> tiles = this->tile->get_Tiles();
  std::vector<int> tile_is_space = this->tile->get_Tile_is_space();
  sf::RectangleShape current_tile;
  int tile_iteration = 0;

  sf::FloatRect nextPos;
  for (auto &current_tile : tiles) {
    sf::FloatRect playerBounds = this->player->getGlobalBounds();
    sf::FloatRect tileBounds = current_tile.getGlobalBounds();

    nextPos = playerBounds;

    if (tileBounds.intersects(nextPos) &&
        tile_is_space.at(tile_iteration) == 2) {
      this->end = true;
    }

    if (tileBounds.intersects(nextPos) &&
        tile_is_space.at(tile_iteration) == 0) {
      // Right collision
      if (playerBounds.left < tileBounds.left &&
          playerBounds.left + playerBounds.width <
              tileBounds.left + tileBounds.width &&
          playerBounds.top < tileBounds.top + tileBounds.height &&
          playerBounds.top + playerBounds.height > tileBounds.top) {
        this->player->resetVelocityX();
        this->player->setPosition(tileBounds.left - playerBounds.width,
                                  playerBounds.top);
      }
      // Left collision
      else if (playerBounds.left > tileBounds.left &&
               playerBounds.left + playerBounds.width >
                   tileBounds.left + tileBounds.width &&
               playerBounds.top < tileBounds.top + tileBounds.height &&
               playerBounds.top + playerBounds.height > tileBounds.top) {
        this->player->resetVelocityX();
        this->player->setPosition(tileBounds.left + tileBounds.width,
                                  playerBounds.top);
      }
      // Bottom collision
      if (playerBounds.top < tileBounds.top &&
          playerBounds.top + playerBounds.height <
              tileBounds.top + tileBounds.height &&
          playerBounds.left < tileBounds.left + tileBounds.width &&
          playerBounds.left + playerBounds.width > tileBounds.left) {
        this->player->resetVelocityY();
        this->player->jumping = false;
        this->player->setPosition(playerBounds.left,
                                  tileBounds.top - playerBounds.height);
      }
      // Top collision
      else if (playerBounds.top > tileBounds.top &&
               playerBounds.top + playerBounds.height >
                   tileBounds.top + tileBounds.height &&
               playerBounds.left < tileBounds.left + tileBounds.width &&
               playerBounds.left + playerBounds.width > tileBounds.left) {
        this->player->resetVelocityY();
        this->player->setPosition(playerBounds.left,
                                  tileBounds.top + tileBounds.height);
      }
    }
    tile_iteration++;
  }
}

// If player has reached end of a level, starts next level.
void Game::updateLevel() {
  if (this->end == true) {
      delete this->tile;
    i++;
    this->initTile(levels);
    this->end = false;
  }
}

// General game update function that calls all other Game update functions
// and checks whether window is open and closes window if x is clicked and
// escape is pressed.
void Game::update() {
  while (this->window.pollEvent(this->event)) {
    if (this->event.type == sf::Event::Closed)
      this->window.close();
    else if (this->event.type == sf::Event::KeyPressed &&
             this->event.key.code == sf::Keyboard::Escape)
      this->window.close();
  }
  this->updatePlayer();
  this->updateTileMap();
  this->updateCollision();
  this->updateLevel();
}

// Draws the player to the window created by the Game class.
void Game::renderPlayer() { this->player->render(this->window); }

// Draws the Tilemap to the window created by the Game class.
void Game::renderTileMap() { this->tile->renderTilemap(this->window); }

// Calls other render functions and continuously redraws the screen
// with each new render.
void Game::render() {
  this->window.clear(sf::Color{55, 55, 55, 117});

  // Renders game
  this->renderTileMap();
  this->renderPlayer();

  this->window.display();
}

// This function returns the window so that other functions can have a window
// as an input.
const sf::RenderWindow &Game::getWindow() const { return this->window; }
