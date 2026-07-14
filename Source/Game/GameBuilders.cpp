#pragma once
#include "GameBuilders.h"

#include "GameActions.h"
#include "GameConfig.h"
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

        BehaviourTree::BlackBoard &bb = bt->getBlackBoard();
        bb.set<Actor*>("Player", player);

        auto sn = new BehaviourTree::Sequence();
        sn->add(new Delay(3.0f));
        sn->add(new MoveActor(1.0f));
        sn->add(new BehaviourTree::DummySuccess());

        bt->setRootNode(sn);

        return bt;
    }

    BehaviourTree::BehaviourTree* GameBuilders::TestMovePlayerToLimit(Player* player)
    {
        auto bt = new BehaviourTree::BehaviourTree();

        BehaviourTree::BlackBoard& bb = bt->getBlackBoard();
        bb.set<Actor*>("Player", player);

        auto sn = new BehaviourTree::Sequence();
        sn->add(new Delay(3.0f));

        // move to the right
        sn->add(new SetDirection(false, true, false, false));
        sn->add(new ReachActorTarget(SCREEN_WIDTH - PLAYER_WIDTH));

        // move to the left
        sn->add(new SetDirection(true, false, false, false));
        sn->add(new ReachActorTarget(0.f));

        // resert direction
        sn->add(new SetDirection(false, false, false, false));
        sn->add(new BehaviourTree::DummySuccess());

        bt->setRootNode(sn);

        return bt;
    }

}
