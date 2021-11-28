#include <iostream>
#include <vector>
#include <queue>
#define MAXN 7

std::vector<int> order;
std::priority_queue<int, std::vector<int>, std::greater<int>> pqueue;
int in[MAXN+1];
bool adj[MAXN+1][MAXN+1];

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    adj[1][4] = true;
    adj[1][7] = true;
    adj[2][1] = true;
    adj[2][1] = true;
    adj[3][4] = true;
    adj[3][5] = true;

    in[1] = 1;
    in[5] = 1;
    in[7] = 1;
    in[4] = 2;

    int u, v;

    std::cin >> u >> v;

    while (u && v) {
        adj[u][v] = true;
        ++in[v];
        std::cin >> u >> v;
    }

    for (int i = 1; i <= MAXN; ++i) {
        if (in[i] == 0) pqueue.push(i);
    }

    while (!pqueue.empty()) {
        // Get minimum node with in-degree of 0.
        int n = pqueue.top();
        pqueue.pop();

        // Add the node to the order list.
        order.push_back(n);

        for (int i = 1; i <= MAXN; ++i) {
            if (adj[n][i]) {
                if (--in[i] == 0) {
                    pqueue.push(i);
                }
            }
        }
    }

    if (order.size() == MAXN) {
        for (const auto& u : order) {
            std::cout << u << ' ';
        }      
        std::cout << '\n';
    }
    else {
        std::cout << "Cannot complete these tasks. Going to bed.\n";
    }

    return 0;
}