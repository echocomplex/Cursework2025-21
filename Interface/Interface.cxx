#include "Interface.hxx"

void Interface::clearInputBuffer (void) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Interface::getBook (Book& unit) {
    std::string temp;
    unsigned short temp_number = 0;

    std::cout << "Enter the Author Name: ";
    std::getline(std::cin, temp);
    unit.setAuthorName(temp);
    std::cout << "Enter the Book Name: ";
    std::getline(std::cin, temp);
    unit.setBookName(temp);
    std::cout << "Enter the Publisher: ";
    std::getline(std::cin, temp);
    unit.setPublisher(temp);
    std::cout << "Enter the year: ";
    std::cin >> temp_number;
    this->clearInputBuffer();
    unit.setYear(temp_number);
    temp_number = 0;
    std::cout << "Enter the Pages Count: ";
    std::cin >> temp_number;
    this->clearInputBuffer();
    unit.setPages(temp_number);
    temp_number = 0;
    std::cout << "Enter the Book Number: ";
    std::cin >> temp_number;
    this->clearInputBuffer();
    unit.setNumber(temp_number);
    std::cout << "Enter the Subject: ";
    std::getline(std::cin, temp);
    unit.setSubject(temp);
    std::cout << "Enter the Classificator: ";
    std::getline(std::cin, temp);
    unit.setClassificator(temp);
}

int Interface::removeBook (void) {
    int number;
    while (true) {
        std::cout << "Enter Book number to delete (1-" << this->unit.size() << "): ";
        
        if (!(std::cin >> number)) {
            std::cin.clear();
            this->clearInputBuffer();
            std::cerr << "Error: Please enter a number\n\n";
            continue;
        }

        if (number > 0 && number <= this->unit.size()) {
            return number - 1;
        }
        
        std::cerr << "Error: Number must be between 1 and " << this->unit.size() << "\n\n";
    }
}

void Interface::displayMenu (void) {
    std::cout << "\n\n=== Book Database Menu ===" << std::endl;
    std::cout << "1. Display all records" << std::endl;
    std::cout << "2. Add new Book" << std::endl;
    std::cout << "3. Remove Book" << std::endl;
    std::cout << "4. Find Books by Subject" << std::endl;
    std::cout << "5. Find Books by Author" << std::endl;
    std::cout << "6. Count Books by Author" << std::endl;
    std::cout << "7. Exit program" << std::endl;
    std::cout << "Enter your choice (1-7): ";
}

void Interface::pool (void) {
    short choice = 0;
    Book new_Book;
    List <Book> collected;
    std::string temp;
    while (true) {
        this->displayMenu();

        while (!(std::cin >> choice) || choice < 1 || choice > 7) {
            std::cout << "Invalid input. Please enter 1-7: ";
            this->clearInputBuffer();
        }

        this->clearInputBuffer();

        switch (choice) {
            case 1:
                std::cout << "\n[Displaying all records]\n";
                std::cout << this->unit << std::endl;
                break;
            case 2:
                std::cout << "\n[Adding new Book]\n";
                this->getBook(new_Book);
                this->unit.append(new_Book);
                break;
            case 3:
                std::cout << "\n[Removing Book]\n";
                this->unit.remove(this->removeBook());
                break;
            case 4:
                std::cout << "Enter the Book Subject you need to search: ";
                std::getline(std::cin, temp);
                std::cout << "\n[Searching Books by " << temp << "]\n";
                this->unit.searchBooksBySubject(collected, temp);
                for (int i = 0; i < collected.length(); ++i) std::cout << collected[i] << std::endl;
                collected.clear();
                break;
            case 5:
                std::cout << "Enter the Book Author you need to search: ";
                std::getline(std::cin, temp);
                std::cout << "\n[Searching Books by " << temp << "]\n";;
                this->unit.searchBooksByAuthor(collected, temp);
                for (int i = 0; i < collected.length(); ++i) std::cout << collected[i] << std::endl;
                collected.clear();
                break;
            case 6:
                std::cout << "Enter the Books Author you need to count: ";
                std::getline(std::cin, temp);
                std::cout << "This author wrote " << this->unit.countBooksByAuthor(temp) << " books." << std::endl;
                break;
            case 7:
                std::cout << "\nExiting program...\n";
                return;
        }

        std::cout << "\nOperation completed. Press Enter to continue...";
        this->clearInputBuffer();
    }
}