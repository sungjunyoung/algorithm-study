#include <iostream>
using namespace std;

int main()
{
    string input;
    getline(cin,input);

    int count  = 0;
    for (int i = 0; i < input.length(); ++i) {
        if ((i == 0 && input[i] != NULL && input[i] != ' ') ||
            (input[i] == ' ' && input[i + 1] != NULL && input[i + 1] != ' '))
            count++;
    }

    cout<< count;

    return 0;
}