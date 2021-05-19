#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argvnum, char **argv){
	char *origen = argv[1];
	char *destino = argv[2];
	struct stat sb;
	stat(origen, &sb);
	if(stat(origen, &sb) == -1){
		printf("Error el archivo origen no existe\n");
		return -1;
	}
	if(S_ISDIR(sb.st_mode)){
		printf("El origen es un directorio\n");
		return -1;
	}
	stat(destino, &sb);
	if(stat(destino, &sb) == -1){
		link(origen, destino);
		unlink(origen);
		return 0;
	}
	if(S_ISREG(sb.st_mode)){
		printf("Error el archivo destino ya existe\n");
		return -1;
	}
	if(S_ISDIR(sb.st_mode)){
		link(origen, strcat(destino, origen));
		unlink(origen);
	}
	return 0;
}
