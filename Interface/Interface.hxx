#ifndef INTERFACE_HXX
#define INTERFACE_HXX


#include <iostream>
#include <Book.hxx> 
#include <List.hxx>
#include <Database.hxx>


class Interface {
private:
    Database unit;
    void displayMenu (void);
    void getBook (Book& unit);
    int removeBook (void);
    void clearInputBuffer (void);
public:
    Interface (void) = default;
    Interface (const Interface& unit) = delete;
    Interface& operator= (const Interface& unit) = delete;
    ~Interface (void) noexcept = default;
    void pool (void);
};


#endif // INTERFACE_HXX