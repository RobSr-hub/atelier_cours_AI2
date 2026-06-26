#pragma once

#include "../../Core/Globals.h"
#include "Core/LeafNode.h"

namespace BehaviourTree
{
    class DummySuccess : public LeafNode
    {
    public:
        NodeState tick(const BlackBoard& bb) override
        {
            Core::log(" DummySuccess Leaf");
            return NodeState::SUCCESS;
        }
    };


    class DummyFail : public LeafNode
    {
    public:
        NodeState tick(const BlackBoard& bb) override
        {
            Core::log(" DummyFail Leaf");
            return NodeState::FAILURE;
        }
    };

    class DummyRunning : public LeafNode
    {
    public:
        NodeState tick(const BlackBoard& bb) override
        {
            Core::log(" DummyRunning Leaf");
            return NodeState::RUNNING;
        }
    };
}