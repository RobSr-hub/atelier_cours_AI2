#pragma once
#include "Composites.h"
#include "DummyLeaves.h"
#include "Core/BehaviourTree.h"

namespace BehaviourTree
{
    class Builders
    {
    public:
        // Testing case for the tree, can be replaced with a more complex tree structure
        static BehaviourTree* TestSequence()
        {
            auto bt = new BehaviourTree();

            auto sn = new Sequence();
            sn->add(new DummySuccess());
            sn->add(new DummyFail());
            sn->add(new DummySuccess());

            bt->setRootNode(sn);

            return bt;
        }

        static BehaviourTree* TestSelector()
        {
            auto bt = new BehaviourTree();

            auto sn = new Selector();
            sn->add(new DummySuccess());
            sn->add(new DummyFail());
            sn->add(new DummyFail());

            bt->setRootNode(sn);

            return bt;
        }

        static BehaviourTree* TestComposites()
        {
            auto bt = new BehaviourTree();
            auto sln = new Selector();
            auto sqn = new Sequence();

            sqn->add(new DummySuccess());
            sqn->add(sln);
            sqn->add(new DummySuccess());

            sln->add(new DummyFail());
            sln->add(new DummyFail());
            sln->add(new DummyFail());

            bt->setRootNode(sqn);

            return bt;
        }
    };
}
