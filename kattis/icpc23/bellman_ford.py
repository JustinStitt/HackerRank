"""
The Bellman-Ford algorithm finds the shortest path in a Graph from a source to
*all* other vertices asdasd asd asd .
This algorithm supports negative weights (unlike Dijkstra's)
"""
from collections import defaultdict
from math import inf


INFINITY = inf


class Graph:
    def __init__(self):
        self.adj = defaultdict(lambda: list())

    def addEdge(self, u, v, w):
        self.adj[u].append((v, w))
        len(self.adj[v])  # used to trigger default construction

    def keys(self):
        return self.adj.keys()

    def items(self):
        return self.adj.items()

    def __len__(self):
        return len(self.adj)


def bellmanFord(G: Graph, src: int):
    V = len(G)
    dists = [INFINITY] * V  # initialize all weights
    print(dists)
    dists[src] = 0  # starting at src, distance 0

    for _ in range(V - 1):
        for vertex, edges in G.items():
            for dest, weight in edges:
                if dists[vertex] + weight < dists[dest]:
                    dists[dest] = dists[vertex] + weight

    # detect negative cycles by running one more iteration
    for vertex, edges in G.items():
        for dest, weight in edges:
            if dists[vertex] + weight < dists[dest]:
                print("NEGATIVE CYCLE FOUND BETWEEN", vertex, "and", dest)
                exit(0)

    return dists


def main():
    G = Graph()
    G.addEdge(0, 3, -2)
    G.addEdge(0, 1, 1)
    G.addEdge(1, 2, -3)
    G.addEdge(2, 4, 1)
    G.addEdge(2, 3, 4)
    G.addEdge(3, 5, 2)
    G.addEdge(3, 0, -1)
    dists = bellmanFord(G, src=0)
    print(dists)


if __name__ == "__main__":
    main()
