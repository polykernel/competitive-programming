#include <iostream>
#include <vector>
#include <queue>
#define MAXN 9999

std::vector<int> adj[MAXN+1];
std::queue<int> queue;
int in[MAXN+1];
int path[MAXN+1];

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n;

    int u, v;

    std::cin >> n;

    std::cin >> u >> v;

    while (u && v) {
        adj[u].push_back(v);
        ++in[v];
        std::cin >> u >> v;
    }

    queue.push(1);
    path[1] = 1;

    while (!queue.empty()) {
        // Get minimum node with in-degree of 0.
        int c = queue.front();
        queue.pop();

        for (const auto& u : adj[c]) {
            // Add path value of current node to all adjacent node.
            path[u] += path[c];
            if (--in[u] == 0) queue.push(u);
        }
    }

    std::cout << path[n] << '\n';

    return 0;
}