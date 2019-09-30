#include "foxer/time/timed_entity.hpp"

namespace fox {

TimedEntity::TimedEntity() {}
TimedEntity::TimedEntity(sf::Time update_rate) : time_handler(update_rate) {}
TimeHandler *TimedEntity::get_time_handler() { return &time_handler; }
void TimedEntity::time_trigger() {
  if (time_handler.time_to_update())
    on_update_time();
}
void TimedEntity::reset_last_update() { time_handler.reset_last_update(); }
void TimedEntity::ready_to_update() { time_handler.ready_to_update(); }

} // namespace fox
