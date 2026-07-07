#pragma once
#include <raylib.h>

#include "../Core/Actor.h"
#include "../Core/Globals.h"
#include "BehaviourTree/Core/BlackBoard.h"
#include "BehaviourTree/Core/LeafNode.h"
#include "BehaviourTree/Core/Node.h"

using namespace Core;

namespace Game
{
    class MoveActor : public BehaviourTree::LeafNode
    {
        float _duration;
        float _elapsed = 0.f;

    public:
        MoveActor(float duration)
            : _duration(duration) {}

        BehaviourTree::NodeState tick(BehaviourTree::BlackBoard& bb) override
        {
            Core::log("Start MoveActor");
            _elapsed += GetFrameTime();
            if (_elapsed < _duration)
            {
                auto data = bb.get<Actor*>("Player", nullptr);
                if (data)
                    data->move();
                return BehaviourTree::NodeState::RUNNING;
            }

            _elapsed = 0.f;
            return BehaviourTree::NodeState::SUCCESS;
        }
    };
}
