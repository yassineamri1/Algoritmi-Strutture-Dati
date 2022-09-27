package esercizio4;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

public class DirectGraph<T,S extends Comparable> extends Graph<T,S>{


    private HashMap<T, Node<T,S>> nodes;

    public DirectGraph() {
        nodes = new HashMap<>();
    }

    @Override
    boolean createNode(T nodeValue) {
        if (nodeValue == null)
            throw new NullPointerException("nodeValue is null");
        else if(this.existsNode(nodeValue))
            return false;
        else {
            nodes.put(nodeValue, new Node<T, S>(nodeValue));
            return true;
        }
    }

    @Override
    boolean createEdge(T nodeStartValue, T nodeDestinationtValue, S label) {
        if (nodeStartValue == null || nodeDestinationtValue == null )
            throw new NullPointerException("nodeValue is null");
        else if (!this.existsNode(nodeStartValue) || !this.existsNode(nodeDestinationtValue) )
            return false;
        else if (this.existsEdge(nodeStartValue, nodeDestinationtValue))
            return false;
        else
            nodes.get(nodeStartValue).addEdge(nodes.get(nodeDestinationtValue), label);
        return true;
    }

    @Override
    boolean isDirect() {
        return true;
    }

    @Override
    boolean existsNode(T nodeValue) {
        return nodes.containsKey(nodeValue);
    }

    @Override
    boolean existsEdge(T nodeStartValue, T nodeDestinationtValue) {
        if (this.existsNode(nodeStartValue))
            return (nodes.get(nodeStartValue)).existsEdge(nodeDestinationtValue);
        else
            return false;
    }

    @Override
    void deleteEdge(T nodeStartValue, T nodeDestinationtValue) {
        nodes.get(nodeStartValue).removeEdge(nodes.get(nodeDestinationtValue));
    }

    @Override
    void deleteNode(T nodeValue) {  
        nodes.remove(nodeValue);
    }

    @Override
    List<Edge<T,S>> getEdges() {
        LinkedList<Edge<T,S>> arrayEdges= new LinkedList<>();
        nodes.keySet().forEach(
                (K) -> arrayEdges.addAll(nodes.get(K).neighbors())
        );

        return arrayEdges;
    }

    @Override
    List<T> getNodes() {
        ArrayList<T> arrayNode = new ArrayList<>();
        nodes.keySet().forEach(
                (K) -> arrayNode.add(K)
        );
        return arrayNode;
    }
}

