#include <stdio.h>
int main(void)
{
	#pragma omp parallel
	{
		printf("Hello 1\n");
		#pragma omp barrier
		printf("Hello 2\n");
	}
}

/*
同時に実行されている全てのスレッドの同期を取ります

上記の場合、全てのスレッドが"Hello 1"を表示し終わってから、"Hello 2"が表示されます。
共有変数の値の参照・更新、プログラム内部での時間計測、出力を順番どおりに行いたい場合などに
利用します。
またプログラムのデバッグの際にもよく使われます。ただし、"#pragma omp barrier"指示文を
たくさん入れてしまうと速度低下の一因になりますので、利用は最小限にとどめましょう。
*/

