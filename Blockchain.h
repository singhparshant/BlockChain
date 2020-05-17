#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include<bits/stdc++.h>
#include "Block.h"

using namespace std;

class Blockchain {
public:
    Blockchain();

    void AddBlock(Block bNew);
    void showLedger();
    bool isChainValid();

private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;

    Block _GetLastBlock() const;

};
#endif