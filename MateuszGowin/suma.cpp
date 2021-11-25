#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int suma=0;
    vector<int> tab;
    string a;
    while(true)
    {
        getline(cin,a);
        if(a.empty())
            break;
        tab.push_back(suma+=stoi(a));
    }
    for(int i=0;i<tab.size();i++)
        cout<<tab[i]<<endl;
    return 0;
}
