#include <iostream>
#include <vector>
#include <array>
#include <queue>
#define MAXN 500000

std::array<std::vector<int>, MAXN+1> adj;
std::queue<int> queue;
std::array<bool, MAXN+1> vst;
std::array<int, MAXN+1> dist1;
std::array<int, MAXN+1> dist2;
int d1, d2;

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int c = 0;

    int n;
    std::cin >> n;

    for (int i = 0; i < n-1; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue.push(1);
    vst[1] = true;

    // Find one endpoint of diameter.
    while (!queue.empty()) {
        c = queue.front();
        queue.pop();

        for (const auto& u : adj[c]) {
            if (!vst[u]) {
                vst[u] = true;
                queue.push(u);
            }
        }
    }

    d1 = c;

    vst.fill(false);

    dist1[d1] = 1;
    vst[d1] = true;
    queue.push(d1);


    // Find the other endpoint of diameter.
    while (!queue.empty()) {
        c = queue.front();
        queue.pop();

        for (const auto& u : adj[c]) {
            if (!vst[u]) {
                vst[u] = true;
                dist1[u] = dist1[c] + 1;
                queue.push(u);
            }
        }
    }

    d2 = c;

    vst.fill(false);

    dist2[d2] = 1;
    vst[d2] = true;
    queue.push(d2);

    // Find the other endpoint of diameter.
    while (!queue.empty()) {
        c = queue.front();
        queue.pop();

        for (const auto& u : adj[c]) {
            if (!vst[u]) {
                vst[u] = true;
                dist2[u] = dist2[c] + 1;
                queue.push(u);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << std::max(dist1[i], dist2[i]) << '\n';
    }

    return 0;
}
