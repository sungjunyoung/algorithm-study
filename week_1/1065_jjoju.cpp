#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int tmp;
    int piece;
    int preDiffer;
    int prePiece;

    bool ok;
    int count = 0;

    for (int i = 1; i <= N; ++i) {
        tmp = i;
        ok = true;
        preDiffer = 0;
        prePiece = 0;

        for (int j = 0; tmp > 0; j++) {
            piece = tmp % 10;
            tmp = tmp / 10;

            if (j > 1 && (preDiffer != prePiece - piece))
                    ok = false;

            preDiffer = prePiece - piece;
            prePiece = piece;
        }

        if (ok) count++;
    }
    cout << count << endl;

    return 0;
}
