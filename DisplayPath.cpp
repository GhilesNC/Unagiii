#include <iostream>
#include <time.h>

using namespace std;

void DisplayPath(string str)
{
    int deb = 2;
    int fin = str.find("\\",deb);
    cout << ">> About to open : ";
    cout << str.substr(deb,fin-deb) << endl;

    while (fin!=str.npos)
    {
        deb = fin+1;
        fin = str.find("\\",deb);
        cout << "                   ";
        cout << str.substr(deb,fin-deb) << endl;
    }

    Sleep(2000);
    cout << ">> Enjoy !";
}
