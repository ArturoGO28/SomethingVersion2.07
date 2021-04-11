#include "libs.h"
#include "Player.h"

void Player::initVariables() {
  this->moving = false;
}

void Player::initTexture() {
  if (!this->sourceSheet.loadFromFile("betterdemo.png"))
    std::cout << "ERROR IN PLAYER.CPP: Could not load player sheet!" << "\n";
}

void Player::initSprite() {
  this->model.setTexture(this->sourceSheet);
  this->currentFrame = sf::IntRect(0,0,85,85);
  this->model.setTextureRect(this->currentFrame); //How much of the sheet we want to render.
  this->model.setScale(1.5f, 1.5f);
}

void Player::initAnimations() {
  this->animationTimer.restart();
}

Player::Player() {
  this->initVariables();
  this->initTexture();
  this->initSprite();
  this->initAnimations();

}

Player::~Player() {

}
void Player::updateMovement() {
  // Remember that left top corner is zero. All movement based off of that.
  this->moving = false;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) 
  {
    this->model.move(-3.f, 0.f);
    this->moving = true;
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
    this->model.move(3.f, 0.f);
    this->moving = true;
  } 
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) 
  {
    this->model.move(0.f, 3.f);
    this->moving = true;
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
    this->model.move(0.f, -3.f);
    this->moving = true;
  }
}

void Player::updateAnimations() {
  if (this->animationTimer.getElapsedTime().asSeconds() >= 0.5f) {
  if (this->moving == false) { //idle
    this->currentFrame.left += 85.f;
    if (this->currentFrame.left >= 512.f)
      this->currentFrame.left = 0;
  }
  }
  this->animationTimer.restart();
  this->model.setTextureRect(this->currentFrame);
}

void Player::update() {
  this->updateMovement();
  this->updateAnimations();
}

void Player::render(sf::RenderTarget & target)
{
  target.draw(this->model);
}