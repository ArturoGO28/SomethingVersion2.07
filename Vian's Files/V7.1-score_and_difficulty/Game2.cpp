

#include "Game2.h"
#include "libs.h"


int level[] = {
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 12, 12, 11, 11, 11, 12, 12, 11, 11, 11, 12, 12, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 12, 12, 12, 12, 11, 11, 12, 12, 12, 12, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 11, 11, 11, 11, 11, 11,
    12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12,
    12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 
    12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 
    12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
};

void Game2::initVariables() {
  this->end = false;
  this->done = false;
}

void Game2::initWindow() {
  this->window.create(sf::VideoMode(1024, 768), "Project: SOMETHING",
                      sf::Style::Close | sf::Style::Titlebar);
  this->window.setFramerateLimit(60);
}

void Game2::initPlayer() { this->player = new Player2(); }

void Game2::initTile(int * level) { this->tile = new Tile2(level); }

Game2::Game2() {
  this->initWindow();
  this->initPlayer();
  this->initTile(level);
  this->initVariables();
}

Game2::~Game2() {
  delete this->player;
  delete this->tile;
}

void Game2::updatePlayer() { this->player->update(); }

void Game2::updateTileMap() { 
  this->tile->updateTilemap(); 
}

void Game2::updateCollision() {
  // Checks for collision between player and bottom of screen
  if (this->player->getPosition().y + this->player->getGlobalBounds().height >
      this->window.getSize().y) {
    this->player->resetVelocityY();

    // If there is a collision at the bottom of the screen, 
    //set jumping to false to allow the player to jump again
    this->player->jumping = false;
    this->player->setPosition(
        this->player->getPosition().x,
        this->window.getSize().y - this->player->getGlobalBounds().height);
    this->end = true;
  }

  // Checks for collision between player and top of screen
  if (this->player->getPosition().y < 0.f) {
    this->player->resetVelocityY();
    this->player->setPosition(this->player->getPosition().x, 0.f);
  }

  // Checks for collision between player and right area of screen
  if (this->player->getPosition().x + this->player->getGlobalBounds().width >
      this->window.getSize().x) {
    this->player->resetVelocityX();
    this->player->setPosition(
        this->window.getSize().x - this->player->getGlobalBounds().width,
        this->player->getPosition().y);
  }

  // Checks for collision between player and left area of screen
  if (this->player->getPosition().x < 0.f) {
    this->player->resetVelocityX();
    this->player->setPosition(0.f, this->player->getPosition().y);
  }

  // Run a for loop to check for intersections between the player and each tile in the tilemap
  std::vector<sf::RectangleShape> tiles = this->tile->get_Tiles();
  std::vector<int> tile_is_space = this->tile->get_Tile_is_space();
  sf::RectangleShape current_tile;
  int tile_iteration = 0;
  
  for (auto &current_tile : tiles) {
    sf::FloatRect playerBounds = this->player->getGlobalBounds();
    sf::FloatRect tileBounds = current_tile.getGlobalBounds();
    
    // if a tile of tile_is_space type 0 intersects with the player, run further if-statements
    // to check how the player collides with the tile
    if (tileBounds.intersects(playerBounds) &&
      tile_is_space.at(tile_iteration) == 0) {

      // Boolean statement to check for collision between
      // bottom side of player with the tile
      bool bottom_of_player = playerBounds.top < tileBounds.top
					&& playerBounds.top + playerBounds.height < tileBounds.top + tileBounds.height
					&& playerBounds.left < tileBounds.left + tileBounds.width
					&& playerBounds.left + playerBounds.width > tileBounds.left;

        // Checks for collision between bottom side of player and the tile,
        // if true: resets vertical velocity and sets player position 
        // exactly above the tile
				if (bottom_of_player)
				{
					this->player->resetVelocityY();

          // If there is a collision between the bottom of player and tile, 
          //set jumping to false to allow the player to jump again 
          this->player->jumping = false;
					this->player->setPosition(playerBounds.left, tileBounds.top - playerBounds.height);
				}
    }
    tile_iteration++;
  }
}

void Game2::updateLevel() {
  if (this->end == true && this->done ==false) {
      this->score = this->tile->chance_difficulty;
      delete this->tile;
      int final[] = {
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 12, 12, 12, 11, 12, 11, 12, 11, 11, 12, 11, 11, 11,
    11, 11, 11, 12, 11, 11, 11, 12, 11, 12, 12, 11, 12, 11, 11, 11,
    11, 11, 11, 12, 11, 11, 11, 12, 11, 12, 11, 12, 12, 11, 11, 11,
    11, 11, 11, 12, 12, 11, 11, 12, 11, 12, 11, 11, 12, 11, 11, 11,
    11, 11, 11, 12, 11, 11, 11, 12, 11, 12, 11, 11, 12, 11, 11, 11,
    11, 11, 11, 12, 11, 11, 11, 12, 11, 12, 11, 11, 12, 11, 11, 11,
    11, 11, 11, 12, 11, 11, 11, 12, 11, 12, 11, 11, 12, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
};
  this->initTile(final);
  this->done = true;
  }
}


void Game2::update() {

  while (this->window.pollEvent(this->event)) {
    if (this->event.type == sf::Event::Closed)
      this->window.close();
    else if (this->event.type == sf::Event::KeyPressed &&
             this->event.key.code == sf::Keyboard::Escape)
      this->window.close();
  }
    this->updatePlayer();
    this->updateCollision();
    this->updateLevel();
   if (this->player->jumping == true && this->player->getVelocity().y == 0 && this->end == false) {
    this->updateTileMap();
    this->tile->chance_difficulty += 0.05;
   }

}

void Game2::renderPlayer() { this->player->render(this->window); }

void Game2::renderTileMap() { this->tile->renderTilemap(this->window); }

void Game2::render() {
  this->window.clear(sf::Color{55, 55, 55, 117});

  this->renderTileMap();
  this->renderPlayer();
  if (this->done == true) {
    sf::Font font;
    font.loadFromFile("/usr/share/fonts/truetype/ubuntu/UbuntuMono-B.ttf");
    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setPosition(192, 0);
    text.setCharacterSize(100);
    text.setString("Score: " + std::to_string((int)(this->score*1000)));
    this->window.draw(text);
  }

  this->window.display();
}

const sf::RenderWindow &Game2::getWindow() const { return this->window; }
