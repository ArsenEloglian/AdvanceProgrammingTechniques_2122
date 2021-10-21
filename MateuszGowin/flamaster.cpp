#include <iostream>
#include <string>
using namespace std;
int main(){
    int c;
    cin>>c;
    if(c<0 || c>50)
        return 0;
    string s;
    cin>>s;
    if(s.size()>200)
        return 0;
    int wsk=0;
    int i=0;
    int licznik=0;
    while(i<s.size()){
        wsk=i+2;
        licznik=2;
        while(wsk<s.size() && s[i]==s[wsk]){
            //cout<<"s["<<i<<"]:"<<s[i]<<" s["<<wsk<<"]:"<<s[wsk]<<endl;
            licznik++;
            wsk++;

        }
        if(licznik>2){
            cout<<s[i]<<licznik<<endl;
            i=wsk;
        }else{
            i++;
        }
    }
    return 0;
}
