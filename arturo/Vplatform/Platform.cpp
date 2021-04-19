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
}

Platform::Platform() {

  this->initMapTexture();
  this->initSpriteMap();
  // this->block.setOrigin({19.5f,19.5f});
  this->block.setPosition({200,560});


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