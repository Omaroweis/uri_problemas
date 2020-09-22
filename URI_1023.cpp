/* 
Due to the continuous drought that happened recently in some regions of Brazil, the Federal Government created an agency to assess the consumption of these regions in order to verify the behavior of the population at the time of rationing. This agency will take some cities (for sampling) and it will verify the consumption of each of the townspeople and the average consumption per inhabitant of each town.
Input
The input contains a number of test's cases. The first line of each case of test contains an integer N (1 ≤ N ≤ 1 * 10 6), indicating the amount of properties. The following N lines contains a pair of values X (1 ≤ X ≤ 10) and Y ( 1 ≤ Y ≤ 200) indicating the number of residents of each property and its total consumption (m3). Surely, no residence consumes more than 200 m3 per month. The input's end is represented by zero.
Output
For each case of test you must present the message “Cidade# n:”, where n is the number of the city in the sequence (1, 2, 3, ...), and then you must list in ascending order of consumption, the people's amount followed by a hyphen and the consumption of these people, rounding the value down. In the third line of output you should present the consumption per person in that town, with two decimal places without rounding, considering the total real consumption. Print a blank line between two consecutives test's cases. There is no blank line at the end of output.
*/

#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<cstdio>
#include<fstream>
using namespace std;
int main()
{

  int *n, tam;
  cin>>tam;

   for(int i=1; tam ; i++)
    {
      map<int, int>mp;
      map<int, int>::iterator it;
      int qtd_pessoas = 0, consumo = 0, soma_pessoas = 0, soma_consumo = 0;
        n = new int[tam];
        for(int i=1; i<=tam;i++)
          {
            cin>>qtd_pessoas >> consumo;
            it = mp.find(consumo/qtd_pessoas);
            if(it == mp.end())
               mp.insert(::pair<int,int>((consumo/qtd_pessoas),qtd_pessoas));
            else
                mp[consumo/qtd_pessoas] += qtd_pessoas;

            soma_consumo+=consumo;
            soma_pessoas+=qtd_pessoas;
          }
        cout<<"Cidade# "<<i<<":\n";
        for(it=mp.begin();it!=mp.end();it++)
          {
            cout<<it->second<<"-"<<it->first<<" ";
          }
        cout<<endl;

        long long aux = soma_consumo;
        long long aux2 = soma_pessoas;
        long double aux3 = (long double) aux / (long double) aux2;
        aux3 = ((long long )(floor(aux3 *100))/100.00);
        cout<<"Consumo medio: ";
        cout<<fixed<<setprecision(2)<<aux3;

        cout<<" m3.\n";
        mp.clear();

        cout<<endl;
        cin>>tam;
    }

}
