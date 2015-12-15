#include <stdio.h>
#include <unistd.h>

int main(void)
{
	#pragma omp parallel
	{
		#pragma omp critical (name)
		{
			sleep(1);
			printf("sleep end\n");
		}
	}
}

/*
直後の１文またはブロックの実行を一度に１つのスレッドに制限します。
このような領域をクリティカル領域と言います。全てのスレッドが実行を行うという点に注意して下さい。

上記のプログラムでは、各スレッドがsleep(1)で１秒待機した後に"sleep end"と表示します。
一度に１つのスレッドに制限しているので、結果的に、１秒おきに"sleep end"が表示されます（実行スレッドの数だけ）
オプションのnameは、クリティカル領域を認識するのに使用します。スレッドは、同じ名前のクリティカル領域を他のどのスレッドも
実行していない状態になるまで、クリティカル領域の入り口で待機します。名前のないクリティカル領域は全て同一のクリティカル領域として
扱われます。
*/					