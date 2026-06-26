#pragma once

#include "../Core/GameBase.h"

namespace BehaviourTree
{
    class BehaviourTree;
}

namespace Core
{
    class GameTest : public GameBase
    {
        BehaviourTree::BehaviourTree* _tree;
    public:
        GameTest();
        ~GameTest() override;

        void handleInput() override;
        void update() override;
        void render() override;
    }; 
}
