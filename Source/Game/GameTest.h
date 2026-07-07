#pragma once

#include "Player.h"
#include "../Core/GameBase.h"

namespace BehaviourTree
{
    class BehaviourTree;
}

namespace Game
{
    class GameTest : public GameBase
    {
        BehaviourTree::BehaviourTree* _tree;
        Player _player;
    public:
        GameTest();
        ~GameTest() override;
        void HandlePlayerDirection();

        void handleInput() override;
        void update() override;
        void render() override;
    }; 
}
