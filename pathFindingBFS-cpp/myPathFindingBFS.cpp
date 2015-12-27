#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

#define MAX_N  100001

int nStat[MAX_N];
int deg[MAX_N];
vector<int> edge[MAX_N];


//find the minimum number of edge start from s to every other node
//when this function finish. nstat[i] will contain the minimum number
//of edge start from s to i
void myPathFindingBFS(int s)
{
  queue<int> queue;
  int currentNode = s;
  queue.push(currentNode);
  nStat[currentNode] = 0;

  while(queue.size() != 0 )
  { 
    currentNode = queue.front();
    queue.pop();

    for (int i = 0; i < deg[currentNode] ; ++i)
    {
        int v = edge[currentNode][i];
        if (nStat[v] == 100000)
        {
          queue.push(v);
          nStat[v] = nStat[currentNode]+1;
        }
    }

  }
}

void setG()
{
  int n,m;// n = total node,m = total edge
  scanf("%d %d",&n,&m);

  for (int i = 0; i < MAX_N; ++i)
  {
      deg[i] = 0;
  }

  for (int i = 1; i <= n; ++i)
  {
      nStat[i] = 100000;
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
  int a;// a = how many time to use
  scanf("%d",&a);
  for (int i = 0; i < a; ++i)
  {
    setG();
    myPathFindingBFS(1);
   // printf("%d\n",nStat[5] );
  }
}


//sample input
/*
1
5 4
1 2
2 3
3 4
5 6
*/