package esercizio4;
import org.junit.Test;

import java.util.ArrayList;


import static org.junit.Assert.*;

public class DirectGraphTest {

    @Test
    public void testAddNode() {
        DirectGraph<Integer, Integer> direct = new DirectGraph<>();
        direct.createNode(3);
        assertTrue(direct.existsNode(3));
    }

    @Test
    public void testAlredyExistNode() {
        DirectGraph<Integer, Integer> direct = new DirectGraph<>();
        direct.createNode(3);
        assertFalse(direct.createNode(3));
    }

    @Test
    public void testNotExistNode() {
        DirectGraph<Integer, Integer> direct = new DirectGraph<>();
        assertFalse(direct.existsNode(5));
    }

    @Test
    public void testIsDirect() {
        DirectGraph<Integer, Integer> direct = new DirectGraph<>();
        assertTrue(direct.isDirect());
    }


    @Test
    public void testNodeIsNull() {
        DirectGraph<Integer, Integer> direct = new DirectGraph<>();
        try {
            direct.createNode(null);
            assertTrue(false);
        } catch(Exception e) {
            assertTrue(true);
        }
    }

    @Test
    public void testAddEdge(){
        DirectGraph<Integer, Integer> direct = new DirectGraph<>();
        direct.createNode(3);
        direct.createNode(5);
        direct.createEdge(3, 5, 5);
        assertTrue(direct.existsEdge(3,5));
    }

    @Test
    public void testAddEdgeIfParameterIsNull() {
        DirectGraph<Integer, Integer> direct = new DirectGraph<>();
        try {
            direct.createNode(1);
            direct.createEdge(1, null, 5);
            assertTrue(false);
        } catch (Exception e) {
            assertTrue(true);
        }
    }

    @Test
    public void testExistEdge() {
        DirectGraph<Integer, Integer> direct = new DirectGraph<>();
        direct.createNode(0);
        direct.createNode(1);
        direct.createNode(2);
        direct.createEdge(1,2, null);
        assertFalse(direct.existsEdge(1,3));    // v1 exists and v2 not
        assertFalse(direct.existsEdge(3,1));    // v1 not exists and v2 exists
        assertFalse(direct.existsEdge(3,4));    // v1 and v2 not exists
        assertTrue(direct.existsEdge(1,2));     // v1 and v2 exist and are linked
        assertFalse(direct.existsEdge(0,1));     // v1 and v2 exist but aren't linked
    }

    @Test
    public void testDeleteNode() {
        DirectGraph<Integer, Integer> direct = new DirectGraph<>();
        direct.createNode(3);
        direct.deleteNode(3);
        assertFalse(direct.existsNode(3));
    }

    @Test
    public void testDeleteEdge() {
        DirectGraph<Integer, Integer> direct = new DirectGraph<>();
        direct.createNode(3);
        direct.createNode(5);
        direct.createEdge(5,3,2);
        direct.deleteEdge(5,3);
        assertFalse(direct.existsEdge(5,3));
    }

    @Test
    public void testGetNodes() {
        DirectGraph<Integer, Integer> direct = new DirectGraph<>();
        direct.createNode(3);
        direct.createNode(5);
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.add(3);
        arr.add(5);
        assertEquals(arr, direct.getNodes());
    }

    /*@Test
    public void testGetEdges() {
        DirectGraph<Integer, Integer> direct = new DirectGraph<>();
        direct.createNode(3);
        direct.createNode(5);
        direct.createEdge(5,3,2);
        LinkedList <Edge<Integer, Integer>> lin = new LinkedList<Edge<Integer, Integer>();
    }*/
}
