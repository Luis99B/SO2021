#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int var;

void signalHandler(int sig){
	printf("Recibi signal %d\n", sig);
	var = 0;
}

int main(){
	var = 1;
	signal(2, signalHandler);
	signal(15, signalHandler);
	while(var){
		printf("Trabajando\n");
		sleep(1);
	}
	printf("Ya voy a terminar\n");
	return 0;
}
