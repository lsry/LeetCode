#include <fast_io.h>
#include <vector>
#include <array>
#include <utility>
#include <queue>

struct Path
{
    std::vector<int> nodes;
    int cost;
    int node;

    Path(std::vector<int> const &nodes_, int cost_, int node_): nodes(nodes_), cost(cost_), node(node_) {}
    Path(Path const &) = default;
    Path& operator=(const Path &) = default;
    Path() {}
};

std::vector<Path> dijkstra(std::vector<std::vector<int>> const &edges, int n, int src) {
    std::vector<std::vector<std::pair<int, int>>> adjoints(n, std::vector<std::pair<int, int>>());
    for (std::vector<int> const &edge : edges) {
        adjoints[edge[0]].push_back(std::make_pair(edge[1], edge[2]));
        adjoints[edge[1]].push_back(std::make_pair(edge[0], edge[2]));
    }
    std::vector<bool> visited(n, false);
    auto fn = [](Path const &p1, Path const &p2) {
        return p1.cost > p2.cost;
    };
    std::priority_queue<Path, std::vector<Path>, decltype(fn)> pq(fn);
    std::vector<int> nns{0};
    Path fisrt(nns, 0, src);
    pq.push(fisrt);
    std::vector<Path> distances(n);
    while (!pq.empty()) {
        Path cur = pq.top();
        pq.pop();
        if (visited[cur.node]) {
            continue;
        }
        visited[cur.node] = true;
        distances[cur.node] = cur;
        for (auto &[nextNode, nextCost] : adjoints[cur.node]) {
            if (visited[nextNode]) {
                continue;
            }
            Path nextPath(cur);
            nextPath.cost = cur.cost + nextCost;
            nextPath.nodes.push_back(nextNode);
            nextPath.node = nextNode;
            pq.push(nextPath);
        }
    }
    return distances;
}

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> edges{{0, 1, 2}, {0, 2, 6}, {1, 3, 5}, {2, 3, 8}, {3, 5, 15}, {3, 4, 10}, {4, 5, 6}, {5, 6, 6}, {4, 6, 2}};
    std::vector<Path> dis{dijkstra(edges, 7, 0)};
    for (Path const &p : dis) {
        print(0, "->", p.node, ", cost: ", p.cost, "\n", "path:");
        for (const int x : p.nodes) {
            print(x, "->");
        }
        print("\n");
    }
    print("\n");
    return 0;
}
