#include "kruskal.h"

int main(int argc, char* argv[])
{
	//int parent[10];
	//int i;
	//
	//for (i = 0; i < 10; i++)
	//{
	//	parent[i] = i;
	//}
	//unionParent(parent, 1, 2);
	//unionParent(parent, 2, 3);
	//unionParent(parent, 3, 4);
	//unionParent(parent, 5, 6);
	//unionParent(parent, 6, 7);
	//unionParent(parent, 7, 8);
	//
	//printf("1�� 5�� ����Ǿ� �ִ°�? %d\n", findParent(parent, 1, 5));
	//unionParent(parent, 1, 5);
	//printf("1�� 5�� ����Ǿ� �ִ°�? %d\n", findParent(parent, 1, 5));
	//
	//for (i = 0; i < 10; i++)
	//{
	//	printf("parent[%d] = %d\n", i, parent[i]);
	//}

	EDGE * Graph;
	int* parent;
	int nedge, num_vertex, i;
	int sum;
	
	Graph = read_graph(argv[1], &nedge, &num_vertex);
	parent = (int*)malloc(sizeof(int)* num_vertex);
	sum = 0;

	//print
	Print(Graph, nedge);

	//sort
	qsort(Graph, nedge, sizeof(EDGE), e_order);

	//print
	Print(Graph, nedge);

	for (i = 0; i < num_vertex; i++)
	{
		parent[i] = i;
	}
	
	for (i = 0; i < num_vertex; i++)
	{
		//Parent ����� �迭�� [0] ~ [6]�̹Ƿ�, Graph �迭�� [1]~ [7]�� ������ ������ ��忡�� -1 �� ����� �Ѵ�.
		if (!findParent(parent, Graph[i].node[0] - 1, Graph[i].node[1] - 1))
		{
			sum += Graph[i].distance;
			unionParent(parent, Graph[i].node[0] - 1, Graph[i].node[1] - 1);
		}
	}

	printf("sum = %d\n", sum);

	free(Graph);
	free(parent);

	return 0;
}



