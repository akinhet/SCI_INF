#include <iostream>
#include <string>

using std::string, std::cout, std::cin, std::endl;


class Cypher {
	public:
		string caesar(int offset, string buffer)
		{
			if (!buffer.length())
				return "";
			if (!(offset > 0 && offset < 26)) {
				cout << "ERROR: Offset outside of range (1-25)\n";
				exit(2);
			}

			for (int i=0; i <= buffer.length(); i++)
				buffer[i] = (buffer[i] - 97 + offset) % 26 + 97;

			return buffer;
		}

		string shift(string buffer)
		{
			if (!buffer.length())
				return "";

			char temp;

			for (int i=0; i <= (int)(buffer.length() / 2); i+=2) {
				temp = buffer[i];
				buffer[i] = buffer[i+1];
				buffer[i+1] = temp;
			}

			return buffer;
		}
};


class Decypher {
	public:
		void decrypt(string buffer)
		{
			for (int offset=0; offset <= 26; offset++) {
				string temp = buffer;

				for (int j=0; j <= temp.length(); j++)
					temp[j] = (26 + temp[j] - 97 - offset) % 26 + 97;
				cout << offset << ": " << temp << endl;
			}
		}
};


int main()
{
	Cypher c = Cypher();
	Decypher d = Decypher();

	string buffer;
	int choice, temp;

	cout << "Write what you want to cipher (only lowercase letters): ";
	getline(cin, buffer);
	
	cout << "1. Caesar cipher\n2. Shifting cipher\n3. Caesar and shifting cipher\n4. Decipher message\n";
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "Rotation (1-25): ";
			cin >> temp;
			cout << c.caesar(temp, buffer) << endl;
			break;
		case 2:
			cout << c.shift(buffer) << endl;
			break;
		case 3:
			cout << "Rotation (1-26): ";
			cin >> temp;
			cout << c.shift(c.caesar(temp, buffer)) << endl;
			break;
		case 4:
			d.decrypt(buffer);
			break;
		default:
			cout << "ERROR: Unknown option\n";
			exit(1);
	}

	return 0;
}
