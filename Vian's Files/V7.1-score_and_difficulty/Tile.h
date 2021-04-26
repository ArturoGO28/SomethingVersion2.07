#ifndef TILE_H
#define TILE_H
#include "libs.h"

// Class Tile is a class for the map of tiles for the levels game, with
// some tilesrepresenting obstacles, some tiles representing goals of
// game levels, and other tiles representing empty space
class Tile {
 private:           
  // Initialize the tile map as a vector of rectangle shapes    
  std::vector<sf::RectangleShape> tiles;  
  // Initialize a recording system as a vector which stores the 
  // type of each corresponding tile in vector "tiles" as an integer
  std::vector<int> tile_is_space;

 public:
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

  // Modifiers for the tilemap (explained more in Tile.cpp)
  void setPosition(const float x, const float y);
  void updateTilemap();
  const std::vector<sf::RectangleShape> get_Tiles() const;
  const std::vector<int> get_Tile_is_space() const;
  void renderTilemap(sf::RenderTarget& target);
  void initVariables();
};

#endif