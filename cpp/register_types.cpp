#include "camera/camera_controller.hpp"
#include "root/root.hpp"
#include "rts_controller/rts_controller.hpp"

#include "ground_surface/ground_surface.h"

#include "game_object/unit/unit.hpp"
#include "game_object/unit/builder/builder.hpp"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;
void initialize_camera_controller_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

    /**
     * Controller and main node
     */
    ClassDB::register_class<Root>();
    ClassDB::register_class<CameraController>();
    ClassDB::register_class<RTSController>();
    /**
     * World
     */
    ClassDB::register_class<GroundSurface>();
    /**
     * Units
     */
    ClassDB::register_class<unit::Unit>();
    ClassDB::register_class<unit::Builder>();
}

void uninitialize_camera_controller_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C"
{
    GDExtensionBool GDE_EXPORT middle_ages_rts_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
    {
        godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

        init_obj.register_initializer(initialize_camera_controller_module);
        init_obj.register_terminator(uninitialize_camera_controller_module);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}