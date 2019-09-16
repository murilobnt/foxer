#ifndef COMMON_LEVEL_HPP
#define COMMON_LEVEL_HPP

#include <gs2d/scene/components/camera/camera.hpp>
#include <gs2d/scene/components/object/main_object.hpp>

class CommonLevel {
protected:
  sf::Vector2f *delay;

public:
  CommonLevel();
  CommonLevel(sf::Vector2f *delay);

  void stop_character(gs::MainObject *character, gs::Camera *camera,
                      const float &delta_time);
  void initialise_camera(gs::MainObject *character, gs::Camera *camera,
                         const int &fading_speed);
  void adjust_camera(gs::Camera *camera, const sf::Vector2u level_size,
                     const sf::Vector2u tile_size);
};

#endif
