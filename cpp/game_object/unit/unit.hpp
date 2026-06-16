#pragma once

#include "../utils/health_bar.hpp"

#include <godot_cpp/classes/character_body3d.hpp>
#include <godot_cpp/classes/navigation_agent3d.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>
#include <godot_cpp/classes/decal.hpp>

using namespace godot;

namespace unit
{
    class Unit : public CharacterBody3D
    {
        GDCLASS(Unit, CharacterBody3D);

    public:
        Unit();
        virtual ~Unit() = default;

        virtual void _enter_tree() override;
        virtual void _process(double delta) override;
        virtual void _physics_process(double delta) override;

        void moveTo(const godot::Vector3 &target);

        void select() { selected = true; selectionDecal->set_visible(true); }
        void unselect() { selected = false; selectionDecal->set_visible(false);  }

    protected:
        static void _bind_methods();

    protected:
        double health = 100.0;
        int armor = 0;
        int damage = 0;
        float speed = 5.0f;

        bool selected = false;

        NavigationAgent3D* navigationAgent = nullptr;
        MeshInstance3D* mesh = nullptr;
        Decal* selectionDecal = nullptr;
    };
}