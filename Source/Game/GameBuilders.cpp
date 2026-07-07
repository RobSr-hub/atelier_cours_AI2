#pragma once
#include "GameBuilders.h"

#include "GameActions.h"
#include "Player.h"
#include "BehaviourTree/ActionLeaves.h"
#include "BehaviourTree/Composites.h"
#include "BehaviourTree/DummyLeaves.h"
#include "BehaviourTree/Core/BehaviourTree.h"

namespace Game
{
    BehaviourTree::BehaviourTree* GameBuilders::TestMovePlayer(Player* player)
    {
        auto bt = new BehaviourTree::BehaviourTree();

        player->setDirection(false, true, false, false);

        auto bb = bt->getBlackBoard();
        bb.set<Actor*>("Player", player);

        auto sn = new BehaviourTree::Sequence();
        sn->add(new Delay(5.0f));
        sn->add(new MoveActor(2.0f));
        sn->add(new BehaviourTree::DummySuccess());

        bt->setRootNode(sn);

        return bt;
    }

}
