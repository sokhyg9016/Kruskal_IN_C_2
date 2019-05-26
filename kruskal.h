#pragma once
#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
	int node[2];
	int distance;
}EDGE;

void init(EDGE* ins, int a, int b, int distance);
int e_order(const void *a, const void *b);   //for qsort
EDGE *read_graph(char *GFile, int *m, int *n);
void Print(EDGE* ins, int size);

//Union-Find �˰���

// Ư���� �θ��� ��带 ã�� �Լ�
int getParent(int parent[], int x);

// �� �θ� ��带 ��ġ�� �Լ�
void unionParent(int parent[], int a, int b);

// ���� �θ� ��带 ������ �� Ȯ���ϴ� �Լ�
int findParent(int parent[], int a, int b);