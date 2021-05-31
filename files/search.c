#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main(int argc, char **argv){
	char *filename = argv[1];
	char *parameter = argv[2];
	char *value = argv[3];
	FILE *forigen;
	forigen = fopen(filename, "rb");
	int size = 0;
	STUDENT student;
	while(fread(&student, sizeof(student), 1, forigen) != 0){
		size++;
	}
	rewind(forigen);
	int found = 0;
	for(int i = 0; i < size; i++){
		fread(&student, sizeof(student), 1, forigen);
		if(strcmp(parameter, "name") == 0){ // Busqueda por nombre
			if(strcmp(value, student.name) == 0){
				if(found == 0){
					printf("-----Nombre %s encontrado-----\n", value);
				}
				printf("Nombre: %s, Apellido: %s, ID: %d, Semestre: %d\n", student.name, student.lastname, student.id, student.semestre);
				found++;
			}
		}else if(strcmp(parameter, "lastname") == 0){ // Busqueda por apellido
			if(strcmp(value, student.lastname) == 0){
				if(found == 0){
					printf("-----Apellido %s encontrado-----\n", value);
				}
				printf("Nombre: %s, Apellido: %s, ID: %d, Semestre: %d\n", student.name, student.lastname, student.id, student.semestre);
				found++;
			}
		}else if(strcmp(parameter, "id") == 0){ // Busqueda por id
			int id = atoi(value);
			if(id == student.id){
				if(found == 0){
					printf("-----Id %d encontrado-----\n", id);
				}
				printf("Nombre: %s, Apellido: %s, ID: %d, Semestre: %d\n", student.name, student.lastname, student.id, student.semestre);
				found++;
			}
		}else if(strcmp(parameter, "semestre") == 0){ // Busqueda por semestre
			int semestre = atoi(value);
			if(semestre == student.semestre){
				if(found == 0){
					printf("-----Semestre %d encontrado-----\n", semestre);
				}
				printf("Nombre: %s, Apellido: %s, ID: %d, Semestre: %d\n", student.name, student.lastname, student.id, student.semestre);
				found++;
			}
		}else{
			printf("%s no es un parametro de busqueda\n", parameter);
			return -1;
		}
	}
	if(found == 0){
		printf("Dato no encontrado\n");
	}
	fclose(forigen);
	return 0;
}
