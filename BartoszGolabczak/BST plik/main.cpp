#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <random>
#include <algorithm>
#include <time.h>
#include <windows.h>
#define SPACE 10

using namespace std;

class TreeNode{

public:
    string value;
    TreeNode* left;
    TreeNode *right;

    TreeNode()
    {
        value = "0";
        left = NULL;
        right = NULL;
    }
TreeNode(string v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }

};

class BST{


public:
    TreeNode* root;
BST()
{
    root = NULL;
}
    bool isTreeEmpty()
    {
        if(root==NULL)
        {

            return true;
    }
        else
        {


            return false;
        }
    }



TreeNode* insertRecursive (TreeNode *r, TreeNode *new_node)
{

    if (r== NULL)
    {
        r= new_node;
        return r;
    }
   if (new_node->value < r->value)
   {
       r->left = insertRecursive(r->left,new_node);
       return r;
   }
    else if (new_node->value > r->value)
    {
        r->right = insertRecursive(r->right,new_node);
      return r;
    }
    else if (new_node->value == r->value)
    {
        r->left = insertRecursive(r->left,new_node);

return r;

    }
    return r;
}

void print2D(TreeNode *r, int space)
{
    if( r == NULL )
        return;
    space += SPACE;
    print2D(r->right, space);
    cout << endl;
    for ( int i = SPACE; i < space; i++)
cout << " ";
    cout <<r->value<<"\n";
    print2D(r->left, space);

}

void printPreorder(TreeNode *r)
{
    if( r == NULL )
        return;
    cout << r->value << " ";
    printPreorder(r->left);
    printPreorder(r->right);
}
void printInorder(TreeNode *r)
{
    if( r == NULL )
        return;
         printInorder(r->left);
    cout << r->value << " ";
    printInorder(r->right);
}
void printPostorder(TreeNode *r)
{
    if( r == NULL )
        return;
         printPostorder(r->left);
           printPostorder(r->right);
    cout << r->value << " ";
}

    TreeNode* iterativeSearch(string val)
    {
        if (root==NULL)
        {
            return root;
        }
        else
        {
            TreeNode *temp=root;
            while(temp!=NULL)
            {
                if(val==temp->value)
                {
                    return temp;
                }
                else if(val<temp->value)
                {
                    temp = temp->left;
                }
                else if(val>temp->value)
                {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }

    int height(TreeNode* r)
    {
        if (r == NULL)
            return -1;
        else
        {
            int lheight = height(r->left);
            int rheight = height(r->right);


            if(lheight > rheight)
            {


                return(lheight + 1);
            }
            else{
                return(rheight +1);
            }
        }
    }

    TreeNode* minValueNode(TreeNode* node)
    {
        TreeNode* current = node;

        while (current-> left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    TreeNode* deleteNode(TreeNode* r, string v)
{

    if(r == NULL)
    {
        return NULL;
    }

    else if (v < r->value)
    {
       r->left = deleteNode(r->left, v);

    }
else if (v > r->value)
    {
       r->right = deleteNode(r->right, v);

    }
else
{
    if (r->left == NULL)
    {
        TreeNode* temp = r->right;
        delete r;
        return temp;
    }
    else if (r->right == NULL)
    {
        TreeNode* temp = r->left;
        delete r;
        return temp;
    }
    else
    {
      TreeNode* temp = minValueNode(r->right);
      r->value = temp->value;
      r->right = deleteNode(r->right, temp->value);
    }
}
return r;
}


};

int main()
{
    BST obj;
    int option;
    int numLines = 0;
    const int ARRAY_SIZE = 20000;
    srand(time(0));
    int roz = 100;
            int ilu = 0;
    int ils = 0;
    string tab[ARRAY_SIZE];
    int j = 0;
    ifstream plik("tekst.txt");
     ofstream out("los.txt");
std::string unused;
while ( std::getline(plik, unused) )
{
plik >> tab[numLines];
   ++numLines;
}
 //cout << numLines << endl;
 for (int i = 0; i < numLines; i++){
  }
 for(int i=0; i<numLines; i++)
 {
     int index = rand () % numLines;
     string temp = tab[i];
     tab[i] = tab[index];
     tab[index] = temp;
 }


 for(int i=0; i<numLines; i++)
 {
     out  <<  tab[i] << endl  ;
 }
  plik.close();
 out.close();
 ifstream in("los.txt");
string val;
    do
    {
       cout << "Wybierz operacje do wykonania :"
       << "Wybierz numer opcji. wybierz 0 do zakonczenia dzialania." << endl;
       cout << "1. Wprowadz wezel" << endl;
       cout << "2. Szukaj wezla" << endl;
       cout << "3. Usun wezel" << endl;
       cout << "4. Wyswietl drzewo binarne" << endl;
       cout << "5. Wysokosc drzewa" << endl;
       cout << "6. Wyczysc ekran" << endl;
       cout << "7. Powieksz drzewo" << endl;
       cout << "0. Wyjdz z programu" << endl;
       cin >> option;
   TreeNode *new_node = new TreeNode();
       switch(option)
       {
       case 0:
        break;
         case 1:
             cout << "Wprowadzanie" << endl;
             cout << "Wprowadzanie danych do drzewa : ";
             for(int i = j; i<roz; i++)
             {


     getline(in,val) ;
            TreeNode *new_node = new TreeNode();
                  new_node->value = val;
obj.root = obj.insertRecursive(obj.root,new_node);
             cout<<endl;
       }
        break;
         case 2:
             cout << "Wyszukiwanie" << endl;
              cout << "Wprowadz szukana wartosc w drzewie : ";
              cin >> val;
           new_node = obj.iterativeSearch(val);
              if(new_node!=NULL)
              {
                  cout<<"Odnaleziono wartosc"<<endl;

             cout << "Na wysokosci drzewa : " <<obj.height(new_node)<<endl;

                               ils++;
                               cout << "Ilosc wyszukan :" << ils << endl;

              }
              else
                {
                    cout<<"Brak wartosci"<<endl;
                }
        break;
        case 3:
             cout << "Usun" << endl;
               cout << "Wprowadz element do usuniecia z drzewa : ";
             cin >> val;
               new_node = obj.iterativeSearch(val);
                 if(new_node!=NULL)
              {
                  obj.deleteNode(obj.root, val);
                  cout<<"Usunieto wartosc"<<endl;
                                                      ilu++;
                  cout << "Ilosc usuniec :" << ilu << endl;
              }
              else
                {
                    cout<<"Brak wartosci"<<endl;
                }
        break;
         case 4:
             cout << "Wyswietl" << endl;
             obj.print2D(obj.root,5);
        break;
         case 5:
             cout << "Wysokosc drzewa" << endl;
             cout << "Wysokosc drzewa wynosi : " <<obj.height(obj.root)<<endl;
        break;
         case 6:
             cout << "Wyczysc ekran" << endl;
             system("cls");
        break;
         case 7:
            cout << "Powieksz drzewo o 100 elementow" << endl;
             if(roz<10000)
             {
            roz = roz + 100;
            j = j+100;
            cout << "Obecny rozmiar drzewa: " << roz << endl;
             }
         else cout << "Osiagnieto maksymalna ustalona wielkosc drzewa!";
        break;
         default:
            cout << "Podaj poprawna opcje" << endl;
       }
    }
    while(option!=0);

    in.close();
    return 0;
};
