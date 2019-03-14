#include "gs2d/time/timed_entity.hpp"

namespace gs {

TimedEntity::TimedEntity() {}
TimedEntity::TimedEntity(sf::Time update_rate) : time_handler(update_rate) {}
TimeHandler *TimedEntity::get_time_handler() { return &time_handler; }
void TimedEntity::time_trigger() {
  if (time_handler.time_to_update())
    on_update_time();
}

} // namespace gs
