#include <iostream>
#include <random>
#include <vector>
#include <time.h>

using namespace std;

int main()
{
    int d;
    vector<int> vec;

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(1,10);

    for(int i=0; i<10; i++)
    {
        d = dist(rng);
        cout << "Unagiii : " << d << "\n" << time(NULL) << endl;
    }
}