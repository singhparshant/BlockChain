#include<bits/stdc++.h>
#include "Block.h"
#include "Blockchain.h"
#include<chrono>
using namespace std;
using namespace std::chrono; 

int main() {
    auto start = high_resolution_clock::now(); 
    Blockchain *bChain = new Blockchain();

    // // cout << "Mining block 1..." << endl;
    // thread t1(&Blockchain::AddBlock,bChain,Block(1, "Block 1 Data"));

    // // cout << "Mining block 2..." << endl;
    // thread t2(&Blockchain::AddBlock,bChain,Block(2, "Block 2 Data"));

    // // cout << "Mining \block 3..." << endl;
    // thread t3(&Blockchain::AddBlock,bChain,Block(3, "Block 3 Data"));

    // t1.join();
    // t2.join();
    // t3.join();
    bChain->AddBlock(Block(1, "Block 1 Data"));
    bChain->AddBlock(Block(2, "Block 2 Data"));
    bChain->AddBlock(Block(3, "Block 3 Data"));
    bChain->showLedger();
    cout<<"Is this chain valid ? "<<bChain->isChainValid()<<endl;
    delete bChain;
    
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by program: "
         << (float)duration.count()/1000000 << " seconds" << endl; 

    return 0;
}