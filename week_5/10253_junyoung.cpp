//
// Created by 성준영 on 2017. 8. 2..
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int getResult(pair<int, int> ab) {

    pair<int, int> comp(1, 2);
    while (ab.first != 1) {

        while (ab.first * comp.second < comp.first * ab.second) {
            comp.second++;
        }


        ab.first = ab.first * comp.second - comp.first * ab.second;
        ab.second = ab.second * comp.second;
        int gcdDivider = gcd(ab.first, ab.second);
        ab.first /= gcdDivider;
        ab.second /= gcdDivider;
    }

    return ab.second;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        pair<int, int> ab;
        cin >> ab.first >> ab.second;
        int result = getResult(ab);
        printf("%d\n", result);
    }
}