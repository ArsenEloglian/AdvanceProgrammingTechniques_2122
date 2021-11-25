#include <iostream>

using namespace std;

int main()
{
    int c, q, i;
    char p;
    char input[200];
    cin>>c;
    ++c;
    while(--c)
    {
        cin>>input;
        for(i=0;input[i]!='\0';++i)
        {
            if(input[i]==input[i+1] && input[i+1]==input[i+2])
            {
                p=input[i];
                q=2;
                while(input[i+q]==p)
                {
                    ++q;
                }
                cout<<input[i]<<q;
                i+=q;
                --i;

            }
            else
            {
                cout<<input[i];
            }
        }
        cout<<endl;
    }
    return 0;
}
