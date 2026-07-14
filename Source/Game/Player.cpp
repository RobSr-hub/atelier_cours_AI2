#include <raylib.h>
#include <algorithm>
#include <cmath>

#include "../Core/Globals.h"
#include "../Core/Actor.h"

#include "Player.h"
#include "GameConfig.h"

using namespace Core;

namespace Game
{
    Player::Player(double x, double y)
        : Actor{x, y}
          , _inputs{false}
          , _isJumping{false}
    {
        _w = PLAYER_WIDTH;
        _h = PLAYER_HEIGHT;

        _colorR = PLAYER_COLOR_R;
        _colorG = PLAYER_COLOR_G;
        _colorB = PLAYER_COLOR_B;
        _colorA = 1;

        _ay = PLAYER_GRAVITY;
    }

    void Player::update()
    {
        float dt = GetFrameTime();

        _ax = _inputs.left * -PLAYER_ACCEL + _inputs.right * PLAYER_ACCEL;

        if (!_isJumping && _inputs.jump)
        {
            _vy = PLAYER_JUMP_VELOCITY;
            _isJumping = true;
        }

        if (_inputs.down)
        {
            if (_h == PLAYER_HEIGHT) _y += PLAYER_HEIGHT - PLAYER_HEIGHT_CROUCH;
            _h = PLAYER_HEIGHT_CROUCH;
            _ay = PLAYER_GRAVITY_CROUCH;
        }
        else
        {
            if (_h == PLAYER_HEIGHT_CROUCH) _y -= PLAYER_HEIGHT - PLAYER_HEIGHT_CROUCH;
            _h = PLAYER_HEIGHT;
            _ay = PLAYER_GRAVITY;
        }

        Actor::update();

        // Damping
        if (!_inputs.left && !_inputs.right)
        {
            double sign_vx = copysign(1, _vx);
            _vx -= dt * sign_vx * PLAYER_DAMPING;

            if (copysign(1, _vx) != sign_vx) // sign changed: velocity crossed zero
                _vx = 0;
        }

        _vx = std::clamp(_vx, -(double)SPEED_LIMIT, (double)SPEED_LIMIT);

        if (_x < 0)
        {
            _x = 0;
            _vx *= -PLAYER_WALL_BOUNCE;
        }
        else if (_x + _w > SCREEN_WIDTH)
        {
            _x = SCREEN_WIDTH - _w;
            _vx *= -PLAYER_WALL_BOUNCE;
        }

        if (_y + _h > SCREEN_HEIGHT)
        {
            _y = SCREEN_HEIGHT - _h;
            _vy = 0;
            _isJumping = false;
        }
    }

    void Player::drawHealth(double x, double y) const
    {
        auto text = TextFormat("HP: %d", _health);
        DrawText(text, x, y, 10, RED);
    }

    void Player::setPosition(double x, double y)
    {
        _x = x;
        _y = y;
    }

    void Player::setDirection(bool l, bool r, bool d, bool j)
    {
        _inputs.left  = l;
        _inputs.right = r;
        _inputs.down  = d;
        _inputs.jump  = j;
        log("[setDirection] Player::setDirection");
    }

    void Player::setDirection(Inputs inputs)
    {
        _inputs = inputs;
        log("[setDirection] Player::setDirection with inputs");
    }

    void Player::resetDirection()
    {
        _inputs.left = false;
        _inputs.right = false;
        _inputs.down = false;
        _inputs.jump = false;
    }

    bool Player::reachPosition(float x)
    {
        const float Epsilon = 0.0001f;
        auto distance = std::abs(_x - x);
        if (distance < Epsilon)
            return true;

        // TODO: check vertical limit if needed
        return false;
    }

    void Player::render() const
    {
        Actor::render();

        Rectangle r;
        r.x         = (float) _x;
        r.y         = (float) _y;
        r.width     = (float) _w;
        r.height    = (float) _h;

        Color c1
        {
            (uchar)(_colorR * 255),
            (uchar)(_colorG * 255),
            (uchar)(_colorB * 255),
            (uchar)(_colorA * 255)
        };

        // Head
        DrawRectangleRec(r, c1);

        // Head
        drawHealth(_x, _y - _h);

        Color c2{0, 0, 0, 255};

        int offset = 0;

        if (_vx > 0)
            offset = PLAYER_EYE_OFFSET;
        else if (_vx < 0)
            offset = -PLAYER_EYE_OFFSET;

        // Eyes
        r.width  = PLAYER_EYE_SIZE;
        r.height = PLAYER_EYE_SIZE;

        // Left eye
        r.x = (float) (_x + _w/4.0 - PLAYER_EYE_SIZE/2.0) + offset;
        r.y = (float) (_y + _h/3.0 - PLAYER_EYE_SIZE/2.0);
        DrawRectangleRec(r, c2);

        // Right eye
        r.x = (float) (_x + 3*_w/4.0 - PLAYER_EYE_SIZE/2.0) + offset;
        DrawRectangleRec(r, c2);

        // Mouth
        int mouthY = (int)(_y + 3*_h/4.0);
        DrawLine((int)(_x + _w/4.0), mouthY, (int)(_x + 3*_w/4.0), mouthY, c2);
    }

    void Player::collide(Actor&)
    {
        log("test Player::collide");
    }

    void Player::setHealth(int health)
    {
        _health = health;
    }
}
