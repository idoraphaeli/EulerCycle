#include "Node.h"
#include "Edge.h"

void Node::MarkEdgeTo(int neighborId) {

    for (Edge* e : Edges) {
        if (e->getEnd()->GetNodeNum() == neighborId) {
            e->mark();
            if (e->getTwin()) {
                e->getTwin()->mark();
            }
            return;
        }
    }
}
