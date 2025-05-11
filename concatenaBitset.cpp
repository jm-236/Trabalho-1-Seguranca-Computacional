#include<bits/stdc++.h>

using namespace std;

bitset<8> concatenaBitset(bitset<4> a,bitset<4> b)
{
    bitset<8> result;
    for(int i =0;i<4;i++)
    {
        result[i] = a[i];
        result[i+4] = b[i];
    }
    return result;
}