#include "libs.h"
#include "Player.h"
using std::abs;

// Initializes variables for player
void Player::initVariables() {
  this->moving = false;
  this->jumping = false;
}

// void Player::initCollider() {
//   this->collider = new Collider(this->model);
// }

// Reads in sourceSheet and checks if it worked
void Player::initTexture() {
  if (!this->sourceSheet.loadFromFile("betterdemo.png"))
    std::cout << "ERROR IN PLAYER.CPP: Could not load player sheet!" << "\n";
}

// Initializes and sets the size of the first fram of the player sprite
void Player::initSprite() {
  this->model.setTexture(this->sourceSheet);
  this->currentFrame = sf::IntRect(0,0,85,85); // First frame size
  this->model.setTextureRect(this->currentFrame); //How much of the sheet we want to render.
  this->model.setScale(0.5f, 0.5f); // How big the sprite is
}

void Player::initAnimations() {
  this->animationTimer.restart();
}

void Player::initPhysics() {
  this->maxVelocity = 10.f;
  this->minVelocity = 1.f;
  this->acceleration = 3.f;
  this->deceleration = 0.95f;
  this->gravity = 2.f;
  this->yMaxVelocity = 15.f;
  this->movespeed = 8.f;
}

// Runs all initilizations for Player to exist.
Player::Player() {
  this->initVariables();
  this->initTexture();
  this->initSprite();
  this->initAnimations();
  this->initPhysics();
  // this->initCollider();
}

Player::~Player() {

}


const sf::Vector2f Player::getPosition() const
{
  return this->model.getPosition();
}

const sf::FloatRect Player::getGlobalBounds() const
{
  return this->model.getGlobalBounds();
}

const sf::Vector2f Player::getVelocity() const
{
  return this->velocity;
}

void Player::setPosition(const float x, const float y)
{
  this->model.setPosition(x, y);
}

void Player::resetVelocityY()
{
  this->velocity.y = 0.f;
}

void Player::resetVelocityX()
{
  this->velocity.x = 0.f;
}



void Player::move(const float xDir, const float yDir) {
  // Acceleration
  this->velocity.x += xDir * this->acceleration;
  this->velocity.y += yDir * this->acceleration;
  // Limit velocity
  if(abs(this->velocity.x) > this->maxVelocity) {
    this->velocity.y = this->maxVelocity * ((this->velocity.y < 0.f) ? -1.f : 1.f);
  }
}



void Player::updatePhysics() {
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

void Player::updateMovement() {
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
  // else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) 
  // {
  //   this->model.move(0.f, movespeed);
  //   this->moving = true;
  // }
  // else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
  //   this->model.move(0.f, -movespeed);
  //   this->moving = true;
  // }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
    this->velocity.y -= 4;
    this->jumping = true;
   }
}

void Player::updateAnimations() {
  // if (this->animationTimer.getElapsedTime().asSeconds() >= 0.5f) {
  // if (this->moving == false) { //idle
  //   this->currentFrame.left += 85.f;
  //   if (this->currentFrame.left >= 512.f)
  //     this->currentFrame.left = 0;
  // }
  // }
  // this->animationTimer.restart();
  // this->model.setTextureRect(this->currentFrame);
}

// Updates current player 
void Player::update() {
  this->updateMovement();
  // this->updateAnimations();
  this->updatePhysics();
}

void Player::render(sf::RenderTarget & target)
{
  target.draw(this->model);
}