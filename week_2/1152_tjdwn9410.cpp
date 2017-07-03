#define _CRT_SECURE_NO_WARNINGS    // strtok 보안 경고로 인한 컴파일 에러 방지
#include<iostream>
#include<string.h>
using std::cin;
using std::cout;
using std::endl;
int main() {
    char input[1000010];
    char *vocas;
    vocas = strtok(input," ");
    cin.getline(input,1000000);
    int res = 0;
    while(vocas != NULL)
    {
        vocas = strtok(NULL," ");
        //문자열을 자르는 함수
        res ++;
    }
    cout<<res<<endl;
    return 0;
}