#include <iostream>
#include <cstring>



using namespace std;

char* string_merge(char *a, char *b)
{
    int i, c;
    i=0;
    c=0;
    char *s = new char [513];
    while(a[i] != '\0' && b[i] !=  '\0')
    {
        s[c]=a[i];
        ++c;
        s[c]=b[i];
        ++c;
        ++i;
    }
    s[c]='\0';
    return s;
};

int main()
{
    int t, n;
    char S1[256], S2[256], *S;
    cin >> t;
    cin.getline(S1,256);
    while(t)
    {
        cin.getline(S1,256,' ');
        cin.getline(S2,256);
        S=string_merge(S1,S2);
        cout << S << endl;
        delete[] S;
        t--;
    }
    return 0;
}
