> 이곳은 해당 주차에 문제를 풀면서 알게된 노하우 / 정보를 공유하는 공간입니다.
> 숙제 : 마크다운 문법 알아오기

## Todo

단계별로 풀어보기 - [함수 사용하기](https://www.acmicpc.net/step/5)

## Tips

- 성준영
    - (예시) [1000번](https://github.com/sungjunyoung/algorithm-study/blob/master/week_1/1000_junyoung.cpp)
        - 출력은 `cout` 보다 `printf`가 성능이 좋다
    - [4673번](https://github.com/sungjunyoung/algorithm-study/blob/master/week_1/4673_junyoung.cpp)
        - 배열 선언시 초기화 방법 `int list[10001] = {0};` 혹은 `int list[10001] = {0,};` <- 모두 0 으로 초기화가 된다.
    - [4673번](https://github.com/sungjunyoung/algorithm-study/blob/master/week_1/4673_junyoung.cpp)
        - 알고리즘을 풀때 1000개 리미트이면 배열을 1001 개 선언해서 1~1000 으로 쓰면 가독성이 좋다
    - [1065번](https://github.com/sungjunyoung/algorithm-study/blob/master/week_1/1065_junyoung.cpp)
        - vector 사용하기
        ```cpp
        // 벡터 include
        #include <vector>
        
        // 벡터 선언
        vector<int> testVector;
        
        // 벡터 푸시
        testVector.push_back(1);
        ```
- 오영택
	- [4763번](https://github.com/sungjunyoung/algorithm-study/blob/master/week_1/4763_teki.cpp)
		- c++ 배열초기화 방법 : std::fill_n(초기화 시작할 곳의 주소, 시작주소부터 몇개를 초기화 할건지, 뭐로 초기화 할건지)
		ex) std::fill_n(arr,4*4,-1) >> arr배열의 시작주소부터 16개를 -1로 초기화
- 조주영
- 강석윤
- 정소현
- 김성주
    - [4673번](https://github.com/sungjunyoung/algorithm-study/blob/master/week_1/4673_tjdwn9410.cpp)
        - using namespace std 대신 using std::cout과 같은 문법으로 필요한 것만 선택하여 추가하는게 좋다.
        - 전역 변수로 배열을 선언하면 모든 값이 0으로 초기화 된다.
    - [1065번] (https://github.com/sungjunyoung/algorithm-study/blob/master/week_1/2448_tjdwn9410.cpp)
        - 전체 부분이 일정 구조의 반복이므로 각 부분을 잘라서 코딩 전에 분석을 먼저해보는것 추천.

> 현재 푼 문제들을 적어넣으세요

## Progress


- 성준영 : (예시) 1000, 4673, 1065
- 오영택 : 4673, 1065
- 조주영 : 4673, 2448, 1065, 1152
- 강석윤 :
- 정소현 :
- 김성주 : 4673, 1065, 2448
- 김민호 : 4673
