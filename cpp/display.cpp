#include "display.hpp"
#include "src/config_manager.hpp"
#include <godot_cpp/classes/project_settings.hpp>

using namespace godot;

namespace core
{
    void Display::_init_display_()
    {
        auto defaultDisplayValue = DisplayServer::get_singleton()->window_get_size();
        auto configManager = ConfigManager::get();
        width = configManager.getInt("Display", "width", defaultDisplayValue.x);
        height = configManager.getInt("Display", "height", defaultDisplayValue.y);
        vsync = configManager.getBool("Display", "vsync", vsync);

        ProjectSettings *ps = ProjectSettings::get_singleton();
        if (!ps)
        {
            UtilityFunctions::print("ProjectSettings is null");
            return;
        }

        ps->set_setting("display/window/size/viewport_width", width);
        ps->set_setting("display/window/size/viewport_height", height);
    }
}