#pragma once
#include "../Core/GameBase.h"
#include "BehaviourTree/Core/BehaviourTree.h"

namespace Core
{
    class GameTest : public GameBase
    {
        BehaviourTree::BehaviourTree _tree;
    public:
        GameTest();
        ~GameTest() override;

        void handleInput() override;
        void update() override;
        void render() override;
    }; 
}
