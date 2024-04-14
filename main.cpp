
#include <iostream>
#include "s_files.hpp"

int main(){

    // read file test
    file txt = s_files::read_from_file("tar.txt");

    if(txt.buffer == nullptr){
        std::cout << "failed to read tar.txt\n";
    }
    else {
        std::cout << "tar.txt :\n";
        char* data = (char*)txt.buffer;

        for(uint32_t i = 0 ; i < txt.size ; i++){
            std::cout << data[i];
        }
    }

    // write to file test
    if( s_files::write_to_file("tar.txt",(void*)&"few lines",8,true)){
        std::cout << "write successed \n";
    }
    else {
        std::cout << "write failed \n";
    }

    return 0;
}
