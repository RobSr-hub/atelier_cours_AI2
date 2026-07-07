#pragma once

namespace BehaviourTree
{
    class BehaviourTree;
}

namespace Game
{
    class Player;

    class GameBuilders
    {
    public:
        static BehaviourTree::BehaviourTree* TestMovePlayer(Player* player);
    };
}
