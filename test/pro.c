#include <stdio.h>   // printf()
#include <stdlib.h>  // system()
#include <unistd.h>  // fork(), sleep()

int main()
{
	int	counter =0;

	char[] path = "./1697";
	char[] comp = "./comp";

	switch( fork()){
		case -1  :
			//failed to fork();
			return -1;
		case 0   :
			//child fork
			system( "./1697");
			system("5 17");
			break;
		default  :
			//parents fork();
			while( 1 ){
				++counter;
				sleep( 1);
			}
	}
}
