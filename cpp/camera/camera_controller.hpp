#pragma once

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/spring_arm3d.hpp>
#include <godot_cpp/classes/camera3d.hpp>
#include <godot_cpp/classes/input_event.hpp>

namespace godot
{
	class CameraController : public Node3D
	{
		GDCLASS(CameraController, Node3D)

	public:
		CameraController();
		~CameraController();

		void _ready();
		void _process(double delta);
		void _input(const Ref<InputEvent>& event);

		Camera3D* getCamera3D() { return camera; }
	protected:
		static void _bind_methods();

		void mousePositionHandle(double delta); 

	private:
		Camera3D *camera = nullptr;

		float moveSpeed = 40.0f;
		float rotationSpeed = 1.5f;

		int zoomSpeed = 10;
	};

}