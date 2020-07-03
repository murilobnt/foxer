#include "level_one.hpp"
#include "level_two.hpp"

LevelTwo::LevelTwo() {}

LevelTwo::LevelTwo(Character *player, fox::LevelBundle *bundle,
                   const std::string start_id) :
                     FoxerLevel("assets/levels/level02.json", bundle),
                     player(player),
                     start_id(start_id) {}

void LevelTwo::init(){
  rays = sf::Sprite(ltex_repo.load("assets/textures/rays.png"));

  const fox::TiledJsonObj start_pos = get_event(start_id);
  const fox::TiledJsonObj level_change = get_event("level_change");

  exit = fox::EventArea(level_change,
  std::make_unique<SampleExitAreaCH>(&bundle->level_proxy,
  std::make_shared<LevelOne>(player, bundle, "gate0"), bundle->fader));

  player->setPosition(start_pos.x, start_pos.y);
  bundle->fader->fade_in();
}

void LevelTwo::level_update(const float &delta_time){
  exit.verify_collision(player->getGlobalBounds());

  if(bundle->fader->is_complete()){
    fox::FoxerLevel::level_update(delta_time);
    rays.setPosition(bundle->camera.get_center().x- bundle->camera.get_size().x/2, bundle->camera.get_center().y - bundle->camera.get_size().y/2);
  }
}

void LevelTwo::draw(sf::RenderTarget &target,
                     sf::RenderStates states) const {
    target.draw(get_layers(1, 4));
    target.draw(*player);
    target.draw(rays);
}
