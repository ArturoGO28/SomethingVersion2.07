#include "Collider.h"
using std::abs;

Collider::Collider(sf::RectangleShape& body) : 
  body(body)
  {
}

Collider::~Collider() {

}

bool Collider::checkCollision(Collider & object, float push) {
  sf::Vector2f objectPos = object.getPosition();
  sf::Vector2f objectHalfSize = object.GetHalfSize();
  sf::Vector2f thisPos = getPosition();
  sf::Vector2f thisHalfSize = GetHalfSize();

  float deltaX = objectPos.x - thisPos.x;
  float deltaY = objectPos.y - thisPos.y;

  float intersectX = abs(deltaX) - (objectHalfSize.x + thisHalfSize.x);
  float intersectY = abs(deltaY) - (objectHalfSize.y + thisHalfSize.y);

  if(intersectX < 0.0f && intersectY < 0.0f) {
    push = std::min(std::max(push,0.0f), 1.0f);

    if(intersectX > intersectY) {
      if(deltaX > 0.0f) {
        Move(intersectX * (1.0 - push), 0.0f);
        object.Move(-intersectX * push, 0.0f);
      } else {
        Move(-intersectX * (1.0 - push), 0.0f);
        object.Move(intersectX * push, 0.0f);
      }
    } else {
        if(deltaY > 0.0f) {
          Move(0.0f, intersectY * (1.0 - push));
          object.Move(0.0f, -intersectY * push);
        } else {
          Move(0.0f, -intersectY * (1.0 - push));
          object.Move(0.0f, intersectY * push);
      }
    }

    return true;
  }
  return false;
}