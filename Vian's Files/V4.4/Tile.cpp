#include "libs.h"
#include "Tile.h"

Tile::Tile(sf::Texture& mapsheet, sf::IntRect texture_rect, bool damaging)
  : damaging(damaging)
{
  this->sprite.setTexture(mapsheet);
  this->sprite.setTextureRect(texture_rect);
}

const sf::FloatRect Tile::getGlobalBounds() const
{
  return this->sprite.getGlobalBounds();
}

void Tile::update()
{

}

void Tile::render(sf::RenderTarget& target)
{
  target.draw(this->sprite);
}