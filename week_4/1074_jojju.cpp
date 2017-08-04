#include <iostream>
#include <cmath>

using namespace std;
int N, yy, xx;
int order;

void recursive(int y, int x, int size) {

    if (size == 1) {
        if (y == yy && x == xx)
            cout << order << endl;
        return;
    }
    size /= 2;
    int roomY = yy - (y + size);
    int roomX = xx - (x + size);

    if (roomY < 0 && roomX < 0)
        recursive(y, x, size);
    else if (roomY < 0 && roomX >= 0) {
        order = order + (size * size);
        recursive(y, x + size, size);
    } else if (roomY >= 0 && roomX < 0) {
        order = order + (size * size) * 2;
        recursive(y + size, x, size);
    } else {
        order = order + (size * size) * 3;
        recursive(y + size, x + size, size);
    }

    return;

}

int main() {
    cin >> N >> yy >> xx;

    int size = (int) pow(2, N);
    recursive(0, 0, size);

    return 0;
}