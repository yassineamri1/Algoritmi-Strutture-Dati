package esercizio4;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class Main {
    public static float sum;
    public static Graph<String, Float> testGraph(File file) {
        Graph<String, Float> g = new UndirectGraph<>();
        try {
            BufferedReader br = new BufferedReader(new FileReader(file));
            String line = br.readLine();
            String array[];
            while(line != null){
                array = line.split(",");
                g.createNode(array[0]);
                g.createNode(array[1]);
                g.createEdge(array[0], array[1], Float.parseFloat(array[2]));
                line = br.readLine();
            }
        } catch (IOException e) { e.printStackTrace(); }
        return g;
    }
    public static void main(String [] argv){
        long start = System.currentTimeMillis();
        String path = "src/italian_dist_graph.csv";
        UndirectGraph<String, Float> graph = (UndirectGraph<String, Float>) testGraph(new File(path));
        System.out.println("Graph creation Time:"+(System.currentTimeMillis()-start)+" ms");

        start = System.currentTimeMillis();
        UndirectGraph<String, Float> g = (UndirectGraph<String, Float>) Mst.kruskal(graph);
        System.out.println("Kruskal time :"+(System.currentTimeMillis()-start)+" ms");
        sum = 0;
        g.getEdges().forEach((e) -> {
            sum += e.getLabel()/1000;
        });
        System.out.println("Nodes: " + g.getNodes().size());
        System.out.println("Edges: " + g.getEdges().size() / 2);
        System.out.println("weight: "+ sum/2);
    }
}
