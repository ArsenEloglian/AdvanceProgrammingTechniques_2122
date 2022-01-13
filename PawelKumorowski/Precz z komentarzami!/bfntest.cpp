#include <iostream>
#include <string>

using namespace std;

bool inputEnd(string &input)
{
    static bool mainFunc = false, firstBrace = false;
    static int braceCount = 0;
    int i = 0;

    if(!mainFunc)
    {
        string pattern = "int main(";

        for(; i < input.length(); i++)
        {
            if(input[i] != pattern[i])
                break;

            if(i == pattern.length() - 1)
                mainFunc = true;
        }
    }

    if(mainFunc)
    {
        for(;i < input.length(); i++)
        {
            if(input[i] == '{')
            {
                braceCount++;
                firstBrace = true;
            }
            else if(input[i] == '}')
                braceCount--;
        }
    }

    if(firstBrace && braceCount == 0)
        return true;
    else
        return false;
}

string usunKomentarz(string &input)
{
    string output = "";

    for (int i = 0; i < input.length(); i++)
    {
        if (i < input.length() - 1 && input[i] == '/')
        {
            if (input[i + 1] == '/')
            {
                if(i == 0)
                    break;
                while (i < input.length() && input[i] != '\n')
                    i++;
            }
            else if (input[i + 1] == '*')
            {
                while (i < input.length() - 1 && !(input[i] == '*' && input[i + 1] == '/'))
                    i++;
                i += 2;
            }
        }

        output += input[i];
    }

    return output;
}

int main()
{
    string program = "", input;

    while(true)
    {
        getline(cin, input);
        program += input;

        if(inputEnd(input))
            break;

        program += '\n';
    }

    cout << usunKomentarz(program);


}
