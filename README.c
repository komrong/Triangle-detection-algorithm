//Triangle-detection-algorith -- Finds the triangle with distinct assigned numbers 


/*
A triangle ABC is given. Each side of ABC is divided into equal
parts, and through each of the division points are drawn lines parallel to
AB,BC, and CA, thus cutting ABC into small triangles. To each of the
vertices of these triangles is assigned 1, 2, or 3, so that:
(1) to A,B,C are assigned 1, 2 and 3 respectively;
(2) points on AB are marked by 1 or 2;
(3) points on BC are marked by 2 or 3;
(4) points on CA are marked by 3 or 1.
Prove that there must exist a small triangle whose vertices are marked by
1, 2, and 3.
*/

/*
Below algorithms assigns all possible values of 1,2 and 3 to those vertices differently for each run-time
and detects if the triangle exists with all vertices all different
*/

#include <stdio.h>
#include <time.h>
#include <math.h>

int main(void){
	int con = 0;
	do{
	srand(time(NULL));
	
	int const DIV = 4;
	int const NUM_LIN = DIV;
	int const LIN_DOT = DIV+1;
	
	int arr[NUM_LIN][LIN_DOT];
	int A = 1;
	int i, j;
	
	for(i = 0; i < NUM_LIN; i++){
		for(j = 0; j < LIN_DOT; j++){
			arr[i][j] = -1;
		}
	}
	
	for(i = 0; i < NUM_LIN; i++){
		for(j = 0; j < i+2; j++){
			if(j == 0){
				if(i == NUM_LIN-1){
					arr[i][j] = 2;
				}
				else{
					arr[i][j] = rand()%2+1;
				}
			}
			else if(j == i+1){
				if(i == NUM_LIN-1){
					arr[i][j] = 3;
				}
				else{
					do{
						arr[i][j] = rand()%3+1;
					}while(arr[i][j] == 2);
				}
			}
			else{
				if(i == NUM_LIN-1){
					arr[i][j] = rand()%2+2;
				}
				else{
					arr[i][j] = rand()%3+1;
				}
			}
		}
	}
	int y, t;
	for(y = 0; y < LIN_DOT/2; y++){
		printf("%4c", 32);
	}
	printf("%2d", A);
	printf("\n");

	for(i = 0; i < NUM_LIN; i++){
		if(i % 2 == 0){
				for(t = 0; t < LIN_DOT/2-(i+1); t++){
					printf("%4c", 32);
				}
				printf("%2c", 32);
			}
			else if(i % 2 == 1){
				for(t = 0; t < LIN_DOT/2-(i); t++){
					printf("%4c", 32);
				}
			}
			
		for(j = 0; j < LIN_DOT; j++){
			if(arr[i][j] == -1){
				break;
			}
			else{
				printf("%2d  ", arr[i][j]);
			}
		}
		printf("\n");
	}
	
	int stop = 0;
	for(i = 0; i < NUM_LIN; i++){
		if(i == 0){
			if(check(A, arr[i][0], arr[i][1]) == 1){
				printf("Found one\n");
				printf("Line: %d\tIndexes: %d %d Line: %d\t Index: %d\n", i+2, 1, 2, i+1, 1);
				break;
			}
			if(check(arr[i][0], arr[i][1], arr[i+1][(int)ceil((0+1)/2.0)]) == 1){
				printf("Found one\n");
				printf("Line: %d\tIndexes: %d %d Line: %d\t Index: %d\n", i+2, 1, 2, i+3, (int)ceil((0+1)/2.0)+1);
				break;
			}
		}
		else if(i == NUM_LIN-1){
			for(j = 0; j < i+1; j++){
				if(check(arr[i][j], arr[i][j+1], arr[i-1][(int)floor((j+j+1)/2.0)]) == 1){
					printf("Found one\n");
					printf("Line: %d\tIndexes: %d %d Line: %d\t Index: %d\n", i+2, j+1, j+2, i+1, (int)floor((j+j+1)/2.0)+1);
					stop = 1;
					break;
				}
			}
		}
		else{
			for(j = 0; j < i+1; j++){
				if(check(arr[i][j], arr[i][j+1], arr[i-1][(int)floor((j+j+1)/2.0)]) == 1){
					printf("Found one\n");
					printf("Line: %d\tIndexes: %d %d Line: %d\t Index: %d\n", i+2, j+1, j+2, i+1, (int)floor((j+j+1)/2.0)+1);
					stop = 1;
					break;
				}
				else if(check(arr[i][j], arr[i][j+1], arr[i+1][(int)ceil((j+j+1)/2.0)]) == 1){
					printf("Found one\n");
					printf("Line: %d\tIndexes: %d %d Line: %d\t Index: %d\n", i+2, j+1, j+2, i+3, (int)ceil((j+j+1)/2.0)+1);
					stop = 1;
					break;
				}
			}
		}
		if(stop == 1){
			break;
		}
	}
	printf("More run(1 or 0)?\n");
	scanf("%d", &con);
	}while(con == 1);
}

int check(int a, int b, int c){
	if(a == 1){
		if(b == 2){
			if(c == 3){
				return 1;
			}
		}
		else if(b == 3){
			if(c == 2){
				return 1;
			}
		}
	}
	else if(a == 2){
		if(b == 1){
			if(c == 3){
				return 1;
			}
		}
		else if(b == 3){
			if(c == 1){
				return 1;
			}
		}
	}
	else if(a == 3){
		if(b == 1){
			if(c == 2){
				return 1;
			}
		}
		else if(b == 2){
			if(c == 1){
				return 1;
			}
		}
	}
	
	return 0;
}
