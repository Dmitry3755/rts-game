
#pragma once

#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/display_server.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

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

        void getScreenInfo();

    protected:
        static void _bind_methods();

        // Variables set get
    public:
#pragma region Dispaly
        class Display
        {
        public:
            static Display &get()
            {
                static Display instance;
                return instance;
            }

            void _init_display_info_();
            void _update_display_info_() { setDisplayInfo(); }

            void _on_screen_full_() { setWindowMode(DisplayServer::WindowMode::WINDOW_MODE_FULLSCREEN); };
            void _on_screen_windowed_() { setWindowMode(DisplayServer::WindowMode::WINDOW_MODE_WINDOWED); };
            void _on_screen_maximized_() { setWindowMode(DisplayServer::WindowMode::WINDOW_MODE_MAXIMIZED); };
            void _on_screen_full_exclusive_() { setWindowMode(DisplayServer::WindowMode::WINDOW_MODE_EXCLUSIVE_FULLSCREEN); };

        protected:
            void setWindowMode(DisplayServer::WindowMode mode = DisplayServer::WindowMode::WINDOW_MODE_EXCLUSIVE_FULLSCREEN);
            void setDisplayInfo();

        protected:
            struct DisplayInfo
            {
                int width;
                int height;
            };

        private:
            Display();

            DisplayServer *displayServer;
            DisplayInfo displayInfo;
        };

#pragma endregion Dispaly
    };
}