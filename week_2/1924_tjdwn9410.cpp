//
// Created by MAC on 2017. 7. 3..
//

#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    char days[7][4]={"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int monthlyDays[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int x,y;
    int transDays=0;
    cin>>x>>y;
    for(int i=1;i<x;i++)
        transDays+=monthlyDays[i];
    transDays+=y;
    cout<<days[transDays%7]<<endl;
}