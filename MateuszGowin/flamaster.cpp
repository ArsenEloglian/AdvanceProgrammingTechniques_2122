#include <iostream>

using namespace std;

int main()
{
    int C;
    string ciag;
    cin>>C;
    for(int i=0; i<C; i++)
    {
        cin>>ciag;
        int suma=1;
        for(int j=0; j<ciag.length(); j++)
        {
            if(ciag[j]==ciag[j+1])
                suma++;
            else
            {
                if(suma<2)
                    cout<<ciag[j];
                else if(suma==2)
                    cout<<ciag[j-1]<<ciag[j];
                else
                    cout<<ciag[j]<<suma;
                suma=1;
            }
        }
        cout << endl;
    }
    return 0;
}
