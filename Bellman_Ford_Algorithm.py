class Graph:
    def __init__(self):
        # Dictionary that maps vertex keys to corresponding vertex objects
        self.vertices = {}

    def add_vertex(self, key):
        """Adds a vertex with the given key to the graph."""
        if key not in self.vertices:
            vertex = Vertex(key)
            self.vertices[key] = vertex
        else:
            print(f"Vertex {key} already exists.")

    def get_vertex(self, key):
        """Returns the vertex object with the corresponding key."""
        return self.vertices.get(key)

    def __contains__(self, key):
        """Checks if a vertex with the given key exists in the graph."""
        return key in self.vertices

    def add_edge(self, src_key, dest_key, weight=1):
        """Adds a directed edge from src_key to dest_key with the given weight."""
        if src_key in self.vertices and dest_key in self.vertices:
            self.vertices[src_key].add_neighbor(self.vertices[dest_key], weight)
        else:
            print(f"One or both vertices {src_key} and {dest_key} do not exist.")

    def does_edge_exist(self, src_key, dest_key):
        """Checks if an edge exists from src_key to dest_key."""
        if src_key in self.vertices and dest_key in self.vertices:
            return self.vertices[src_key].is_pointing_to(self.vertices[dest_key])
        return False

    def __len__(self):
        """Returns the number of vertices in the graph."""
        return len(self.vertices)

    def __iter__(self):
        """Returns an iterator over the vertex objects in the graph."""
        return iter(self.vertices.values())


class Vertex:
    def __init__(self, key):
        # Key identifies the vertex
        self.key = key
        # Dictionary mapping neighboring vertices to the weight of the edge
        self.adjacency_list = {}

    def get_key(self):
        """Returns the key corresponding to this vertex object."""
        return self.key

    def add_neighbor(self, destination, weight):
        """Adds a directed edge to the destination vertex with the given weight."""
        self.adjacency_list[destination] = weight

    def get_neighbors(self):
        """Returns all vertices pointed to by this vertex."""
        return self.adjacency_list.keys()

    def get_edge_weight(self, destination):
        """Gets the weight of the edge from this vertex to the destination."""
        return self.adjacency_list.get(destination, float('inf'))

    def is_pointing_to(self, destination):
        """Checks if this vertex has an edge pointing to the destination."""
        return destination in self.adjacency_list


def bellman_ford(graph, source):
    """
    Executes the Bellman-Ford algorithm to compute the shortest path from the source vertex.
    
    Returns a dictionary where the keys are vertices and values are the minimum distances 
    from the source vertex.
    """
    # Initialize distances from source to all vertices as infinity
    distances = {vertex: float('inf') for vertex in graph}
    distances[source] = 0

    # Relax edges repeatedly for (number of vertices - 1) iterations
    for _ in range(len(graph) - 1):
        for vertex in graph:
            for neighbor in vertex.get_neighbors():
                new_distance = distances[vertex] + vertex.get_edge_weight(neighbor)
                if new_distance < distances[neighbor]:
                    distances[neighbor] = new_distance

    return distances


# Main code for menu-driven interaction with the graph
graph = Graph()
print("Menu")
print("add vertex <key>")
print("add edge <src> <dest> <weight>")
print("bellman-Ford <source vertex key>")
print("display graph")
print("quit")

while True:
    user_input = input("Enter a command: ").split()

    command = user_input[0]
    
    if command == "add":
        subcommand = user_input[1]
        
        if subcommand == "vertex":
            vertex_key = int(user_input[2])
            graph.add_vertex(vertex_key)

        elif subcommand == "edge":
            src_key = int(user_input[2])
            dest_key = int(user_input[3])
            weight = int(user_input[4])

            if src_key not in graph:
                print(f"Vertex {src_key} does not exist.")
            elif dest_key not in graph:
                print(f"Vertex {dest_key} does not exist.")
            else:
                if not graph.does_edge_exist(src_key, dest_key):
                    graph.add_edge(src_key, dest_key, weight)
                else:
                    print(f"Edge from {src_key} to {dest_key} already exists.")

    elif command == "bellman-ford":
        source_key = int(user_input[1])
        source_vertex = graph.get_vertex(source_key)
        
        if source_vertex:
            distances = bellman_ford(graph, source_vertex)
            print(f"Distances from vertex {source_key}:")
            for vertex, distance in distances.items():
                print(f"Distance to {vertex.get_key()}: {distance}")
            print()
        else:
            print(f"Vertex {source_key} does not exist.")

    elif command == "display":
        print("Vertices: ", end="")
        for vertex in graph:
            print(vertex.get_key(), end=" ")
        print("\nEdges:")
        for vertex in graph:
            for neighbor in vertex.get_neighbors():
                weight = vertex.get_edge_weight(neighbor)
                print(f"(src={vertex.get_key()}, dest={neighbor.get_key()}, weight={weight})")
        print()

    elif command == "quit":
        break

    else:
        print("Invalid command.")
