#pragma once

#include "Node.h"
#include <../Source/Core/Globals.h>

namespace BehaviourTree
{
    class BehaviourTree
    {
    private:
        Node* _rootNode = nullptr;

    public:
        BehaviourTree() = default;
        ~BehaviourTree() = default;

        NodeState tick() const
        {
            Core::log("[BehaviourTree] - Tick()");
            if (_rootNode)
                return _rootNode->tick();
            return NodeState::FAILURE;
        }
    };
}
