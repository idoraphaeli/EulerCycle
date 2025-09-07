#include "Vertex.h"
#include "Edge.h"

void Vertex::MarkEdgeTo(int neighborId) {

    for (Edge* e : Edges) {
        if (e->getEnd()->GetVertexNum() == neighborId) {
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
