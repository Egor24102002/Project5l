#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define HEADER ("Лабораторная работа №4\nВыполнили: Шмелёв Д. и Пантюшов Е.\n")

#include <stdio.h>
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define HEADER ("Лабораторная работа №5\nВыполнили: Шмелёв Д. и Пантюшов Е.\n\n")
#include <queue>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
using namespace std;



void bfs(int** G, int* NUM, int v, int n)
{
	queue <int> q;
	q.push(v);
	NUM[v] = 1;
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		printf(" %d ", v);
		for (int i = 0; i < n; i++)
		{
			if ((G[v][i] == 1) && (NUM[i] == 0))
			{
				q.push(i);
				NUM[i] = 1;
			}
		}
	}
}

void task_1_1(int** G, int n)
{
	printf("\nЗадание 1.\n\nПункт 1.\nМатрица смежности:\n");
	for (int i = 0; i < n; i++)
	{
		G[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
		{
			G[i][j] = rand() % 2;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				G[i][j] = 0;
			}
			else
			{
				G[i][j] = G[j][i];
			}
			printf(" %d ", G[i][j]);
		}
		printf("\n");
	}
}

void task_1_2(int** G, int n)
{
	int* NUM = (int*)malloc(n * sizeof(int));
	int v;
	for (int i = 0; i < n; i++)
	{
		NUM[i] = 0;
	}
	printf("\nПункт 2.\nВведите точку входа: ");
	scanf("%d", &v);
	printf("Результат работы алгоритма обхода в ширину(матрица): ");
	bfs(G, NUM, v, n);
	free(NUM);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	printf(HEADER);
	printf("Введите размерность матрицы: ");
	int n;
	scanf("%d", &n);
	int** G = (int**)malloc(n * sizeof(int*));
	task_1_1(G, n);
	task_1_2(G, n);
	system("PAUSE");
	return 0;
}