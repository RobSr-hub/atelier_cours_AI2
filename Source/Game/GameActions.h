#pragma once
#include <raylib.h>

#include "Player.h"
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

        bool _left;
        bool _right;

    public:
        MoveActor(float duration, bool left, bool right)
            : _duration(duration), _left(left), _right(right)
    	{}

        BehaviourTree::NodeState tick(BehaviourTree::BlackBoard& bb) override
        {
            // On récupère l'acteur du blackboard 
            auto actor = bb.get<Actor*>("Player", nullptr);
            if (!actor)
                return BehaviourTree::NodeState::FAILURE;

            // On cast l'acteur en Player
            // TODO: pas la meilleur solution, mais pour l'instant ça fera l'affaire
            auto player = static_cast<Player*>(actor);
            player->setDirection(_left, _right, false, false);

            // On déplace le joueur pendant la durée spécifiée
            Core::log("Start MoveActor");
            _elapsed += GetFrameTime();
            if (_elapsed < _duration)
            {
                player->move();
                return BehaviourTree::NodeState::RUNNING;
            }

            // on arrête le mouvement du joueur après la durée spécifiée
            player->resetDirection();
            _elapsed = 0.f;
            return BehaviourTree::NodeState::SUCCESS;
        }
    };
}
