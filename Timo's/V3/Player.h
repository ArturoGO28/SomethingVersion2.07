#ifndef PLAYER_H
#define PLAYER_H
#include "Collider.h"
// Class for the actual player model, containing all functions
// and variables pertaining to the player model itself.
// Explanations for each particular function can be found
// in Player.cpp
class Player {
private:
  sf::Sprite model; // Sprite for the player model
  sf::Texture sourceSheet; // Art for player model and animations
  bool moving; // Checks whether player is moving
  sf::Clock animationTimer; // Timer for idle animation

  //Animation
  sf::IntRect currentFrame; // Which image we use from sourceSheet

  //Physics
  sf::Vector2f velocity;
  float minVelocity;
  float maxVelocity;
  float acceleration;
  float deceleration;
  float gravity;
  float yMaxVelocity;
  //Movement
  Collider* collider;
  sf::Vector2f getPosition() {
    return this->collider->body.getPosition();
  }
  Collider GetCollider() {
    return Collider(this->collider->body);
  }
  //Stats

  void initVariables();
  void initTexture();
  void initSprite();
  void initAnimations();
  void initPhysics();

public:
  Player();
  virtual ~Player();

  //Functions
  void move(const float xDir, const float yDir);
  void updatePhysics();
  void updateMovement();
  void updateAnimations();
  void update();
  void render(sf::RenderTarget& target); 
};

#endif