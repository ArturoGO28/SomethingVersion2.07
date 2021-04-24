#include "Game.h"
#include "libs.h"

void Game::initWindow() {
  this->window.create(sf::VideoMode(800, 600), "Project: SOMETHING",
                      sf::Style::Close | sf::Style::Titlebar);
  this->window.setFramerateLimit(60);
}

void Game::initPlayer() { this->player = new Player(); }

// void Game::initPlatform() {
//   this->platform = new Platform();
// }
void Game::initTile() {this->tile = new Tile();}

Game::Game() {
  this->initWindow();
  this->initPlayer();
  this->initTile();
  // this->initPlatform();
}

Game::~Game() { 
  delete this->player;
  delete this->tile; 
}

void Game::updatePlayer() { this->player->update(); }

// void Game::updatePlatform() {
//   this->platform->GetCollider().checkCollision(player->GetCollider(), 1.0f);
//   this->platform->updatePlatform(player);
// }
// Checks if game is closed and updates all game events.

void Game::updateTileMap() {this->tile->updateTilemap();}
  

void Game::updateCollision() {
  // Collision bottom of screen
  if (this->player->getPosition().y + this->player->getGlobalBounds().height >
      this->window.getSize().y) {
    this->player->resetVelocityY();
    this->player->setPosition(
        this->player->getPosition().x,
        this->window.getSize().y - this->player->getGlobalBounds().height);
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
    nextPos.left += this->player->getVelocity().x;
    nextPos.top += this->player->getVelocity().y;

    if (tileBounds.intersects(nextPos) && tile_is_space.at(tile_iteration) == 0) {

      // Right collision
       if (playerBounds.left < tileBounds.left
            && playerBounds.left + playerBounds.width < tileBounds.left + tileBounds.width
            && playerBounds.top < tileBounds.top + tileBounds.height
            && playerBounds.top + playerBounds.height > tileBounds.top)
        {
          this->player->resetVelocityX();
          this->player->setPosition(tileBounds.left - playerBounds.width, this->player->getPosition().y);
        }
      // Left collision
        else if (playerBounds.left > tileBounds.left
            && playerBounds.left + playerBounds.width > tileBounds.left + tileBounds.width
            && playerBounds.top < tileBounds.top + tileBounds.height
            && playerBounds.top + playerBounds.height > tileBounds.top)
        {
          this->player->resetVelocityX();
          this->player->setPosition(tileBounds.left + tileBounds.width, this->player->getPosition().y);
        }
      // Bottom collision
        if (playerBounds.top < tileBounds.top
            && playerBounds.top + playerBounds.height < tileBounds.top + tileBounds.height
            && playerBounds.left < tileBounds.left + tileBounds.width
            && playerBounds.left + playerBounds.width > tileBounds.left)
        {
          this->player->resetVelocityY();
          this->player->setPosition(this->player->getPosition().x, tileBounds.top - playerBounds.height);
        }
      // Top collision
        else if (playerBounds.top > tileBounds.top
            && playerBounds.top + playerBounds.height > tileBounds.top + tileBounds.height
            && playerBounds.left < tileBounds.left + tileBounds.width
            && playerBounds.left + playerBounds.width > tileBounds.left)
        {
          this->player->resetVelocityY();
          this->player->setPosition(this->player->getPosition().x, tileBounds.top + tileBounds.height);
        }
    }
    tile_iteration++;
  }
}

void Game::update() {
  // Tracks window events
  while (this->window.pollEvent(this->event)) {
    if (this->event.type == sf::Event::Closed)
      this->window.close();
    else if (this->event.type == sf::Event::KeyPressed &&
             this->event.key.code == sf::Keyboard::Escape)
      this->window.close();
  }
  this->updatePlayer();
  // this->updatePlatform();
  this->updateTileMap();
  this->updateCollision();
}

void Game::renderPlayer() { this->player->render(this->window); }

// void Game::renderPlatform() {
//   this->platform->render(this->window);
// }
void Game::renderTileMap() {
  this->tile->renderTilemap(this->window);
}

void Game::render() {
  this->window.clear(sf::Color{55, 55, 55, 127});

  // Render game
  this->renderPlayer();
  this->renderTileMap();
  // this->renderPlatform();

  this->window.display();
}

const sf::RenderWindow &Game::getWindow() const { return this->window; }
