#include "libs.h"
#include "Game.h"


int width = 16;
int height = 12;
int solid = 11;
  int tilenum[] = {0,0,0,0};
  int indices[] = {0,0,0,0};
   const int level[] =
    {
        11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        11, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11, 12, 11, 11, 11, 11,
        12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
        11, 12, 11, 11, 12, 11, 11, 11, 11, 11, 12, 12, 12, 11, 11, 11,
        11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 11, 11,
        11, 11, 12, 11, 11, 11, 12, 12, 11, 11, 12, 12, 12, 12, 12, 11,
        12, 11, 12, 11, 11, 11, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12,
        11, 11, 12, 11, 11, 12, 12, 12, 11, 11, 11, 11, 12, 12, 12, 12,
        11, 11, 12, 11, 11, 12, 12, 12, 11, 11, 11, 11, 12, 12, 12, 12,
        11, 11, 12, 11, 11, 12, 12, 12, 11, 11, 11, 11, 12, 12, 12, 12,
        11, 11, 12, 11, 11, 12, 12, 12, 11, 11, 11, 11, 12, 12, 12, 12,
        11, 11, 12, 11, 11, 12, 12, 12, 11, 11, 11, 11, 12, 12, 12, 12,
    };

void Game::initWindow() {
   this->window.create(sf::VideoMode(1024,768), "Project: SOMETHING", sf::Style::Close | sf::Style::Titlebar);
   this->window.setFramerateLimit(60);
   this->window.setKeyRepeatEnabled(false); 
}

void Game::initPlayer() {
  this->player = new Player();
}

 void Game::initMap() {

  this->map = new TileMap("tileset.png", sf::Vector2u(64, 64), level, width, height);
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

// bool Game::CheckCollision(sf::RenderWindow & window,Player & player) {
//   if (player.getPosition().y + player.getGlobalBounds().height > window.getSize().y) {
//     return true;
//   }
//   return false;
// }

void Game::update() {
  // Tracks window events
  while(this->window.pollEvent(this->event)) {
    if(this->event.type == sf::Event::Closed)
      this->window.close();
    else if(this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape)
      this->window.close();
  }
  this->updatePlayer();
  // this->getTilenum();
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

// void Game::getTilenum() {

//     bool collision = false;
//     sf::FloatRect nextPos;
//     sf::FloatRect playerBounds = this->player->getGlobalBounds();
//     nextPos = playerBounds;
//     nextPos.left += this->player->getVelocity().x;
//     nextPos.top += this->player->getVelocity().y;

//   int i = nextPos.top / 64;
//   int j = nextPos.left / 64;
//   tilenum[0] = level[i + j * width];
//   indices[0] = i + j * width;

//   i = (nextPos.top) / 64;
//   j = (nextPos.left + nextPos.width) / 64;
//   tilenum[1] = level[i + j * width];
//    indices[1] = i + j * width;

//   i = (nextPos.top + nextPos.height) / 64;
//   j = nextPos.left / 64;
//   tilenum[2] = level[i + j * width];
//    indices[2] = i + j * width;

//   i = (nextPos.top + nextPos.height) / 64;
//   j = (nextPos.left + nextPos.width) / 64;
//   tilenum[3] = level[i + j * width];
//    indices[3] = i + j * width;

//   for (int k = 0; k<4; k++) {
//     if (tilenum[k] == 11) {
//        // std::cout << "Collision" << '\n';
//        this->player->resetVelocityY();
//       collision = true;

//     }
   
//   }
//   // std::cout << "No" << '\n';
//   collision = false;


  // if (collision == true) {

  // }

// }

const sf::RenderWindow & Game::getWindow() const
{
  return this->window;
}

// const Player* Game::getPlayer() const
// {
//   return player;
// }

