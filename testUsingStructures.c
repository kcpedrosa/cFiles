#include <stdio.h>

struct horario{
	int hora;
	int min;
	int seg;
};
//youtube Programar em C - Passar e Receber Estruturas à uma Função - Aula 42 De aluno para aluno
//passing struct as a parameter to a function

int main(void){
	struct horario funcStru(struct horario x);

	struct horario agora;
	agora.hora = 10;
	agora.min = 20;
	agora.seg=30;

	struct horario proxima;
	proxima = funcStru(agora);
	printf("print located in main %i %i %i \n", proxima.hora, proxima.min, proxima.seg );

	printf("Calling funcStru() alone: \n");
	funcStru(agora);//calling this func alone will result in a print, the data will be in struct horario agora

	return 0;

}
//construct your function after main
struct horario funcStru( struct horario x){
	
	printf("print inside funcStru %i %i %i \n", x.hora, x.min, x.seg );

//these structs elements will override what is received as  parameters
	//x.hora = 70;
	//x.min = 70;
	//x.seg = 70;
//this will result in a ''print located in main 70 70 70 

	return x;

}