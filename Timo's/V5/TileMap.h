#ifndef TILEMAP_H
#define TILEMAP_H


class TileMap : public sf::Drawable, public sf::Transformable
{

public:
  TileMap(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
  ~TileMap();


  bool initTexture(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
  //Functions
  // void initMap();
  // void update();
  void render();


        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &tileset;

        // draw the vertex array
        target.draw(vertices, states);
    }
  sf::VertexArray vertices;
  sf::Texture tileset;
};

#endif