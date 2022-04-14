#ifndef BLOCKCHAIN_HPP
#define BLOCHCHAIN_HPP

#include <ctime>
#include <string>
#include <vector>

#include "Block.h"


class Blockchain {


private:

    // array of blocks
    std::vector<Block> chain;


public:

    // a function to add blocks to the chain
    void addBlock(Block);

    // check if the hash is vaild
    // recalclute the hash and combire
    // it with the previous hash
    bool isHashVaild(std::string hash);

    // check if the entire chain is vaild
    // this function will use the previous function
    // ( isHashVaild ) 
    bool isChainVaild(std::vector<Block>);

    

};


#endif 