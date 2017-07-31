#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int tall;
    bool ok;
    node(){
        tall = 0;
        ok = true;
    }
    bool operator < (const node & nextPoint) const {
        return tall < nextPoint.tall;
    }
};

bool compareByTall(node & first, node & second)
{
    return first.tall<second.tall;
}

int main()
{
    vector<node> people;
    int sum = 0;
    node input;
    for (int i = 0; i < 9; ++i) {
        cin>>input.tall;
        people.push_back(input);
        sum += input.tall;
    }

    int over100 = sum - 100;
    for (int i = 0; i < people.size() - 1; ++i) {
        for (int j = i + 1; j < people.size(); ++j) {
            if(people[i].tall + people[j].tall == over100){
                people[i].ok = false;
                people[j].ok = false;
            }
        }
    }

    sort(people.begin(),people.end(),compareByTall);

    for (int i = 0; i < people.size(); ++i) {
        if(people[i].ok)
            cout<<people[i].tall<<endl;
    }

    return 0;
}