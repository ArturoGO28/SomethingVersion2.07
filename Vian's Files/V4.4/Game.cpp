#include "Game.h"

#include "Collider.cpp"
#include "Tilemap.cpp"
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

Game::Game() {
  this->initWindow();
  this->initPlayer();
  // this->initPlatform();
}

Game::~Game() { delete this->player; }

void Game::updatePlayer() { this->player->update(); }

// void Game::updatePlatform() {
//   this->platform->GetCollider().checkCollision(player->GetCollider(), 1.0f);
//   this->platform->updatePlatform(player);
// }
// Checks if game is closed and updates all game events.

std::vector<sf::RectangleShape> Game::updateTileMap() {
  std::vector<sf::RectangleShape> tiles;
  sf::RectangleShape tile;
  tile.setFillColor(sf::Color::Green);
  tile.setSize(sf::Vector2f(512 / 13, 512 / 13));
  tile.setPosition(500, 500);
  tiles.push_back(tile);
  return tiles;
}

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
  std::vector<sf::RectangleShape> tiles = updateTileMap();
  sf::RectangleShape tile;
 
  sf::FloatRect nextPos;
  for (auto &tile : tiles) {
    sf::FloatRect playerBounds = this->player->getGlobalBounds();
    sf::FloatRect tileBounds = tile.getGlobalBounds();

    nextPos = playerBounds;
    nextPos.left += this->player->getVelocity().x;
    nextPos.top += this->player->getVelocity().y;

    if (tileBounds.intersects(nextPos)) {

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
  this->updateCollision();
}

void Game::renderPlayer() { this->player->render(this->window); }

// void Game::renderPlatform() {
//   this->platform->render(this->window);
// }
void Game::renderTileMap() {
  std::vector<sf::RectangleShape> tiles = updateTileMap();
  for (auto &tile : tiles) window.draw(tile);
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
