#include<bits/stdc++.h>
#include "Blockchain.h"

Blockchain::Blockchain() {
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 3;
}

void Blockchain::AddBlock(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}

void Blockchain::showLedger()
{
    for(Block b : _vChain)
    {
        b.printData();
    }
}

bool Blockchain::isChainValid()
{
    for(int i=1;i < _vChain.size();i++)
    {
        if(_vChain[i].GetHash() != _vChain[i]._CalculateHash())
            return false;

        if(_vChain[i].sPrevHash != _vChain[i-1].GetHash())
            return false;    
    }
    return true;
}