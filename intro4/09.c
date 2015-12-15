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

*/