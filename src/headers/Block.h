#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <ctime>
#include <string>

#include "../libs/sha256/sha256.h"

struct Block {
    
    // a data structure of Block !

private:

    unsigned int index = 0; // number of block
    int32_t nonce = 0; // number of trys ( to get right hash )
    std::string hash; // the hash of block
    std::string prevHash; // previous hash
    std::string data = ""; // actual data
    time_t timestamp; // the time of block creation


public:

    // Block constructr to parse info !
    Block(std::string PrevHash, std::string Data, time_t Timestamp);

    
    // getters //

    unsigned int getIndex(); // function returns number of Block

    int32_t getNonce(); // function returns Nonce

    std::string getHash(); // function gets a hash of Block
    
    std::string getPrevHash(); // function gets a previous hash of block

    std::string getData(); // function gets a data of Block

    time_t getTimestamp(); // function retruns a Timestamp


    // setters //

    void setNonce(int32_t Nonce);
    void setIndex(unsigned int Index);


    // main functions //

    // check if the hash is vaild
    // by checking the difficulty rules
    bool isHashMined(std::string hash, unsigned int difficulty);


    // this function will check
    // if the hash of a block is same to
    // the new calculated hash or not
    bool isHashVaild();


    // the mining function
    // make sure that is block
    // hard to mine !
    std::string mineBlock(unsigned int difficulty);

    // function generates hash for Block !
    std::string generateHash();

    // function prints signle block data
    void printBlockData();

};


#endif