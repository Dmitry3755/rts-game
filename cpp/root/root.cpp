#include "root.hpp"
#include "../src/config_manager.hpp"
#include "../display.hpp"

using namespace godot;

Root::Root() {}

Root::~Root() {}

void Root::_bind_methods() {}

void Root::_enter_tree()
{
    auto configManager = core::ConfigManager::get();
    configManager.load();
    auto display = core::Display::get();
    display._init_display_();
}

void Root::_process(double delta)
{
}

void Root::_ready()
{
    //auto& display = Display::get();
    //display._init_display_();
}