#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;
#define N 100000
#define M 1000000

struct edge{
	int h;
	int t;
	int valid;
};
struct edge eg[M];
vector< vector<int> > edges;
vector< int > replaced_edges;
int nTag[N], del_num, rep_num, naive_cnt = 10000;
int n, m, TYPE;
FILE *fp = NULL;

void init(){
	fp = fopen("./data/graph2.txt","r");
	fscanf(fp, "%d %d", &n, &m);
	edges.resize(n+1);
	for (int i = 1; i <= n; i++)
		edges[i].resize(n+1);
	for (int i = 1; i <= m; i++){
		fscanf(fp, "%d %d", &eg[i].h, &eg[i].t);
		edges[eg[i].h][eg[i].t] = 1;
		eg[i].valid = 1;
	}
	for (int i = 1; i <= n; i++){
		nTag[i] = i;
	}
	fclose(fp);
}

void naive(){
	srand(time(NULL));
	int tCount = naive_cnt;
	int x, y;
	int tmp;
	while(tCount--){
		x = rand() % n + 1;
		y = rand() % n + 1;
		if (x == y) continue;
		tmp = nTag[x];
		nTag[x] = nTag[y];
		nTag[y] = tmp;
	}
}

void sparsify(){
	srand(time(NULL));
	int cnt = del_num;
	while (cnt--){
		retry:
			int x = rand() % m + 1;
			if (eg[x].valid == 0)
				goto retry;
			eg[x].valid = 0;
	}

}

void switching(){
	srand(time(NULL));
	int cnt = del_num / 2;
	while (cnt--){
		retry:
			
			int p1 = rand() % m + 1;
			int p2 = rand() % m + 1;
			if (p1 == p2) 
				goto retry;
			
			int x1 = eg[p1].h;
			int x2 = eg[p1].t;
			int y1 = eg[p2].h;
			int y2 = eg[p2].t;
			
			if (edges[x1][y2] || edges[y1][x2])
				goto retry;

			edges[x1][x2] = 0;
			edges[y1][y2] = 0;
			edges[x1][y2] = 1;
			edges[y1][x2] = 1;

			eg[p1].t = y2;
			eg[p2].t = x2;
	}
}

void perturb(){
	srand(time(NULL));
	int cnt = rep_num;
	while (cnt--){
		p_del_retry:
			int id = rand() % m + 1;
			if (eg[id].valid == 0)
				goto p_del_retry;
			eg[id].valid = 0;
			replaced_edges.push_back(id);

	}

	for (vector<int>::iterator it = replaced_edges.begin(); it != replaced_edges.end(); it++) {
		int id = *it;
		p_add_retry:
			int h = rand() % n + 1;
			int t = rand() % n + 1;
			if (h == t)
				goto p_add_retry;
			if (edges[h][t] == 1)
				goto p_add_retry;
			edges[h][t] = 1;
			eg[id].h = h;
			eg[id].t = t;
			eg[id].valid = 1;
	}
}

void output(){
	fp = fopen("./data/pair.txt","w");
	for (int i = 1; i <= n; i++){
		fprintf(fp, "%d %d\n", nTag[i], i);
	}
	fclose(fp);
	fp = fopen("./data/anonymized.txt","w");
	fprintf(fp, "%d %d\n", n, m - del_num);
	for (int i = 1; i <= m; i++){
		if (eg[i].valid)
			fprintf(fp, "%d %d\n", nTag[eg[i].h], nTag[eg[i].t]);
	}
	fclose(fp);
}

int main(int argv, char* argc[]){
	TYPE = atoi(argc[1]);
	init();
	switch (TYPE){
		case 1:
			del_num = (int)(0.1*m);
			sparsify();
			break;
		case 2:
			del_num = (int)(0.1*m);
			switching();
			break;
		case 3:
			rep_num = (int)(0.1*m);
			perturb();
			break;
		default:
			naive();
	}
	output();
}