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
  // Collision bottom of screen
  if (this->player->getPosition().y + this->player->getGlobalBounds().height >
      this->window.getSize().y) {
    this->player->resetVelocityY();
    this->player->jumping = false;
    this->player->setPosition(
        this->player->getPosition().x,
        this->window.getSize().y - this->player->getGlobalBounds().height);
    this->end = true;
  }

  // Collision top of screen
  if (this->player->getPosition().y < 0.f) {
    this->player->resetVelocityY();
    this->player->setPosition(this->player->getPosition().x, 0.f);
  }

  // Collision right of screen
  if (this->player->getPosition().x + this->player->getGlobalBounds().width >
      this->window.getSize().x) {
    this->player->resetVelocityX();
    this->player->setPosition(
        this->window.getSize().x - this->player->getGlobalBounds().width,
        this->player->getPosition().y);
  }

  // Collision left of screen
  if (this->player->getPosition().x < 0.f) {
    this->player->resetVelocityX();
    this->player->setPosition(0.f, this->player->getPosition().y);
  }

  // Collision with tile
  std::vector<sf::RectangleShape> tiles = this->tile->get_Tiles();
  std::vector<int> tile_is_space = this->tile->get_Tile_is_space();
  sf::RectangleShape current_tile;
  int tile_iteration = 0;

  sf::FloatRect nextPos;
  for (auto &current_tile : tiles) {
    sf::FloatRect playerBounds = this->player->getGlobalBounds();
    sf::FloatRect tileBounds = current_tile.getGlobalBounds();

    nextPos = playerBounds;
    // nextPos.left -= this->player->getVelocity().x;
    // nextPos.top -= this->player->getVelocity().y;

    if (tileBounds.intersects(nextPos) &&
      tile_is_space.at(tile_iteration) == 0) {

      bool bottom_of_player = playerBounds.top < tileBounds.top
					&& playerBounds.top + playerBounds.height < tileBounds.top + tileBounds.height
					&& playerBounds.left < tileBounds.left + tileBounds.width
					&& playerBounds.left + playerBounds.width > tileBounds.left;
     //  bool top_of_player = playerBounds.top > tileBounds.top
					// && playerBounds.top + playerBounds.height > tileBounds.top + tileBounds.height
					// && playerBounds.left < tileBounds.left + tileBounds.width
					// && playerBounds.left + playerBounds.width > tileBounds.left;
     //  bool right_of_player = playerBounds.left < tileBounds.left
					// && playerBounds.left + playerBounds.width < tileBounds.left + tileBounds.width
					// && playerBounds.top < tileBounds.top + tileBounds.height
					// && playerBounds.top + playerBounds.height > tileBounds.top;
     //  bool left_of_player = playerBounds.left > tileBounds.left
					// && playerBounds.left + playerBounds.width > tileBounds.left + tileBounds.width
					// && playerBounds.top < tileBounds.top + tileBounds.height
					// && playerBounds.top + playerBounds.height > tileBounds.top;

				// //Right collision
				// if (right_of_player)
				// {
				// 	this->player->resetVelocityX();
				// 	this->player->setPosition(tileBounds.left - playerBounds.width, playerBounds.top);
				// }
				
				// //Left collision
				// else if (left_of_player)
				// {
				// 	this->player->resetVelocityX();
				// 	this->player->setPosition(tileBounds.left + tileBounds.width, playerBounds.top);
				// }

        //Bottom collision
				if (bottom_of_player)
				{
					this->player->resetVelocityY();
          this->player->jumping = false;
					this->player->setPosition(playerBounds.left, tileBounds.top - playerBounds.height);
				}

				// //Top collision
				// else if (top_of_player)
				// {
				// 	this->player->resetVelocityY();
				// 	this->player->setPosition(playerBounds.left, tileBounds.top + tileBounds.height);
				// }
    }
    tile_iteration++;
  }
}

void Game2::updateLevel() {
  if (this->end == true && this->done ==false) {
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
  // Tracks window events
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
   if (this->player->jumping == true && this->player->getVelocity().y == 0 && this->end == false) 
    this->updateTileMap();

}

void Game2::renderPlayer() { this->player->render(this->window); }

void Game2::renderTileMap() { this->tile->renderTilemap(this->window); }

void Game2::render() {
  this->window.clear(sf::Color{55, 55, 55, 117});

  // Render Game2
  this->renderTileMap();
  this->renderPlayer();

  this->window.display();
}

const sf::RenderWindow &Game2::getWindow() const { return this->window; }
