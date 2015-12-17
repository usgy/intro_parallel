/*
int型の配列a[100]の全要素を0に初期化するプログラム
*/
int main(void)
{
	int i, a[100];
	#pragma omp parallel for
	for(i=0; i<100; i++){
		a[i] = 0;
	}
}


/*
//This program is same meaning with a below source.
//filename: ex04-02-1.c

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

// 並列リージョンの中に「#pragma omp for」が 1 つしかない場合には、
// 右のプログラムのように結合指示文「#pragma omp parallel for」を使って書くと行数が短くなります。
// 上記のプログラムの場合、例えば実行スレッド数を 4 にして実行すると、4 つのスレッドが下記のように for ループの処理を分担して実行します。
// スレッド 0 番： for(i= 0;i< 25;i++) a[i]=0;
// スレッド 1 番： for(i=25;i< 50;i++) a[i]=0;
// スレッド 2 番： for(i=50;i< 75;i++) a[i]=0;
// スレッド 3 番： for(i=75;i<100;i++) a[i]=0;
//  実行スレッド数は動的に決定されるため、このような分担をプログラム実行時に行うような実行コードがコンパイラによって生成されています。
*/