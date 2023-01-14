#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>				/* printf, scanf definitions.	*/
#include <stdlib.h>		
typedef struct {
	int x;
	int y;
}coordinate_t;
void path(char[][8], int, int, int*,int*,int[], coordinate_t[][64]);

int main(void)
{
	coordinate_t all[100][64] = {0};
	int step[100] = {0};
	int x = 0;
	int y = 1;
	int state;
	int s_step=1000,s_map;
	int count = 0;
	char map[8][8] = {
		 {'X',    ' ',    ' ',    ' ',    ' ',    'X',    'X',    'X'},
		 {' ',    'X',    ' ',    'X',    ' ',    ' ',    ' ',    'X'},
		 {' ',    'X',    ' ',    'X',    ' ',    'X',    ' ',    'X'},
		 {' ',    'X',    ' ',    'X',    ' ',    'X',    ' ',    'X'},
		 {' ',    'X',    ' ',    ' ',    ' ',    ' ',    'X',    'X'},
		 {' ',    'X',    ' ',    'X',    ' ',    ' ',    ' ',    ' '},
		 {' ',    'X',    ' ',    'X',    ' ',    'X',    ' ',    ' '},
		 {' ',    ' ',    ' ',    ' ',    ' ',    'X',    'X',    ' '}
	};
	path(map, x, y, &state,&count,step,all);
	if (state != 1) {
		system("pause");
		printf("NO path");
		return 0;
	}
	for (int i = 1; i < count + 1; i++) {
		if (s_step > step[i]) {
			s_step = step[i];
		}		
	}
	printf("The number of shortest paths moves in map is %d\n", s_step);
	printf("All shortest paths in map are shown below\n");
	for (int i = 1; i < count + 1; i++) {
		if (s_step == step[i]) {
			printf("Path :%d\n", i);
			for (int j = 1; j < s_step + 1; j++) {
				printf("(%d,%d)->", all[i][j].x, all[i][j].y);			
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}

void path(char map[][8], int x, int y, int* state,int *count,int step[], coordinate_t all[][64]) {

	map[x][y] = '*';
	if (x == 7 and y == 7) {
		*state = 1;
		*count += 1;
		printf("Path:%d\n", *count);
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (map[i][j]=='*'){
					step[*count] += 1;
					all[*count][step[*count]].x = i;
					all[*count][step[*count]].y = j;
				printf("(%d,%d)->",i,j);
				}
			}
		}
		printf("\n");

	}
	else
	{
		if (map[x][y + 1] == ' ' and y + 1 <= 7) {

			path(map, x, y + 1, state,count,step,all);
		}
		if (x - 1 >= 0 and map[x - 1][y] == ' ') {

			path(map, x - 1, y, state, count, step,all);
		}
		if (x + 1 <= 7 and map[x + 1][y] == ' ') {

			path(map, x + 1, y, state, count, step,all);
		}
		if (y - 1 >= 7 and map[x][y - 1] == ' ') {

			path(map, x, y - 1, state, count, step,all);
		}
	}
	map[x][y] = ' ';
}
