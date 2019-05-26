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

//Union-Find 알고리즘

// 특정한 부모의 노드를 찾는 함수
int getParent(int parent[], int x);

// 두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b);

// 같은 부모 노드를 가지는 지 확인하는 함수
int findParent(int parent[], int a, int b);