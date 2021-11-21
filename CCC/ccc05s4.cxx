#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, int> name_map;
std::vector<std::string> path;

int main(void) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int l;
    std::cin >> l;

    for (int i = 0; i < l; ++i) {
        int m = 0;

        int n;
        std::cin >> n;

        path.clear();

        for (int v = 0; v < n; ++v) {
            std::string s;
            std::cin >> s;
            path.push_back(s);
        }

        std::string p = path.back();

        name_map.clear();

        name_map[p] = 0;

        for (const auto& u : path) {
            if (name_map.count(u) == 0) {
                name_map[u] = name_map[p] + 1;
                if (name_map[u] > m) m = name_map[u];
            }

            p = u;
        }

        std::cout << 10 * (n - 2 * m) << '\n';
    }

    return 0;
}

