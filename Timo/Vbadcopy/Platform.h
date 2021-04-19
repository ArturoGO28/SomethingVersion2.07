#ifndef PLATFORM_H
#define PLATFORM_H
#include "libs.h"
#include "Collider.h"
#include "Player.h"


class Platform {
public:
  Platform();
  ~Platform();

  void Draw(sf::RenderWindow& window);
  Collider GetCollider() { 
    return Collider(block);
  }


  void initMapTexture();
  void initSpriteMap();
  void render(sf::RenderTarget & target);
  void updatePlatform(Player*);

  sf::Sprite block;
  sf::IntRect spriteNum;
  // sf::RectangleShape body;
  sf::Texture mapSheet;
};




#endif