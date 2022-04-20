#include "headers/Block.h"

Block::Block(std::string PrevHash, std::string Data, time_t Timestamp) {

    prevHash = PrevHash;
    data = Data;
    timestamp = Timestamp;

}


std::string Block::generateHash() {

    // combine 2 strings
    std::string allData = prevHash + data;

    // continue combining
    allData += std::to_string(timestamp) + std::to_string(nonce);

    hash = sha256(allData);

    return hash;

}


bool Block::isHashMined(std::string hash, unsigned int difficulty) {

    // variable stores number of zeros
    int zeros = 0;

    // loop all over the hash
    // and check if the front of hash is contining ( 0 ) or not
    // zeros number are same as diffculty
    // if diffculty is ( 3 ) zeros are ( 000 )
    for(int i=0; i < difficulty; i++) {

        // check if index of i is zero
        if(hash[i] == '0')
            zeros+=1;

        // if not we will end this function
        // by return false
        else 
            return false;

    }

    // return true when we find the right hash !
    return true;


}


std::string Block::mineBlock(unsigned int difficulty) {

    // check if the hash is mined
    // ( have zeros at the front )
    while(!isHashMined(hash, difficulty)) {

        // increment nonce by 1 each loop
        nonce++;

        // each loop we gonna generate the hash of block
        generateHash();
    }

    return hash;
}


void Block::printBlockData() {

    // output 40 of - 
    std::cout << std::string(40, '-') + "\n";

    std::cout << "Index: " << index << "\n";
    std::cout << "Hash: " << hash << "\n";
    std::cout << "PrevHash: " << prevHash << "\n";
    std::cout << "Data: " << data << "\n";
    std::cout << "Nonce: " << nonce << "\n";

    // output time in Unix timestamp and format it to be readable to humans
    std::cout << "Timestamp: " << timestamp << " | " << ctime(&timestamp) << "\n";
    std::cout << std::string(40, '-') + "\n";

}


bool Block::isHashVaild(){ return generateHash() == hash;}


// body of getters functions !
std::string Block::getHash() { return hash;}

unsigned int Block::getIndex() { return index;}

int32_t Block::getNonce() { return nonce;}

time_t Block::getTimestamp() { return timestamp;}

std::string Block::getPrevHash() { return prevHash;}

std::string Block::getData() { return data;}

// body of setters functions !
void Block::setIndex(unsigned int Index) { index = Index;}

void Block::setNonce(int32_t Nonce) { nonce = Nonce;}