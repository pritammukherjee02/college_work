#include <iostream>
#include <string>

using namespace std;

class BookDatabase{
    struct Book{
        string name;
        float price;
        string ISBN;
        string genre;
    };
    Book books[100];
    int count;

    public:
    BookDatabase(){
        this->count = 0;
    }

    bool addBook(string name, float price, string ISBN, string genre){
        if(count == 99) return false;

        Book temp;
        temp.name = name;
        temp.price = price;
        temp.ISBN = ISBN;
        temp.genre = genre;
        this->books[count++] = temp;
        return true;
    }

    void searchBookByISBN(string ISBN){
        for(int i = 0; i <= this->count; i++){
            if(this->books[i].ISBN == ISBN){
                cout << endl;
                cout << "\tFound book:" << endl;
                cout << "\t-----------------------------------`" << endl;
                cout << "\tName\tPrice\tISBN\tGenre" << endl;
                cout << "\t" << this->books[i].name << "\t" << this->books[i].price << "\t" << this->books[i].ISBN << "\t" << this->books[i].genre << endl;
                return;
            }
        }

        cout << "\tCouldn't find book in the database" << endl;
    }
};

int main()
{
    BookDatabase db = BookDatabase();

    cout << "Book Database Management System" << endl << endl;
    bool cont = true;
    while(cont){
        int choice;
        string name;
        float price;
        string ISBN;
        string genre;

        cout << "Actions:" << endl << "\t1 -> Add book to the database\n\t2 -> Search book in the database\n\t3 -> exit" << endl;
        cout << "\tYour choice: ";
        cin >> choice;
        cout << endl;
        switch (choice){
        case 1:
            cout << "\tEnter the name of the book: ";
            cin >> name;
            cout << "\tEnter the ISBN of the book: ";
            cin >> ISBN;
            cout << "\tEnter the genre of the book: ";
            cin >> genre;
            cout << "\tEnter the price of the book: ";
            cin >> price;
            db.addBook(name, price, ISBN, genre);
            cout << endl;
            break;
        case 2:
            cout << "\tEnter the ISBN of the book: ";
            cin >> ISBN;
            db.searchBookByISBN(ISBN);
            cout << endl;
            break;
        default:
            cont = false;
        }
    }

    return 0;
}