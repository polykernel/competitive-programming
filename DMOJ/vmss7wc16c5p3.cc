#include <iostream>
#include <vector>
#include <queue>
#define MAXN 10000

std::vector<int> adj[MAXN+1];
bool vst[MAXN+1];
int dist[MAXN+1];
std::queue<int> queue;
int d1, d2;

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    for (int i = 0; i < n-1; ++i) {
        int x, y;
        std::cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Initial BFS.
    vst[1] = true;
    queue.push(1);

    while (!queue.empty()) {
        int c = queue.front();
        queue.pop();

        d1 = c;

        for (const int& u : adj[c]) {
            if (!vst[u]) {
                vst[u] = true;
                dist[u] = dist[c] + 1;
                queue.push(u);
            }
        }
    }

    // Reset visited array.
    std::fill(vst, vst+n+1, false);

    // Second BFS.
    vst[d1] = true;
    dist[d1] = 0;
    queue.push(d1);

    while (!queue.empty()) {
        int c = queue.front();
        queue.pop();

        d2 = c;

        for (const int& u : adj[c]) {
            if (!vst[u]) {
                vst[u] = true;
                dist[u] = dist[c] + 1;
                queue.push(u);
            }
        }
    }

    // Print diameter of tree.
    std::cout << dist[d2] << '\n';

    return 0;
}
