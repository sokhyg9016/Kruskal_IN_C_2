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

	if (aa->distance < bb->distance)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ
	if (aa->distance > bb->distance)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
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

// Ư���� �θ��� ��带 ã�� �Լ�
int getParent(int parent[], int x)
{
	//�Է����� ���� ����� ���� �� ����� �θ� ���� ���ٸ�
	//�� ��� ��ü�� ��Ʈ����̹Ƿ� �״�� �������ش�.
	if (parent[x] == x)
	{
		return x;
	}
	return getParent(parent, parent[x]);
}

// �� �θ� ��带 ��ġ�� �Լ�
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, parent[a]);
	b = getParent(parent, parent[b]);

	//�θ� ��ĥ ���� �� ���� ������ ��ħ
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

// ���� �θ� ��带 ������ �� Ȯ���ϴ� �Լ�
int findParent(int parent[], int a, int b)
{
	a = getParent(parent, parent[a]);
	b = getParent(parent, parent[b]);

	if (a == b)
		return 1;
	else
		return 0;
}


