#include "Game.h"

#include "libs.h"
using std::vector;


int level1[] = {
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 13,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
    11, 11, 11, 11, 11, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 11, 11, 
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
};

int level2[] = {
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12,
    11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 11, 11, 12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11,
    12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 13,
};

int level3[] = {
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 13,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12,
    11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 11, 11, 12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11,
    12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11,
};

int level4[] = {
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 12, 12, 12,
    11, 11, 12, 12, 12, 12, 12, 11, 11, 11, 12, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 12, 11, 11, 11, 11, 12,
    11, 11, 11, 11, 11, 11, 11, 12, 11, 11, 11, 11, 11, 12, 12, 12,
    12, 12, 12, 11, 11, 12, 12, 12, 11, 11, 11, 11, 11, 12, 12, 12,
    12, 12, 12, 11, 11, 12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11,
    12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 13,
};

int level5[] = {
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 13,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12,
    11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 11, 11, 12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11,
    12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11,
};

int level6[] = {
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
    11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12,
    11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
    12, 12, 12, 11, 11, 12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11,
    12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
    12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 13,
};

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

int i = 0;

vector <int *> levels;

void Game::initVariables() {
  this->end = false;
}

void Game::initLevels() {
  levels.push_back(level1);
  levels.push_back(level2);
  levels.push_back(level3);
  levels.push_back(level4);
  levels.push_back(level5);
  levels.push_back(level6);
  levels.push_back(final);
}

void Game::initWindow() {
  this->window.create(sf::VideoMode(1024, 768), "Project: SOMETHING",
                      sf::Style::Close | sf::Style::Titlebar);
  this->window.setFramerateLimit(60);
}

void Game::initPlayer() { this->player = new Player(); }

void Game::initTile(vector <int *> levels) { 
  this->tile = new Tile(levels.at(i)); 
}

Game::Game() {
  this->initWindow();
  this->initPlayer();
  this->initLevels();
  this->initTile(levels);

}

Game::~Game() {
  delete this->player;
  delete this->tile;
}

void Game::updatePlayer() { this->player->update(); }

void Game::updateTileMap() { this->tile->updateTilemap(); }

void Game::updateCollision() {
  // Collision bottom of screen
  if (this->player->getPosition().y + this->player->getGlobalBounds().height >
      this->window.getSize().y) {
    this->player->resetVelocityY();
    this->player->jumping = false;
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

    if (tileBounds.intersects(nextPos) &&
        tile_is_space.at(tile_iteration) == 2) {
      this->end = true;
    }

    if (tileBounds.intersects(nextPos) &&
        tile_is_space.at(tile_iteration) == 0) {
      // Right collision
      if (playerBounds.left < tileBounds.left &&
          playerBounds.left + playerBounds.width <
              tileBounds.left + tileBounds.width &&
          playerBounds.top < tileBounds.top + tileBounds.height &&
          playerBounds.top + playerBounds.height > tileBounds.top) {
        this->player->resetVelocityX();
        this->player->setPosition(tileBounds.left - playerBounds.width,
                                  playerBounds.top);
      }
      // Left collision
      else if (playerBounds.left > tileBounds.left &&
               playerBounds.left + playerBounds.width >
                   tileBounds.left + tileBounds.width &&
               playerBounds.top < tileBounds.top + tileBounds.height &&
               playerBounds.top + playerBounds.height > tileBounds.top) {
        this->player->resetVelocityX();
        this->player->setPosition(tileBounds.left + tileBounds.width,
                                  playerBounds.top);
      }
      // Bottom collision
      if (playerBounds.top < tileBounds.top &&
          playerBounds.top + playerBounds.height <
              tileBounds.top + tileBounds.height &&
          playerBounds.left < tileBounds.left + tileBounds.width &&
          playerBounds.left + playerBounds.width > tileBounds.left) {
        this->player->resetVelocityY();
        this->player->jumping = false;
        this->player->setPosition(playerBounds.left,
                                  tileBounds.top - playerBounds.height);
      }
      // Top collision
      else if (playerBounds.top > tileBounds.top &&
               playerBounds.top + playerBounds.height >
                   tileBounds.top + tileBounds.height &&
               playerBounds.left < tileBounds.left + tileBounds.width &&
               playerBounds.left + playerBounds.width > tileBounds.left) {
        this->player->resetVelocityY();
        this->player->setPosition(playerBounds.left,
                                  tileBounds.top + tileBounds.height);
      }
    }
    tile_iteration++;
  }
}

void Game::updateLevel() {
  if (this->end == true) {
      delete this->tile;
    i++;
    this->initTile(levels);
    this->end = false;
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
  this->updateTileMap();
  this->updateCollision();
  this->updateLevel();
}

void Game::renderPlayer() { this->player->render(this->window); }

void Game::renderTileMap() { this->tile->renderTilemap(this->window); }

void Game::render() {
  this->window.clear(sf::Color{55, 55, 55, 117});

  // Render game
  this->renderTileMap();
  this->renderPlayer();

  this->window.display();
}

const sf::RenderWindow &Game::getWindow() const { return this->window; }