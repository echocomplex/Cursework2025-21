#include "Filer.hxx"

Filer::Filer (const std::string& path, const bool createNew) {
    if (createNew) {
        this->file.open(path, std::ios::in);
        if (!this->file.is_open()) {
            this->file.open(path, std::ios::out);
            this->file.close();
            this->file.open(path, std::ios::in);
            if (!this->file.is_open()) throw std::runtime_error("Failed to create the file.");
        }
    }
    else {
        this->file.open(path, std::ios::in);
        if (!this->file.is_open()) throw std::runtime_error("File cannot be opened or does not exists");
    }
    this->path = path;
}

Filer::~Filer (void) noexcept {
    if (this->file.is_open()) this->file.close();
}

void Filer::open (const std::string& path, const bool createNew) {
    if (createNew) {
        this->file.open(path, std::ios::in);
        if (!this->file.is_open()) {
            this->file.open(path, std::ios::out);
            this->file.close();
            this->file.open(path, std::ios::in);
            if (!this->file.is_open()) throw std::runtime_error("Failed to create the file.");
        }
    }
    else {
        this->file.open(path, std::ios::in);
        if (!this->file.is_open()) throw std::runtime_error("File cannot be opened or does not exists");
    }
    this->path = path;
}

void Filer::read (std::string& str) {
    if (!this->file.is_open()) throw std::runtime_error("File does not open now");
    
    this->mutex.lock();

    this->file.close();
    this->file.open(this->path, std::ios::in);

    this->file.seekg(0, std::ios::beg);
    std::string temp;

    this->file.seekp(0, std::ios::beg);
    while (std::getline(this->file, temp)) str += temp + '\n';
    
    this->mutex.unlock();
}

void Filer::readToList (List <Book>& unit) {
    if (!this->file.is_open()) throw std::runtime_error("File does not open now");
    
    this->mutex.lock();

    this->file.close();
    this->file.open(this->path, std::ios::in);

    this->file.seekg(0, std::ios::beg);
    std::string temp;
    Book node;
    while (std::getline(this->file, temp)) {
        node = Book();
        this->stringToBook(node, temp);
        unit.append(node);
    }

    this->mutex.unlock();
}

void Filer::writeBack (std::string& string) {
    if (!this->file.is_open()) throw std::runtime_error("File does not open now");
    else if (string.empty()) return;

    this->mutex.lock();

    this->file.close();
    this->file.open(this->path, std::ios::out | std::ios::app);

    this->file << string << '\n';
    this->file.flush();
    this->mutex.unlock();
}

void Filer::writeBackFromBook (const Book& unit) {
    if (!this->file.is_open()) throw std::runtime_error("File does not open now");

    this->mutex.lock();

    this->file.close();
    this->file.open(this->path, std::ios::out | std::ios::app);

    this->file << 
        unit.getAuthorName() << "$$" <<
        unit.getBookName() << "$$" <<
        unit.getPublisher() << "$$" <<
        unit.getYear() << "$$" <<
        unit.getPages() << "$$" <<
        unit.getNumber() << "$$" <<
        unit.getSubject() << "$$" <<
        unit.getClassificator() << '\n'
    ;
    this->file.flush();
    
    this->mutex.unlock();
}

void Filer::rewrite (std::string& string) {
    if (!this->file.is_open()) throw std::runtime_error("File does not open now");
    else if (string.empty()) return;

    this->mutex.lock();

    this->file.close();
    this->file.open(this->path, std::ios::out | std::ios::trunc);

    this->file << string << '\n';
    this->file.flush();

    this->mutex.unlock();
}

void Filer::rewriteFromList (const List <Book>& unit) {
    if (!this->file.is_open()) throw std::runtime_error("File does not open now");
    else if (unit.length() == 0) return;

    this->mutex.lock();

    this->file.close();
    this->file.open(this->path, std::ios::out | std::ios::trunc);

    this->file.seekg(0, std::ios::beg);

    for (unsigned int i = 0; i < unit.length(); ++i) {
        this->file << 
            unit[i].getAuthorName() << "$$" <<
            unit[i].getBookName() << "$$" <<
            unit[i].getPublisher() << "$$" <<
            unit[i].getYear() << "$$" <<
            unit[i].getPages() << "$$" <<
            unit[i].getNumber() << "$$" <<
            unit[i].getSubject() << "$$" <<
            unit[i].getClassificator() << '\n'
        ;
    }
    this->file.flush();

    this->mutex.unlock();
}

void Filer::stringToBook (Book& unit, const std::string& str) {
    if (str.empty()) return;

    std::string arr[8];
    unsigned short count = 0;
    for (size_t i = 0; i < (str.size() - 1) && count < 7; ++i) {
        if (str[i] == '$' && str[i + 1] == '$') {
            ++count, ++i;
        } 
        else arr[count].push_back(str[i]);
    }
    if (count < 8) arr[count].push_back(str[str.size() - 1]);

    unit.setAuthorName(arr[0]);
    unit.setBookName(arr[1]);
    unit.setPublisher(arr[2]);
    try {
        unit.setYear(std::stoul(arr[3]));
    } 
    catch (std::exception) {
        unit.setYear(0); 
    }
    try {
        unit.setPages(std::stoul(arr[4]));
    } 
    catch (std::exception) {
        unit.setPages(0); 
    }
    try {
        unit.setNumber(std::stoul(arr[5]));
    } 
    catch (std::exception) {
        unit.setNumber(0); 
    }
    unit.setSubject(arr[6]);
    unit.setClassificator(arr[7]);
}
