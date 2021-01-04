#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int	areFriends[10][10];
int check[10];
int	st;
int cpn;

void		match(int preFree, int *sol)
{
	int firstFree;
	for (firstFree = preFree + 1; firstFree < st; firstFree++)
		if (!check[firstFree]) break;
	if (firstFree == st)
	{	(*sol)++;	return;}
	int mate;
	for (mate = firstFree + 1; mate < st; mate++)
	{
		if (!check[mate] && areFriends[firstFree][mate])
		{
			check[firstFree] = check[mate] = 1;
			match(firstFree, sol);
			check[firstFree] = check[mate] = 0;
		}
	}
	return;
}

int		main()
{
	int	c;
	int	sol;

	scanf("%d", &c);
	for (int i = 0; i < c; i++)
	{
		sol = 0;
		scanf("%d", &st);
		scanf("%d", &cpn);
		for (int i = 0; i < cpn; i++)
		{
			int row,col;
			scanf("%d", &row);
			scanf("%d", &col);
			areFriends[row][col] =
				areFriends[col][row] = 1;
		}
		match(-1, &sol);
		printf("%d\n", sol);
		//reset areFriends(friend, couple list)
		for (int i = 0; i < st; i++)
			for (int j = 0; j < st; j++) areFriends[i][j] = 0;
	}
}
