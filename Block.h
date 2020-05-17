#ifndef BLOCK_H
#define BLOCK_H
#include<bits/stdc++.h>
using namespace std;
class Block {
public:
    string sPrevHash;

    Block(uint32_t nIndexIn, const string &sDataIn);

    string GetHash();

    void MineBlock(uint32_t nDifficulty);
    void printData();
    string _CalculateHash() const;

private:
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sData;
    string _sHash;
    time_t _tTime;
};
#endif