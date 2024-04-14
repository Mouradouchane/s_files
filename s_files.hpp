
#ifndef S_FILES_LIB_HPP
#define S_FILES_LIB_HPP

#include <string>

/*
    ========== library types ========== 
*/
class file;
class atomic_file;
class file_information;
// ====================================


class file_information { // represent file information and deatils 

private :
    // file attribute
    uint32_t _attribute = NULL;
    uint32_t _number_of_links = NULL;
    uint32_t _volume_serial_number = NULL;

    uint64_t _creation_time = NULL;
    uint64_t _last_read_time = NULL;
    uint64_t _last_wrtie_time = NULL;

    uint32_t _size_low  = NULL;
    uint32_t _size_high = NULL;
    
    uint32_t _index_low  = NULL;
    uint32_t _index_high = NULL;

public : 
    // constructor's
    file_information();

    // destructor
    ~file_information();
};
// class file_information "end"


/*
    to represent files as objects in the code
*/
class file {

public :
    static const char read_and_write = 'rw';
    static const char read    = 'r';
    static const char write   = 'w';
    static const char binary  = 'b';
    static const char special = 's';
    
private :
    std::string _name = "";
    std::string _type = ""; // file.type : bin,rar,...

    std::string _current_path = ""; // current path of this file "path without name"
    std::string _current_full_path = ""; // full path with everything
    std::string _new_path = ""; // new path where to save this file "path without name"
    std::string _new_full_path = ""; // new path where to save this file "path without name"

    uint64_t _size = NULL; // file size in byte
    std::string _permissions = "";

    void* data = nullptr;

    bool _lock = false; // for multi-threading

public :

    // public object contain deatils and information about this files 
    file_information deatiles();

    // constructor's
    file();
    file(std::string file_path);
    file(std::string file_path , std::string file_permission);

    // destructor
    ~file();

    // file public functions 

    std::string name(); // o(1)
    std::string type(); // o(1)

    void rename(std::string const& new_name); // o(1)
    void change_type(std::string const& new_type); // o(1)

    std::string path(); // o(1)
    std::string full_path(); // o(1)

    uint64_t size(); // o(1)

    std::string permissions(); // o(1)

    // atomic stuff
    void lock(); // o(1)
    void unlock(); // o(1)
    bool is_locked(); // o(1)
    bool try_lock(); // o(1)

};
// class file "end"

#endif
