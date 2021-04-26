#include "Tile.h"
#include "libs.h"
#include <iostream>
using std::cout;

const std::vector<sf::RectangleShape> Tile::get_Tiles() const {
  return this->tiles;
}

const std::vector<int> Tile::get_Tile_is_space() const {
  return this->tile_is_space;
}

void Tile::updateTilemap() {}

Tile::Tile(int level[]) {
  this->tiles = {};
  this->tile_is_space = {};
  sf::RectangleShape current_tile;
  for (int i = 0; i < 192; i++) {
    int x = i % 16;
    int y = i / 16;
    if (level[i] == 11) {
      tile_is_space.push_back(1);
      current_tile.setFillColor(sf::Color{ 55 , 55 , 55, 0});
    } else if (level[i] == 12) {
      tile_is_space.push_back(0);
      current_tile.setFillColor(sf::Color::Green);
    } else if (level[i] == 13) {
      tile_is_space.push_back(2);
      current_tile.setFillColor(sf::Color::Red);
    }
    current_tile.setSize(sf::Vector2f(64, 64));
    current_tile.setPosition(x * 64, y * 64);
    this->tiles.push_back(current_tile);
  }
  // calls the initTexture function to load the texture for the tiles;
  // This is only called once in the Tile constructor because loading
  // several textures slows down the game.
  this->initTexture();
}

Tile::~Tile() {}

// Loads the texture for the tiles and checks if it worked
void Tile::initTexture() {
  if (!this->texture.loadFromFile("sprite_sheet1.png", 
    sf::IntRect(xnum, ynum, xwidth, ywidth))) {
    cout << "Failed to load the sprite sheet" << '\n';
  }
}

void Tile::renderTilemap(sf::RenderTarget &target) {
  // Add texture and render each tile
  for (auto &current_tile : this->tiles) {
    current_tile.setTexture(&(this->texture));
    target.draw(current_tile);
  }
}