#include "bits/stdc++.h"
using namespace std;

vector<bitset<8>> divideMessages(bitset<32> msg)
{
    vector<bitset<8>> result;
    //cout<<msg<<endl;

    for(int i =3;i>=0;i--)
    {
        bitset<8> current;
        for(int j=0;j<8;j++)
        {
            current[j] = msg[i*8+j];
        }
        result.push_back(current);
        //cout<<current<<" ";
    }
    return result;
}