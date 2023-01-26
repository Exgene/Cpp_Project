// Book Shope Project With File Handling in C++.
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

class book_shop
{
public:
	void control_panel();
	void get_choice();

private:
	void add_book();
	void show_books();
	void check_book(int id);
	void update_book(int id);
	void del_book(int id);
	void rent_book(int id);
};

void book_shop::get_choice()
{
	book_shop b;

	int choice;
	cout << "\n\n Your Choice : ";
	cin >> choice;

	char x;
	int i;

	switch (choice)
	{
	case 1:
		do
		{
			b.add_book();
			cout << "\n\n Do You Want to Add another Book (y,n) : ";
			cin >> x;
		} while (x == 'y' || x == 'Y');
		break;
	case 2:
		b.show_books();
		break;
	case 3:
		cout << "\033c" << endl;
		cout << "\n\n\t\t\t\tSearch a book\n";
		cout << "Enter Book ID: ";
		cin >> i;
		b.check_book(i);
		break;
	case 4:
		cout << "\033c" << endl;
		cout << "\n\n\t\t\t\tUpdate/Edit book\n";
		cout << "Enter Book ID: ";
		cin >> i;
		b.update_book(i);
		break;
	case 5:
		cout << "\033c" << endl;
		cout << "\n\n\t\t\t\tDelete book\n";
		cout << "Enter Book ID: ";
		cin >> i;
		b.del_book(i);
		break;
	case 6:
		cout << "\033c" << endl;
		cout << "\n\n\t\t\t\tRent book\n";
		cout << "Enter Book ID: ";
		cin >> i;
		b.rent_book(i);
		break;
	case 7:
		exit(0);
	default:
		cout << "\n\n Invalid Value...Please Try Again...";
	}
	cin.get();
	control_panel();
}

void book_shop::control_panel()
{
	book_shop b;
	// cout << "\033c" << endl;
	cout << "\n\n\t\t\t\tControl Panel";
	cout << "\n\n 1. Add New Book";
	cout << "\n 2. Display Books";
	cout << "\n 3. Check Specific Book";
	cout << "\n 4. Update Book";
	cout << "\n 5. Delete Book";
	cout << "\n 6. Rent Book";
	cout << "\n 7. Exit";
	b.get_choice();
}

void book_shop::add_book()
{
	cout << "\033c" << endl; // clears the terminal

	fstream file;

	string title, authors, book_id;
	int num_copies;

	cout << "\n\n\t\t\t\t ADD New Book";
	cout << "\n\n Book ID : ";
	cin >> book_id;
	getline(cin, title);

	cout << "\n\n\t\t\t Book Name : ";
	getline(cin, title);

	cout << "\n\n Author Name : ";
	getline(cin, authors);

	cout << "\n\n\t\t\t No. of Copies : ";
	cin >> num_copies;

	file.open("library.csv", ios::out | ios::app);
	file << book_id << "," << title << "," << authors << "," << num_copies << "\n";
	file.close();
}

void book_shop::show_books()
{
	cout << "\033c" << endl;

	cout << "\n\n\t\t\t\t   All Books";

	fstream file;
	file.open("library.csv", ios::in);
	if (!file)
	{
		cout << "\n\n File Openning Error...";
		return;
	}

	cout << "\n\n\t Book ID\tBook\t\tAuthor\t\tNo. of Copies\n\n";
	string row;
	getline(file, row);

	string book_id, title, authors, num_copies;

	while (getline(file, row))
	{
		istringstream ssin(row);
		if (!getline(ssin, book_id, ','))
		{
			cout << "Invalid data in file" << endl;
			continue;
		}
		if (!getline(ssin, title, ','))
		{
			cout << "Invalid data in file" << endl;
			continue;
		}
		if (!getline(ssin, authors, ','))
		{
			cout << "Invalid data in file" << endl;
			continue;
		}
		if (!getline(ssin, num_copies, ','))
		{
			cout << "Invalid data in file" << endl;
			continue;
		}
		cout << "\t" << left << setw(8) << book_id << setw(25) << title << setw(20) << authors << num_copies << endl;
	}
	file.close();
}

void book_shop::check_book(int id)
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
}

void book_shop::update_book(int id)
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
	getline(cin, element);
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

void book_shop::del_book(int id)
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

	char x;
	cout << "\nAre you sure you want to delete this book? (y,n)\nNote this action is permanent and irreversible : ";
	cin >> x;
	if (x != 'y' && x != 'Y')
	{
		cout << "The book was not deleted" << endl;
		return;
	}

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
	}

	file_in.close();
	file_out.close();
	remove("library.csv");
	rename(temp_file.c_str(), "library.csv");

	cout << "\nThe book (id:" << book_id << ") is now deleted ";
}

void book_shop::rent_book(int id)
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

	int copies = stoi(num_copies);

	if (copies == 0)
	{
		cout << "\nThis book is currently unavailable" << endl;
		cout << "\nCannot be rented" << endl;
		return;
	}

	char x;
	cout << "\nAre you sure you want to rent/borrow this book? (y,n)\n";
	cin >> x;
	if (x != 'y' && x != 'Y')
	{
		cout << "Book not rented" << endl;
		return;
	}

	copies = copies - 1;

	num_copies = to_string(copies);

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

	cout << "\nThe book (id:" << book_id << ") is successfully rented ";
}

int main()
{
	int choice;
	char x;
	book_shop b;
	b.control_panel();
	return 0;
}