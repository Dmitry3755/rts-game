#pragma once

#include <godot_cpp/classes/texture_progress_bar.hpp>

namespace ui
{
    class HealthBar : public godot::TextureProgressBar
    {
        GDCLASS(HealthBar, godot::TextureProgressBar);

    public:
        HealthBar() {};
        ~HealthBar() = default;

        void _ready() override;
        void setValue(double min, double max, double current);

    protected:
        static void _bind_methods();

    private:
        double minValue = 0.0;
        double maxValue = 100.0;
        double currentValue = 100.0;
    };
}