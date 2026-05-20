#include "root.h"

using namespace godot;

#pragma region Root

Root::Root() {}

Root::~Root() {}

void Root::_bind_methods() {}

void Root::_enter_tree()
{
    auto& display = Display::get();
    display._init_display_info_();
    UtilityFunctions::print("Root and display init");
}

void Root::_process(double delta)
{
}

void Root::getScreenInfo()
{

}

#pragma endregion Root

#pragma region Display

Root::Display::Display()
{
    displayServer = DisplayServer::get_singleton();
    UtilityFunctions::print("Display ctor: ", displayServer);
}

void Root::Display::_init_display_info_()
{
    if (!displayServer)
    {
        UtilityFunctions::print("Root::Display::displayServer - ref is nullptr");
        return;
    }
    _update_display_info_();
}

void Root::Display::setWindowMode(DisplayServer::WindowMode mode)
{
    if (!displayServer)
    {
        UtilityFunctions::print("Root::Display::displayServer - ref is nullptr");
        return;
    }

    displayServer->window_set_mode(mode);
    _update_display_info_();
}

void Root::Display::setDisplayInfo()
{
    if (!displayServer)
    {
        UtilityFunctions::print("Root::Display::displayServer - ref is nullptr");
        return;
    }

    auto displaySize = displayServer->screen_get_size();
    displayInfo.width = displaySize.x;
    displayInfo.height = displaySize.y;
}

#pragma endregion Display