#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv){
	int fd[2];
	int pid;
	pipe(fd);
	pid = fork();
	if(pid == 0){
		// Hijo
		// cerrar la salida del byte
		close(fd[1]);
		// abrir la entrada del byte
		dup2(fd[0], STDIN_FILENO);
		//reemplazar ' ' con '-'
		execl("/usr/bin/tr", "tr", "' '", "-", NULL);
	}
	if(pid > 0){
		// Padre
		// cerrar fd[0] la salida del byte porque no se utiliza
		close(fd[0]);
		// fd[1] la entrada del byte
		dup2(fd[1], STDOUT_FILENO);
		execl("/bin/cat", "cat", NULL);
	}
	//execl("/bin/ls", "ls", "-l", "-a", NULL);
	return 0;
}
