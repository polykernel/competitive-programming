#include <iostream>
#include <vector>
#include <stack>
#define MAXN 10000

std::vector<int> adj[MAXN+1];
bool vst[MAXN+1];
int dist[MAXN+1];
std::stack<int> stack;
int d1, d2;

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    dist.fill(-1);

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
    stack.push(1);

    while (!stack.empty()) {
        int c = stack.top();
        stack.pop();

        if (dist[c] > dist[d1]) d1 = c;

        for (const int& u : adj[c]) {
            if (!vst[u]) {
                vst[u] = true;
                dist[u] = dist[c] + 1;
                stack.push(u);
            }
        }
    }

    vst.fill(false);

    // Second DFS.
    vst[d1] = true;
    dist[d1] = 0;
    stack.push(d1);

    while (!stack.empty()) {
        int c = stack.top();
        stack.pop();

        if (dist[c] > dist[d2]) d2 = c;

        for (const int& u : adj[c]) {
            if (!vst[u]) {
                vst[u] = true;
                dist[u] = dist[c] + 1;
                stack.push(u);
            }
        }
    }

    // Print diameter of tree.
    std::cout << dist[d2] << '\n';

    return 0;
}
