#include "foxer/abstract_components/event_area.hpp"

namespace fox {

EventArea::EventArea(){

}

EventArea::EventArea(const TiledJsonObj &data,
          std::unique_ptr<CollisionHandler> collision_handler)
: area(sf::FloatRect(data.x, data.y, data.width, data.height)),
  collision_handler(std::move(collision_handler))
{}

void EventArea::verify_collision(const sf::FloatRect &what){
  if(area.intersects(what))
    collision_handler->handle_collision();
}

}
