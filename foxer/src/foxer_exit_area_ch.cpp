#include "foxer/logical/foxer_exit_area_ch.hpp"

namespace fox {

FoxerExitAreaCH::FoxerExitAreaCH() {

}

FoxerExitAreaCH::FoxerExitAreaCH(LevelProxy *level_proxy,
                std::shared_ptr<Level> next_level) :
                proxy(level_proxy){
  loader.run(next_level);
}

void FoxerExitAreaCH::handle_collision() {
  proxy->change_level(loader.get_level());
}

}
