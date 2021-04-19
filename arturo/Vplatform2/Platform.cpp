#include "Platform.h"
#include "Player.h"

void Platform::initMapTexture() {
 if (!mapSheet.loadFromFile("sprite_sheet1.png"))
    std::cout << "ERROR IN PLAYER.CPP: Could not load player sheet!" << "\n";
}


void Platform::initSpriteMap() {
  this->block.setTexture(this->mapSheet);
  this->spriteNum = sf::IntRect(0,0,512/13,512/13); // First frame size
  this->block.setTextureRect(this->spriteNum); //How much of the sheet we want to render.
  // this->block.setOrigin()
  Platform platform(200, 560, block);
  return platform;
}

// // simple block with no collision
// Platform::Platform() {

//   this->initMapTexture();
//   this->initSpriteMap();
//   // this->block.setOrigin({19.5f,19.5f});
//   this->block.setPosition({200,560});
// }

  // this constructor has to be called and passed the necessary components
Platform::Platform (int intxPos, int initYPos, Sprite sprite) {
  scale = 3;
  image = sprite;
  image.setPosition(initXPos, initYPos);
  image.setScale(scale, scale);
  leftSide = image.getPosition().x;
  rightSide = image.getPosition().x + (image.getLocalBounds().width * scale);
  topSide = image.getPosition().y;
  bottomSide = image.getPosition().y + (image.getLocalBounds().height * scale);    
}

Platform::~Platform() {
  
}

void Platform::updatePlatform(Player *player) {
  // this->GetCollider().checkCollision(player->GetCollider(),1.0f);
}

void Platform::render(sf::RenderTarget & target)
{
  target.draw(this->block);
}