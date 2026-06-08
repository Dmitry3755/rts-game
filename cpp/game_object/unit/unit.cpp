#include "unit.hpp"

using namespace godot;

namespace unit
{
    Unit::Unit() {}

    void Unit::_enter_tree() {}

    void Unit::_process(double delta) {}

    void Unit::_physics_process(double delta)
    {
        if (!navigationAgent)
            return;

        if (navigationAgent->is_navigation_finished())
        {
            set_velocity(Vector3());
            move_and_slide();
            return;
        }

        Vector3 next_waypoint = navigationAgent->get_next_path_position();
        Vector3 direction = (next_waypoint - get_global_position()).normalized();

        set_velocity(direction * speed);
        move_and_slide();
    }

    void Unit::_bind_methods() {}

    void Unit::moveTo(const godot::Vector3 &target)
    {
        if (!navigationAgent)
            return;

        navigationAgent->set_target_position(target);
    }
}