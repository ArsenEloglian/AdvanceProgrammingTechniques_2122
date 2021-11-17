#include <iostream>
#include <fstream>

using namespace std;

void merge(char arr[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;


    int temp[5];
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
    ifstream in("zadanie.txt");


char tab[100] = { ' ' };
int tmp;

while (!in.eof())
    in >> tab[tmp++];
in.close();
       cout << "Before MergeSort:" << endl  ;
    for (int i = 0; i < tmp; i++){
            cout << tab[i] << " " ;
    }
//mergeSort (tab,0, 5);
cout << endl;
      cout << "After MergeSort:" << endl  ;
    for (int i = 0; i < tmp; i++){
            cout << tab[i] << " " ;
    }
    return 0;
}
