#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>				/* printf, scanf definitions.	*/
#include <stdlib.h>
#include <math.h>
typedef struct {
	int x;
	int y;
}coodi;
void path(int[][8],int,int,int*,int*, int[] ,coodi[],coodi[][64],int,int*);
int main(void) {
	coodi all[100][64] = { 0 };
	int x = 0, y = 0;
	int state = 0;
	int count_map = 0, count_step[64] = { 0 };
	int min_step = 100;
	coodi path_temp[64];
	int maze1[8][8] = {
		{0, 0, 0, 0, 0, 0, 0, 1},
		{0, 1, 0, 0, 0, 1, 0, 0},
		{0, 0, 1, 1, 0, 0, 1, 0},
		{1, 0, 1, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 1, 1},
		{0, 1, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 1, 0, 1, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0},
	};
	int maze2[8][8] = {
		{0, 1, 0, 1, 0, 0, 0, 1},
		{0, 0, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 1, 0, 0, 1, 0},
		{1, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 0, 1},
		{0, 1, 0, 0, 0, 1, 0, 1},
		{0, 1, 0, 1, 0, 1, 0, 0},
		{0, 0, 0, 1, 0, 0, 1, 0},
	};
	path(maze1, x, y, &state, &count_map, count_step,path_temp, all,0,&min_step);
	if (state != 1) {
		printf("no path\n");
	}
	else {
		printf("The shortest path is :");
		printf("%d\n", min_step);
		printf("All shortest paths in map are shown below\n");

		for (int i = 0;i < count_map;i++) {
			if (min_step==count_step[i]){
				printf("Path :%d\n", i+1);
				for (int j = 0;j < count_step[i];j++) {					
					printf("(%d,%d)->", all[i][j].x, all[i][j].y);
				}
				printf("\n");
			}
		}	
		
	}
	state = 0;
	count_map = 0;
	min_step = 100;
	path(maze2, x, y, &state, &count_map, count_step, path_temp, all, 0, &min_step);
	if (state != 1) {
		printf("no path\n");
	}
	else {
		printf("The shortest path is :");
		printf("%d\n", min_step);
		printf("All shortest paths in map are shown below\n");

		for (int i = 0;i < count_map;i++) {
			if (min_step == count_step[i]) {
				printf("Path :%d\n", i + 1);
				for (int j = 0;j < count_step[i];j++) {
					printf("(%d,%d)->", all[i][j].x, all[i][j].y);
				}
				printf("\n");
			}
		}

	}

}

void path(int map[][8], int x, int y, int* state, int* count_map, int count_step[],  coodi path_temp[], coodi all[][64],int len,int *min_step) {
	map[x][y] = 2;
	if (x == 7 and y == 7) {
		path_temp[len].x = x;
		path_temp[len].y = y;
		len++;
		*state = 1;
		count_step[*count_map] = len;
		*count_map += 1;
		printf("Path %d:\n", *count_map);
		for (int i = 0;i < len;i++) {
			all[*count_map - 1][i].x = path_temp[i].x;
			all[*count_map - 1][i].y = path_temp[i].y;
			printf("(%d,%d)->", all[*count_map - 1][i].x, all[*count_map - 1][i].y);
		}

		printf("\n");
	
		if (*min_step > len) {
			*min_step = len;
		}
		
	}
	else {
		path_temp[len].x = x;
		path_temp[len].y = y;
		len++;
		
		if (map[x + 1][y] == 0 and x + 1 < 8) {

			path(map, x+1,  y, state, count_map, count_step, path_temp, all, len, min_step);
		}
		if (map[x][y + 1] == 0 and y + 1 < 8) {

			path(map, x, y+1, state, count_map, count_step, path_temp, all, len, min_step);
		}
		if (map[x - 1][y] == 0 and x - 1 > -1) {

			path(map, x-1, y, state, count_map, count_step, path_temp, all,len, min_step);
		}
		if (map[x][y - 1] == 0 and y - 1 > -1) {

			path(map, x, y-1, state, count_map, count_step, path_temp, all, len, min_step);
		}
	}
	map[x][y] = 0;
}
