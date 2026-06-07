#pragma once

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/input_event.hpp>

#include "../game_object/unit/unit.hpp"
#include "../camera/camera_controller.hpp"

namespace godot
{
    class RTSController : public godot::Node
    {
        GDCLASS(RTSController, Node);

    public:
        RTSController();
        ~RTSController() = default;

        void _ready() override;
        void _input(const godot::Ref<godot::InputEvent>& event) override;

    protected:
        static void _bind_methods();

    private:
        void selectUnit(const godot::Vector2& mousePos);
        void moveSelectedUnit(const godot::Vector2& mousePos);

    private:
	    Camera3D* camera = nullptr;
        unit::Unit* selectedUnit = nullptr;
    };
}