package esercizio4;

public class UndirectGraph<T,S extends Comparable> extends DirectGraph<T,S> {

    public UndirectGraph(){
        super();
    }

    @Override
    boolean isDirect() {
        return false;
    }

    @Override
    boolean createEdge(T nodeStartValue, T nodeDestinationtValue, S label) {
        super.createEdge(nodeStartValue,nodeDestinationtValue,label);
        super.createEdge(nodeDestinationtValue,nodeStartValue,label);
        return true;
    }

    @Override
    void deleteEdge(T nodeStartValue, T nodeDestinationtValue) {
        super.deleteEdge(nodeStartValue,nodeDestinationtValue);
        super.deleteEdge(nodeDestinationtValue,nodeStartValue);
    }
}