// Definition of the platform class. Includes basic one room map for the game

#include <SFML/Graphics.hpp>
#include <iostream>
using std::cin;
using std::cout;

int main (int argc, char **argv) {
  sf::RenderWindow window(sf::VideoMode(640,480), "Basic Platform");
  sf::RectangleShape rectangle(sf::Vector2f(128, 128));
  // rectangle.setFillColor(sf::Color::Red);
  // rectangle.setOrigin(64, 64);
  // rectangle.setPosition(320, 240);
  sf::Texture texture;
  int spriterow = 5;
  int spritecolumn = 4;
  float xwidth = 512/13;
  float ywidth = 512/13;
  float xnum = (spritecolumn * 512) / 13;
  float ynum = (spriterow * 512) / 13;


  if (!texture.loadFromFile("/media/sf_EC327/groupproject/sprite_sheet1.png", 
    sf::IntRect(xnum, ynum, xwidth, ywidth))) {
    cout << "Failed to load the sprite sheet" << '\n';
  }
  sf::Sprite sprite1(texture);
  sf::Sprite sprite2(texture);
  sf::Sprite sprite3(texture);
  sf::Sprite sprite4(texture);
  sf::Sprite sprite5(texture);
  sprite1.setPosition(0 , 400);
  sprite2.setPosition(xwidth, 400);
  sprite3.setPosition((xwidth) * 2, 400);
  sprite4.setPosition((xwidth) * 4 , 300);
  sprite5.setPosition((xwidth) * 5 , 300);
  // Create the game loop
  while (window.isOpen()) {
    sf::Event event;
    // Create the event loop polling events
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    window.clear(sf::Color::Black);
    // window.draw(rectangle);
    window.draw(sprite1);
    window.draw(sprite2);
    window.draw(sprite3);
    window.draw(sprite4);
    window.draw(sprite5);
    window.display();
  }
  return 0;
}