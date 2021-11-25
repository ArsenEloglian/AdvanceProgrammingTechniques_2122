#include <iostream>
#include <string>
using namespace std;

string napis;

int main() {
    int t;
    int ile_znakow=52;
    int counter[ile_znakow];
    cin>>t;
    for(int i=0; i<ile_znakow; i++)
    {
         counter[i]=0;
    }

    for(int j=0; j<=t; j++) {
        getline(cin,napis);
        for(int i=0; i<napis.size(); i++) {
            if( static_cast<int>(napis[i]>64) && static_cast<int>(napis[i]<91) )
                counter[static_cast<int>(napis[i]-39)]++;
            else if(static_cast<int>(napis[i]>96) && static_cast<int>(napis[i]<123) )
                counter[static_cast<int>(napis[i]-97)]++;
            else
                continue;
        }
    }
    for(int i=0; i<ile_znakow; i++) {
        if(counter[i]!=0) {
            if(i<26)
                cout << "\n" << (char)(i+97) << "\t" << counter[i];
            else
                cout << "\n" << (char)(i+39) << "\t" << counter[i];
        }
    }
}
