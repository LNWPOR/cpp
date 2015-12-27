#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N  100001 

int nStat[MAX_N];
int deg[MAX_N];
vector<int> edge[MAX_N];

void setG(int* totalNode)
{
  int n,m;
  scanf("%d %d",&n,&m);
  *totalNode = n;

  for (int i = 0; i < MAX_N; ++i)
  {
      deg[i] = 0;
  }

  for (int i = 1; i <= n; ++i)
  {
      nStat[i] = 3;//3 == white
  }

  for (int i = 0; i < m; ++i)
  {
      int u,v;
      scanf("%d %d",&u,&v);
      edge[u].push_back(v);
      edge[v].push_back(u);
      deg[u]++;
      deg[v]++;
  }
}

void myDFS(int u)
{
  nStat[u] = 2;
  for(int i=0; i<deg[u]; i++) {
    int v = edge[u][i];
    
    if(nStat[v] == 3) {
      myDFS(v);
    }
  }
  nStat[u] = 1;
}

void myDFSall(int totalNode)
{
	for (int i = 1; i <= totalNode; ++i)
	{
		if (nStat[i] == 3)
		{
			myDFS(i);
		}
	}
}

main()
{
  int a;
  int totalNode;
  scanf("%d",&a);
  for (int i = 0; i < a; ++i)
  {
    setG(&totalNode);
    myDFSall(totalNode);
  }
}
