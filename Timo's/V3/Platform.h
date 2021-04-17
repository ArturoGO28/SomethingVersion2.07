#ifndef PLATFORM_H
#define PLATFORM_H
#include "libs.h"
#include "Collider.h"


class Platform {
public:
  Platform();
  ~Platform();

  void Draw(sf::RenderWindow& window);
  Collider GetCollider() { 
    return Collider(body);
  }


  void initMapTexture();
  void initSpriteMap();
  void render(sf::RenderTarget & target);

  sf::Sprite block;
  sf::IntRect spriteNum;
  sf::RectangleShape body;
  sf::Texture mapSheet;
};




#endif