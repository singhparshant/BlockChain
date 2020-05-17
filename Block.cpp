#include<bits/stdc++.h>
#include "Block.h"
#include "sha256.h"

string Block::GetHash() {
    return _sHash;
}

Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1;
    _tTime = time(nullptr);
    sPrevHash='0';
    _sHash=_CalculateHash();
}

void Block::MineBlock(uint32_t nDifficulty) {

    _sHash = _CalculateHash();
    const string comparezeroes_(nDifficulty,'0');
    string toCompare_ = _sHash.substr(0,nDifficulty);

    do
    {
         _nNonce++;
         _sHash = _CalculateHash();
         toCompare_ = _sHash.substr(0,nDifficulty);   
    }while(comparezeroes_.compare(toCompare_)!=0);

    // cout<<"Block Mined: " <<_sHash <<endl;
}

string Block::_CalculateHash() const
{
    stringstream ss;
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

    return sha256(ss.str());
}

void Block::printData()
{
    cout<<"Index: "<<_nIndex<<endl;
    cout<<"Nounce: "<<_nNonce<<endl;
    cout<<"Data: "<<_sData<<endl;
    cout<<"Hash: "<<_sHash<<endl;
    cout<<"Time: "<<_tTime<<endl;
    cout<<"PrevHash "<<sPrevHash<<endl;
}