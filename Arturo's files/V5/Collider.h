#ifndef COLLIDER_H
#define COLLIDER_H
#include "libs.h"

class Collider {
public:
  Collider(sf::RectangleShape& body);
  ~Collider();

  void Move(float dx, float dy) {
    body.move(dx, dy);
  }

  bool checkCollision(Collider& object, float push);
  sf::Vector2f getPosition() {
    return body.getPosition();
  }
  sf::Vector2f GetHalfSize() {
    return body.getSize() / 2.0f;
  }


  sf::RectangleShape& body;

};

#endif