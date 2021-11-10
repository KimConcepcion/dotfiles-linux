#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

const std::string WHITESPACE = " \n\r\t\f\v";

std::string read_string_from_systemfile(std::string file_path, std::string key)
{
    std::ifstream infile(file_path);
    std::string line;
    std::size_t colon_pos;
    std::size_t first_not_whitespace_pos;

    // Read file line by line
    while (std::getline(infile, line))
    {
        // Check if "key" is in line:
        if (line.find(key) != std::string::npos)                           // Search for "key" in line.
        {
            colon_pos = line.find(":");                                    // Return position of first ":" in line.
            line  = line.substr(colon_pos+1);                              // Read from ":" position in string and add 1 to exclude ":" in trimmed "line" string.
            first_not_whitespace_pos = line.find_first_not_of(WHITESPACE); // Store position of first read character, which is not " ", \n, \r, \t, \f, \v.
            line = line.substr(first_not_whitespace_pos);                  // Read from the first character in "line", which is not WHITESPACE. 
            
            return line;                                                   // Return string with removed leading whitespaces and removed colon.
        }
    }
}

uint32_t read_number_from_systemfile(std::string file_path, std::string key)
{
    std::ifstream infile(file_path);
    std::string line;
    std::size_t colon_pos;
    std::size_t first_not_whitespace_pos;
    
    uint32_t value;

    // Read file line by line
    while (std::getline(infile, line))
    {
        // Check if "key" is in line:
        if (line.find(key) != std::string::npos)
        {
            colon_pos = line.find(":");
            line  = line.substr(colon_pos+1);
            first_not_whitespace_pos = line.find_first_not_of(WHITESPACE);
            line = line.substr(first_not_whitespace_pos);

            value = atoi(line.c_str());
            return value;
        }
    }
}

int main()
{
    std::string model_name;
    std::string hardware;
    std::string serial;

    uint32_t MemTotal;
    uint32_t MemFree;
    uint32_t CmaTotal;
    uint32_t CmaFree;

    printf("------ Linux System collector ------\n");

    // Read cpuinfo
    model_name = read_string_from_systemfile("/proc/cpuinfo", "model name");
    hardware   = read_string_from_systemfile("/proc/cpuinfo", "Hardware");
    serial     = read_string_from_systemfile("/proc/cpuinfo", "Serial");

    // Read meminfo
    MemTotal  = read_number_from_systemfile("/proc/meminfo", "MemTotal");
    MemFree   = read_number_from_systemfile("/proc/meminfo", "MemFree");
    CmaTotal  = read_number_from_systemfile("/proc/meminfo", "CmaTotal");
    CmaFree   = read_number_from_systemfile("/proc/meminfo", "CmaFree");

    printf("model name: [%s]\n", model_name.c_str());
    printf("hardware: [%s]\n", hardware.c_str());
    printf("serial: [%s]\n", serial.c_str());

    printf("MemTotal: [%d]\n", MemTotal);
    printf("MemFree: [%d]\n" , MemFree);
    printf("CmaTotal: [%d]\n", CmaTotal);
    printf("CmaFree: [%d]\n" , CmaFree);
    
    return 0;
}
