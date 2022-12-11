#include <iostream>
#include <random>
#include <vector>
#include <time.h>
#include <filesystem>

using namespace std;

int main()
{
    vector<int> vec = {0,1,5};

    cout << "vec[0] : " << vec[0] << endl;
    cout << "vec.front() : " << vec.front() << endl;
    cout << "vec.size() : " << vec.size() << endl;

    unsigned int t0 = time(NULL);
    srand(t0);
    int r;

    cout << "Standard maximum random number : " << RAND_MAX << endl;

    int low = 1;
    int hig = 10;
    int range = hig-low+1;
    int prod = RAND_MAX - (RAND_MAX % range);

//  fopen("Test (copie) (2)");

    for(int i=0; i<100; i++)
    {
        while((r=rand())>prod){ /* cout << "It just happened at " << i << " !!!" << endl; i=-2; */ }
        r = (r % range) + low;
        cout << "Unagiii : " << r << endl;
    }
}