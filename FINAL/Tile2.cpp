#include "Tile2.h"
#include "libs.h"
#include <iostream>
using std::cout;

// Returns the tilemap as a vector of rectangle shapes
const std::vector<sf::RectangleShape> Tile2::get_Tiles() const {
  return this->tiles;
}

// Returns a vector of integers containing information on what
// is the type of the corresponding tile in "tiles"
const std::vector<int> Tile2::get_Tile_is_space() const {
  return this->tile_is_space;
}

// Updates the tilemap (arrangement of tiles and tile types) 
// in the game
void Tile2::updateTilemap() {

  // Initialize temporary new tilemap vector
  std::vector<sf::RectangleShape> new_tiles = {};

  // Initialize temporary new tile_is_space vector
  std::vector<int> new_tile_is_space = {};
  int tiles_size = this->tiles.size();

  sf::RectangleShape current_tile;

  // For loop to go through each tile from the game tilemap "tiles" vector and set them 
  // down a row vertically in the temporary tilemap vector (down by 64)
  for (int i = 0; i < tiles_size; i++) {
    current_tile = this->tiles[i];
    current_tile.setPosition(current_tile.getPosition().x, current_tile.getPosition().y + 64);
    new_tiles.push_back(current_tile);
    new_tile_is_space.push_back(this->tile_is_space[i]);
  }

  // For loop to go through 16 tiles in the empty first row of the temporary tilemap vector
  for (int x = 0; x < 16; x++) {
    // Tile randomizer makes 1/10 chance of getting a magenta obstacle tile on the next level
    int tile_randomizer = rand() % 10;
    // If the tile randomizer is more than zero, the tile becomes a blue empty space tile
    // with a corresponding tile_is_space representation of integer 1 in the temporary new
    // tile_is_space vector
    if (tile_randomizer > 0) {
      current_tile.setFillColor(sf::Color::Blue);
      new_tile_is_space.insert(new_tile_is_space.begin(), 1);
    } else {
      // Otherwise, the tile becomes a magenta obstacle tile
      // with a corresponding tile_is_space representation of integer 0 in the temporary new
      // tile_is_space vector
      current_tile.setFillColor(sf::Color::Magenta);
      new_tile_is_space.insert(new_tile_is_space.begin(), 0);
    }
    // Set the position of the tile as the x-coordinate * 64 at the first row of the tilemap
    current_tile.setPosition(x * 64, 0);

    // Insert the tile at the beginning of the temporary tilemap vector
    new_tiles.insert(new_tiles.begin(), current_tile);
  }
  // Set the actual game tilemap "tiles" vector and actual game tile_is_space vector equal to
  // the temporary tilemap vector and the temporary tile_is_space vector 
  this->tiles = new_tiles;
  this->tile_is_space = new_tile_is_space;
}

// Takes in an array of integers (either 11 or 12) of size 192 to
// initialize the tilemap for each level
Tile2::Tile2(int level[]) {

  // Makes current tilemap empty
  this->tiles = {};
  this->tile_is_space = {};

  sf::RectangleShape current_tile;

  // For loop to go through every value in the level[] array
  for (int i = 0; i < 192; i++) {

    // x-coordinate of the tile is 192 % 16 (map is 16 tiles wide)
    int x = i % 16;
    // y-coordinate of the tile is 192 / 16 (map is 12 tiles high)
    int y = i / 16;

    // if-statements to determine the type of tile
    // if tile is represented by integer 11 in the level array, the tile
    // is blue and is type 1 (meaning empty space) 
    if (level[i] == 11) {
      tile_is_space.push_back(1);
      current_tile.setFillColor(sf::Color::Blue);

    // if tile is represented by integer 12 in the level array, the tile
    // is magenta and is type 0 (meaning obstacle) 
    } else if (level[i] == 12) {
      tile_is_space.push_back(0);
      current_tile.setFillColor(sf::Color::Magenta);
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

Tile2::~Tile2() {}

// Loads the texture for the tiles and checks if it worked
void Tile2::initTexture() {
  if (!this->texture.loadFromFile("sprite_sheet1.png", 
    sf::IntRect(xnum, ynum, xwidth, ywidth))) {
    cout << "Failed to load the sprite sheet" << '\n';
  }
}

void Tile2::renderTilemap(sf::RenderTarget &target) {
  // Add texture and render each tile
  for (auto &current_tile : this->tiles) {
    current_tile.setTexture(&(this->texture));
    target.draw(current_tile);
  }
}