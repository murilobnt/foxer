#include "foxer/other/geared_up/foxer_level.hpp"

namespace fox {

FoxerLevel::FoxerLevel(){}

FoxerLevel::FoxerLevel(const std::string &level_path,
                       LevelBundle *bundle,
                       std::unique_ptr<LevelCollisionVerifier> col_ver)
                       :
                       level_path(level_path),
                       bundle(bundle),
                       col_ver(std::move(col_ver))
{ }

void FoxerLevel::load(){
  this->data = TLDLoader::load(level_path, tex_holder, &bundle->camera);
}

void FoxerLevel::handle_events(const float &delta_time){
  bundle->player_ref->control_entity(delta_time);
  col_ver->verify_collision(*bundle->player_ref, data.get_collision_tile_grid());
  bundle->player_ref->time_trigger();
  bundle->player_ref->move(delta_time);
}

void FoxerLevel::change_level(Level *level) {
  bundle->level_proxy.change_level(level);
}

void FoxerLevel::change_level(std::shared_ptr<Level> level) {
  bundle->level_proxy.change_level(level);
}

void FoxerLevel::set_level_bundle(LevelBundle *bundle) {
  this->bundle = bundle;
  tex_holder = TextureHolder(&(bundle->shared_t_holder));
}

}
