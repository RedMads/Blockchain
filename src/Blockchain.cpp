#include "headers/Blockchain.h"
#include "headers/Block.h"

Blockchain::Blockchain() {

    // create genesis Block
    Block genesisBlock("2022411270d24869205361746f7368692c20796f752772652047524541542021", "F*ck all social media platforms", 1650048219);

    // shrink the chain
    chain.shrink_to_fit();

    // mine the genesis block
    // and add it to the chain
    addBlock(genesisBlock);

}

void Blockchain::addBlock(Block block) {

    // mine a block before add it to the chain
    block.mineBlock(difficulty);

    // set index of block
    block.setIndex(getChainLength());

    // check if hash of block is vaild or not
    if(block.isHashVaild())
        chain.push_back(block);
        
    else
        throw std::runtime_error("The hash of this block is not vaild!");
}


void Blockchain::printChain() {

    std::vector<Block>::iterator i;

    for(i = chain.begin(); i != chain.end(); i++) {

        Block currentBlock = *i;
        time_t time = currentBlock.getTimestamp();

        std::cout << "--------------------------------------\n";
        std::cout << "Index: " << currentBlock.getIndex() << "\n";
        std::cout << "Hash: " << currentBlock.getHash() << "\n";
        std::cout << "PrevHash: " << currentBlock.getPrevHash() << "\n";
        std::cout << "Data: " << currentBlock.getData() << "\n";
        std::cout << "Nonce: " << currentBlock.getNonce() << "\n";
        std::cout << "Timestamp: " << time << " | " << ctime(&time) << "\n";
        std::cout << "--------------------------------------\n";
    }

}



std::vector<Block> Blockchain::getChain() { return chain;}

int Blockchain::getChainLength() { return chain.size();}

Block Blockchain::getLatestBlock() { return chain[chain.size() - 1];}