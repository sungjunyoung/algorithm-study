#include <stdio.h>

int numList[10001];
int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int tempNum;
        scanf("%d", &tempNum);
        numList[tempNum]++;
    }

    for (int i = 1; i <= 10000; i++) {
        if (numList[i] > 0)
            for (int j = 0; j < numList[i]; j++)
                printf("%d\n", i);
    }

    return 0;

}