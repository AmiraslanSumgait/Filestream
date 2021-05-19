#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

// out -> write
// in -> read
// app -> append

void file_txt_write() {
	//ofstream fout("hakuna.txt", ios::out);
	ofstream fout("hakuna.txt", ios_base::app);

	if (!fout) {
		throw "File not found";
	}

	if (fout.is_open()) {
		fout << "Salam millet" << endl;
	}
	else {
		throw "File not open exception";
	}

	fout.close();
}

void file_txt_read() {
	ifstream fin("hakuna.txt", ios::in);

	if (fin.is_open()) {
		string value;
		while (!fin.eof())
		{
			getline(fin, value);
			cout << value << endl;
		}
	}

	fin.close();
}



void file_binary_write() {
	ofstream fout("arr.bin", ios::binary);
	int arr[5]{ 10,20,3,4,5 };

	if (fout.is_open()) {
		fout.write((char*)arr, sizeof(int) * 5);
	}
	fout.close();
}

void file_binary_read() {
	ifstream fin("arr.bin", ios::binary);

	int arr[5]{};

	if (fin.is_open()) {
		fin.read((char*)arr, sizeof(int) * 5);
	}

	for (size_t i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}cout << endl;
}






///////////////////////////
class Contact {
public:
	string name;
	string surname;
	string number;

	Contact() = default;
	Contact(const string& name, const string& surname,
		const string& number)
	{
		this->name = name;
		this->surname = surname;
		this->number = number;
	}
};


void file_txt_write_object() {
	Contact contact("Ilqar", "Hesenov", "94567");

	ofstream fout("True.txt", ios::app);
	fout.setf(ios::left);

	if (fout.is_open()) {

		fout << setw(20) << contact.name << " "
			<< setw(20) << contact.surname << " "
			<< setw(20) << contact.number << endl;
	}

	fout.close();
}




void file_txt_read_object() {
	Contact contact;

	ifstream fin("obj.txt");

	if (fin.is_open()) {

		while (!fin.eof())
		{
			fin >> contact.name;
			fin >> contact.surname;
			fin >> contact.number;

			cout << contact.name << endl;
			cout << contact.surname << endl;
			cout << contact.number << endl;
		}

	}

	fin.close();
}





void find(const string& name) {
	Contact contact;

	ifstream fin("obj.txt");

	if (fin.is_open()) {
		bool isFind = false;
		while (!fin.eof())
		{
			fin >> contact.name;
			fin >> contact.surname;
			fin >> contact.number;

			if (contact.name == name) {
				cout << contact.name << endl;
				cout << contact.surname << endl;
				cout << contact.number << endl;
				isFind = true;
				break;
			}
		}

		if (!isFind) cout << "Not found" << endl;

	}

	fin.close();
}
void delete_speccific_text(const string& name) {
	Contact contact;

	ifstream fin("True.txt");

	if (fin.is_open()) {
		bool isFind = false;
		while (!fin.eof())
		{

			fin >> contact.name;
			
		
			fin >> contact.surname;
			fin >> contact.number;
			if (contact.name == name) {
				isFind = true;
				continue;


			}
			
			ofstream fout("Aleykum.txt",ios::app);
			fout.setf(ios::left);

			if (fout.is_open()) {
				fout << setw(20) << contact.name << " "
					<< setw(20) << contact.surname << " "
					<< setw(20) << contact.number << endl;
				
			}
			
		}
		

		if (!isFind) cout << "Not found" << endl;

	}

	fin.close();
}


int main() {

	//file_txt_write_object();
	delete_speccific_text("Ilqar");

	return 0;
}
