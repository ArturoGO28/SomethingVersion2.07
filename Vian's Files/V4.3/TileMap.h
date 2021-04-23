#ifndef TILEMAP_H
#define TILEMAP_H

#include"Tile.h"

class TileMap
{
private:
  std::vector< std::vector<Tile*> > tiles;

public:
  TileMap();
  ~TileMap();

  //Functions
  void addTile(unsigned x, unsigned y);
  void removeTile(unsigned x, unsigned y);

  std::vector<std::vector<Tile*> > get_tiles() {
    return tiles;
  }

  void update();
  void render();
};

#endif