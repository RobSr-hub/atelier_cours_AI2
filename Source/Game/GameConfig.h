#pragma once

#include "../Core/Globals.h"

using namespace Core;
namespace Game
{
    static const char* WINDOW_TITLE = "Game Test";
    static const int SCREEN_WIDTH  = 720;
    static const int SCREEN_HEIGHT = 480;
    static const uint FPS = 30;

    static const uint SPEED_LIMIT = 50;

    static const double PLAYER_WIDTH          = 70;
    static const double PLAYER_HEIGHT         = 50;
    static const double PLAYER_HEIGHT_CROUCH  = 25;
    static const double PLAYER_COLOR_R        = 0.0;
    static const double PLAYER_COLOR_G        = 0.63;
    static const double PLAYER_COLOR_B        = 0.8;
    static const double PLAYER_ACCEL          = 1000;
    static const double PLAYER_JUMP_VELOCITY  = -600;
    static const double PLAYER_GRAVITY        = 1000;
    static const double PLAYER_GRAVITY_CROUCH = 1500;
    static const double PLAYER_DAMPING        = 300;
    static const double PLAYER_WALL_BOUNCE    = 0.5;
    static const int    PLAYER_EYE_SIZE       = 6;
    static const int    PLAYER_EYE_OFFSET     = 3;
}
