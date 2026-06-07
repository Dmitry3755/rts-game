#include "unit.hpp"

using namespace godot;

namespace unit
{
    Unit::Unit() {}

    void Unit::_enter_tree() {}

    void Unit::_process(double delta) {}

    void Unit::_physics_process(double delta) {}

    void Unit::_bind_methods() {}

    void Unit::moveTo(const godot::Vector3 &target)
    {
        if (!navigationAgent)
            return;

        position = target;
        navigationAgent->set_target_position(position);
        UtilityFunctions::print("Move command: ", position);
    }
}