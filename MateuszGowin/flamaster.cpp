#include <iostream>
#include <string>
using namespace std;
int main()
{
    int c;
    cin>>c;
    if(c<0 || c>50)
        return 0;
    string tab[c];
    string s;
    for(int i=0;i<c;i++){
        cin>>s;
        if(s.size()>200)
            return 0;
        else
        {
            for(int j=0;j<s.size();j++)
            {
                if(s[j]<'A' || s[j]>'Z')
                    return 0;
            }
        }
        tab[i]=s;
    }

    for(int z=0; z<c; z++)
    {
        int wsk=0;
        int i=0;
        int licznik=0;
        while(i<tab[z].size())
        {
            wsk=i+2;
            licznik=2;
            while(wsk<tab[z].size() && tab[z][i]==tab[z][wsk])
            {
                licznik++;
                wsk++;
            }
            if(licznik>2)
            {
                cout<<tab[z][i]<<licznik;
                i=wsk;
            }
            else
            {
                cout<<tab[z][i];
                i++;
            }
        }
        if(z+1!=c)
        cout<<endl;
    }
    return 0;
}
