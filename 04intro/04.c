#include <stdio.h>

int main(void)
{
	#pragma omp parallel
	{
		printf("Hello 1\n");
		#pragma omp single
		{
			printf("Hello 2\n");
		}
		printf("Hello 3\n");
	}
}
//Hello 1とHello 3は実行スレッドの数だけ表示されますが、Hello 2は１回だけ表示されます。
