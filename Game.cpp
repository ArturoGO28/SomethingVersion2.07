#include "libs.h"
#include "Game.h"


void Game::initWindow() {
   this->window.create(sf::VideoMode(800,600), "Project: SOMETHING", sf::Style::Close | sf::Style::Titlebar);
   this->window.setFramerateLimit(60);
}

// Game::Game() {

// }

// Game::~Game() {

// }
void Game::update() {
  //Tracks window events
  while(this->window.pollEvent(this->event)) {
    if(this->event.type == sf::Event::Closed)
      this->window.close();
    else if(this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape)
      this->window.close();
  }
}

void Game::render() {
  this->window.clear();

  //Render game

  this->window.display();
}

const sf::RenderWindow & Game::getWindow() const
{
  return this->window;
}
