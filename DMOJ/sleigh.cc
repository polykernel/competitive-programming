#include <iostream>
#include <vector>
#include <stack>
#define MAXN 100000
#define INF 0x3f3f3f3f

std::vector<std::pair<int, int>> adj[MAXN+1];
std::stack<int> stack;
int dist[MAXN+1];

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    dist.fill(INF);

    int s = 0;
    int m = 0;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
        // Compute sum of all weights.
        s += w;
    }

    stack.push(0);
    dist[0] = 0;

    // Find longest path.
    while (!stack.empty()) {
        int c = stack.top();
        stack.pop();

        // Update longest path.
        if (dist[c] > m) m = dist[c];

        for (const auto& [u, w] : adj[c]) {
            if (dist[u] == INF) {
                dist[u] = dist[c] + w;
                stack.push(u);
            }
        }
    }

    std::cout << 2 * s - m << '\n';

    return 0;
}