#include <stdio.h>
#include <omp.h>
int main(void)
{
	int i, a[100];
	#pragma omp parallel for ordered
	for(i=0; i<100; i++){
		a[i] = 0;
		#pragma omp ordered
		printf(" i=%d thread_num=%d\n", i, omp_get_thread_num());
	}
}

/*
直後の１文またはブロックをforループが逐次実行された場合の順番で実行します。
これは"#pragma omp for"市自分または"#pragma omp parallel for"指示文のブロック内で指定する必要があります。
また、それらの指示文にはorderd指示節を付ける必要があります。

上のプログラムを実行スレッド数4で実行すると上記のように表示されます。
$ g++ 09.c -fopenmp
 i=0 thread_num=0
 i=1 thread_num=0
 i=2 thread_num=0
 ...
 i=23 thread_num=0
 i=24 thread_num=0
 i=25 thread_num=1
 i=26 thread_num=1
 ...
 i=48 thread_num=1
 i=49 thread_num=1
 i=50 thread_num=2
 i=51 thread_num=2
 ...
 i=73 thread_num=2
 i=74 thread_num=2
 i=75 thread_num=3
 i=76 thread_num=3
 ...
 i=98 thread_num=3
 i=99 thread_num=3
*/