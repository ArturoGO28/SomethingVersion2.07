#include "libs.h"
#include "Game.h"
#include "Collider.h"



void Game::initWindow() {
   this->window.create(sf::VideoMode(800,600), "Project: SOMETHING", sf::Style::Close | sf::Style::Titlebar);
   this->window.setFramerateLimit(30);
}

void Game::initPlayer() {
  this->player = new Player();
}

void Game::initPlatform() {
  this->platform = new Platform();
}

Game::Game() {
  this->initWindow();
  this->initPlayer();
  this->initPlatform();
}

Game::~Game() {
  delete this->player;
}


void Game::updatePlayer() {
  this->player->update();
}

// Checks if game is closed and updates all game events.
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

void Game::renderPlatform() {
  this->platform->render(this->window);
}

void Game::render() {
  this->window.clear(sf::Color{55,55,55, 127});

  //Render game
  this->renderPlayer();
  this->renderPlatform();

  this->window.display();
}

const sf::RenderWindow & Game::getWindow() const
{
  return this->window;
}
