#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define MAX_N  100001
int N,M;
int leader[MAX_N];
int height[MAX_N];
typedef pair< int,pair<int,int> > int_pair3;
vector<int_pair3> edgeHeap;

void setLeaderHeight()
{
	for (int i = 1; i <= N ; ++i)
	{
		leader[i] = i;
		height[i] = 0;
	}
}

int findSet(int e)
{	
	if(e != leader[e])
	{
		leader[e] = findSet(leader[e]);
	}
	return leader[e];
}


void unionSet(int s,int t)
{
	if (height[s] > height[t])
	{
		leader[t] = s;
	}
	else if (height[s] == height[t])
	{
		if (s <= t)
		{
			leader[t] = s;
			height[s]++;
		}
		else if (s >= t)
		{
			leader[s] = t;
			height[t]++;
		}
	}
	else if (height[s] < height[t])
	{
		leader[s] = t;
	}
}

void setEdgeHeap()
{
  	for (int i = 0; i < M; ++i)
  	{
      	int u,v,w;
      	scanf("%d %d %d",&u,&v,&w);
      	edgeHeap.push_back(make_pair(w,make_pair(u,v)));
  	}
}

void myKruskal()
{
	setLeaderHeight();
	setEdgeHeap();
	int totalnewEdge = 0;
	//int sumWeight = 0;
	sort(edgeHeap.begin(),edgeHeap.end());
	int i = 0;
	while(totalnewEdge < N-1)
	{
		int u = edgeHeap[i].second.first;
		int v = edgeHeap[i].second.second;
		int leaderU = findSet(u);
		int leaderV = findSet(v);
		if (leaderU != leaderV)
		{
			unionSet(leaderU,leaderV);
			//sumWeight += edgeHeap[i].first;
			totalnewEdge++;
		}
		i++;
	}
	//printf("%d\n",sumWeight);
}

main()
{	
	scanf("%d %d",&N,&M);// N = total node	,M = total edge
	myKruskal();
	
}