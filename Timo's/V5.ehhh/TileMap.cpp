#include "libs.h"
#include "Tilemap.h"

TileMap::TileMap(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{
  this->initTexture(tileset,tileSize,tiles,width,height);

}

TileMap::~TileMap()
{
}


bool TileMap::initTexture(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height) {
  if (!this->tileset.loadFromFile(tileset)) {
    std::cout << "ERROR IN TILEMAP.CPP: Could not load tiletexture sheet!" << "\n";
    return false;
  }

  this->vertices.setPrimitiveType(sf::Quads);
  this->vertices.resize(width * height * 4);

  for (unsigned int i = 0; i < width; ++i)
    for (unsigned int j = 0; j < height; ++j) {
      int tileNumber = tiles[i + j * width];

      int textX = tileNumber % (this->tileset.getSize().x / tileSize.x);
      int textY = tileNumber / (this->tileset.getSize().x / tileSize.x);

      sf::Vertex* quad = &this->vertices[(i + j * width) * 4];

      quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
      quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
      quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
      quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

      // define its 4 texture coordinates
      quad[0].texCoords = sf::Vector2f(textX * tileSize.x, textY * tileSize.y);
      quad[1].texCoords = sf::Vector2f((textX + 1) * tileSize.x, textY * tileSize.y);
      quad[2].texCoords = sf::Vector2f((textX + 1) * tileSize.x, (textY + 1) * tileSize.y);
      quad[3].texCoords = sf::Vector2f(textX * tileSize.x, (textY + 1) * tileSize.y);
    }
  return true;
}

// void TileMap::update()
// {
// }

// void TileMap::initMap() {

// }

void TileMap::render()
{
  // target.draw(this->map);
}