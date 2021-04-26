// Copyright 2021 Timothy Borunov timobohr@bu.edu

// Class for the actual player model, containing all functions
// and variables pertaining to the player model itself.
// Explanations for each particular function can be found
// in Player.cpp

#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
  sf::Sprite model; // Sprite for the player model
  sf::Texture sourceSheet; // Art for player model and animations
  bool moving; // Checks whether player is moving
  sf::Clock animationTimer; // Timer for idle animation

  sf::IntRect currentFrame; // Which image we use from sourceSheet

  // Unitialized Physics variables
  sf::Vector2f velocity;
  float minVelocity;
  float maxVelocity;
  float acceleration;
  float deceleration;
  float gravity;
  float yMaxVelocity;
  float movespeed;

  // Initializing functions
  void initVariables();
  void initTexture();
  void initSprite();
  void initAnimations();
  void initPhysics();

public:
  bool jumping;
  Player(); // Constructor
  virtual ~Player(); // Deconstructor

  // Gets Player information functions
  const sf::Vector2f getPosition() const;
  const sf::FloatRect getGlobalBounds() const;
  const sf::Vector2f getVelocity() const;

  // Functions that deal with player position
  void setPosition(const float x, const float y);
  void resetVelocityY();
  void resetVelocityX();
  void move(const float xDir, const float yDir);

  // Functions that update and render the player
  void updatePhysics();
  void updateMovement();
  void update();
  void render(sf::RenderTarget& target); 
};

#endif