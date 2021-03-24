#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int var;

void signalHandler(int sig){
	int pidHijoTermino = wait(NULL);
	printf("Mi hijo termino %d\n", pidHijoTermino);
	var = 0;
}

int main(){
	var = 1;
	signal(17, signalHandler);
	int pid = fork();
	if(pid == 0){
		// Proceso hijo
		printf("Soy el proceso hijo\n");
	} else{
		printf("Soy el proceso padre y mi hijo es %d\n", pid);
		while(var){
			printf("Trabajando\n");
			sleep(1);
		}
	}
	printf("Terminando\n");
	return 0;
}
