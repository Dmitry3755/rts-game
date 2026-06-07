#include <godot_cpp/classes/display_server.hpp>

namespace core
{
    class Display
    {
    public:
        static Display &get()
        {
            static Display instance;
            return instance;
        }

        void _init_display_();

        void _on_screen_full_() { setWindowMode(godot::DisplayServer::WindowMode::WINDOW_MODE_FULLSCREEN); };
        void _on_screen_windowed_() { setWindowMode(godot::DisplayServer::WindowMode::WINDOW_MODE_WINDOWED); };
        void _on_screen_maximized_() { setWindowMode(godot::DisplayServer::WindowMode::WINDOW_MODE_MAXIMIZED); };
        void _on_screen_full_exclusive_() { setWindowMode(godot::DisplayServer::WindowMode::WINDOW_MODE_EXCLUSIVE_FULLSCREEN); };

    protected:
        void setWindowMode(godot::DisplayServer::WindowMode mode = godot::DisplayServer::WindowMode::WINDOW_MODE_EXCLUSIVE_FULLSCREEN);

    private:
        Display() = default;

        int width;
        int height;
        bool vsync;
        
        godot::DisplayServer::WindowMode mode = godot::DisplayServer::WindowMode::WINDOW_MODE_MAXIMIZED;
    };
    

}
