#include<iostream>
#include<cstring>
using namespace std;
char* string_merge(char*a,char*b)
{
    int i=0, j=0;
    char *s = new char [513];
    while(a[i] != '\0' && b[i] !=  '\0')
    {
        s[j]=a[i];
        j++;
        s[j]=b[i];
        j++;
        i++;
    }
    s[j]='\0';
    return s;
}
int main()
{
    int t;
    char s1[256], s2[256], *s;
    cin>>t;
    cin.getline(s1,256);
    while(t)
    {
        cin.getline(s1,256,' ');
        cin.getline(s2,256);
        S=string_merge(s1,s2);
        cout<<s<<endl;
        delete[] s;
        t--;
    }
}
