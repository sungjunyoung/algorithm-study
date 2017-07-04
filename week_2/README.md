> 이곳은 해당 주차에 문제를 풀면서 알게된 노하우 / 정보를 공유하는 공간입니다.

 ## Todo

 단계별로 풀어보기 - [1차원 배열 사용하기](https://www.acmicpc.net/step/6) - 5문제  
 단계별로 풀어보기 - [규칙 찾기](https://www.acmicpc.net/step/8) - 9문제  
 단계별로 풀어보기 - [정렬해보기](https://www.acmicpc.net/step/9) - 7문제  

 > 문자열 사용해보기는 너무 쉬운거같아서 뺏습니다.

 ## Tips

 - 성준영
    - [1152번](https://github.com/sungjunyoung/algorithm-study/blob/master/week_2/1152_junyoung.cpp)
        - string 입력받기 (공백을 포함해서 한줄)
        ```cpp
        string input;
        getline(cin, input);
        ```
    - [8958번](https://github.com/sungjunyoung/algorithm-study/blob/master/week_2/8958_junyoung.cpp)
        - 테스트 케이스만큼 돌기
        ```cpp
        int n;
        cin >> n;
        while(n--){...}
        ```
    - [1011번](https://github.com/sungjunyoung/algorithm-study/blob/master/week_2/1011_junyoung.cpp)
        - `unsigned int`의 범위 0 ~ 4,294,967,295
 - 오영택
 - 조주영
 - 강석윤
 	- [2577번](https://github.com/sungjunyoung/algorithm-study/blob/master/week_2/2577_sheep1500.cpp)
 		- char의 정수 -> int 로 바꿀 때는 문법 없이 -'0'
으로 하면 됩니다
 - 정소현
 - 김성주
    - [8958번](https://github.com/sungjunyoung/algorithm-study/blob/master/week_2/8958_tjdwn9410.cpp)
        - 3항 연산자를 사용하였는데, 간단한 조건비교 및 값 대입에 사용할 수 있으며 [(조건) ? 참:거짓]으로 표현합니다

    - [1152번](https://github.com/sungjunyoung/algorithm-study/blob/master/week_2/1152_tjdwn9410.cpp)
        - strtok 함수는 문자열을 특정 문자를 자르는데 사용하는 함수이다. 컴파일 에러 발생 시,  #define _CRT_SECURE_NO_WARNINGS을 상단에 입력하면 된다
        - https://dojang.io/mod/page/view.php?id=376 참고 링크
    - [6064번](https://github.com/sungjunyoung/algorithm-study/blob/master/week_2/6064_tjdwn9410.cpp)
            - 유클리드 호제법을 사용하여 최소공배수를 계산하였습니다

    - [2775번](https://github.com/sungjunyoung/algorithm-study/blob/master/week_2/2775_tjdwn9410.cpp)
        - 파스칼 삼각형을 이용하면 간단하게 구할 수 있습니다.

 > 현재 푼 문제들을 적어넣으세요

 ## Progress

 - 성준영 : 1152, 2577, 8958, 2920, 10039, 2438, 2292, 1193, 1011, 10250, 2775, 1924
 - 오영택 :
 - 조주영 : 1152, 2577, 8958, 2920, 10039, 2438, 2292, 1193, 1011, 10250, 2775, 1924, 1475, 6064
 - 강석윤 : 1152, 2577
 - 정소현 :
 - 김성주 : 1152, 2577, 8958, 2920, 10039, 2292, 1193, 1011, 10250, 2775, 1475
