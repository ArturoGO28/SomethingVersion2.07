#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>
using std::cin;
using std::cout;

int main() {
  sf::RenderWindow titlewindow(sf::VideoMode(800, 600), "Game Interface");
  
  sf::Texture background;
  background.loadFromFile("imgonline-com-ua-resize-fDYHej58ZaxjLu8.jpg");
  sf::Sprite windowbackground(background);

  sf::RectangleShape playbutton;
  playbutton.setFillColor(sf::Color::Black);
  playbutton.setSize(sf::Vector2f(250,48));
  playbutton.setPosition(275,250);

  sf::RectangleShape optionsbutton;
  optionsbutton.setFillColor(sf::Color::Black);
  optionsbutton.setSize(sf::Vector2f(250,48));
  optionsbutton.setPosition(275,350);

  sf::Font font;
  font.loadFromFile("/usr/share/fonts/truetype/ubuntu/UbuntuMono-B.ttf");

  sf::Text playword;
  playword.setFont(font);
  playword.setFillColor(sf::Color::White);
  playword.setOutlineColor(sf::Color::Black);
  playword.setOutlineThickness(2);
  playword.setPosition(370, 250);
  playword.setString("PLAY");

  sf::Text optionsword;
  optionsword.setFont(font);
  optionsword.setFillColor(sf::Color::White);
  optionsword.setOutlineColor(sf::Color::Black);
  optionsword.setOutlineThickness(2);
  optionsword.setPosition(350, 350);
  optionsword.setString("OPTIONS");

  titlewindow.setFramerateLimit(10);

  while (titlewindow.isOpen()) {
    sf::Event event;
    while (titlewindow.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        titlewindow.close();


      if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // transform the mouse position from window coordinates to world coordinates
        sf::Vector2f mouse = titlewindow.mapPixelToCoords(sf::Mouse::getPosition(titlewindow));

        // retrieve the bounding box of the sprite
        sf::FloatRect playbounds = playbutton.getGlobalBounds();
        sf::FloatRect optionsbounds = optionsbutton.getGlobalBounds();
        // hit test
        if (playbounds.contains(mouse)) {
        // mouse is on sprite!
          playbutton.setFillColor(sf::Color::Green);
          // sf::RenderWindow gamewindow(sf::VideoMode(800, 600), "Playing Game");
          // gamewindow.display();
        }

        if (optionsbounds.contains(mouse)) {
        // mouse is on sprite!
          optionsbutton.setFillColor(sf::Color::Blue);
          titlewindow.close();
          sf::RenderWindow optionswindow(sf::VideoMode(800, 600), "Options");
          optionswindow.setFramerateLimit(10);
          


          while (optionswindow.isOpen()) {
            sf::Event optionevent;
            while (optionswindow.pollEvent(optionevent)) {
              if (optionevent.type == sf::Event::Closed)
                optionswindow.close();

              if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                // transform the mouse position from window coordinates to world coordinates
                sf::Vector2f mouse = optionswindow.mapPixelToCoords(sf::Mouse::getPosition(optionswindow));
              }
            }
            optionswindow.display();
          }
        }


      }


    }
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