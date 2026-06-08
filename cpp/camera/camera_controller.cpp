#include "camera_controller.hpp"

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/classes/display_server.hpp>
#include <godot_cpp/classes/input_event_mouse_button.hpp>

using namespace godot;

constexpr int EDGE_SIZE = 10;
constexpr float MAX_CAMERA_HEIGHT = 500.0f;
constexpr float MIN_CAMERA_HEIGHT = 10.0f;

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
    {
        UtilityFunctions::print("CameraController camera is null");
        return;
    }

    camera->set_current(true);
    set_position(Vector3(0, MAX_CAMERA_HEIGHT, MAX_CAMERA_HEIGHT));

    camera->set_position(Vector3(0, MAX_CAMERA_HEIGHT, MAX_CAMERA_HEIGHT));
    camera->look_at(Vector3(0, 0, 0));

    UtilityFunctions::print("CameraController init");
}

void CameraController::_process(double delta)
{
    mousePositionHandle(delta);
}

void CameraController::_input(const Ref<InputEvent> &event)
{
    Ref<InputEventMouseButton> mouseEvent = event;

    if (!mouseEvent.is_valid())
        return;

    if (!mouseEvent->is_pressed())
        return;

    Vector3 pos = camera->get_position();

    switch (mouseEvent->get_button_index())
    {
    case MouseButton::MOUSE_BUTTON_WHEEL_UP:
    {
        if (pos.y <= MIN_CAMERA_HEIGHT)
            return;

        pos.y -= zoomSpeed;
        pos.z -= zoomSpeed;
        camera->set_position(pos);
        break;
    }

    case MouseButton::MOUSE_BUTTON_WHEEL_DOWN:
    {
        if (pos.y >= MAX_CAMERA_HEIGHT)
            return;

        pos.y += zoomSpeed;
        pos.z += zoomSpeed;
        camera->set_position(pos);
        break;
    }
    }
}

void CameraController::mousePositionHandle(double delta)
{
    Vector2 mousePos = get_viewport()->get_mouse_position();
    Vector2 viewportSize = get_viewport()->get_visible_rect().size;
    Vector3 direction(0, 0, 0);

    // LEFT
    if (mousePos.x <= EDGE_SIZE)
        direction.x -= 1.0f;

    // RIGHT
    if (mousePos.x >= viewportSize.x - EDGE_SIZE)
        direction.x += 1.0f;

    // TOP
    if (mousePos.y <= EDGE_SIZE)
        direction.z -= 1.0f;

    // BOTTOM
    if (mousePos.y >= viewportSize.y - EDGE_SIZE)
        direction.z += 1.0f;

    if (direction.length() > 0.0f)
    {
        direction = direction.normalized();

        Vector3 pos = get_position();

        pos += direction * moveSpeed * delta;

        set_position(pos);
    }
}