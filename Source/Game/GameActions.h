#pragma once
#include <raylib.h>

#include "../Core/Actor.h"
#include "BehaviourTree/Core/BlackBoard.h"
#include "BehaviourTree/Core/LeafNode.h"
#include "BehaviourTree/Core/Node.h"

using namespace BehaviourTree;
using namespace Core;

namespace Game
{
    class MoveActor : public LeafNode
    {
        float _duration;
        float _elapsed = 0.f;

    public:
        MoveActor(float duration)
            : _duration(duration) {}

        NodeState tick(BlackBoard& bb) override
        {
            _elapsed += GetFrameTime();
            if (_elapsed < _duration)
            {
                auto data = bb.get<Actor*>("Player", nullptr);
                if (data)
                    data->move();
                return NodeState::RUNNING;
            }

            _elapsed = 0.f;
            return NodeState::SUCCESS;
        }
    };
}
