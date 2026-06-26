#pragma once
#include "../../Core/Globals.h"
#include "Core/BlackBoard.h"
#include "Core/CompositeNode.h"

namespace BehaviourTree
{
    class Sequence : public CompositeNode
    {
    public:
        NodeState tick(const BlackBoard& bb) override
        {
            Core::log("Sequence:");
            for (auto node : _nodes)
            {
                if (node->tick(bb) == NodeState::FAILURE)
                    return NodeState::FAILURE;
            }
            return NodeState::SUCCESS;
        }
    };

    class Selector : public CompositeNode
    {
    public:
        NodeState tick(const BlackBoard& bb) override
        {
            Core::log("Selector:");
            for (auto node : _nodes)
            {
                if (node->tick(bb) == NodeState::SUCCESS)
                    return NodeState::SUCCESS;
            }
            return NodeState::FAILURE;
        }
    };
}

