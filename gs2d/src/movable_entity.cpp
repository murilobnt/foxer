#include "gs2d_engine/scene/components/object/movable_object.hpp"

namespace gs {

MovableObject::MovableObject() : can_move_up(true),
                                 can_move_down(true),
                                 can_move_left(true),
                                 can_move_right(true){
    facing_position = DOWN;
    moving_up = false;
    moving_down = false;
    moving_left = false;
    moving_right = false;
}

void MovableObject::nullfy_movement(){
    last_movement = movement;
    movement = sf::Vector2f(0, 0);
}

void MovableObject::set_movement_x(float x){
    movement.x = x;
}
void MovableObject::set_movement_y(float y){
    movement.y = y;
}
void MovableObject::set_movement(sf::Vector2f movement){
    this->movement = movement;
}

sf::Vector2f MovableObject::get_movement() const {
    return movement;
}

}
