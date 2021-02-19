/**
* 2021. 02. 19
* Creater : Gunhee Choi
* Problem Number : 2292
* Title : 벌집 

* Problem :

(https://www.acmicpc.net/JudgeOnline/upload/201009/3(2).png)

위의 그림과 같이 육각형으로 이루어진 벌집이 있다. 그림에서 보는 바와 같이 중앙의 방 1부터 시작해서 이웃하는 방에 돌아가면서 1씩 증가하는 번호를 주소로 매길 수 있다. 숫자 N이 주어졌을 때, 벌집의 중앙 1에서 N번 방까지 최소 개수의 방을 지나서 갈 때 몇 개의 방을 지나가는지(시작과 끝을 포함하여)를 계산하는 프로그램을 작성하시오. 예를 들면, 13까지는 3개, 58까지는 5개를 지난다.

* Input : 첫째 줄에 N(1 ≤ N ≤ 1,000,000,000)이 주어진다.
	1000 70 170

* Output : 입력으로 주어진 방까지 최소 개수의 방을 지나서 갈 때 몇 개의 방을 지나는지 출력한다.
	11

**/

#include <stdio.h>

//증가폭 : 1 6 12 18  24
//값 : 1 7 19 37 61
//증가하는 값이 6씩 증가하는 수열

int main() {
	long long A;
	int value=1;
	int i = 1;
	
	scanf("%lld", &A);
	
	while(1) {
		if( value >= A )
			break;
		value += 6*i;
		i++;
	}
	
	printf("%d\n", i);
	
	return 0;
}