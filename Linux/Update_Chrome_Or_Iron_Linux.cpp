#include <filesystem>
#include <iostream>
#include <string>
#include <system_error>
using namespace std;

int main(){
         string route;
         string destination;
         cout << "Directory path. Enter the location of the origin.: " << endl;
         // Taking string input using getline() 
         getline(cin, route); 
         // Displaying string 
         cout << "The initial string is : "; 
         cout << route << endl;  
         cout << "Directory path. Enter the location of the destination.: " << endl;
         // Taking string input using getline()
         getline(cin, destination);
         cout << "The second string is : ";
         cout << destination << endl;   
         const std::filesystem::path from{route}, to{destination};
 
    try
    {
      	std::filesystem::copy(from, to); // throws: files do not exist
    }
    catch (std::filesystem::filesystem_error const& ex)
    {
        std::cout << "what():  " << ex.what() << '\n'
                  << "path1(): " << ex.path1() << '\n'
                  << "path2(): " << ex.path2() << '\n'
                  << "code().value():    " << ex.code().value() << '\n'
                  << "code().message():  " << ex.code().message() << '\n'
                  << "code().category(): " << ex.code().category().name() << '\n';
    }
 
//     All functions have non-throwing equivalents
     std::error_code ec;
     std::filesystem::copy_file(from, to, ec); // does not throw
     std::cout << "Non-throwing form sets error_code: " << ec.message() << '\n';
}