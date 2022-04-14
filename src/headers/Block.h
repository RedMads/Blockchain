#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <ctime>

struct Block {
    
    // a data structure of Block !

private:

    unsigned int index = 0; // number of block
    int32_t nonce; // number of trys ( to get right hash )
    std::string hash; // the hash of block
    std::string prevHash; // previous hash
    std::string data = ""; // actual data
    time_t timestamp; // the time of block creation


public:

    // Block constructr to parse info !
    Block(unsigned int Index, int32_t Nonce, std::string Hash,
        std::string PrevHash, std::string Data, time_t Timestamp);

    
    // getters //

    unsigned int getIndex(); // function returns number of Block

    int32_t getNonce(); // function returns Nonce

    std::string getHash(); // function gets a hash of Block
    
    std::string getPrevHash(); // function gets a previous hash of block

    time_t getTimestamp(); // function retruns a Timestamp



};


#endif