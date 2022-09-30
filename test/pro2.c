#include <stdio.h>   // printf()
#include <stdlib.h>  // system()
#include <unistd.h>  // fork(), sleep()

int main()
{
	int   counter =0;

	switch( fork()){
		case -1  :
			printf( "자식 프로세스 생성 실패\n");
			return -1;
		case 0   :
			printf( "저는 자식 프로세스로 system()을 호출하겠습니다.\n");
			system( "ls -al");
			break;
		default  :
			printf( "저는 부모 프로세스로 카운트를 하겠습니다.\n");
			while( 1 ){
				printf( "부모: %d\n", counter++);
				sleep( 1);
			}
	}
}
