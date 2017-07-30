#include <iostream>
#include <vector>

using namespace std;

struct big {
    int tall;
    int weight;
    int rank;
};

int main() {
    int N;
    cin >> N;
    vector<big> people;
    big input;

    for (int i = 0; i < N; ++i) {
        cin >> input.weight;
        cin >> input.tall;
        people.push_back(input);
    }
    int rank;

    for (int i = 0; i < people.size(); ++i) {
        rank = 0;
        for (int j = 0; j <people.size(); ++j) {
            if(i == j)  continue;
            if(people[i].tall < people[j].tall && people[i].weight < people[j].weight)
                rank++;
        }
        people[i].rank = rank+1;
    }

    for (int i = 0; i < people.size(); ++i)
        cout<<people[i].rank <<' ';

    return 0;
}