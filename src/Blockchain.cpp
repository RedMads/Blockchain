#include "headers/Blockchain.h"
#include "headers/Block.h"

Blockchain::Blockchain() {

    // ( Genesis Block data )

    // BlockHash = 00000f18688ed6e6b69d74cb3fc870c76031a231988f4c0005037fb87f696333
    // difficulty = 5
    // Nonce = 827641

    // create Genesis Block
    Block genesisBlock(std::string(64, '0'), "F*ck all social media platforms", 1650048219);

    // shrink the chain
    chain.shrink_to_fit();

    // mine the genesis block
    // and add it to the chain
    
    // Debug line ( delete this later )

    // counting how much secends for mining Genesis Block
    //time_t start = time(0);
    addBlock(genesisBlock);
    
    //time_t end = time(0);
    //std::cout << "Mined in: " << end - start << " Secs !\n";

}

void Blockchain::addBlock(Block block) {

    // mine a block before add it to the chain
    block.mineBlock(difficulty);

    // set index of block
    block.setIndex(getChainLength());

    // check if hash of block is vaild or not
    // and check if the hash is mined or not
    if(block.isHashVaild() && block.isHashMined(block.getHash(), difficulty))
        chain.push_back(block);

    else
        throw std::runtime_error("The hash of this block is not vaild or not mined !");
}




void Blockchain::printChain() {

    // initialize iterator to loop over the chain
    std::vector<Block>::iterator i;

    // start the loop
    for(i = chain.begin(); i != chain.end(); i++) {

        // a pointer thats point to Block objects
        // in the chain vector ( Array )
        Block currentBlock = *i;

        // output each Block data
        currentBlock.printBlockData();
    }

}


bool Blockchain::isChainVaild() {

    // intialize iterator to loop over the chain
    std::vector<Block>::iterator i;

    // loop all over the chain
    for(i=chain.begin(); i != chain.end(); ++i) {

        // define pointer points to current block
        Block currentBlock = *i;

        // check if the current block hash is not vaild
        if(!currentBlock.isHashVaild()) {
            //std::cout << "Block hash is not vaild !\n";
            return false;
        }
            

        // another check if the chain starts
        // from the second block ( Skipping genesis block )
        if(i != chain.begin()) {

            // define another pointer points to previous block
            Block prevBlock = *(i - 1);

            // check if ( currentBlock ) previous hash not the same
            // of the ( prevBlock ) hash
            if(currentBlock.getPrevHash() != prevBlock.getHash()) {
                //std::cout << "previous block hash is not vaild !\n";
                return false;
            }
                

        }

    }

    // chain is vaild YAY :P
    return true;
}



std::vector<Block> Blockchain::getChain() { return chain;}

int Blockchain::getChainLength() { return chain.size();}

Block Blockchain::getLatestBlock() { return chain[getChainLength() - 1];}

std::string Blockchain::getLastBlockHash() { return getLatestBlock().getHash(); }