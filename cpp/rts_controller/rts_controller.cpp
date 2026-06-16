#include "rts_controller.hpp"

#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/classes/world3d.hpp>
#include <godot_cpp/classes/physics_direct_space_state3d.hpp>
#include <godot_cpp/classes/physics_ray_query_parameters3d.hpp>
#include <godot_cpp/classes/input_event_mouse_button.hpp>
#include <godot_cpp/classes/node.hpp>

namespace godot
{
    RTSController::RTSController()
    {
    }

    void RTSController::_bind_methods()
    {
    }

    void RTSController::_ready()
    {
        camera = get_node<CameraController>(NodePath("../CameraController"))->getCamera3D();
    }

    void RTSController::_input(const Ref<InputEvent> &event)
    {
        Ref<InputEventMouseButton> mouseEvent = event;

        if (!mouseEvent.is_valid())
            return;

        if (!mouseEvent->is_pressed())
            return;

        switch (mouseEvent->get_button_index())
        {
        case MouseButton::MOUSE_BUTTON_LEFT:
            selectUnit(mouseEvent->get_position());
            break;

        case MouseButton::MOUSE_BUTTON_RIGHT:
            moveSelectedUnit(mouseEvent->get_position());
            break;

        default:
            break;
        }
    }

    void RTSController::selectUnit(const Vector2 &mousePos)
    {
        if (!camera)
            return;

        Vector3 from = camera->project_ray_origin(mousePos);
        Vector3 to = from + camera->project_ray_normal(mousePos) * 5000.0f;

        Ref<PhysicsRayQueryParameters3D> query = PhysicsRayQueryParameters3D::create(from, to);
        Dictionary result = get_viewport()->get_world_3d()->get_direct_space_state()->intersect_ray(query);

        if (result.is_empty())
            return;

        Object *collider = Object::cast_to<Object>(result["collider"]);
        unit::Unit *unit = Object::cast_to<unit::Unit>(collider);

        if (!unit)
            return;

        if (selectedUnit)
            selectedUnit->unselect();

        selectedUnit = unit;
        selectedUnit->select();
        UtilityFunctions::print("Unit selected");
    }

    void RTSController::moveSelectedUnit(const Vector2 &mousePos)
    {
        if (!selectedUnit || !camera)
            return;

        Vector3 from = camera->project_ray_origin(mousePos);
        Vector3 to = from + camera->project_ray_normal(mousePos) * 5000.0f;

        Ref<PhysicsRayQueryParameters3D> query = PhysicsRayQueryParameters3D::create(from, to);
        Dictionary result = get_viewport()->get_world_3d()->get_direct_space_state()->intersect_ray(query);

        if (result.is_empty())
            return;

        Vector3 position = result["position"];
        selectedUnit->moveTo(position);
    }
}