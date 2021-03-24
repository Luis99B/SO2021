#include <stdio.h>
#include <unistd.h>

// 0 = stdin
// 1 = stdout
int main(){
	int lineas = 0;
	char caracter;
	while(read(0, &caracter, 1)){
		if(caracter == '\n'){
			lineas++;
		}
	}
	if(caracter == '\n'){
		lineas++;
	}
	printf("Lineas contadas: %d\n", lineas);
	return 0;
}
