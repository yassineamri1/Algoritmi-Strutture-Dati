package unionfindset;

public class Node<T> {
    private T val;
    private Node<T> parent;
    private int rank;

    public Node(T val){
        this.parent = this;
        this.val = val;
    }

    public Node(T val, Node<T> parent){
        this.parent = parent;
        this.val = val;
    }

    public T getVal() {
        return val;
    }

    public Node<T> getParent() {
        return parent;
    }

    public void setParent(Node<T> parent) {
        if (parent != null)
            this.parent = parent;
        else
            System.out.println("errore"); // TODO: lanciare un eccezione
    }

    public void setVal(T val) {
        if (val != null)
            this.val = val;
        else
            System.out.println("errore"); // TODO: lanciare un'eccezione
    }

    public int getRank() {
        return rank;
    }

    public void setRank(int rank) {
        this.rank = rank;
    }
}
