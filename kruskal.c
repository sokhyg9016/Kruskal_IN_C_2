#include "kruskal.h"

void init(EDGE* ins, int a, int b, int distance)
{
	ins->node[0] = a;
	ins->node[1] = b;
	ins->distance = distance;
}

int e_order(const void *a, const void *b)   //for qsort
{
	EDGE *aa, *bb;
	aa = (EDGE *)a;
	bb = (EDGE *)b;

	if (aa->distance < bb->distance)    // a가 b보다 작을 때는
		return -1;      // -1 반환
	if (aa->distance > bb->distance)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}

EDGE *read_graph(char *GFile, int *m, int *n)
{
	FILE *fp;
	EDGE *elist;
	int i = 0;

	if ((fp = fopen(GFile, "r")) != NULL)
	{
		fscanf(fp, "%d%d", m, n); // total edge and vertex
		elist = (EDGE *)malloc(sizeof(EDGE) * (*m));

		while (i < *m)
		{
			fscanf(fp, "%d%d%d", &elist[i].node[0], &elist[i].node[1], &elist[i].distance);
			i++;
		}
	}
	else
	{
		perror("error : can't read file");
	}
	return elist;
}

void Print(EDGE* ins, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%5d  %10d  %15d : [%02d]\n", ins[i].node[0], ins[i].node[1], ins[i].distance, i);
	}
	puts("");

}

// 특정한 부모의 노드를 찾는 함수
int getParent(int parent[], int x)
{
	//입력으로 들어온 노드의 값이 그 노드의 부모 값과 같다면
	//그 노드 자체가 루트노드이므로 그대로 리턴해준다.
	if (parent[x] == x)
	{
		return x;
	}
	return getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, parent[a]);
	b = getParent(parent, parent[b]);

	//부모를 합칠 때는 더 작은 쪽으로 합침
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

// 같은 부모 노드를 가지는 지 확인하는 함수
int findParent(int parent[], int a, int b)
{
	a = getParent(parent, parent[a]);
	b = getParent(parent, parent[b]);

	if (a == b)
		return 1;
	else
		return 0;
}


