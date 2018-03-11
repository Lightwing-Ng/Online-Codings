#include <cstdio>
#include <iostream>
#include <stdlib.h>
#define MAX_NUM 20
#define DIGIT 1
#define ZERO 0
using namespace std;

typedef struct {
    int num;
    char data;
} Vertex;

typedef struct {
    int n, e; //顶点数、弧数
    Vertex vexs[MAX_NUM];
    int edges[MAX_NUM][MAX_NUM];
} MGraph;

typedef struct node {
    int adjVex;
    node *nextArc;
    char info;
} ArcNode; //邻接表的结点结构

typedef struct {
    char vexData;
    ArcNode *firstArc;
} VexNode; //邻接表的表头结点

typedef struct {
    int vexNum, arcNum; //顶点数、弧数
    VexNode ve[MAX_NUM];
} ALGraph; //邻接表类型

ALGraph *Creat_alg() { //创建邻接表
    ALGraph *alg;
    int n, e, b, a;
    char ch;
    ArcNode *AR;
    alg = new ALGraph;
    cout << "输入顶点数：";
    cin >> n;
    cout << "输入弧数：";
    cin >> e;
    alg->vexNum = n;
    alg->arcNum = e;
    cout << "输入顶点信息：\n";
    for (int i = 0; i < n; ++i) {
        cin >> ch;
        alg->ve[i].vexData = ch;
        alg->ve[i].firstArc = NULL;
    }
    cout << "输入弧的信息(弧的两端点)：\n";
    for (int i = 0; i < e; ++i) {
    	cin >> a >> b;
        AR = new ArcNode;
        AR->adjVex = b;
        AR->info = alg->ve[b].vexData;
        AR->nextArc = alg->ve[a].firstArc;
        alg->ve[a].firstArc = AR;
        AR = new ArcNode;
        AR->adjVex = a;
        AR->info = alg->ve[a].vexData;
        AR->nextArc = alg->ve[b].firstArc;
        alg->ve[b].firstArc = AR;
    }
    return alg;
}

void ALGout(ALGraph *alg) { //邻接表输出
    ArcNode *p;
    VexNode *q;
    int n1 = alg->vexNum;
    for (int i = 0; i < n1; ++i) {
        q = &alg->ve[i];
        cout << q->vexData;
        p = q->firstArc;
        while (p != NULL) {
            cout << " -> " << p->info;
            p = p->nextArc;
        }
        cout << endl;
    }
}

MGraph *ALG_change_MG(ALGraph *alg) { //将邻接表转换为邻接矩阵
    MGraph *mg;
    mg = new MGraph;
    mg->n = alg->vexNum;
    mg->e = alg->arcNum;
    int n1 = mg->n;
    for (int i = 0; i < n1; i++) {
        mg->vexs[i].num = i;
        mg->vexs[i].data = alg->ve[i].vexData;
    }
    ArcNode *p;
    for (int i = 0; i < n1; i++) {
        p = alg->ve[i].firstArc;
        while (p != NULL) {
            mg->edges[i][p->adjVex] = 1;
            mg->edges[p->adjVex][i] = 1;
            p = p->nextArc;
        }
    }
    return mg;
}

void MGout(MGraph *mg) { //输出邻接矩阵
    int k = mg->n;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j)
            if (mg->edges[i][j] == 1)
                printf("%-5d", DIGIT);
            else
                printf("%-5d", ZERO);
            cout << endl;
    }
}
int main() {
    MGraph *mg;
    ALGraph *alg;
    cout << "建立无向图的邻接表:\n";
    alg = Creat_alg();
    cout << "邻接表输出:\n";
    ALGout(alg);
    mg = ALG_change_MG(alg);
    cout << "邻接矩阵输出:\n";
    MGout(mg);
}
