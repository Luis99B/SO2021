#include <stdio.h>
#include <stdlib.h>

int main(){
	char str[80], ch;
	int dato;
	float valor;
	//scanf("%s %i %f", &str[0], &dato, &valor);
	scanf("%s", str);
	while((fgetc(stdin)) != '\n');
	scanf("%d", &dato);
	while((fgetc(stdin)) != '\n');
	scanf("%f", &valor);
	ch = getchar();
	printf("----------\n");
	fprintf(stdout, "%s\n", str)//printf = fprintf(stdout,)
	//printf("%s\n", str);
	fprintf(stdout, "%d\n", dato);
	//printf("%d\n", dato);
	fprintf(stdout, "%f\n", valor);
	//printf("%f\n", valor);
	fprintf(stdout, "%c\n", ch);
	//printf("%c\n", ch);
	fflush(stdout);
	return 0;
}
