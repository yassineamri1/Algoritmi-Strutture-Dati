package esercizio4;

public class Edge<T,S extends Comparable> implements Comparable<Edge<T,S>> {
    private final T node1;
    private final T node2;
    private S label;

    public Edge(T node1, T node2, S label) {
        this.node1 = node1;
        this.node2 = node2;
        this.label = label;
    }

    public S getLabel() {
        return this.label;
    }

    public void setLabel(S label) {
        this.label = label;
    }

    public T getNode1() {
        return node1;
    }

    public T getNode2() {
        return node2;
    }
    /*
        @Override
        public int compareTo(Edge<T,S> E) {
            return E.getLabel().compareTo(this.getLabel());
        }
    */
    @Override
    public int compareTo(Edge<T,S> E) {
        return this.getLabel().compareTo(E.getLabel());
    }

    @Override
    public boolean equals(Object e2) {
        if (e2 instanceof Edge)
            return this.node1.equals(((Edge) e2).getNode1()) && this.node2.equals(((Edge) e2).getNode2());
        else
            return false;
    }
}