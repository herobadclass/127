#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
	int n = atoi(argv[1]);
	int x = atoi(argv[2]);
	for(int i = 0; i < n; i ++){
		printf("#");
	}
	printf("\n");
	for(int i = 1; i < x; i ++){
		if(n%2 == 0){
			n = n/2;
		}
		else{
			n = 3*n+1;
		}
		for(int i = 0; i < n; i ++){
			printf("#");
		}
		printf("\n");
	}
}

