package unionfindset;

import org.junit.Test;

import static org.junit.Assert.*;

public class UnionFindSetTest {

    @Test
    public void testMakeSet() {
        UnionFindSet<Integer> u = new UnionFindSet<Integer>();
        assertTrue(u.makeSet(5));
    }

    @Test
    public void testMakeSetIsNull() {
        UnionFindSet<Integer> u = new UnionFindSet<Integer>();
        assertFalse(u.makeSet(null));
    }

    @Test
    public void testMakeAlredyExist() {
        UnionFindSet<Integer> u = new UnionFindSet<Integer>();
        u.makeSet(5);
        assertFalse(u.makeSet(5));
    }

    @Test
    public void testUnion() {
        UnionFindSet<Integer> u = new UnionFindSet<Integer>();
        u.makeSet(5);
        u.makeSet(3);
        u.union(5,3);
        int i = u.findSet(5);
        assertEquals(5, i);
    }


    @Test
    public void testUnionElemsAreSame() {
        UnionFindSet<Integer> u = new UnionFindSet<Integer>();
        u.makeSet(5);
        u.union(5,5);
        int i = u.findSet(5);
        assertEquals(5, i);
    }

    @Test
    public void testFindSetNotExist() {
        UnionFindSet<Integer> u = new UnionFindSet<Integer>();
        assertNull(u.findSet(5));
    }

    @Test
    public void testFindSetIsNull() {
        UnionFindSet<Integer> u = new UnionFindSet<Integer>();
        assertNull(u.findSet(null));
    }

    @Test
    public void testFindSetParentOfElement() {
        UnionFindSet<Integer> u = new UnionFindSet<Integer>();
        u.makeSet(2);
        u.makeSet(4);
        u.union(2,4);
        int i = u.findSet(4);
        assertEquals(2, i);
    }

    @Test
    public void testFindSetParentOfParent() {
        UnionFindSet<Integer> u = new UnionFindSet<Integer>();
        u.makeSet(2);
        u.makeSet(4);
        u.union(2,4);
        int j = u.findSet(2);
        assertEquals(2, j);
    }

}

