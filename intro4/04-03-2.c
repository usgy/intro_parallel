#include <stdio.h>
int main(void)
{
	#pragma omp parallel sections
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

/*

//This program is same meaning with a below source.
//filename: ex04-03-1.c
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

// あるスレッドが「Hello 1」と表示、別のスレッドが「Hello 2」と表示、さらに別のスレッドが「Hello
// 3」を 2 回表示します。実行スレッド数が「#pragma omp section」宣言子で指定したセクションの数
// より少ない場合には、早く処理の終わったスレッドがまだ実行が開始されていないセクションを実行
// していきます。逆に実行スレッド数が「#pragma omp section」宣言子で指定したセクションの数より
// 多い場合には、仕事を一切行わないスレッドが出てくることになります。
// 最初のセクションの始まりの「#pragma omp section」宣言子は記述を省略することができます。
// 「#pragma omp section」宣言子には指示節を付けることはできません。
// 「#pragma omp sections」指示文で指定したブロックの出口では暗黙のバリア（全てのスレッドが
// その場所に到達するまで待機する）があります。そのため、ブロック以降の処理を開始する段階で、
// 全てのセクションの実行が終えていることが保証されています。ただし、これは「#pragma omp
// sections」指示文に nowait 指示節が指定されていない場合に限ります。
// 並列リージョンの中に指示文が「#pragma omp sections」指示文の 1 つしかない場合には、右のプ
// ログラムのように結合指示文「#pragma omp parallel sections」を使って書くと行数が短くなります。
//  セクション部分では、当然ながら関数呼び出しを行うことも可能です。そうすると、各スレッドで
// 全く独立した処理を実行するようなことも可能となります

*/