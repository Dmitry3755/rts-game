#include "builder.hpp"

#include <godot_cpp/classes/sprite3d.hpp>
#include <godot_cpp/classes/progress_bar.hpp>
#include <godot_cpp/classes/sub_viewport.hpp>
#include <godot_cpp/classes/viewport_texture.hpp>
#include <godot_cpp/classes/texture2d.hpp>

constexpr double BUILDER_HEALTH_MAX_DEFAULT{100.0};
constexpr double BUILDER_HEALTH_MIN_DEFAULT{0.0};

namespace unit
{
    Builder::Builder() {}

    void Builder::_enter_tree() {}

    void Builder::_ready()
    {
        health = BUILDER_HEALTH_MAX_DEFAULT;

        auto *viewport = get_node<SubViewport>("SubViewport");
        auto *healthBar = get_node<ui::HealthBar>("SubViewport/HealthBar");
        auto *sprite = get_node<Sprite3D>("Sprite3D");
        navigationAgent = get_node<NavigationAgent3D>("NavigationAgent3D");
        mesh = get_node<MeshInstance3D>("MeshInstance3D");

        if (!healthBar || !sprite || !viewport || !navigationAgent || !mesh)
        {
            UtilityFunctions::print("Builder create error"); 
            return;
        }

        healthBar->setValue(BUILDER_HEALTH_MIN_DEFAULT, BUILDER_HEALTH_MAX_DEFAULT, BUILDER_HEALTH_MAX_DEFAULT);
        sprite->set_texture(Ref<Texture2D>(viewport->get_texture()));
        sprite->set_position(Vector3(0.0, 2.0, 0.0));
    }

    void Builder::_physics_process(double delta) { inhereted::_physics_process(delta); }

    void Builder::_process(double delta) {}

    void Builder::_bind_methods() {}
}