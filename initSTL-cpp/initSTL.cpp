#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map> 
#include <list> 

#define MAX_N  100001


main()
{
	queue<int> myQueue;
	//myQueue.push(1);
	//int a = myQueue.front();
	//myQueue.pop();
	
	stack<int> myStack;
	//myStack.push(1);
	//int a = myStack.top();
	//myStack.pop();

	vector<int> myVector;
	//myVector.push_back(1);
	//printf("%d\n",myVector[0]);
	
	vector<int> myArrayVector[MAX_N];
	//myArrayVector[0].push_back(1);
	//printf("%d\n",myArrayVector[0][0]);

	set<int> mySet; // sort min to max
	//set<int>::iterator it;
	// mySet.insert(mySet.end(),1);
	// it = mySet.begin();
	// it++;
	// printf("%d\n",*it);
	// mySet.insert(it,10);//push 10 after 1
	// it = mySet.begin();
	// it++;
	// printf("%d\n",*it);
	// it = mySet.end();// end = null value;
	// it--;// so now it = last element
	// printf("%d\n",*it);

	set<int>* entry = new set<int>[MAX_N];
 	// for (int i = 0; i < n2; ++i)
	// {
	// 	entry[i].insert(10);
	// }
	// int sum = 0;
	// set<int>::iterator it;
	// for (int i = 0; i < n1; ++i)
	// {	
	// 	it = entry[i].begin();
	// 	sum += *it;
	// }

	list<int> myList; // use same set but not sort
	//list<int>::iterator it;

	map<int,int> myMap;// init 0 to every element
	// myMap[0] = 1;
	// printf("%d\n",myMap[0]);
	// map<int,char> myCharMap;
	// myMap[0] = 'A';
	// printf("%c\n",myMap[0]);

	map<int,map<int,int>> myArrayMap;
	// myArrayMap[0][0] = 1;
	// printf("%d\n",myArrayMap[0][0]);
	// map<int,map<int,char>> myArrayMapChar;
	// myArrayMapChar[0][0] = 'A';
	// printf("%c\n",myArrayMapChar[0][0] );

	typedef pair<int,int> int_pair;
	set<int_pair> s;// so the set will sort by the sum of first,second
					// then sort by first,then sort by seconde  (min to max)
	 // s.insert(make_pair(5,20));
	 // pair<set<int_pair>::iterator,bool> res = s.insert(int_pair(10,0));
	 // s.insert(int_pair(15,10));
	 // s.insert(int_pair(10,15)); 
	 // s.erase(res.first);//10,0 will be delete
	 // for(set<int_pair>::iterator i = s.begin();
	 //   	i != s.end(); i++) 
	 // {
	 // 	 printf("%d, %d\n", i->first, i->second);
	 // }
}