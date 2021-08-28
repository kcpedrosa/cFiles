#include <stdio.h>

struct horario{
	int hora;
	int min;
	int seg;
};

int main(void)
{
	void recebHorarios(struct horario lista[2]);
	void printHorarios(struct horario lista[2]);
	struct horario listaHorarios[2];

	recebHorarios(listaHorarios);
	printHorarios(listaHorarios);

//system("pause");

return 0;
}
void recebHorarios(struct horario lista[2]){
	int i;
	for(i=0; i < 2; ++i){
		printf("Enter the %i time as [hh:mm:ss]  \n", i + 1);
		scanf(" %i  ", &lista[i].hora);
		scanf(" %i  ", &lista[i].min);
		scanf(" %i  ", &lista[i].seg);
	}

}
void printHorarios(struct horario lista[2]){
	int i;
	for(i=0; i < 2; ++i){
		printf("O %i horario é = %i / %i / %i \n",i+1, 
			lista[i].hora,
		 lista[i].min,
			lista[i].seg);
	}
}