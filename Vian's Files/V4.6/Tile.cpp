#include "libs.h"
#include "Tile.h"



const std::vector<sf::RectangleShape> Tile::get_Tiles() const
{
  return this->tiles;
}

void Tile::updateTilemap()
{
  this->tiles = {};
  sf::RectangleShape current_tile;
  for (int i = 0; i < 800; i = i + (512/13)) {
    for (int j = 0; j < 600; j = j + (512/13)) {
      int tile_randomizer = rand() % 6;
      this->tile_is_space.push_back(tile_randomizer);
      if (tile_randomizer == 0 || tile_randomizer == 1) {
        current_tile.setFillColor(sf::Color::Green);
      } else {
        current_tile.setFillColor(sf::Color::Transparent);
      }
      current_tile.setSize(sf::Vector2f(512 / 13, 512 / 13));
      current_tile.setPosition(i, j);
      this->tiles.push_back(current_tile);
    }
  }
}

Tile::Tile()
{
  this->tiles = {};
  this->tile_is_space = {};
}

Tile::~Tile() {

}

void Tile::renderTilemap(sf::RenderTarget & target)
{
  for (auto &current_tile : this->tiles) target.draw(current_tile);
}