#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <time.h>
#include <windows.h>
using namespace std;

void merge(char arr[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;


    int temp[104189];
    while (i<= m && j<= r)
    {
        if (arr[i] <= arr[j] )
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
{
    temp[k] = arr[j];
            j++;
            k++;
}


    }
    while (i<=m)
    {
        temp[k] = arr[i] ;
        i++;
        k++;
    }
    while (j<=r)
    {
        temp[k] = arr[j] ;
        j++;
        k++;
    }
    for (int s = l; s <= r; s++)
    {
        arr[s]= temp[s];
    }
}
void mergeSort (char arr[], int l, int r)
{
 if (l<r)
    {
     int m = (l+r)/2;
 mergeSort (arr,l,m);
 mergeSort (arr,m+1,r);
 merge(arr,l,m,r);
 }
}
int main()
{
    ifstream wejscie("zadanie.txt");
    ofstream out("wynik.txt");
    char tab[104200] = {};
    int tmp = 0;
    int pliki;
   clock_t start, stop;
   double czas;
    if (!wejscie)
    {
        cout << "Nie mozna otworzyc pliku";
        getchar();
        return 1;
    }
    while (!wejscie.eof())
       wejscie >> tab[tmp++];
    wejscie.close();
    start = clock();
 mergeSort (tab,0,104189);
 stop = clock();
    cout << "Zastosowanie MergeSort:" << endl  ;
   for (int i = 0; i < tmp; i++){
          cout << tab[i] << " " ;
          out << tab[i] << " " ;
          pliki =  i + tmp ;
  }
czas = (double)(stop-start)/CLOCKS_PER_SEC;
    cout << endl;
cout << "ilosc znakow w pliku wynosi : " << tmp << endl;
cout << "Czas sortowania mergeSort wynosi : " << czas << " s" << endl;
cout << "Liczba zapisow i odczytow z pliku i do pliku wynosi : " << pliki << endl;
    out.close();
    return 0;
}
