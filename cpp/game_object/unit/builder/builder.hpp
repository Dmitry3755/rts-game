#include "../unit.hpp"
#include "../../utils/health_bar.hpp"

namespace unit
{
    class Builder : public Unit
    {
        GDCLASS(Builder, Unit);

        using inhereted = Unit;

    public:
        Builder();
        virtual ~Builder() = default;

        void _enter_tree() override;
        void _process(double delta) override;
        void _ready() override;
        void _physics_process(double delta);

    protected:
        static void _bind_methods();
    };
}