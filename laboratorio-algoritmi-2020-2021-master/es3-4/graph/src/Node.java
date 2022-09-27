package esercizio4;

import java.util.ArrayList;

public class Node<T,S extends Comparable> {
    private T value;
    private ArrayList<Edge<T,S>> edges;

    public Node(T value) {
        this.value = value;
        this.edges = new ArrayList<>();
    }

    public T getValue() {
        return value;
    }

    public void addEdge(Node<T,S> v2, S label) {
        edges.add(new Edge(this.getValue(), v2.getValue(), label));
    }

    public void removeEdge(Node<T,S> v2) {
        for ( int i=0; i < edges.size(); i++) {
            if (edges.get(i).getNode2().equals(v2.getValue()))
                edges.remove(edges.get(i));
            return;
        }
    }

    public ArrayList<Edge<T, S>> neighbors() {
        return edges;
    }

    public boolean existsEdge(T v2) {
        for ( int i=0; i < edges.size(); i++) {
            T v1 = edges.get(i).getNode2();
            if (v1.equals(v2))
                return true;
        }
        return false;
    }

    @Override
    public boolean equals(Object v2) {
        //return v2 instanceof Node && this.value == ((Node) v2).getValue();
        return v2 instanceof Node && (this.getValue()).equals(((Node <T,S>) v2).getValue());
    }
}