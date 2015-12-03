#include <stdio.h>
int main(void)
{
	#pragma omp parallel
	{
		#pragma omp sections
		{
			#pragma omp section
			printf("Hello 1\n");
			#pragma omp section
			printf("Hello 2\n");
			#pragma omp section
			{
				printf("Hello 3\n");
				printf("Hello 3\n");
			}
		}
	}
}

