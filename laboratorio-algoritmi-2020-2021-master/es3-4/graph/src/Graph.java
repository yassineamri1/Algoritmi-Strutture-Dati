package esercizio4;

import java.util.List;

public abstract class Graph<T,S extends Comparable> {

    /**
     * Create a new node of the graph
     *
     * @param nodeValue the value to insert as new node
     */
    abstract boolean createNode(T nodeValue);

    /**
     * Create a new edge between two nodes
     *
     * @param nodeStartValue the starter node's value of the edge
     * @param nodeDestinationValue the destination node's value of the edge
     * @param label the label of the edge
     */
    abstract boolean createEdge(T nodeStartValue, T nodeDestinationValue, S label);

    /**
     * check if the graph is direct
     *
     * @return  true if the graph is direct,
     *          false otherwise.
     */
    abstract boolean isDirect();

    /**
     * check if the node exists in the graph
     *
     * @param nodeValue the value of the node
     * @return  true if the node exists,
     *          false otherwise.
     */
    abstract boolean existsNode(T nodeValue);

    /**
     * check if the edge exists in the graph
     *
     * @param nodeStartValue the starter node's value of the edge
     * @param nodeDestinationValue the destination node's value of the edge
     * @return  true if the edge between the two nodes exists,
     *          false otherwise.
     */
    abstract boolean existsEdge(T nodeStartValue, T nodeDestinationValue);

    /**
     * delete che gived node of the graph
     *
     * @param nodeValue the value of node to delete
     */
    abstract void deleteNode(T nodeValue);

    /**
     * delete che gived edge of the graph
     *
     * @param nodeStartValue the starter node's value of the edge
     * @param nodeDestinationValue the destination node's value of the edge
     */
    abstract void deleteEdge(T nodeStartValue, T nodeDestinationValue);

    /**
     * return all nodes in the graph
     *
     * @return: a node's value list
     */
    abstract List<T> getNodes();


    /**
     * return all edge in the graph
     *
     * @return: a list of edge
     */
    abstract List<Edge<T,S>> getEdges();
}
