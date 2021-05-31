#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main(int argc, char **argv){
	char *filename = argv[1];
	char *parameter = argv[2];
	char *origenValue = argv[3];
	char *newValue = argv[4];
	
	FILE *forigen;
	forigen = fopen(filename, "r+");
	int size = 0;
	STUDENT student;
	while(fread(&student, sizeof(student), 1, forigen) != 0){
		size++;
	}
	if(size == 0){
		printf("No hay datos, el archivo esta vacio\n");
		return -1;
	}
	rewind(forigen);
	int update = 0;
	for(int i = 0; i < size; i++){
		fread(&student, sizeof(student), 1, forigen);
		if(strcmp(parameter, "name") == 0){ // Actualizar por nombre
			if(strcmp(origenValue, student.name) == 0){
				printf("-----Dato Original-----\n");
				printf("Nombre: %s, Apellido: %s, ID: %d, Semestre: %d\n", student.name, student.lastname, student.id, student.semestre);
				strcpy(student.name, newValue);
				fseek(forigen, -sizeof(student), SEEK_CUR);
				fwrite(&student, sizeof(student), 1, forigen);
				printf("\n-----Dato Actualizado-----\n");
				printf("Nombre: %s, Apellido: %s, ID: %d, Semestre: %d\n", student.name, student.lastname, student.id, student.semestre);
				update++;
				break;
			}
		}else if(strcmp(parameter, "lastname") == 0){ // Actualizar por apellido
			if(strcmp(origenValue, student.lastname) == 0){
				printf("-----Dato Original-----\n");
				printf("Nombre: %s, Apellido: %s, ID: %d, Semestre: %d\n", student.name, student.lastname, student.id, student.semestre);
				strcpy(student.lastname, newValue);
				fseek(forigen, -sizeof(student), SEEK_CUR);
				fwrite(&student, sizeof(student), 1, forigen);
				printf("\n-----Dato Actualizado-----\n");
				printf("Nombre: %s, Apellido: %s, ID: %d, Semestre: %d\n", student.name, student.lastname, student.id, student.semestre);
				update++;
				break;
			}
		}else if(strcmp(parameter, "id") == 0){ // Actualizar por id
			int origenId = atoi(origenValue);
			if(origenId == student.id){
				printf("-----Dato Original-----\n");
				printf("Nombre: %s, Apellido: %s, ID: %d, Semestre: %d\n", student.name, student.lastname, student.id, student.semestre);
				int newId = atoi(newValue);
				student.id = newId;
				fseek(forigen, -sizeof(student), SEEK_CUR);
				fwrite(&student, sizeof(student), 1, forigen);
				printf("\n-----Dato Actualizado-----\n");
				printf("Nombre: %s, Apellido: %s, ID: %d, Semestre: %d\n", student.name, student.lastname, student.id, student.semestre);
				update++;
				break;
			}
		}else if(strcmp(parameter, "semestre") == 0){ // Actualizar por semestre
			int origenSemestre = atoi(origenValue);
			if(origenSemestre == student.semestre){
				printf("-----Dato Original-----\n");
				printf("Nombre: %s, Apellido: %s, ID: %d, Semestre: %d\n", student.name, student.lastname, student.id, student.semestre);
				int newSemestre = atoi(newValue);
				student.semestre = newSemestre;
				fseek(forigen, -sizeof(student), SEEK_CUR);
				fwrite(&student, sizeof(student), 1, forigen);
				printf("\n-----Dato Actualizado-----\n");
				printf("Nombre: %s, Apellido: %s, ID: %d, Semestre: %d\n", student.name, student.lastname, student.id, student.semestre);
				update++;
				break;
			}
		}else{
			printf("%s no es un parametro valido\n", parameter);
			return -1;
		}
	}
	if(update == 0){
		printf("Dato no encontrado para actualizar\n");
	}
	fclose(forigen);
	return 0;
}
