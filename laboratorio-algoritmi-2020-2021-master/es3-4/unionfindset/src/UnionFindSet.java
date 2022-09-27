package unionfindset;

import java.util.HashMap;
import java.util.Map;

public class UnionFindSet<T> {

    private Map<T, Node<T>> elementsMap;

    public UnionFindSet() {
        elementsMap = new HashMap<>();
    }

    /*
     * crea un nuovo insime singoletto elem
     * lancia eccezione se elem è null oppure elem esiste già 
     */
    public boolean makeSet(T elem) {  //TODO: cambiare a void
        if(elem == null)
            return false;             //TODO: lanciare eccezione
        else if(elementsMap.containsKey(elem))
            return false;           //TODO: idem
        else {
            elementsMap.putIfAbsent(elem, new Node<T>(elem));
            elementsMap.get(elem).setRank(0);
        }
        return true;
    }

    /*
     * dato un elemento, restituisce il rappresentante dell'insime a cui appartine
     * lancia eccezione se elem è null oppure non esiste
     */
    public T findSet(T valElem) {
      Node <T> currentNode;
      T parentVal;

        if(valElem == null)
          return null;                 //TODO: lanciare eccezione
        else if(!elementsMap.containsKey(valElem))
          return null;                //TODO: idem
        else
          currentNode = elementsMap.get(valElem);
        
        parentVal = _findSet(currentNode); //TODO: controllare euristica

        if (currentNode.getParent().getVal() != parentVal);
          currentNode.setParent(elementsMap.get(parentVal));
        
        return parentVal;
    }

    /*
     * metodo ausiliario a findSet
     */
    private T _findSet(Node<T> currentNode) {
        if (currentNode.getParent() == currentNode)
            return currentNode.getVal();
        else
            return _findSet(currentNode.getParent());
    }

    /*
     * Dati due elementi, fonde gli insiemi cui appartengono
     */
    public void union(T data1, T data2) {
        Node<T> root1 = elementsMap.get(this.findSet(data1));
        Node<T> root2 = elementsMap.get(this.findSet(data2));
        
        // TODO: aggiungere controlli
        if (root1.getRank() < root2.getRank()) {
          root1.setParent(root2);
        } else {
          if (root1.getRank() == root2.getRank())
              root1.setRank(root1.getRank() + 1);

          root2.setParent(root1);
        }
    }
}

