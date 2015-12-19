/*
File name: 11.c
#pragma omp threadprivate(list)
Author: Yuta Sugii
*/

/*
スレッドごとにプライベートで、スレッド内ではグローバルにアクセスできる変数（threadprivate変数）を宣言します。
通常はプログラムのグローバル領域（関数の外）で宣言します。複数の変数を指定する場合には、カンマ（,）で区切ります。
スレッドは他のスレッドのthreadprivate変数を参照することはできません。プログラムの逐次実行領域では、マスター
スレッドの持つ値を参考することになります。
threadprivate変数の初期値は、宣言した変数の初期値と等しくなります。
「#pragma omp parallel」指示文にcopyin指定節を指定することでマスタースレッドの値が全てのスレッドの値として
コピーされます。
threadprivate変数は、copyin指示節、schedule指示節、if指示節に指定することができますが、private指示節、
firstprivate指示節、lastprivate指示節、shared指示節、reduction指示節で指定することはできません。また、
threadprivate変数についてはdefault指示節は適応されません。
*/

// #pragma omp threadprivate指示文の使い方の例を示します。
#include <stdio.h>
#include <omp.h>

int i=100;
#pragma omp threadprivate(i)

int main()
{
	i=200;
	#pragma omp parallel
	printf("thread_num=%d i=%d\n", omp_get_thread_num(), i);

	i=1000;
	#pragma omp parallel copyin(i)
	{
		i+=omp_get_thread_num();
		printf("thread_num=%d i=%d\n", omp_get_thread_num(),i);
	}
}

/*
5行目でint変数であるiをthreadprivate変数にしています。4行目にiの初期値として100を代入しているため
各スレッドの参照するiの値も全て100が初期値として代入されます。9行目にi=100
としておりこれはマスタースレッドの保持するiのみが200になります。マスタースレッド以外のスレッド
の保持している値は100のままです。したがって、11行目のprintf()で表示される結果は
次のようになります。

thread_num=0 i=200
thread_num=1 i=100
thread_num=2 i=100
thread_num=3 i=100

次に、13行目でi=1000とし、14行目ではcopyin(i)を指定しているためマスタースレッドの保持する
iの価である1000が全てのスレッドのthreadprivate変数のiにコピーされます。16行目で各スレッドの
番号をthreadprivate変数のiに加えています。その結果、17行目printf()で出力される結果
は次のようになります。

thread_num=0 i=1000
thread_num=1 i=1001
thread_num=2 i=1002
thread_num=3 i=1003
*/

