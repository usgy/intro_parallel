#include <stdio.h>

int main(void){
	#pragma omp parallel
	{
		printf("Hello 1\n");
		#pragma omp master
		{
			printf("I am a master\n");
		}
		printf("Hello 2\n");
	}
}

/*
"Hello1"と"Hello2"は実行スレッドの数だけ表示されます。
"I am a master"はマスタースレッドだけが表示されます。
一般には、マスタースレッドに限定するよりは"#pragma omp single"指示文を使ってどのスレッドが実行しても良いようにしたほうが効率は
よくなります。

"#pragma omp master"指示文では、指定されたブロックの入り口と出口で沈黙のバリアは存在しません。
"I am a master"が表示される前に"Hello 2"が表示されることがあります。その点は"#pragma omp single"指示文とは異なっているので
注意が必要です。
*/
