#include "foxer/other/geared_up/foxer_level.hpp"

namespace fox {

FoxerLevel::FoxerLevel(){}

FoxerLevel::FoxerLevel(const std::string &level_path,
                       LevelBundle *bundle,
                       std::unique_ptr<LevelCollisionVerifier> col_ver)
                       :
                       level_path(level_path),
                       bundle(bundle),
                       col_ver(std::move(col_ver)),
                       tex_holder(bundle->shared_t_holder)
{}

TileMap FoxerLevel::get_layer(int index) const { return data.get_layers().at(index - 1); }

LayerContainer FoxerLevel::get_layers(const int &from, const int &to) const {
  const std::vector<TileMap> layers = data.get_layers();
  return LayerContainer(
      std::vector<TileMap>(layers.begin() + from - 1, layers.begin() + to));
}

LayerContainer FoxerLevel::get_layers() const { return LayerContainer(data.get_layers()); }

void FoxerLevel::load(){
  this->data = TLDLoader::load(level_path, tex_holder, &bundle->camera);
}

void FoxerLevel::handle_events(const float &delta_time){
  bundle->player_ref->control_entity(delta_time);
  // col_ver->verify_collision(*(bundle->player_ref), data.get_collision_tile_grid());
  bundle->player_ref->time_trigger();
  bundle->player_ref->move(delta_time);
}

void FoxerLevel::control_camera(const float &delta_time){
  bundle->camera.move(
      sf::Vector2f((bundle->player_ref->get_sprite_position() - bundle->camera.get_center())) *
      (delta_time * 5));
}

void FoxerLevel::change_level(Level *level) {
  bundle->level_proxy.change_level(level);
}

void FoxerLevel::change_level(std::shared_ptr<Level> level) {
  bundle->level_proxy.change_level(level);
}

void FoxerLevel::set_level_bundle(LevelBundle *bundle) {
  this->bundle = bundle;
  tex_holder = TextureHolder(bundle->shared_t_holder);
}

}
