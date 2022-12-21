#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES	100	
#define INF	1000000	/* ���Ѵ� (������ ���� ���) */

typedef struct GraphType {
	int n;	// ������ ����
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];/* �����������κ����� �ִܰ�� �Ÿ� */
int found[MAX_VERTICES];		/* �湮�� ���� ǥ�� */
								
int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i<n; i++)
		if (distance[i]< min && !found[i]) { // 거리가 최대값보다 작고, 방문하지 않은 노드라면
			min = distance[i]; // 최소값을 해당 거리로 변경
			minpos = i; // 최소 거리의 index 설정
		}
	return minpos;
}

void print_status(GraphType* g)
{
	static int step=1;
	printf("STEP %d: ", step++);
	printf("distance: ");
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf("        found:    ");
	for (int i = 0; i<g->n; i++)
		printf("%2d ", found[i]);
	printf("\n\n");
}
//
void shortest_path(GraphType* g, int start)
{
	int i, u, w;
	for (i = 0; i<g->n; i++) /* �ʱ�ȭ */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE; // 초기화 진행
	}
	found[start] = TRUE; // 시작값은 방문하였으므로 TRUE
	distance[start] = 0; // 시작값의 거리는 0
	for (i = 0; i<g->n-1; i++) {
		print_status(g);
		u = choose(distance, g->n, found); // 최소 거리에 존재하는 노드 반환
		found[u] = TRUE;
		for (w = 0; w<g->n; w++)
			if (!found[w]) // 방문하지 않은 노드라면
				if (distance[u] + g->weight[u][w]<distance[w]) // 중첩된 거리를 합했을 때의 거리가 더 짧다면
					distance[w] = distance[u] + g->weight[u][w];
	}
}

int main(void)
{
	GraphType g = { 7,
	{{ 0,  7,  INF, INF,   3,  10, INF },
	{ 7,  0,    4,  10,   2,   6, INF },
	{ INF,  4,    0,   2, INF, INF, INF },
	{ INF, 10,    2,   0,  11,   9,   4 },
	{ 3,  2,  INF,  11,   0, INF,   5 },
	{ 10,  6,  INF,   9, INF,   0, INF },
	{ INF, INF, INF,   4,   5, INF,   0 } }
	};
	shortest_path(&g, 0);
	return 0;
}