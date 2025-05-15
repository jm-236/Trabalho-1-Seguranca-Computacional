#include<bits/stdc++.h>
#include "bits/stdc++.h"

using namespace std;

vector<bitset<8>> cbc(bitset<32> msg, pair<bitset<8>,bitset<8>> keys)
{
    bitset<8> key_1 = keys.first, key_2 = keys.second;
    vector<bitset<8>> result;
    vector<bitset<8>> dividedmessages;
    dividedmessages = divideMessages(msg);
    bitset<8> initializer = 0b01010101;
    bitset<8> first = dividedmessages[0];
    first^= initializer; 
    first = SDES(first,keys);
    cout<<first<<" ";
    result.push_back(first);
    
    for(int i =1;i<4;i++)
    {
        bitset<8> bs = dividedmessages[i]^result[i-1];
        bs = SDES(bs,keys);
        cout<<bs<<" ";
        result.push_back(bs);
    }
    cout<<endl;
    return result;
}

