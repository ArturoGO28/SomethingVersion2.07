#include "Tile.h"

#include "libs.h"

const std::vector<sf::RectangleShape> Tile::get_Tiles() const {
  return this->tiles;
}

const std::vector<int> Tile::get_Tile_is_space() const {
  return this->tile_is_space;
}

void Tile::updateTilemap() {
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