// Book Shope Project With File Handling in C++.
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class book_shop
{
public:
	void control_panel();
	void get_choice();

private:
	void add_book();
	void show_books();
	void check_book();
	void update_book();
	void del_book();
	void rent_book();
};

void book_shop::get_choice()
{
	book_shop b;

	int choice;
	cout << "\n\n Your Choice : ";
	cin >> choice;

	char x;

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
		b.check_book();
		break;
	case 4:
		b.update_book();
		break;
	case 5:
		b.del_book();
		break;
	case 6:
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
	cout << "\n 6. Exit";
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
	file << " " << book_id << "," << title << "," << authors << "," << num_copies << "\n";
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

void book_shop::check_book()
{
	cout << "\033c" << endl;
	fstream file;
	int num_copies, count = 0;
	string book_id, title, authors, b_idd;
	cout << "\n\n\t\t\t\tCheck Specific Book";
	file.open("book.txt", ios::in);
	if (!file)
		cout << "\n\n File Openning Error...";
	else
	{
		cout << "\n\n Book ID : ";
		cin >> b_idd;
		file >> book_id >> title >> authors >> num_copies;
		while (!file.eof())
		{
			if (b_idd == book_id)
			{
				cout << "\033c" << endl;
				cout << "\n\n\t\t\t\tCheck Specific Book";
				cout << "\n\n Book ID : " << book_id;
				cout << "\n\n\t\t\tName : " << title;
				cout << "\n\n Author : " << authors;
				cout << "\n\n\t\t\tNo. of Copies : " << num_copies;
				count++;
				break;
			}
			file >> book_id >> title >> authors >> num_copies;
		}
		file.close();
		if (count == 0)
			cout << "\n\n Book ID Not Found...";
	}
}

void book_shop::update_book()
{
	cout << "\033c" << endl;
	fstream file, file1;
	int num_copies, no_co, count = 0;
	string title, b_na, authors, a_na, b_idd, book_id;
	cout << "\n\n\t\t\t\tUpdate Book Record";
	file1.open("book1.txt", ios::app | ios::out);
	file.open("book.txt", ios::in);
	if (!file)
		cout << "\n\n File Openning Error...";
	else
	{
		cout << "\n\n Book ID : ";
		cin >> book_id;
		file >> b_idd >> title >> authors >> num_copies;
		while (!file.eof())
		{
			if (book_id == b_idd)
			{
				cout << "\033c" << endl;
				cout << "\n\n\t\t\t\tUpdate Book Record";
				cout << "\n\n New Book Name : ";
				cin >> b_na;
				cout << "\n\n\t\t\tAuthor Name : ";
				cin >> a_na;
				cout << "\n\n No. of Copies : ";
				cin >> no_co;
				file1 << " " << book_id << " " << b_na << " " << a_na << " " << no_co << "\n";
				count++;
			}
			else
				file1 << " " << b_idd << " " << title << " " << authors << " " << num_copies << "\n";
			file >> b_idd >> title >> authors >> num_copies;
		}
		if (count == 0)
			cout << "\n\n Book ID Not Found...";
	}
	file.close();
	file1.close();
	remove("book.txt");
	rename("book1.txt", "book.txt");
}

void book_shop::del_book()
{
	cout << "\033c" << endl;
	fstream file, file1;
	int num_copies, count = 0;
	string book_id, b_idd, title, authors;
	cout << "\n\n\t\t\t\tDelete Book Record";
	file1.open("book1.txt", ios::app | ios::out);
	file.open("book.txt", ios::in);
	if (!file)
		cout << "\n\n File Openning Error...";
	else
	{
		cout << "\n\n Book ID : ";
		cin >> book_id;
		file >> b_idd >> title >> authors >> num_copies;
		while (!file.eof())
		{
			if (book_id == b_idd)
			{
				cout << "\033c" << endl;
				cout << "\n\n\t\t\t\tDelete Book Record";
				cout << "\n\n One Book is Deleted Successfully...";
				count++;
			}
			else
				file1 << " " << b_idd << " " << title << " " << authors << " " << num_copies << "\n";
			file >> b_idd >> title >> authors >> num_copies;
		}
		if (count == 0)
			cout << "\n\n Book ID Not Found...";
	}
	file.close();
	file1.close();
	remove("book.txt");
	rename("book1.txt", "book.txt");
}

int main()
{
	int choice;
	char x;
	book_shop b;
	b.control_panel();
	return 0;
}