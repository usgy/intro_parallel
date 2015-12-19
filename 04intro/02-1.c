/* 
int型の配列a[100]の全要素を0に初期化する
*/
#include <stdio.h>
int main(void)
{
	int i, a[100];
	#pragma omp parallel
	{
		#pragma omp for
		for(i=0; i<100; i++){
			a[i] = 0;
		}
	}
}
