#include <iostream>
#include <iostream>
#include <fstream>  
#include<string>
using namespace std;
string caesar_cipher(string plain_text, int key)
{
	for (int i = 0; i < plain_text.length(); i++)
	{
		if ((plain_text[i] >= 65 && plain_text[i] <= 90) || (plain_text[i] >= 97 && plain_text[i] <= 122))
		{
			plain_text[i] += key;
			if (!((plain_text[i] >= 65 && plain_text[i] <= 90) || (plain_text[i] >= 97 && plain_text[i] <= 122)))
			{
				plain_text[i] -= 26;
			}
		}
	}
	return plain_text;
}
void write_to_file(string file_name, string text)
{
	ofstream outfile(file_name+".txt");

	outfile << text << std::endl;

	outfile.close();
}

int main  ()
{
	cout << "please enter plain text !"<<endl;
	string plain_text;
	getline(cin, plain_text);
	cout << "enter the key for caesar cipher : any number between 1 and 26"<<endl;
	int key;
	cin >> key;
	cout<<"the encrypted text is : "<<caesar_cipher(plain_text,key)<<endl;
	write_to_file("ciphered text",caesar_cipher(plain_text, key));


}