#include "Actor.h"

#include <raylib.h>

#include "Globals.h"

namespace Core
{
    Actor::Actor()
        : _x{}, _y{}
        , _w{}, _h{}
        , _vx{}, _vy{}, _ax{}, _ay{}
        , _colorR{}, _colorG{}, _colorB{}, _colorA{}
        , _deleteMe{ false }
    {}

    Actor::Actor(double x, double y)
        : _x{x}, _y{y}
        , _w{}, _h{}
        , _vx{}, _vy{}, _ax{}, _ay{}
        , _colorR{}, _colorG{}, _colorB{}, _colorA{}
        , _deleteMe{false}
    {}

    void Actor::init(double x, double y)
    {
        _x = x;
        _y = y;
        _deleteMe = false;
    }

    void Actor::move()
    {
        float dt = GetFrameTime();
        _vx += dt * _ax;
        _vy += dt * _ay;

        _x += dt * _vx;
        _y += dt * _vy;
    }

    void Actor::update()
    {
        move();
    }

    void Actor::render() const
    {
        Color c
        {
            (uchar) (_colorR * 255),
            (uchar) (_colorG * 255),
            (uchar) (_colorB * 255),
            (uchar) (_colorA * 255)
         };

        Rectangle r{};
        r.x         = (float) _x;
        r.y         = (float) _y;
        r.width     = (float) _w;
        r.height    = (float) _h;

        DrawRectangleRec(r, c);
    }

    void Actor::ProcessCollision(Actor& p)
    {
        if (isColliding(p))
            collide(p);
    }

    bool Actor::isColliding(const Actor& p) const
    {
        return !(
            // Un à gauche de l'autre
            p._x + p._w < _x ||
            _x + _w < p._x ||
            // Un en haut de l'autre
            p._y + p._h < _y ||
            _y + _h < p._y);
    }

    bool Actor::shouldDelete() const
    {
        return _deleteMe;
    }
}
