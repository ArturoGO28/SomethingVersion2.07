#ifndef PLATFORM_H
#define PLATFORM_H
#include "libs.h"
// #include "Collider.h"
#include "Player.h"


class Platform {
public:
  // This is the constructor
  Platform();
  // This is the deconstructor
  ~Platform();

  void Draw(sf::RenderWindow& window);
  // Collider GetCollider() { 
  //   return Collider(block);
  // }


  void initMapTexture();
  void initSpriteMap();
  void render(sf::RenderTarget & target);
  void updatePlatform(Player*);

  sf::Sprite block;
  sf::IntRect spriteNum;
  // sf::RectangleShape body;
  sf::Texture mapSheet;

  //new code:
  float xPos;
  float yPos;
  float xVel;
  float yVel;
  int scale;
  int topSide;
  int bottomSide;
  int rightSide;
  int leftSide;
  sf::Sprite image;
};




#endif