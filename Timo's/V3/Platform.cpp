#include "Platform.h"

void Platform::initMapTexture() {
 if (!this->mapSheet.loadFromFile("sprite_sheet1.png"))
    std::cout << "ERROR IN PLAYER.CPP: Could not load player sheet!" << "\n";
}

void Platform::initSpriteMap() {
  this->block.setTexture(this->mapSheet);
  this->spriteNum = sf::IntRect(0,0,512/13,512/13); // First frame size
  this->block.setTextureRect(this->spriteNum); //How much of the sheet we want to render.
  // this->block.setOrigin()
}

Platform::Platform() {

  this->initMapTexture();
  this->initSpriteMap();
  // body.setSize(size);
  // body.setOrigin(size / 2.0f);
  // body.setTexture(texture);
  // body.setPosition(pos);


}
Platform::~Platform() {

}

void Platform::render(sf::RenderTarget & target)
{
  target.draw(this->block);
}