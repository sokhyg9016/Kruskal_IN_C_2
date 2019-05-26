# Kruskal_IN_C_2
다른 방법으로 크러스컬(Kruskal)알고리즘을 구현해보자.

<h5>Data</h5>
<img src = "http://cslab2.kku.ac.kr/~201721210/graph.jpg" width = "500px" height = "400px"><br>
<ol>
  <li>"data.txt"파일에 위의 그림과 같은 데이터 형식을 파일 입출력을 통해 얻을 수 있도록 텍스트 파일의 구조로 변경합니다.</li>
<pre>
11 7
1 7 12
1 4 28
1 2 67
1 5 17
2 4 24
2 5 62
3 5 20
3 6 37
4 7 13
5 6 45
5 7 73
</pre>
  <li>첫 번재 줄의 <pre>11 7</pre>은 각각 그래프의 <b>전체 간선의 개수</b>와 <b>전체 노드의 개수</b>를 나타냅니다.</li><br>
  <li>그 뒤에 나오는 <pre>1 7 12</pre>의 형식은 각각 <b>노드A</b>,&nbsp;&nbsp;<b>노드B</b>,&nbsp;&nbsp;<b>노드A와 노드B의 가중치 값</b>의 형식입니다.</li><br>
  <li>이 파일의 형식을 "kruskal.c"의 <pre><b>EDGE *read_graph(char *GFile, int *m, int *n);</b></pre>에서 읽도록 합니다.<br>
      <pre>
      <code>
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
      </code>
      </pre>
   </li><br>
 </ol>
 <br>
 <br>
 
 <h3>참고</h3>
 <ul>
  <li><a href = "https://www.youtube.com/watch?v=AMByrd53PHM&list=PLRx0vPvlEmdDHxCvAQS1_6XV4deOwfVrz&index=18">합집합 찾기(Union-Find)   </a></li>
  <li><a href = "https://www.youtube.com/watch?v=LQ3JHknGy8c&list=PLRx0vPvlEmdDHxCvAQS1_6XV4deOwfVrz&index=19">크루스칼 알고리즘(Kruskal Algorithm)</a></li>
 </ul>
 
 
 
