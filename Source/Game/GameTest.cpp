#include "GameTest.h"

#include <raylib.h>

#include "BehaviourTree/Builders.h"
#include "BehaviourTree/Core/BehaviourTree.h"

namespace Core
{
    GameTest::GameTest()
    {
        InitWindow(720, 480, "GameTest");
        SetTargetFPS(30);

        _tree = BehaviourTree::Builders::TestSequence();
        _loop = true;
    }

    GameTest::~GameTest()
    {
        delete _tree;
        _tree = nullptr;
        CloseWindow();
    }

    void GameTest::handleInput()
    {
       int key = GetKeyPressed();
       switch (key)
       {
       case KEY_ESCAPE:
           _loop = false;
           break;
       }
    }

    void GameTest::update()
    {
        if (!_tree->isComplete())
            _tree->tick();
    }

    void GameTest::render()
    {
        BeginDrawing();
        {
            ClearBackground(BLANK);
            DrawFPS(20, 20);
        }
        EndDrawing();
    }
}
