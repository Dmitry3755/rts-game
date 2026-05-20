#include "camera_controller.h"

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/classes/display_server.hpp>
#include <godot_cpp/classes/input_event_mouse_button.hpp>

using namespace godot;

void CameraController::_bind_methods()
{
}

CameraController::CameraController()
{
}

CameraController::~CameraController()
{
}

void CameraController::_ready()
{
    camera = get_node<Camera3D>("Camera3D");
    if (!camera)
        UtilityFunctions::print("CameraController camera is ");

    camera->set_current(true);
    camera->set_position(Vector3(0, 15, 15));
    camera->look_at(Vector3(0, 0, 0));

    UtilityFunctions::print("CameraController init");
}

void CameraController::_process(double delta)
{
   // mousePositionHandle(delta);
}

void CameraController::_input(const Ref<InputEvent> &event)
{
    Ref<InputEventMouseButton> mouseEvent = event;
    if (mouseEvent.is_valid())
    {
        if (mouseEvent->is_pressed())
        {
             Vector3 vectorZoom = camera->get_position();
            switch (mouseEvent->get_button_index())
            {
            case MouseButton::MOUSE_BUTTON_WHEEL_UP:
            {
                UtilityFunctions::print("Zoom in");
                if (vectorZoom.y < 6)
                    break;

                vectorZoom.y -= zoomSpeed;
                camera->set_position(vectorZoom);
                break;
            }
            case MouseButton::MOUSE_BUTTON_WHEEL_DOWN:
            {
                UtilityFunctions::print("Zoom out");
                // if (vectorZoom.y > 50)
                //     break;

                vectorZoom.y += zoomSpeed;
                camera->set_position(vectorZoom);
                break;
            }
            
            default:
                break;
            }
        }
    }
}

void CameraController::mousePositionHandle(double delta)
{
    Vector2 mousePos = get_viewport()->get_mouse_position();

    Vector2 viewportSize = get_viewport()->get_visible_rect().size;

    Vector3 direction(0, 0, 0);

    // LEFT
    if (mousePos.x <= edgeSize)
        direction.x -= 1.0f;

    // RIGHT
    if (mousePos.x >= viewportSize.x - edgeSize)
        direction.x += 1.0f;

    // TOP
    if (mousePos.y <= edgeSize)
        direction.z -= 1.0f;

    // BOTTOM
    if (mousePos.y >= viewportSize.y - edgeSize)
        direction.z += 1.0f;

    if (direction.length() > 0.0f)
    {
        direction = direction.normalized();

        set_position(
            get_position() +
            direction * moveSpeed * delta);
    }
}