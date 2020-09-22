/*
Peter is a curious boy who liked electronics. One day, the boy was playing in his school lab and found a box full of small electronic devices made ​​by other students in previous years.

Inside that box was a device that had only one display and two buttons. This display had an integer. Pressing the buttons, Peter discovered the functions for each of the buttons. The first button add a unit to the number on the display. The second button reverse the digits, for example, 123 inverted is 321 and 150 inverted is 51 (ignore the leading zeros).

Initially, the display showed the number A. After discover the functions of the buttons, Peter wants to know how to change the display number of A to a greater number equal to B. Your job in this problem is to help Peter to find out what the minimum number of button pressings to make the display the number be equal to B.

Input
The input is started by an integer T, 0 < T ≤ 500, which indicates the number of test cases. After this, the input consists of T lines, each one containing two integers A and B, 0 < A < B < 10000, A is equal to the initial value on the display and B is equal to the final number we need to get on the display.

Output
For each test, your program must output one integer equal to the minimum number of button pressings to make the number A on the displays change to the number B.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<int>vi;
vi G[1000];

void zerar()
{
  for(int i=0 ; i<1000;i++)
    {
      G[i].clear();
    }
}
/*
int bfs(int inic, int final, int qtd)
{
  int const inf = 999999999;
  int *distancia = new int[qtd+2];
  for(int i=1;i<=qtd;i++)
    {
      distancia[i] = inf;
    }
  queue<int> fila;
  fila.push(inic);
  distancia[inic] = 0;
  while(!fila.empty())
    {
      int vertice = fila.front();
      fila.pop();
      int adj;
      for(int i=0; i < G[vertice].size(); i++) // percorrendo a fila de adjacencia do vertice
        {
          adj = G[vertice][i];
          if(distancia[adj] > distancia[vertice]+ 1)
            {
              distancia[adj] = distancia[vertice]+1;
              fila.push(adj);
            }
        }
    }
  for(int j=0;j<qtd;j++) cout<<distancia[j]<<" "; cout<<endl;
  return distancia[final];
}
*/
int inverte(int a)
{
  int aux = 0;
  while (a) {
      aux*=10;
      aux+=a%10;
      a/=10;
    }
  return aux;
}
/*
void monta(int a, int b, int c, bool &cond, int final)
{
  contador++;
  cout<<a<<" "<<b<<endl;
  G[a].push_back(b);
  G[b].push_back(a);
  if(b != c && cond)
    {

      monta(b,b+1, c, cond,final);
      monta(b,inverte(b),c,cond,final);

    }
  else
    {

      ans = bfs(b,final, contador );
      cond = false;
    }

}
*/
int bfs(int inic, int final)
{
  int *dist = new int [10000];
  int infinito = 123456789;
  for(int i=0; i<10000;i++)
    {
      dist[i] = infinito;
    }
  queue<int>q;
  q.push(inic);
  dist[inic] = 0;
  while (!q.empty()) {
      int vertice = q.front();
      q.pop();
      if(vertice<10000 and dist[vertice + 1] == infinito)
        {
          q.push(vertice+1);
          dist[vertice+1] = dist[vertice]+1;
        }
      int invertido = inverte(vertice);
      if(invertido<=10000 and dist[invertido]== infinito)
        {
          q.push(invertido);
          dist[invertido] = dist[vertice]+ 1;
        }
    }
  return dist[final];
}
int main()
{
 int n;
 cin>>n;
 for(int i=0; i<n; i++){
      int a, b;
      cin>>a>>b;
      //G[1].push_back(a);

      cout<<bfs(a,b)<<endl;
   }


}

