#include<iostream>
using namespace std;
bool czy_pierwsza(int n)
{
	if(n<2)
		return false;

	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;
}
int main(){
    int dlugosc;
    cin>>dlugosc;
    if (dlugosc>=100000)
    {
        return -1;
    }
    int tab[dlugosc];
    int zmienna;
    for(int i=0;i<dlugosc;i++)
    {
        cin>>zmienna;
        if(zmienna<1 || zmienna>10000){
            return -1;
        }
        tab[i]=zmienna;
    }

    for(int i=0;i<dlugosc;i++)
    {
        if(czy_pierwsza(tab[i])){
            cout<<"TAK"<<endl;
        }
        else
        {
            cout<<"NIE"<<endl;
        }
    }
}
