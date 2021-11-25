#include <iostream>

using namespace std;

int main()
{
    int uczniowie, cukierki, x, y ;
    cout << "Uczniowie w klasie? : " ;
    cin >> uczniowie ;
    cout <<  "Ile cukierkow kupila mama? : " ;
    cin >> cukierki;
    cout  << "Ile cukierkow dla klasy? : " << endl ;
    x = cukierki/(uczniowie - 1);
    cout << "Dla dzieci bedzie po : " << x << " cukierkow" << endl;
    cout << "Ile zostanie dla Jasia? " << endl ;
    y = (cukierki - (x*(uczniowie-1)));
    cout << "Pozostanie " << y << " cukierkow" << endl;
    return 0;
}
