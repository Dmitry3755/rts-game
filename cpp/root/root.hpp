
#pragma once

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/project_settings.hpp>

namespace godot
{
    class Root : public Node3D
    {
        GDCLASS(Root, Node3D);

    public:
        Root();
        ~Root();

        void _enter_tree();
        void _process(double delta);
        void _ready();

    protected:
        static void _bind_methods();

        // Variables set get
    };
}