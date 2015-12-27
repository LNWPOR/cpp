#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N  100001 

int nStat[MAX_N];
int deg[MAX_N];
vector<int> edge[MAX_N];

void myBFS(int s)
{
  queue<int> queue;
  int currentNode = s;
  queue.push(currentNode);
  nStat[currentNode] = 2;// 2 == gray

  while(queue.size() != 0 )
  { 
    currentNode = queue.front();
    queue.pop();
    nStat[currentNode] = 1;// 1 == black

    printf("%d\n", currentNode);

    for (int i = 0; i < deg[currentNode] ; ++i)
    {
        int v = edge[currentNode][i];
        
        if (nStat[v] == 3)
        {
          queue.push(v);
          nStat[v] = 2;
        }
    } 
  }
}

void setG()
{
  int n,m;
  scanf("%d %d",&n,&m);

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

main()
{
  int a;
  scanf("%d",&a);
  for (int i = 0; i < a; ++i)
  {
    setG();
    myBFS(1);
  }
}
