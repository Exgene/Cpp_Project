#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void edit_book(int id)
{
    string line;
    string book_id, title, authors, num_copies;

    fstream file;
    file.open("library.csv", ios::in);
    if (!file)
    {
        cout << "\n\n File Openning Error...";
        return;
    }

    getline(file, line);
    while (getline(file, line))
    {
        istringstream ssin(line);
        getline(ssin, book_id, ',');
        if (stoi(book_id) == id)
        {
            getline(ssin, title, ',');
            getline(ssin, authors, ',');
            getline(ssin, num_copies, ',');
            cout << "Book ID: " << book_id << endl;
            cout << "Title: " << title << endl;
            cout << "Authors: " << authors << endl;
            cout << "Number of Copies: " << num_copies << endl;
            break;
        }
    }
    file.close();

    if (stoi(book_id) != id)
    {
        cout << "Book not found" << endl;
        return;
    }

    string new_title, new_authors, new_num_copies, element;

    cout << "What element would you like to update? (title, authors, num_copies): ";
    getline(cin, element);

    if (element == "title")
    {
        cout << "Enter new title: ";
        // cin.ignore();
        getline(cin, new_title);
        title = new_title;
    }
    else if (element == "authors")
    {
        cout << "Enter new authors: ";
        // cin.ignore();
        getline(cin, new_authors);
        authors = new_authors;
    }
    else if (element == "num_copies")
    {
        cout << "Enter new num_copies: ";
        // cin.ignore();
        getline(cin, new_num_copies);
        num_copies = new_num_copies;
    }

    string new_line = book_id + "," + title + "," + authors + "," + num_copies;
    cout << new_line << endl;

    string temp_file = "temp.csv";
    fstream file_in("library.csv", ios::in);
    fstream file_out(temp_file, ios::out);

    getline(file_in, line);
    file_out << line << endl;
    while (getline(file_in, line))
    {
        istringstream ssin(line);
        getline(ssin, book_id, ',');
        if (stoi(book_id) != id)
        {
            file_out << line << endl;
        }
        else
        {
            file_out << new_line << endl;
        }
    }

    file_in.close();
    file_out.close();
    remove("library.csv");
    rename(temp_file.c_str(), "library.csv");
}

int main()
{
    edit_book(11767);
    return 0;
}