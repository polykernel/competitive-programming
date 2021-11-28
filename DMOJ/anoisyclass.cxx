#include <iostream>
#include <vector>
#include <queue>
#define MAXN 1000

std::vector<int> adj[MAXN+1];
std::queue<int> queue;
int in[MAXN+1];
int count;

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m;

    std::cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        ++in[v];
    }

    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) queue.push(i);
    }

    while (!queue.empty()) {
        // Get first node in the queue with in-degree of 0.
        int c = queue.front();
        queue.pop();

        // Increment the order counter.
        ++count;

        for (const auto& u : adj[c]) {
            if (--in[u] == 0) queue.push(u);
        }
    }

    // If the order is equal to the number of student, there exists a topological ordering.
    // Otherwise, there is a cycle in the graph.
    if (count == n) std::cout << "Y\n";
    else std::cout << "N\n";

    return 0;
}