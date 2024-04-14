
#define OS WIN
#include "s_files.hpp"

int main(){

    file empty_file();
    
    new_file new_zip("new_file.zip", 24mb);

    file py_script("./src/mod.py" , file::read);
    file cfg_script("../config.cfg" , file::write);
    file md_file("c://dir1/dir2/readme.md" , file::read_and_write);


    return 0;
}
