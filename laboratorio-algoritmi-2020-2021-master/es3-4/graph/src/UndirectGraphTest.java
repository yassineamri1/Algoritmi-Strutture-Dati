package esercizio4;

import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.*;


public class UndirectGraphTest {

    @Test
    public void testAddNode() {
        UndirectGraph<Integer, Integer> undirect = new UndirectGraph<>();
        undirect.createNode(3);
        assertTrue(undirect.existsNode(3));
    }

    @Test
    public void testAlredyExistNode() {
        UndirectGraph<Integer, Integer> undirect = new UndirectGraph<>();
        undirect.createNode(3);
        assertFalse(undirect.createNode(3));
    }

    @Test
    public void testNotExistNode() {
        UndirectGraph<Integer, Integer> undirect = new UndirectGraph<>();
        assertFalse(undirect.existsNode(5));
    }

    @Test
    public void testIsUndirect() {
        UndirectGraph<Integer, Integer> undirect = new UndirectGraph<>();
        assertFalse(undirect.isDirect());
    }


    @Test
    public void testNodeIsNull() {
        UndirectGraph<Integer, Integer> undirect = new UndirectGraph<>();
        try {
            undirect.createNode(null);
            assertTrue(false);
        } catch(Exception e) {
            assertTrue(true);
        }
    }

    @Test
    public void testAddEdge(){
        UndirectGraph<Integer, Integer> undirect = new UndirectGraph<>();
        undirect.createNode(3);
        undirect.createNode(5);
        undirect.createEdge(3, 5, 5);
        assertTrue(undirect.existsEdge(3,5));
        assertTrue(undirect.existsEdge(5,3));
    }

    @Test
    public void testAddEdgeIfParameterIsNull() {
        UndirectGraph<Integer, Integer> undirect = new UndirectGraph<>();
        try {
            undirect.createNode(1);
            undirect.createEdge(1, null, 5);
            assertTrue(false);
        } catch (Exception e) {
            assertTrue(true);
        }
    }

    @Test
    public void testExistEdge() {
        UndirectGraph<Integer, Integer> undirect = new UndirectGraph<>();
        undirect.createNode(0);
        undirect.createNode(1);
        undirect.createNode(2);
        undirect.createEdge(1,2, null);
        assertFalse(undirect.existsEdge(1,3));    // v1 exists and v2 not
        assertFalse(undirect.existsEdge(3,1));    // v1 not exists and v2 exists
        assertFalse(undirect.existsEdge(3,4));    // v1 and v2 not exists
        assertTrue(undirect.existsEdge(1,2));     // v1 and v2 exist and are linked
        assertFalse(undirect.existsEdge(0,1));     // v1 and v2 exist but aren't linked
    }

    @Test
    public void testGetNodes() {
        UndirectGraph<Integer, Integer> undirect = new UndirectGraph<>();
        undirect.createNode(3);
        undirect.createNode(5);
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.add(3);
        arr.add(5);
        assertEquals(arr, undirect.getNodes());
    }

    @Test
    public void testDeleteNode() {
        UndirectGraph<Integer, Integer> undirect = new UndirectGraph<>();
        undirect.createNode(3);
        undirect.deleteNode(3);
        assertFalse(undirect.existsNode(3));
    }

    @Test
    public void testDeleteEdge() {
        UndirectGraph<Integer, Integer> undirect = new UndirectGraph<>();
        undirect.createNode(3);
        undirect.createNode(5);
        undirect.createEdge(3,5,2);
        undirect.deleteEdge(5,3);
        assertFalse(undirect.existsEdge(3,5));
        assertFalse(undirect.existsEdge(5,3));
    }
}
