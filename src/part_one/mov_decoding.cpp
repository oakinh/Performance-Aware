#include <iostream>
#include <fstream>
#include <vector>

int main() {

    std::ifstream inputFile("binaries/single_register_mov", std::ios::binary);
    if (!inputFile) {
        std::cerr << "Failed to open file." << std::endl;
        return -1;
    }
    
    std::vector<uint8_t> buffer(std::istreambuf_iterator<char>(inputFile), {});
    inputFile.close();

    for (uint8_t byte : buffer) {
        std::cout << std::hex << static_cast<int>(byte) << " ";
    }

    return 0;
}