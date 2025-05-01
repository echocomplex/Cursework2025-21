#ifndef FILER_HXX
#define FILER_HXX


#include <fstream>
#include <string>
#include <stdexcept>
#include <mutex>
#include <List.hxx>
#include <Book.hxx>

class Filer {
private:
    std::fstream file;
    std::mutex mutex;
    std::string path;
public:
    Filer (void) noexcept = default;
    Filer (const std::string& path, const bool createNew = false);
    ~Filer (void) noexcept;
    void open (const std::string& path, const bool createNew = false);
    void read (std::string& str);
    void readToList (List <Book>& unit);
    void writeBack (std::string& string);
    void writeBackFromBook (const Book& unit);
    void rewrite (std::string& string);
    void rewriteFromList (const List <Book>& unit);
    static void stringToBook (Book& unit, const std::string& str);
};

#endif // FILER_HXX