#ifndef TILE_H
#define TILE_H
#include "libs.h"

class Tile {
 private:
  sf::Clock animationTimer;               // Timer for idle animation
  std::vector<sf::RectangleShape> tiles;  // Gridmap
  std::vector<int> tile_is_space;

 public:
  Tile(int level[]);
  virtual ~Tile();

  // Modifiers
  void setPosition(const float x, const float y);
  void updateTilemap();
  const std::vector<sf::RectangleShape> get_Tiles() const;
  const std::vector<int> get_Tile_is_space() const;
  void renderTilemap(sf::RenderTarget& target);
  void initVariables();
};

#endif