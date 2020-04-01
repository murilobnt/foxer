#include "foxer/abstract_components/foxer_level.hpp"

namespace fox {

FoxerLevel::FoxerLevel(){}

FoxerLevel::FoxerLevel(const std::string &level_path,
                       LevelBundle *bundle)
                       :
                       level_path(level_path),
                       bundle(bundle),
                       ltex_repo(bundle->stex_repo)
{}

TileMap FoxerLevel::get_layer(int index) const { return data.get_layers().at(index - 1); }

LayerContainer FoxerLevel::get_layers(const int &from, const int &to) const {
  const std::vector<TileMap> layers = data.get_layers();
  return LayerContainer(
      std::vector<TileMap>(layers.begin() + from - 1, layers.begin() + to));
}

LayerContainer FoxerLevel::get_layers() const { return LayerContainer(data.get_layers()); }

TiledJsonObj FoxerLevel::get_event(const std::string &event_id) const {
  return data.get_events().find(event_id)->second;
}

const TiledLevelData &FoxerLevel::get_level_data() const {
  return data;
}

void FoxerLevel::load() {
  this->data = TLDLoader::load(level_path, ltex_repo, &bundle->camera);
  col_ver = std::make_unique<FoxerCollisionHandler>(bundle->player_ref,
                                              data.get_collision_tile_grid());
}

void FoxerLevel::handle_events(const float &delta_time) {
  bundle->player_ref->control_entity(delta_time);
  col_ver->handle_collision();
  bundle->player_ref->time_trigger();
  bundle->player_ref->move(delta_time);
}

void FoxerLevel::control_camera(const float &delta_time) {
  sf::Vector2f pos = (bundle->player_ref->get_sprite_position() -
  bundle->camera.get_center()) *
  (delta_time * 4);

  bundle->camera.move(pos);
  bundle->camera.correction(data.get_tile_size(), data.get_level_size());
}

void FoxerLevel::change_level(Level *level) {
  bundle->level_proxy.change_level(level);
}

void FoxerLevel::change_level(std::shared_ptr<Level> level) {
  bundle->level_proxy.change_level(level);
}

void FoxerLevel::set_level_bundle(LevelBundle *bundle) {
  this->bundle = bundle;
  ltex_repo = LocalTextureRepository(bundle->stex_repo);
}

void FoxerLevel::set_collision_handler(std::unique_ptr<CollisionHandler> col_ver) {
  this->col_ver = std::move(col_ver);
}

}
