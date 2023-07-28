#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#define MAXN 900

std::unordered_map<std::string, int> prio;
std::string names[MAXN+1];
std::vector<std::string> order;
std::vector<int> adj[MAXN+1];
std::priority_queue<int, std::vector<int>, std::greater<int>> pqueue;
int in[MAXN+1];
int count = 1;

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n;

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string u, v;
        std::cin >> u >> v;

        // Translate name <-> priority.
        if (prio[u] == 0) {
            prio[u] = count;
            names[count] = u;
            ++count;
        }
        if (prio[v] == 0) {
            prio[v] = count;
            names[count] = v;
            ++count;
        }

        adj[prio[v]].push_back(prio[u]);
        ++in[prio[u]];
    }

    for (int i = 1; i < count; ++i) {
        if (in[i] == 0) pqueue.push(i);
    }

    while (!pqueue.empty()) {
        // Get minimum node with in-degree of 0.
        int c = pqueue.top();
        pqueue.pop();

        // Add the current node to order.
        order.push_back(names[c]);

        for (const auto& u : adj[c]) {
            if (--in[u] == 0) pqueue.push(u);
        }
    }

    for (const auto& u : order) std::cout << u << '\n';

    return 0;
}