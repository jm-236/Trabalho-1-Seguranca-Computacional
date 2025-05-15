#include<bits/stdc++.h>
#include "divideBlocks.cpp"
using namespace std;

vector<bitset<8>> ebc(bitset<32> msg, pair<bitset<8>,bitset<8>> keys)
{
    bitset<8> key_1 = keys.first, key_2 = keys.second;
    vector<bitset<8>> result;
    vector<bitset<8>> dividedmessages = divideMessages(msg);
    for(bitset<8> bs : dividedmessages)
    {
        bs = SDES(bs,keys);
        cout<<bs<<" ";
        result.push_back(bs);
    }
    cout<<endl;
    return result;
}


