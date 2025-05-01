#include "Book.hxx"

Book::Book (void) noexcept {
    this->year = 0;
    this->pages = 0;
    this->number = 0;
}
    
Book::Book (const std::string& author_name, const std::string& book_name, const std::string& publisher, const unsigned short year, const unsigned short pages, const unsigned int number, const std::string& subject, const std::string& classificator) noexcept {
    this->author_name = author_name;
    this->book_name = book_name;
    this->publisher = publisher;
    this->year = year;
    this->pages = pages;
    this->number = number;
    this->subject = subject;
    this->classificator = classificator;
}

Book& Book::operator= (const Book& unit) noexcept {
    this->author_name = unit.author_name;
    this->book_name = unit.book_name;
    this->publisher = unit.publisher;
    this->year = unit.year;
    this->pages = unit.pages;
    this->number = unit.number;
    this->subject = unit.subject;
    this->classificator = unit.classificator;
    return *this;
}
std::ostream& operator<< (std::ostream& os, const Book& unit) {
    os << 
        unit.author_name << ", " <<
        unit.book_name << ", " <<
        unit.publisher << ", " <<
        unit.year << ", " <<
        unit.pages << ", " <<
        unit.number << ", " <<
        unit.subject << ", " <<
        unit.classificator
    ;
    return os;
}
    
std::string Book::getAuthorName (void) const noexcept {
    return this->author_name;
}
    
std::string Book::getBookName (void) const noexcept {
    return this->book_name;
}
    
std::string Book::getPublisher (void) const noexcept {
    return this->publisher;
}
    
unsigned short Book::getYear (void) const noexcept {
    return this->year;
}
    
unsigned short Book::getPages (void) const noexcept {
    return this->pages;
}
    
unsigned short Book::getNumber (void) const noexcept {
    return this->number;
}
    
std::string Book::getSubject (void) const noexcept {
    return this->subject;
}
    
std::string Book::getClassificator (void) const noexcept {
    return this->classificator;
}
    
void Book::setAuthorName (const std::string& author_name) noexcept {
    this->author_name = author_name;
}
    
void Book::setBookName (const std::string& book_name) noexcept {
    this->book_name = book_name;
}
    
void Book::setPublisher (const std::string& publisher) noexcept {
    this->publisher = publisher;
}
    
void Book::setYear (const unsigned short year) noexcept {
    this->year = year;
}
    
void Book::setPages (const unsigned short pages) noexcept {
    this->pages = pages;
}
    
void Book::setNumber (const unsigned int number) noexcept {
    this->number = number;
}
    
void Book::setSubject (const std::string& subject) noexcept {
    this->subject = subject;
}
    
void Book::setClassificator (const std::string& classificator) noexcept {
    this->classificator = classificator;
}