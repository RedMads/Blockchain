#ifndef BLOCKCHAIN_HPP
#define BLOCHCHAIN_HPP

#include <ctime>
#include <string>
#include <vector>
#include <iostream>

#include "Block.h"


class Blockchain {


private:

    // array of blocks
    std::vector<Block> chain;

    // this variable stores
    // how many zeros in front of hash
    // ( DIFFICULTY LEVEL )
    const unsigned int difficulty = 5;


public:

    Blockchain();

    // a function to add blocks to the chain
    void addBlock(Block);

    // check if the entire chain is vaild
    // this function will use the previous function
    // ( isHashVaild ) 
    bool isChainVaild();

    // function loops over the chain
    // and print it out
    void printChain();

    // getters //

    // returns the chain
    std::vector<Block> getChain();

    // return the chain length
    int getChainLength();

    // a useful function thats return last block
    Block getLatestBlock();

    // function to get last block hash
    std::string getLastBlockHash();


};


#endif 