#ifndef TILE_H
#define TILE_H
#include "libs.h"

class Tile {

private:
  sf::Clock animationTimer; // Timer for idle animation
  std::vector<sf::RectangleShape> tiles; //Gridmap
  std::vector<int> tile_is_space;

public:
  Tile();
  virtual ~Tile();

  //Functions
  const sf::Vector2f getPosition() const;
  const sf::FloatRect getGlobalBounds() const;
  const sf::Vector2f getVelocity() const;

  //Modifiers
  void setPosition(const float x, const float y);
  void updateTilemap();
  const std::vector<sf::RectangleShape> get_Tiles() const;
  void renderTilemap(sf::RenderTarget & target);
  void initVariables();
};

#endif