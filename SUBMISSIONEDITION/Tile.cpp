#include "Tile.h"
#include "libs.h"
using std::cout;

// Returns the tilemap as a vector of rectangle shapes
const std::vector<sf::RectangleShape> Tile::get_Tiles() const {
  return this->tiles;
}

// Returns a vector of integers containing information on what
// is the type of the corresponding tile in "tiles"
const std::vector<int> Tile::get_Tile_is_space() const {
  return this->tile_is_space;
}

// Updates the tilemap (arrangement of tiles and tile types) 
// in the game (is not used for levels game)
void Tile::updateTilemap() {}

// Takes in an array of integers (either 11, 12, or 13) of size 192 to
// initialize the tilemap for each level
Tile::Tile(int level[]) {
    // Makes current tilemap empty
  this->tiles = {};
  this->tile_is_space = {};

  sf::RectangleShape current_tile;
  
  // For loop to go through every value in the level[] array
  for (int i = 0; i < 192; i++) {
    int x = i % 16;
    // x-coordinate of the tile is 192 % 16 (map is 16 tiles wide)
    int y = i / 16;
    // y-coordinate of the tile is 192 / 16 (map is 12 tiles high)
    // if-statements to determine the type of tile
    // if tile is represented by integer 11 in the level array, the tile
    // is blue and is type 1 (meaning empty space) 
    if (level[i] == 11) {
      tile_is_space.push_back(1);
      current_tile.setFillColor(sf::Color{55 , 55 , 55, 0});
      // if tile is represented by integer 12 in the level array, the tile
      // is is type 0 (meaning obstacle)
    } else if (level[i] == 12) {
      tile_is_space.push_back(0);
      current_tile.setFillColor(sf::Color::Green);
      // if tile is represented by integer 13 in the level array, the tile
      // is type 2 (meaning goal tile) 
    } else if (level[i] == 13) {
      tile_is_space.push_back(2);
      current_tile.setFillColor(sf::Color::Red);
    }
    // set position of tile as x position * 64 and y position * 64 since
    // each tile is 64 x 64 big
    current_tile.setSize(sf::Vector2f(64, 64));
    current_tile.setPosition(x * 64, y * 64);
    // add the tile to the tilemap
    this->tiles.push_back(current_tile);
  }
  // calls the initTexture function to load the texture for the tiles;
  // This is only called once in the Tile constructor because loading
  // several textures slows down the game.
  this->initTexture();
}

Tile::~Tile() {}

// Loads the texture for the tiles and checks if it worked
void Tile::initTexture() {
  if (!this->texture.loadFromFile("sprite_sheet1.png", 
    sf::IntRect(xnum, ynum, xwidth, ywidth))) {
    cout << "Failed to load the sprite sheet" << '\n';
  }
}

void Tile::renderTilemap(sf::RenderTarget &target) {
  // Add texture and render each tile
  for (auto &current_tile : this->tiles) {
    current_tile.setTexture(&(this->texture));
    target.draw(current_tile);
  }
}