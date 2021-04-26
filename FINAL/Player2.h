// Copyright 2021 Timothy Borunov timobohr@bu.edu

// Class for the actual Player2 model, containing all functions
// and variables pertaining to the Player2 model itself.
// Explanations for each particular function can be found
// in Player2.cpp

#ifndef PLAYER2_H
#define PLAYER2_H

class Player2 {
private:
  sf::Sprite model; // Sprite for the Player2 model
  sf::Texture sourceSheet; // Art for Player2 model and animations
  bool moving; // Checks whether Player2 is moving
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
  Player2(); // Constructor
  virtual ~Player2(); // Deconstructor

  //Functions
  const sf::Vector2f getPosition() const;
  const sf::FloatRect getGlobalBounds() const;
  const sf::Vector2f getVelocity() const;

  // Functions that deal with player position
  void setPosition(const float x, const float y);
  void resetVelocityY();
  void resetVelocityX();

  // Functions that update and render the player
  void move(const float xDir, const float yDir);
  void updatePhysics();
  void updateMovement();
  void update();
  void render(sf::RenderTarget& target); 
};

#endif
