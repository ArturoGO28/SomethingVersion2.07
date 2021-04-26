// Copyright 2021 Timothy Borunov timobohr@bu.edu

// Player2.cpp: This file contains all of the functions for Player2.h
// in their executable form. All functions called using Player class,
// are executed from here.

#include "libs.h"
#include "Player2.h"
using std::abs;

// Initializes variables for Player2
void Player2::initVariables() {
  this->moving = false;
  this->jumping = false;
}

// Reads in sourceSheet and checks if it worked
void Player2::initTexture() {
  if (!this->sourceSheet.loadFromFile("frog64.png"))
    std::cout << "ERROR IN Player2.CPP: Could not load Player2 sheet!" << "\n";
}

// Initializes and sets the size of the first fram of the Player2 sprite
void Player2::initSprite() {
  this->model.setTexture(this->sourceSheet);
  this->currentFrame = sf::IntRect(10,10,50,54); // First frame size
  this->model.setTextureRect(this->currentFrame); //How much of the sheet we want to render.
  this->model.setScale(0.95f, 0.95f); // How big the sprite is
}

// This function initiallizes the SFML Clock which we planned to use for animations
// but did not get to them.
void Player2::initAnimations() {
  this->animationTimer.restart();
}

// Initializes all of the physics variables which the player uses to determine movement.
void Player2::initPhysics() {
  this->maxVelocity = 10.f;
  this->minVelocity = 1.f;
  this->acceleration = 3.f;
  this->deceleration = 0.95f;
  this->gravity = 2.f;
  this->yMaxVelocity = 15.f;
  this->movespeed = 8.f;
}

// Runs all initilizations for Player2 to exist.
Player2::Player2() {
  this->initVariables();
  this->initTexture();
  this->initSprite();
  this->initAnimations();
  this->initPhysics();
}

// Obligatory deconstructor function.
Player2::~Player2() {
}

// Gets player position
const sf::Vector2f Player2::getPosition() const
{
  return this->model.getPosition();
}

// Gets FloatRect Dimensions of player
const sf::FloatRect Player2::getGlobalBounds() const
{
  return this->model.getGlobalBounds();
}

// Gets the current velocity of player
const sf::Vector2f Player2::getVelocity() const
{
  return this->velocity;
}

// Sets the current position of player
void Player2::setPosition(const float x, const float y)
{
  this->model.setPosition(x, y);
}

// Stops the player in vertical direction
void Player2::resetVelocityY()
{
  this->velocity.y = 0.f;
}

// Stops the player in horizontal direction
void Player2::resetVelocityX()
{
  this->velocity.x = 0.f;
}

// Function that is used to move the player.
void Player2::move(const float xDir, const float yDir) {
  // Acceleration
  this->velocity.x += xDir * this->acceleration;
  this->velocity.y += yDir * this->acceleration;
  // Limit velocity
  if(abs(this->velocity.x) > this->maxVelocity) {
    this->velocity.y = this->maxVelocity * ((this->velocity.y < 0.f) ? -1.f : 1.f);
  }
}

// Updates current state of physics
void Player2::updatePhysics() {
  // Gravity
  this->velocity.y += 1.0 * this->gravity;
  if(abs(this->velocity.x) > this->yMaxVelocity) {
    this->velocity.x = this->yMaxVelocity * ((this->velocity.x < 0.f) ? -1.f : 1.f);
  }
  // Deceleration
  this->velocity *= this->deceleration;
  // Limit velocity
  if(abs(this->velocity.x) < this->minVelocity)
    this->velocity.x = 0.f;
  if(abs(this->velocity.y) < this->minVelocity)
    this->velocity.y = 0.f;

  this->model.move(this->velocity);
}

// Updates current state of movement
void Player2::updateMovement() {
  // Remember that left top corner is zero. All movement based off of that.
  this->moving = false;
  
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) 
  {
    this->model.move(-movespeed, 0.f);
    this->moving = true;
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
    this->model.move(movespeed, 0.f);
    this->moving = true;
  } 

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !this->jumping) {
    this->velocity.y -= 40;
    this->jumping = true;
   }
}

// Updates current Player2 
void Player2::update() {
  this->updateMovement();
  this->updatePhysics();
}

// Renders player to targetted window.
void Player2::render(sf::RenderTarget & target)
{
  target.draw(this->model);
}