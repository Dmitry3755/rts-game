#include "builder.hpp"

namespace unit
{
    Builder::Builder() {}

    void Builder::_enter_tree() {}

    void Builder::_ready()
    {
        navigationAgent = get_node<NavigationAgent3D>("NavigationAgent3D");
        mesh = get_node<MeshInstance3D>("MeshInstance3D");
    }

    void Builder::_physics_process(double delta) { inhereted::_physics_process(delta); }

    void Builder::_process(double delta) {}

    void Builder::_bind_methods() {}
}