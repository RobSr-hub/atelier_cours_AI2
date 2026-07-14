#pragma once

#include "../Core/Actor.h"

using namespace Core;

namespace Game
{
    struct Inputs
    {
        bool left;
        bool right;
        bool down;
        bool jump;
    };

    class Player : public Actor
    {
    public:
        Player(double x, double y);

        void update() override;
        void render() const override;

        void collide(Actor& o) override;

        void setPosition(double x, double y);
        void setDirection(bool l, bool r, bool d, bool j);
        void setDirection(Inputs inputs);
        void resetDirection();
        bool reachPosition(float x);

    private:
        Inputs _inputs;
        bool _isJumping;
    };
}
