#pragma once
#include "../../Core/Globals.h"
#include "Core/BlackBoard.h"
#include "Core/CompositeNode.h"

namespace BehaviourTree
{
    class Sequence : public CompositeNode
    {
        uint _currentIndex = 0;

    public:
        NodeState tick(BlackBoard& bb) override
        {
            Core::log("Sequence:");
            for (auto i = _currentIndex; i < _nodes.size(); ++i)
            {
                NodeState state = _nodes[i]->tick(bb);
                // On enregistre l'index du noeud courant si il est en cours d'exécution, 
                // pour reprendre à partir de ce noeud lors du prochain tick
                if (state == NodeState::RUNNING)
                    _currentIndex = i;

                if (state != NodeState::SUCCESS)
                    return state;
            }
            return NodeState::SUCCESS;
        }
    };

    class Selector : public CompositeNode
    {
        uint _currentIndex = 0;
    public:
        NodeState tick(BlackBoard& bb) override
        {
            Core::log("Selector:");
            for (auto i = _currentIndex; i < _nodes.size(); ++i)
            {
                NodeState state = _nodes[i]->tick(bb);

                // On enregistre l'index du noeud courant si il est en cours d'exécution, 
                // pour reprendre à partir de ce noeud lors du prochain tick
                if (state == NodeState::RUNNING)
                    _currentIndex = i;

                if (state != NodeState::FAILURE)
                    return state;
            }
            return NodeState::FAILURE;
        }
    };
}
