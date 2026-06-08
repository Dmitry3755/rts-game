#pragma once

#include <godot_cpp/classes/character_body3d.hpp>
#include <godot_cpp/classes/navigation_agent3d.hpp>
#include <godot_cpp/classes/mesh_instance3d.hpp>

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

        void select() { selected = true; }
        void unselect() { selected = false; }
        void moveTo(const godot::Vector3 &target);

    protected:
        static void _bind_methods();

    protected:
        int health;
        int armor;
        int damage;
        float speed = 5.0f;

        bool selected = false;

        NavigationAgent3D *navigationAgent = nullptr;
        MeshInstance3D *mesh = nullptr;
    };
}