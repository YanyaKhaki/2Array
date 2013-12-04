#include <iostream>
#include <windows.h>

using namespace std;

/*В массиве А(M,N) переместить нулевые строки в конец массива*/

const int m=3,n=3;

void IOarray(int mas[m][n]) //функция ввода-вывода двумерного массива
{
    cout <<"Enter the array:"<< endl;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin>>mas[i][j];
        }
    }
}

bool IsZero(int mas[m][n],int i) //функция, которая находит нулевую строку
{
    for(int j=0; j<n; j++)
    {
        if(mas[i][j]!=0)
        {
            return false;
        }
        return true;
    }
}

void InTheEnd(int mas[m][n], int t) //функция, которая перемещает нужную строку в низ массива
{
    int d=0;
    for(int i=t; i<m-1; i++)
    {
        for(int j=0; j<n; j++)
        {
            d=mas[i][j];
            mas[i][j]=mas[i+1][j];
            mas[i+1][j]=d;
        }
    }
}

int main()
{
    int mas[m][n];
    IOarray(mas);

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            if(IsZero(mas,i))
            {
                InTheEnd(mas,i);
            }
        }
    }
    cout << "New array:" <<endl;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            cout<<mas[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
