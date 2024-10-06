import java.util.*;

// Node class to store node id, f(n), g(n) values
class Node implements Comparable<Node> {
    int id;
    double f, g;
    
    public Node(int id, double f, double g) {
        this.id = id;
        this.f = f;
        this.g = g;
    }

    // Compare nodes based on f(n) value (for the priority queue)
    @Override
    public int compareTo(Node other) {
        return Double.compare(this.f, other.f);
    }
}

public class AStarPathfinding {
    
    // Function to find the shortest path from start to goal using A*
    public static List<Integer> aStar(int start, int goal, Map<Integer, List<int[]>> graph, Map<Integer, Double> heuristic) {
        PriorityQueue<Node> openList = new PriorityQueue<>();
        Map<Integer, Double> gScore = new HashMap<>();
        Map<Integer, Integer> cameFrom = new HashMap<>();
        Set<Integer> closedList = new HashSet<>();

        gScore.put(start, 0.0);
        openList.add(new Node(start, heuristic.get(start), 0));

        while (!openList.isEmpty()) {
            Node current = openList.poll();

            // If the goal node is reached, reconstruct and return the path
            if (current.id == goal) {
                return reconstructPath(cameFrom, current.id);
            }

            closedList.add(current.id);

            // For each neighbor of the current node
            for (int[] neighborData : graph.get(current.id)) {
                int neighbor = neighborData[0];
                double weight = neighborData[1];

                if (closedList.contains(neighbor)) {
                    continue; // Ignore the node if already processed
                }

                // Calculate tentative g score (g(n) + cost(n, m))
                double tentativeG = gScore.get(current.id) + weight;

                if (!gScore.containsKey(neighbor) || tentativeG < gScore.get(neighbor)) {
                    // Record the best path to the neighbor
                    cameFrom.put(neighbor, current.id);
                    gScore.put(neighbor, tentativeG);
                    double f = tentativeG + heuristic.get(neighbor);  // f(n) = g(n) + h(n)

                    // Add neighbor to the open list if not already in it
                    openList.add(new Node(neighbor, f, tentativeG));
                }
            }
        }

        // No path found
        return new ArrayList<>();
    }

    // Heuristic function (e.g., Manhattan distance for grids, Euclidean for general graphs)
    public static double heuristic(int node, int goal) {
        // In a 2D grid, you might use something like Manhattan distance:
        // return Math.abs(node.x - goal.x) + Math.abs(node.y - goal.y);
        return 0;  // Placeholder, define according to your graph
    }

    // Helper function to reconstruct the path from the cameFrom map
    private static List<Integer> reconstructPath(Map<Integer, Integer> cameFrom, int current) {
        List<Integer> path = new ArrayList<>();
        while (cameFrom.containsKey(current)) {
            path.add(current);
            current = cameFrom.get(current);
        }
        path.add(current);  // Add the start node
        Collections.reverse(path);  // Reverse the list to get path from start to goal
        return path;
    }

    public static void main(String[] args) {
        // Graph representation: node -> list of (neighbor, weight) pairs
        Map<Integer, List<int[]>> graph = new HashMap<>();
        graph.put(1, Arrays.asList(new int[]{2, 1}, new int[]{3, 3}));
        graph.put(2, Arrays.asList(new int[]{4, 1}, new int[]{5, 4}));
        graph.put(3, Arrays.asList(new int[]{5, 2}));
        graph.put(4, Arrays.asList(new int[]{5, 2}));
        graph.put(5, Arrays.asList(new int[]{6, 1}));
        graph.put(6, new ArrayList<>());

        // Heuristic values (these would typically be precomputed)
        Map<Integer, Double> heuristic = new HashMap<>();
        heuristic.put(1, 4.0);
        heuristic.put(2, 3.0);
        heuristic.put(3, 3.0);
        heuristic.put(4, 2.0);
        heuristic.put(5, 1.0);
        heuristic.put(6, 0.0);

        // Find the shortest path from node 1 to node 6
        List<Integer> path = aStar(1, 6, graph, heuristic);
        System.out.println("Shortest Path: " + path);
    }
}
