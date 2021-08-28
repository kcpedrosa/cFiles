#include <stdio.h>

int main(void){

	//declare your funtion in main [convention]
	void funcPrint( int mP[3][3]);//
	int matrix[3][3] = {1,2,3,4,5,6,7,8,15};//remember to declare the size of the matrix = [][]
	//int i, j;
	funcPrint(matrix);

	return 0;

}
//construct your function after main
void funcPrint( int mP[][3]){
	int i, j;
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			printf("%i ", mP[i][j] );
		}
		printf("\n");
	}
}