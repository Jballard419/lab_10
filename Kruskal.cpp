#include <iostream>
#include "skew_heap.h"
struct edge_t {
  int x,y,cost;
  bool operator <(const edge_t& x)
  {
    return this->cost<x.cost;
  };
  bool operator >(const edge_t& x)
  {
    return this->cost>x.cost;
  };
  edge_t(int x, int y, int c):x(x),y(y),cost(c){};
};

void Kruskal(int** cost, int x)
{
  //build Q
  Skew_Heap<edge_t>* edges = new Skew_Heap<edge_t>();
  edge_t temp = edge_t(0,0,0);
  edge_t soln[x-1];
  bool notused[x];
  for (int i = 0; i < x; i++) {
    notused[i]= true;
    for (int j = 0; j < i; j++) {
      if(cost[i][j]!= 0)
      {
         temp=  edge_t(i, j,cost[i][j]);
         edges->insert(temp);
      }
    }
  }
  int num_sel = 0;

  while(num_sel<(x-1) && !(edges->isempty()))
  {

    temp = edges->findmin();
    edges->deletemin();

    if(notused[temp.x]||notused[temp.y]) // add edge
    {
      soln[num_sel] = temp;
      notused[temp.x]= false;
      notused[temp.y]= false;
      num_sel++;
    }

  }

  if (num_sel != (x-1))
    {std::cout << "Kruskal: no soln" << '\n';
    return;
  }
    std::cout << " \n Kruskal:";
    for(int i = 0; i<num_sel; i++)
    {
      std::cout << " <" << soln[i].x <<","<<soln[i].y<< "> ";

    }
}
