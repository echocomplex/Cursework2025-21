#ifndef BOOK_HXX
#define BOOK_HXX


#include <string>
#include <iostream>


class Book {
private:
    std::string author_name;
    std::string book_name;
    std::string publisher;
    unsigned short year;
    unsigned short pages;
    unsigned int number;
    std::string subject;
    std::string classificator;
public:
    Book (void) noexcept;
    Book (const std::string& author_name, const std::string& book_name, const std::string& publisher, const unsigned short year, const unsigned short pages, const unsigned int number, const std::string& subject, const std::string& classificator) noexcept;
    ~Book (void) noexcept = default;
    Book& operator= (const Book& unit) noexcept;
    friend std::ostream& operator<< (std::ostream& os, const Book& unit);
    std::string getAuthorName (void) const noexcept;
    std::string getBookName (void) const noexcept;
    std::string getPublisher (void) const noexcept;
    unsigned short getYear (void) const noexcept;
    unsigned short getPages (void) const noexcept;
    unsigned short getNumber (void) const noexcept;
    std::string getSubject (void) const noexcept;
    std::string getClassificator (void) const noexcept;
    void setAuthorName (const std::string& author_name) noexcept;
    void setBookName (const std::string& book_name) noexcept;
    void setPublisher (const std::string& publisher) noexcept;
    void setYear (const unsigned short year) noexcept;
    void setPages (const unsigned short pages) noexcept;
    void setNumber (const unsigned int number) noexcept;
    void setSubject (const std::string& subject) noexcept;
    void setClassificator (const std::string& classificator) noexcept;
};

#endif // BOOK_HXX