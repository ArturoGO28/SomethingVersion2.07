#include "libs.h"
#include "Game.h"


void Game::initWindow() {
   this->window.create(sf::VideoMode(800,600), "Project: SOMETHING", sf::Style::Close | sf::Style::Titlebar);
   this->window.setFramerateLimit(60);
}

void Game::initPlayer() {
  this->player = new Player();
}

Game::Game() {
  this->initWindow();
  this->initPlayer();
}

Game::~Game() {
  delete this->player;
}


void Game::updatePlayer() {
  this->player->update();
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
}

void Game::renderPlayer() {
  this->player->render(this->window);
}

void Game::render() {
  this->window.clear(sf::Color{55,55,55, 127});

  //Render game
  this->renderPlayer();

  this->window.display();
}

const sf::RenderWindow & Game::getWindow() const
{
  return this->window;
}
