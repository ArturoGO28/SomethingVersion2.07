#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
  sf::Sprite model;
  sf::Texture sourceSheet;
  bool moving;
  sf::Clock animationTimer;

  //Animation
  sf::IntRect currentFrame;
  //Movement
  //Stats

  void initVariables();
  void initTexture();
  void initSprite();
  void initAnimations();

public:
  Player();
  virtual ~Player();

  //Functions

  void updateMovement();
  void updateAnimations();
  void update();
  void render(sf::RenderTarget& target); 
};

#endif