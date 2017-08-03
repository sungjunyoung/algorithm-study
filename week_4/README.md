 > 이곳은 해당 주차에 문제를 풀면서 알게된 노하우 / 정보를 공유하는 공간입니다.

 ## Todo

 단계별로 풀어보기 - [분할 정복](https://www.acmicpc.net/step/20) - 12문제  
 단계별로 풀어보기 - [트리 사용하기](https://www.acmicpc.net/step/23) - 7문제  
 단계별로 풀어보기 - [위상정렬](https://www.acmicpc.net/step/25) - 4문제  

 ## Tips

 - 성준영
 - 오영택
    - [11004번](https://github.com/sungjunyoung/algorithm-study/tree/master/week_4/11004_teki.cpp)
		- nth element 찾기
		- cin보다 scanf가 더 빠르다. 경우에 따라서 cin을 사용하면 실패하고, scanf를 사용하면 성공할수도있음!

		```cpp
		int	a[5000000];
		std::nth_element(a, a + n - 1, a + 500000);

		// nth_element(시작점,n번째 원소를 찾을거다,끝점)
        // 참고 : http://www.cplusplus.com/reference/algorithm/nth_element/
		```
	- [7469번](https://github.com/sungjunyoung/algorithm-study/tree/master/week_4/7469_teki.cpp)
		- std::sort사용법(정렬기준)
		```cpp
		struct _a {
		int num;
		int index;
		};

		// 오름차순 정렬
		bool com(_a A, _a B){
			return A.num < B.num;
		}
		_a a[100000];
		std::sort(a,a+100000,com);
		```
	- [2749번](https://github.com/sungjunyoung/algorithm-study/tree/master/week_4/2749_teki.cpp)
		- 여러 피보나치 문제 참고(https://www.acmicpc.net/blog/view/28)
 - 조주영
 - 강석윤
 - 정소현
 - 김성주
 - 김민호

 > 현재 푼 문제들을 적어넣으세요

 ## Progress

 - 성준영 : 11004, 7469, 1780, 6459, 2740, 2749, 1992, 2477, 1074, 1167, 11725, 1191, 2263, 1967, 3665, 2252, 1516, 1776, 2261
 - 오영택 : 11004, 7469, 1780, 2740, 2749, 1992, 1074
 - 조주영 : 7469, 11004, 2261, 1992
 - 강석윤 : 11004
 - 정소현 : 1780, 2740, 1074
 - 김성주 :
 - 김민호 :

 > 모여서 토론할 만한 문제 / 했으면 하는 문제를 써주세요

 ## To Study

- 성준영 : sqrt decomposition, 세그먼트 트리, 위상정렬
- 오영택 : fibonacci
- 조주영 :
- 강석윤 :
- 정소현 :
- 김성주 :
- 김민호 :
