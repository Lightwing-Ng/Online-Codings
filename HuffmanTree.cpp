#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!\n";
}
typedef struct {
    float wt;
    int parent, lChild, rChild;
} node;
typedef node HfTree[2 * n - 1];

void Huffman(int k, float W[k], HfTree T) {
    for (int i = 0; i < 2 * k - 1; ++i) {
        T[i].parent = -1;
        T[i].lChild = -1;
        T[i].rChild = -1;
        if (i < k)
            T[i].wt = W[i];
        else
            T[i].wt = 0;
    } //初始化描述的完全二叉树，霍夫曼树T[2n-1]
    for (int i = 0; i < k - 1; ++i) {
        int x = 0, y = 0;
        float m = 0xFFFF, n = 0xFFFF;
        for (int j = 0; j < k + i; ++j) {
            if (T[j].wt < m && (T[j].parent == -1)) { //T[j] < m时
                n = m, y = x; //更新最小值和坐标
                m = T[j].wt, x = j; //更新次小值和坐标
            } else if (T[j].wt < n && (T[j].parent == -1)) { //m < T[j] < n时
                n = T[j].wt; //更新次小值和坐标
                y = j; //仅更新次小值和坐标
            }
            T[x].parent = k + i, T[y].parent = k + i;
            T[k + i].wt = m + n;
            T[k + i].lChild = x, T[k + i].rChild = y; //更新父节点的值和其左右子孩坐标
        }
    }
}

const int MaxInt = INT_MANX;
const int n = 6;
typedef AdjMatrix[n][n];
typedef struct {
    int fromVex, toVex;
    int weight;
} TreeEdgeNode;
typedef TreeEdgeNode MST[n - 1];

void PrimMST(AdjMatrix G, MST T, int rt) {
    TreeEdgeNode e;
    int k = 0, min, minPos, v;
    for (int i = 0, i < n; ++i)
        if (i != rt) {
            T[k].fromVex = rt;
            T[k].toVex = i;
            T[k++].weight = G[rt][i];
        }
    for (k = 0; k < n - 1; ++k) {
        min = MaxInt;
        for (i = k; i < n - 1; ++i)
            if (T[i].weight < min) {
                min = T[i].weight;
                minPos = i;
            }
        if (min = MaxInt) {
            cerr << "Graph is disconnected!\n";
            exit(1);
        }
        e = T[minPos];
        T[minPos] = T[k];
        T[k] = e;
        v = T[k].toVex;
        for (int i = k + 1; i < n - 1; ++i)
            if (G[v][T[i].toVex] < T[i].weight) {
                T[i].weight = G[v][T[i].toVex];
                T[i].fromVex = v;
            }
    }
}

void DFS(int a[][], int v, int N) {
    access(v);
    visited[v] = 1;
    int w = 0;
    while (w <= N && a[v][w] == 0)
        w++;
    while (w <= N) {
        if (visited[w] != 1)
            DFS(a, w, N);
        w++;
        while (w <= n && a[v][w] == 0)
            w++;
    }
}

typedef struct {
    int vertex[m];
    int edge[m][m];
} GAdjMatrix;

typedef struct node1 {
    int info;
    int adjVertex;
    struct node1 *nextArc;
} GLinkListNode;

typedef struct node2 {
    int vertexinfo;
    GLinkListNode *firstArc;
} GLinkHeadNode;

void AdjMatrixToAdjList(GAdjMatrix g1[], GLinkHeadNode g2[]) {
    GLinkListNode *p;
    for (int i = 0; i < n; ++i)
        g2[i].firstArc = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && g1.edge[i][j]) {
                p = (GLinkListNode *)malloc(sizeof(GLinkListNode));
                p->adjVertex = j;
                p->nextarc = g[i].firstArc;
                g[i].firstArc = p;
                p = (GLinkListNode *)malloc(sizeof(GLinkListNode));
                p->adjVertex = i;
                p->nextarc = g[j].firstArc;
                g[j].firstArc = p;
            }
        }
    }
}















































