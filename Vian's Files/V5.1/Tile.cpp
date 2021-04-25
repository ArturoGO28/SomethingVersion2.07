#include "Tile.h"

#include "libs.h"

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
      current_tile.setFillColor(sf::Color::Blue);
    } else if (level[i] == 12) {
      tile_is_space.push_back(0);
      current_tile.setFillColor(sf::Color::Magenta);
    }
    current_tile.setSize(sf::Vector2f(64, 64));
    current_tile.setPosition(x * 64, y * 64);
    this->tiles.push_back(current_tile);
  }
  // for (int i = 0; i < 800; i = i + (512 / 13)) {
  //   for (int j = 0; j < 600; j = j + (512 / 13)) {
  //     int tile_randomizer = rand() % 500;
  //     this->tile_is_space.push_back(tile_randomizer);
  //     if (tile_randomizer == 0) {
  //       current_tile.setFillColor(sf::Color::Green);
  //     } else {
  //       current_tile.setFillColor(sf::Color::Transparent);
  //     }
  //     current_tile.setSize(sf::Vector2f(512 / 13, 512 / 13));
  //     current_tile.setPosition(i, j);
  //     this->tiles.push_back(current_tile);
  //   }
  // }
}

Tile::~Tile() {}

void Tile::renderTilemap(sf::RenderTarget &target) {
  for (auto &current_tile : this->tiles) target.draw(current_tile);
}