#ifndef TILE_H
#define TILE_H
#include "libs.h"

class Tile {
 private:
  sf::Clock animationTimer;               // Timer for idle animation
  std::vector<sf::RectangleShape> tiles;  // Gridmap
  std::vector<int> tile_is_space;

 public:
  // Create a texture object and initialize static variables that indicate
  // which texture from the spritesheet we want to use.
  sf::Texture texture;
  int spritex = 9;
  int spritey = 13;
  float xwidth = 512/13;
  float ywidth = 512/13;
  float xnum = ((spritex - 1) * 512) / 13;
  float ynum = ((spritey - 1) * 512) / 13;
  void initTexture();

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