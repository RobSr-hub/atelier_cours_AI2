#pragma once
#include "../../Core/Globals.h"
#include "Core/BlackBoard.h"
#include "Core/LeafNode.h"

using namespace Core;

namespace Game
{
    class Repeater : public BehaviourTree::LeafNode
    {
        uint _maxLoop;
        uint _loop = 0;

    public:
        Repeater(uint maxloop)
            : _maxLoop(maxloop)
        {}

        BehaviourTree::NodeState tick(BehaviourTree::BlackBoard& bb) override
        {
            if (_loop++ < _maxLoop)
                return BehaviourTree::NodeState::RUNNING;

            _loop = 0;
            return BehaviourTree::NodeState::SUCCESS;
        }
    };

    class Delay : public BehaviourTree::LeafNode
    {
        float _duration;
        float _elapsed = 0.f;

    public:
        Delay(float duration)
            : _duration(duration) { }

        BehaviourTree::NodeState tick(BehaviourTree::BlackBoard& bb) override
        {
            _elapsed += GetFrameTime();
            if (_elapsed < _duration)
                return BehaviourTree::NodeState::RUNNING;

            _elapsed = 0.f;
            return BehaviourTree::NodeState::SUCCESS;
        }
    };
}


