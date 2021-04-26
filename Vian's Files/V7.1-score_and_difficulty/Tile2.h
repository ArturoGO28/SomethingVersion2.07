#ifndef TILE2_H
#define TILE2_H
#include "libs.h"

// Class Tile2 is a class for the map of tiles for the jump game, with
// some tiles representing obstacles and other tiles representing empty space
class Tile2 {
 private:
  // Initialize the tile map as a vector of rectangle shapes
  std::vector<sf::RectangleShape> tiles;
  // Initialize a recording system as a vector which stores the 
  // type of each corresponding tile in vector "tiles" as an integer
  std::vector<int> tile_is_space;

 public:
  sf::Texture texture;
  float chance_difficulty;
  int spritex = 9;
  int spritey = 13;
  float xwidth = 512/13;
  float ywidth = 512/13;
  float xnum = ((spritex - 1) * 512) / 13;
  float ynum = ((spritey - 1) * 512) / 13;
  void initTexture();

  Tile2(int level[]);
  virtual ~Tile2();

  // Modifiers for the tilemap (explained more in Tile2.cpp)
  void setPosition(const float x, const float y);
  void displayScore(sf::RenderTarget &target, float score);
  void updateTilemap();
  const std::vector<sf::RectangleShape> get_Tiles() const;
  const std::vector<int> get_Tile_is_space() const;
  void renderTilemap(sf::RenderTarget& target);
  void initVariables();
};

#endif