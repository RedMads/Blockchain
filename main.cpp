#include "src/headers/Block.h"
#include "src/headers/Blockchain.h"


int main() {

    std::cout << "\nMining Genesis Block ...\n\n";


    Blockchain blockchainObj;


    std::vector<std::string> data = {

        "The WORLD is losing",
        "The WORLD needs a Revolution",
        "Tell the WORLD i'm coming"

    };


    for(std::string line: data) {

        Block b(blockchainObj.getLastBlockHash(), line, time(0));

        std::cout << "Mining Block-" << blockchainObj.getChainLength() << " ...\n\n";

        blockchainObj.addBlock(b);
        
    }


    blockchainObj.printChain();

    std::cout << "is Chain Vaild: " << blockchainObj.isChainVaild() << std::endl;

    return 0;
}