#include "health_bar.hpp"
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/texture2d.hpp>

using namespace godot;

namespace ui
{
    void HealthBar::_bind_methods() {}

    void HealthBar::_ready()
    {
        Ref<Texture2D> under = ResourceLoader::get_singleton()->load("res://textures/2d/health_under.png");
        Ref<Texture2D> progress = ResourceLoader::get_singleton()->load("res://textures/2d/health_progress.png");

        if (under.is_null() || progress.is_null())
        {
            UtilityFunctions::print("HealthBar textures dont create");
            return;
        }

        set_under_texture(under);
        set_progress_texture(progress);
    }

    void HealthBar::setValue(double min, double max, double current)
    {
        set_min(min);
        set_max(max);
        set_value(current);
    }
}