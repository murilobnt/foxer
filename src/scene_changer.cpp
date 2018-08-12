#include "gs2d_engine/concrete/scene_changer.hpp"

Scene* SceneChanger::create_scene(Scene* scene, SceneManager* scene_manager){
    scene->set_scene_manager(scene_manager);
    return scene;
}
