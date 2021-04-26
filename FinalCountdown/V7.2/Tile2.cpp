#include "Tile2.h"
#include "libs.h"
#include <iostream>
using std::cout;

const std::vector<sf::RectangleShape> Tile2::get_Tiles() const {
  return this->tiles;
}

const std::vector<int> Tile2::get_Tile_is_space() const {
  return this->tile_is_space;
}

void Tile2::updateTilemap() {
  std::vector<sf::RectangleShape> new_tiles = {};
  std::vector<int> new_tile_is_space = {};
  int tiles_size = this->tiles.size();

  sf::RectangleShape current_tile;

  for (int i = 0; i < tiles_size; i++) {
    current_tile = this->tiles[i];
    current_tile.setPosition(current_tile.getPosition().x, current_tile.getPosition().y + 64);
    new_tiles.push_back(current_tile);
    new_tile_is_space.push_back(this->tile_is_space[i]);
  }

  for (int x = 0; x < 16; x++) {
    // tile randomizer makes 1/10 chance of getting a magenta tile on the next level
    int tile_randomizer = rand() % 10;
    if (tile_randomizer > 0) {
      current_tile.setFillColor(sf::Color::Blue);
      new_tile_is_space.insert(new_tile_is_space.begin(), 1);
    } else {
      current_tile.setFillColor(sf::Color::Magenta);
      new_tile_is_space.insert(new_tile_is_space.begin(), 0);
    }
    current_tile.setPosition(x * 64, 0);
    new_tiles.insert(new_tiles.begin(), current_tile);
  }
  this->tiles = new_tiles;
  this->tile_is_space = new_tile_is_space;
}

Tile2::Tile2(int level[]) {
  this->tiles = {};
  this->tile_is_space = {};
  sf::RectangleShape current_tile;
  for (int i = 0; i < 192; i++) {
    int x = i % 16;
    int y = i / 16;
    if (level[i] == 11) {
      tile_is_space.push_back(1);
      current_tile.setFillColor(sf::Color::Blue);
    } else if (level[i] == 12) {
      tile_is_space.push_back(0);
      current_tile.setFillColor(sf::Color::Magenta);
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

Tile2::~Tile2() {}

// Loads the texture for the tiles and checks if it worked
void Tile2::initTexture() {
  if (!this->texture.loadFromFile("sprite_sheet1.png", 
    sf::IntRect(xnum, ynum, xwidth, ywidth))) {
    cout << "Failed to load the sprite sheet" << '\n';
  }
}

void Tile2::renderTilemap(sf::RenderTarget &target) {
  // Add texture and render each tile
  for (auto &current_tile : this->tiles) {
    current_tile.setTexture(&(this->texture));
    target.draw(current_tile);
  }
}