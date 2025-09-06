#include "Node.h"
#include "Edge.h"

void Node::MarkEdgeTo(int neighborId) {

    for (Edge* e : Edges) {
        if (e->getEnd()->GetNodeNum() == neighborId) {
            e->mark();
            e->getStart()->GetCurrentNeighbers()--;
            e->getEnd()->GetCurrentNeighbers()--;
            if (e->getTwin()) {
                e->getTwin()->mark();
            }
            return;
        }
    }
}
