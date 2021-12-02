#include <iostream>

using namespace std;

int main()
{
        string sWiersz;
    do
    {
        getline( std::cin, sWiersz );

        for( int i = 0; i < sWiersz.size(); i++ ){
            char a = sWiersz[i];
            if((int)a == 32){
                    int toErase = 1;
                    while((int)sWiersz[i+toErase] == 32){
                        toErase++;
                    }

            sWiersz[i+toErase] = toupper(sWiersz[i+toErase]);
            sWiersz.erase(i,toErase);
            }
        }
        cout<<sWiersz<<endl;
    } while( !sWiersz.empty() );
}
