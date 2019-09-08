#include <stdio.h>

int main()
{
	int a = 0;
	int b=0, c=0;
	int num = 0;
	int number = 0;
	int number1[3][3] = { {0,0,1},{1,1,1},{0,1,0} };
	int number2[3][3] = { {1,0,1},{0,0,0},{0,1,0} };
	
	printf("M/m 행렬의 곱셈\n");
	printf("A/a 행렬의 덧셈\n");
	printf("D/d 행렬의 뺄셈\n");
	printf("R/r 행렬식의 값\n");
	printf("H/h 3x3 -> 4x4행렬 변환\n");
	printf("Q/q 프로그램 종료\n");
	printf("\n");
	printf("        1행렬             2행렬\n");
	for (int K = 0; K < 3; ++K) {
		for (int l = 0; l < 3; ++l) {
			printf(" %3d   ", number1[K][l]);
			printf(" %3d   ", number2[K][l]);
		}
		printf("\n");
	}
	
	while (a!=1) {
		
	
		int number3[3][3] = { {0,0,0 }, { 0,0,0 }, { 0,0,0 } };
	
		char c;
		scanf_s("%c", &c);
		
		switch (c) {
		case 'M':
			case 'm':

				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						int sum = 0;
						for (int n = 0; n < 3; n++) {
							sum = sum + number1[i][n] * number2[n][j];
						}
						number3[i][j] = sum;
					}
				}
				for (int K = 0; K < 3; ++K) {
					for (int l = 0; l < 3; ++l) {
						printf("%3d   ", number3[K][l]);
					}
					printf("\n");
				}
				break;
		case 'A':
		case'a':
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					number3[i][j] = number1[i][j] + number2[i][j];
				}
			}
			for (int K = 0; K < 3; ++K) {
				for (int l = 0; l < 3; ++l) {
					printf("%3d   ", number3[K][l]);
				}
				printf("\n");
			}
			break;
		case 'D':
		case'd':
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					number3[i][j] = number1[i][j] - number2[i][j];
				}
			}
			for (int K = 0; K < 3; ++K) {
				for (int l = 0; l < 3; ++l) {
					printf("%3d   ", number3[K][l]);
				}
				printf("\n");
			}
			break;
		case 'R':
		case 'r':
			printf("1or 2\n");
			scanf_s("%d", &number);
			if (number == 1) {
				b = number1[0][0] * number1[1][1] * number1[2][2] + number1[0][1] * number1[1][2] * number1[2][0] + number1[0][2] * number1[1][0] * number1[2][1];
				c = number1[0][2] * number1[1][1] * number1[2][0] + number1[1][2] * number1[2][1] * number1[0][0] + number1[2][2] * number1[0][1] * number1[1][0];
				num = b - c;
				printf("\n");
				printf("R=%3d   ",num);
				printf("\n");
				printf("\n");
				printf("\n");
				
			}
			if (number == 2) {
				b = number2[0][0] * number2[1][1] * number2[2][2] + number2[0][1] * number2[1][2] * number2[2][0] + number2[0][2] * number2[1][0] * number2[2][1];
				c = number2[0][2] * number2[1][1] * number2[2][0] + number2[1][2] * number2[2][1] * number2[0][0] + number2[2][2] * number2[0][1] * number2[1][0];
				num = b - c;
				printf("\n");
				printf(" R=%3d   ",num);
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");
				
			}
			
			printf("%d", num);
			break;
		case 'H':
		case'h':
			printf("1or 2\n");
			scanf_s("%d", &number);
			if (number == 1) {
				int z[4][4];
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {

						z[i][j] = number1[i][j];

						if (i == 3 && j == 3)
							z[i][j] = 1;
						else if (j == 3)
							z[i][j] = 0;
						else if (i == 3)
							z[i][j] = 0;

						printf("%3d   ", z[i][j]);
					}
					printf("\n");
				}
			}
			if (number == 2) {
				int z[4][4];
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {

						z[i][j] = number2[i][j];

						if (i == 3 && j == 3)
							z[i][j] = 1;
						else if (j == 3)
							z[i][j] = 0;
						else if (i == 3)
							z[i][j] = 0;

						printf("%3d   ", z[i][j]);
					}
					printf("\n");
				}
			}

			break;
		case 'Q':
		case'q':
			printf("종료합니다.\n");
			a +=1;
			break;
		}
	}
}

