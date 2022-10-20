#include <iostream>

const int MAXG = 100'000;

int ds[MAXG+1];

int find(int x) {
    if (ds[x] != x) ds[x] = find(ds[x]);
    return ds[x];
}

int main(void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int g, p;
    std::cin >> g >> p;

    for (int i = 1; i <= g; ++i) ds[i] = i;

    int count = 0;

    for (int i = 1; i <= p; ++i) {
        int gi;
        std::cin >> gi;

        // find the highest gate g_i' less than or equal to gate g_i
        int ur = find(gi);
        // all the gates from 1 .. g_i have been filled
        if (ur == 0) break;

        // union the sets g_i'-1 and g_i', i.e fill gate g_i'
        int vr = find(ur-1);
        ds[ur] = vr;

        ++count;
    }

    std::cout << count << '\n';


    return 0;
}
