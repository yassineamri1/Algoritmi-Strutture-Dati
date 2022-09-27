package esercizio4;

import unionfindset.*;
import java.util.List;

public class Mst {
    public static <T,S extends Comparable> Graph<T,S> kruskal(Graph<T,S> g) {
        Graph<T,S> mstGraph;
        if (g == null)
            return null;
        if (g.isDirect())
            mstGraph = new DirectGraph<>();
        else
            mstGraph = new UndirectGraph<>();

        UnionFindSet<T> u = new UnionFindSet<>();
        g.getNodes().forEach((n) -> {
            u.makeSet(n);
            mstGraph.createNode(n);
        });
        List<Edge<T,S>> orderEdges = g.getEdges();
        orderEdges.sort(null);
        orderEdges.forEach((e) -> {
            if(!(u.findSet(e.getNode1())).equals(u.findSet(e.getNode2()))) {
                mstGraph.createEdge(e.getNode1(), e.getNode2(), e.getLabel());
                u.union(e.getNode1(), e.getNode2());
            }
        });

        return mstGraph;
    }
}
