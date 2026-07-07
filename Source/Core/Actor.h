#pragma once

namespace Core
{
    class Actor
    {
    public:
        Actor();

        Actor(double x, double y);

        virtual ~Actor() = default;

        virtual void init(double x, double y);
        void move();

        virtual void update();

        virtual void render() const;

        void ProcessCollision(Actor &);

        bool shouldDelete() const;

    protected:
        bool isColliding(const Actor &) const;

        virtual void collide(Actor &) = 0;

        double _x, _y;
        double _w, _h;
        double _vx, _vy;
        double _ax, _ay;

        double _colorR, _colorG, _colorB, _colorA;
        bool _deleteMe;
    };
}
