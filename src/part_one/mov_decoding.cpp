#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <unordered_map>

int main() {

    std::ifstream inputFile("binaries/single_register_mov", std::ios::binary);
    if (!inputFile) {
        std::cerr << "Failed to open file." << std::endl;
        return -1;
    }
    
    std::vector<uint8_t> buffer(std::istreambuf_iterator<char>(inputFile), {});
    inputFile.close();

    std::unordered_map<int, std::string> Reg0Encoding = {
        {000, "AL"},
        {001, "CL"},
        {010, "DL"},
        {011, "BL"},
        {100, "AH"},
        {110, "CH"},
        {110, "DH"},
        {111, "BH"},
    };

    std::unordered_map<int, std::string> Reg1Encoding = {
        {000, "AX"},
        {001, "CX"},
        {010, "DX"},
        {011, "BX"},
        {100, "SP"},
        {101, "BP"},
        {110, "SI"},
        {111, "DI"},
    };

    std::string instructionType;
    uint8_t opCodeMask = 0b11111100;
    uint8_t opCode = buffer[0] & opCodeMask;
    uint8_t dMask = 0b00000010;
    uint8_t wMask = 0b00000001;
    
    if (opCode == 0b10001000) {
        instructionType = "MOV";
        std::cout << "Instruction type: " << instructionType << std::endl;
    } else {
        std::cerr << "Unexpected opcode received: 0x" << std::bitset<8>(buffer[0]) << std::endl;
    }
    std::cout << std::endl;

    return 0;
}