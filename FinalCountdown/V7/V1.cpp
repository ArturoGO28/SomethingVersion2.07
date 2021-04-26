#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>
#include "libs.h"
#include "Game.h"
#include "Game2.h"
using std::cin;
using std::cout;

int main() {
  // Creates game interface window.
  sf::RenderWindow titlewindow(sf::VideoMode(1024, 768), "Game Interface");
  
  // Loads background image.
  sf::Texture background;
  background.loadFromFile("jumpquest2.png");
  sf::Sprite windowbackground(background);

  // Creates button shapes for game options.
  sf::RectangleShape playbutton;
  playbutton.setFillColor(sf::Color::Black);
  playbutton.setSize(sf::Vector2f(350,75));
  playbutton.setPosition(350,200);

  sf::RectangleShape optionsbutton;
  optionsbutton.setFillColor(sf::Color::Black);
  optionsbutton.setSize(sf::Vector2f(350,75));
  optionsbutton.setPosition(350,350);
  
  // Loads font from file.
  sf::Font font;
  font.loadFromFile("/usr/share/fonts/truetype/ubuntu/UbuntuMono-B.ttf");

  // Creates the words to go on the game options buttons.
  sf::Text playword;
  playword.setFont(font);
  playword.setFillColor(sf::Color::White);
  playword.setOutlineColor(sf::Color::Black);
  playword.setOutlineThickness(2);
  playword.setPosition(440, 215);
  playword.setString("PLAY LEVELS");

  sf::Text optionsword;
  optionsword.setFont(font);
  optionsword.setFillColor(sf::Color::White);
  optionsword.setOutlineColor(sf::Color::Black);
  optionsword.setOutlineThickness(2);
  optionsword.setPosition(460, 365);
  optionsword.setString("PLAY JUMP");

  titlewindow.setFramerateLimit(10);

  // Loop occurs until game interface is exited.
  while (titlewindow.isOpen()) {
    sf::Event event;

    // Loop occurs while event (like mouse click) occurs.
    while (titlewindow.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        titlewindow.close();

      if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // Change the mouse position from window coordinates to world coordinates.
        sf::Vector2f mouse = titlewindow.mapPixelToCoords(sf::Mouse::getPosition(titlewindow));

        // Get the bounds (edges) of the two buttons on the interface.
        sf::FloatRect playbounds = playbutton.getGlobalBounds();
        sf::FloatRect optionsbounds = optionsbutton.getGlobalBounds();
        
        // If the first button's bounds contain the coordinates of the mouse press, play the first game.
        if (playbounds.contains(mouse)) {
          titlewindow.close();
          Game game;
          while (game.getWindow().isOpen()) {
            game.update();
            game.render();
          }
        }

        // If the second button's bounds contain the coordinates of the mouse press, play the second game.
        if (optionsbounds.contains(mouse)) {
          titlewindow.close();
           Game2 game;
          while (game.getWindow().isOpen()) {
            game.update();
            game.render();
          }
        }
      }
    }

    // Clear and draw all elements on the interface.
    titlewindow.clear();
    titlewindow.draw(windowbackground);
    titlewindow.draw(playbutton);
    titlewindow.draw(optionsbutton);
    titlewindow.draw(optionsword);
    titlewindow.draw(playword);
    titlewindow.display();
  }
  return 0;
}