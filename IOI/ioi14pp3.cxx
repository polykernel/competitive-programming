#include <iostream>
#include <vector>

struct tromino {
    int x1, y1;
    int x2, y2;
    int x3, y3;
};

std::vector<tromino> tiling;

void tile(int cx, int cy, int hx, int hy, int n) {
    if (n == 0) return;

    int nx = cx + (1 << (n-1));
    int ny = cy + (1 << (n-1));

    if (hx < nx && hy < ny) {
        tiling.push_back(tromino{nx,ny-1,nx,ny,nx-1,ny});
        tile(cx, cy, hx, hy, n-1);      // upper left quadrant
        tile(nx, cy, nx, ny-1, n-1);    // upper right quadrant
        tile(nx, ny, nx, ny, n-1);      // lower right quadrant
        tile(cx, ny, nx-1, ny, n-1);    // lower left quadrant
    }
    else if (hx >= nx && hy < ny) {
        tiling.push_back(tromino{nx-1,ny-1,nx,ny,nx-1,ny});
        tile(nx, cy, hx, hy, n-1);      // upper right quadrant
        tile(cx, cy, nx-1, ny-1, n-1);  // upper left quadrant
        tile(nx, ny, nx, ny, n-1);      // lower right quadrant
        tile(cx, ny, nx-1, ny, n-1);    // lower left quadrant
    }
    else if (hx < nx && hy >= ny) {
        tiling.push_back(tromino{nx,ny-1,nx,ny,nx-1,ny-1});
        tile(cx, ny, hx, hy, n-1);      // lower left quadrant
        tile(cx, cy, nx-1, ny-1, n-1);  // upper left quadrant
        tile(nx, cy, nx, ny-1, n-1);    // upper right quadrant
        tile(nx, ny, nx, ny, n-1);      // lower right quadrant
    }
    else if (hx >= nx && hy >= ny) {
        tiling.push_back(tromino{nx,ny-1,nx-1,ny-1,nx-1,ny});
        tile(nx, ny, hx, hy, n-1);      // lower right quadrant
        tile(nx, cy, nx, ny-1, n-1);    // upper right quadrant
        tile(cx, cy, nx-1, ny-1, n-1);  // upper left quadrant
        tile(cx, ny, nx-1, ny, n-1);    // lower left quadrant
    }
}

int main(void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    int x, y;
    std::cin >> x >> y;

    tile(0, 0, x, y, n);

    for (const auto& t : tiling) {
        std::cout << t.x1 << ' ' << t.y1 << ' ' << t.x2 << ' ' << t.y2 << ' ' << t.x3 << ' ' << t.y3 << '\n';
    }

    return 0;
}
