// Copyright 2021 Timothy Borunov timobohr@bu.edu

// Game2.cpp: This file contains all of the functions for Game2.h
// in their executable form. All functions called using Game2 class,
// are executed from here.

#include "Game2.h"
#include "libs.h"

// This level array is the initial platform for the beginning of the
// the game.
int level[] = {
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 12, 12, 11, 11, 11, 12, 12, 11, 11, 11, 12, 12, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 12, 12, 12, 12, 11, 11, 12, 12, 12, 12, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 11, 11, 11, 11, 11, 11,
    12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12,
    12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 
    12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 
    12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
};

// Initializes variable bool end and bool done, which defines whether the end of
// a level has been reached.
void Game2::initVariables() {
  this->end = false;
  this->done = false;
}

// Initializes the window for the game, close button, titlebar, and frame limit.
void Game2::initWindow() {
  this->window.create(sf::VideoMode(1024, 768), "Project: SOMETHING",
                      sf::Style::Close | sf::Style::Titlebar);
  this->window.setFramerateLimit(60);
}

// Initializes Player Class within Game Class
void Game2::initPlayer() { this->player = new Player2(); }

// Initializes Tile Class for a particular level array. Expects an input
// of an int array for level.
void Game2::initTile(int * level) { this->tile = new Tile2(level); }

// Constructor for game class; Initializes the Game2 class by initializing
// each separate aspect of the Game2 class: Player2, Tile2, Levels, Window, and
// Variables.
Game2::Game2() {
  this->initWindow();
  this->initPlayer();
  this->initTile(level);
  this->initVariables();
}

// Deletes player class and tile class references in Game2 class.
Game2::~Game2() {
  delete this->player;
  delete this->tile;
}

// Calls the update function in player class causing the player
// class to update.
void Game2::updatePlayer() { this->player->update(); }

// Calls the update function in tile class causing the tile
// class to update.
void Game2::updateTileMap() { 
  this->tile->updateTilemap(); 
}

// Checks for collision between player, sides of the screens, and tiles. This function
// causes specific blocks to be impassible for the player on the top surface. If player
// collides with the bottom of the screen, makes end true.
void Game2::updateCollision() {
  // Checks for collision between player and bottom of screen
  if (this->player->getPosition().y + this->player->getGlobalBounds().height >
      this->window.getSize().y) {
    this->player->resetVelocityY();

    // If there is a collision at the bottom of the screen, 
    //set jumping to false to allow the player to jump again
    this->player->jumping = false;
    this->player->setPosition(
        this->player->getPosition().x,
        this->window.getSize().y - this->player->getGlobalBounds().height);
    this->end = true;
  }

  // Checks for collision between player and top of screen
  if (this->player->getPosition().y < 0.f) {
    this->player->resetVelocityY();
    this->player->setPosition(this->player->getPosition().x, 0.f);
  }

  // Checks for collision between player and right area of screen
  if (this->player->getPosition().x + this->player->getGlobalBounds().width >
      this->window.getSize().x) {
    this->player->resetVelocityX();
    this->player->setPosition(
        this->window.getSize().x - this->player->getGlobalBounds().width,
        this->player->getPosition().y);
  }

  // Checks for collision between player and left area of screen
  if (this->player->getPosition().x < 0.f) {
    this->player->resetVelocityX();
    this->player->setPosition(0.f, this->player->getPosition().y);
  }

  // Run a for loop to check for intersections between the player and each tile in the tilemap
  std::vector<sf::RectangleShape> tiles = this->tile->get_Tiles();
  std::vector<int> tile_is_space = this->tile->get_Tile_is_space();
  sf::RectangleShape current_tile;
  int tile_iteration = 0;

  for (auto &current_tile : tiles) {
    sf::FloatRect playerBounds = this->player->getGlobalBounds();
    sf::FloatRect tileBounds = current_tile.getGlobalBounds();

    // if a tile of tile_is_space type 0 intersects with the player, run further if-statements
    // to check how the player collides with the tile
    if (tileBounds.intersects(playerBounds) &&
      tile_is_space.at(tile_iteration) == 0) {

      // Boolean statement to check for collision between
      // bottom side of player with the tile
      bool bottom_of_player = playerBounds.top < tileBounds.top
          && playerBounds.top + playerBounds.height < tileBounds.top + tileBounds.height
          && playerBounds.left < tileBounds.left + tileBounds.width
          && playerBounds.left + playerBounds.width > tileBounds.left;

        // Checks for collision between bottom side of player and the tile,
        // if true: resets vertical velocity and sets player position 
        // exactly above the tile
        if (bottom_of_player)
        {
          this->player->resetVelocityY();

          // If there is a collision between the bottom of player and tile, 
          //set jumping to false to allow the player to jump again 
          this->player->jumping = false;
          this->player->setPosition(playerBounds.left, tileBounds.top - playerBounds.height);
        }
    }
    tile_iteration++;
  }
}

// If end is true, as in if player hits the bottom of the screen,
// ends the game and brings player to end screen.
void Game2::updateLevel() {
  if (this->end == true && this->done ==false) {
      delete this->tile;
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
  this->initTile(final);
  this->done = true;
  }
}

// General game update function that calls all other Game2 update functions
// and checks whether window is open and closes window if x is clicked and
// escape is pressed.
void Game2::update() {
  // Tracks window events
  while (this->window.pollEvent(this->event)) {
    if (this->event.type == sf::Event::Closed)
      this->window.close();
    else if (this->event.type == sf::Event::KeyPressed &&
             this->event.key.code == sf::Keyboard::Escape)
      this->window.close();
  }
    this->updatePlayer();
    this->updateCollision();
    this->updateLevel();
   if (this->player->jumping == true && this->player->getVelocity().y == 0 && this->end == false) 
    this->updateTileMap();

}

// Draws the player to the window created by the Game2 class.
void Game2::renderPlayer() { this->player->render(this->window); }

// Draws the Tilemap to the window created by the Game2 class.
void Game2::renderTileMap() { this->tile->renderTilemap(this->window); }

// Calls other render functions and continuously redraws the screen
// with each new render.
void Game2::render() {
  this->window.clear(sf::Color{55, 55, 55, 117});

  // Render Game2
  this->renderTileMap();
  this->renderPlayer();

  this->window.display();
}

// This function returns the window so that other functions can have a window
// as an input.
const sf::RenderWindow &Game2::getWindow() const { return this->window; }
