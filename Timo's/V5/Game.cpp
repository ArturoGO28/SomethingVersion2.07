#include "libs.h"
#include "Game.h"




void Game::initWindow() {
   this->window.create(sf::VideoMode(1024,768), "Project: SOMETHING", sf::Style::Close | sf::Style::Titlebar);
   this->window.setFramerateLimit(60);
}

void Game::initPlayer() {
  this->player = new Player();
}

 void Game::initMap() {
   const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };
  this->map = new TileMap("tileset.png", sf::Vector2u(64, 64), level, 16,12);
}



Game::Game() {
  this->initMap();
  this->initWindow();
  this->initPlayer();

}

Game::~Game() {
  delete this->player;
}


void Game::updatePlayer() {
  this->player->update();
}


void Game::updateCollision()
{
  //Collision bottom of screen
  if (this->player->getPosition().y + this->player->getGlobalBounds().height > this->window.getSize().y)
  {
    this->player->resetVelocityY();
    this->player->setPosition(
      this->player->getPosition().x,
      this->window.getSize().y - this->player->getGlobalBounds().height
    );
  }
}

void Game::update() {
  // Tracks window events
  while(this->window.pollEvent(this->event)) {
    if(this->event.type == sf::Event::Closed)
      this->window.close();
    else if(this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape)
      this->window.close();
  }
  this->updatePlayer();

  this->updateCollision();
}

void Game::renderPlayer() {
  this->player->render(this->window);
}

void Game::renderTileMap() {
  sf::RenderStates states;
  this->map->draw(this->window, states);
}

void Game::render() {
  this->window.clear(sf::Color{55,55,55, 127});

  //Render game
    this->renderTileMap();
  this->renderPlayer();



  this->window.display();
}

const sf::RenderWindow & Game::getWindow() const
{
  return this->window;
}
