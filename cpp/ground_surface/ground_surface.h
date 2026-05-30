#pragma once

#include <godot_cpp/classes/static_body3d.hpp>

namespace godot
{
    class GroundSurface : public StaticBody3D
    {
        GDCLASS(GroundSurface, StaticBody3D);

    protected:
        static void _bind_methods();
    };
}