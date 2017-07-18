> 이곳은 해당 주차에 문제를 풀면서 알게된 노하우 / 정보를 공유하는 공간입니다.

 ## Todo

 단계별로 풀어보기 - [동적 계획법 기초](https://www.acmicpc.net/step/16) - 16문제  
 단계별로 풀어보기 - [구현](https://www.acmicpc.net/step/17) - 5문제  
 단계별로 풀어보기 - [브루트 포스](https://www.acmicpc.net/step/22) - 5문제  

 ## Tips

 - 성준영
    - [11066번](https://github.com/sungjunyoung/algorithm-study/tree/master/week_3/11066_junyoung.cpp)
        - vector 크기 미리 정하기
        ```cpp
        vector<int> resizeMe;
        resizeMe.resize(101);
        ```
    - [1022번](https://github.com/sungjunyoung/algorithm-study/tree/master/week_3/1022_junyoung.cpp)
        - 출력크기 정해놓기
        ```cpp
        printf("%*d ", 5, number);
        ```
    - [3053번](https://github.com/sungjunyoung/algorithm-study/tree/master/week_3/3053_junyoung.cpp)
        - 소수 6째 자리까지 출력
        ```cpp
        printf("%6f", M_PI);
        ```
 - 오영택
 - 조주영
 - 강석윤
 - 정소현
 - 김성주
 - [1912번](https://github.com/sungjunyoung/algorithm-study/blob/master/week_3/1912_tjdwn9410.cpp)
    - 데이터 사이즈에서 추론했을떄 O(n) 혹은 O(n log n)으로 접근해야 합니다
    - 이전의 연속 합을 더 했을 때 지금보다 작아진다면 합할 이유가 없습니다
 - [1463번](https://github.com/sungjunyoung/algorithm-study/blob/master/week_3/1463_tjdwn9410.cpp)
    - N에서 1을 만드는 방법을 역으로 1에서 N을 만드는 방식으로 접근해서 풀수도 있습니다.
    
 - 김민호
 	- [2579번](https://github.com/sungjunyoung/algorithm-study/tree/master/week_3/2579_dolplusi.cpp)
 		- 문제 힌트 : 점화식을 구할 때 이차원 배열로 하였습니다. 
 		1. 계단이 연속으로 붙여진 뒤 n칸의 계단으로 올라왔을 때
 		2. 계단이 한 칸 띄워진 뒤 n칸의 계단으로 올라왔을 때 
 	- [1932번](https://github.com/sungjunyoung/algorithm-study/tree/master/week_3/1932_dolplusi.cpp)
 		- stack 메모리 부족으로 stack overflow가 나는 경우
 		[visual studio에서 stack overflow 해결 방법](http://ocllos.tistory.com/39)
 		visual studio는 디폴트로 스택 크기가 1MB 이므로 변수를 1MB 이상으로 선언하는 경우 에러가 난다.
 		그럴 경우 스택 크기를 늘려면 된다.
 	- [1149번](https://github.com/sungjunyoung/algorithm-study/tree/master/week_3/1003_dolplusi.cpp)
   		- 배열 선언과 동시에 초기화
    	```cpp
    	int D[3][3] = { 0, };
    	```

 > 현재 푼 문제들을 적어넣으세요

 ## Progress

 - 성준영 : 1003, 1149, 1932, 2579, 1463, 1005, 10844, 2293, 2156, 1520, 9251, 11066, 2965, 1912, 9252, 9461, 10871, 2490, 2577, 1022, 3053, 2309, 2231, 7568, 1038
 - 오영택 : 1003, 1149, 1932, 2579, 1463, 10844, 2293, 2156, 1520, 9251, 2965
 - 조주영 : 1003, 1149, 1932, 2579, 1463, 10844, 1912, 2293, 2965
 - 강석윤 : 1003, 1149, 1463
 - 정소현 : 1003, 1149, 1463, 1932, 2579, 10844
 - 김성주 : 1003, 1149, 1932, 1912, 2579, 1463
 - 김민호 : 1003, 1149, 1932, 2579, 1463, 10844

 > 모여서 토론할 만한 문제 / 했으면 하는 문제를 써주세요

 ## To Study

- 성준영 :
- 오영택 :
- 조주영 :
- 강석윤 :
- 정소현 :
- 김성주 :
- 김민호 : 
