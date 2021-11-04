
//FZI_STEF - Stefan


#include <iostream>

using namespace std;



int main()
{
    int maxSuma=0;
    int liczbaMiast;
    int suma;
    cin>>liczbaMiast;
    int zyski[liczbaMiast];

    for(int i=0; i<liczbaMiast; i++){
        cin>>zyski[i];
    }
    for(int i=0; i<liczbaMiast; i++){

        suma =0;
       for(int j=i; j<liczbaMiast; j++){
            suma= zyski[j]+suma;
            if(maxSuma<suma){
                maxSuma=suma;
            }
        }
    }
    cout<< maxSuma;










    return 0;

}
