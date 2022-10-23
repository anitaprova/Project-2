#include <iostream>
#include <string> 
#include <fstream>
#include <cctype>

using namespace std;

void set_width(string input_name){
	ifstream in_file;
        in_file.open(input_name);
	
	int width = 0;

//GET FIRST LINE AND PUT IN INPUT

	ofstream out_file;
	out_file.open("output.txt");
	
	string first_line;
	getline(in_file, first_line);

	int count = 0;
	string line;
	while(getline(in_file, line)) {
		string word;
		for (int i = 0; i < line.length(); i++) {
			if (isspace(line[i])) {
				if ((count + word.length() ) < 60) {
					out_file << word << " ";
					count += word.length() + 1;
				}
				else {
					count = 0;
					out_file << "\n" << word << " ";
					count += word.length() + 1;
				}

				if (word[word.length() - 1] == '?') {
                        		count = 0;
					out_file << "\n";
                		}
				word = "";
			}
			else {
				word += line[i];
			}
		}
		out_file << word;
		if (word[word.length() - 1] == '?') {
			count = 0;
			out_file << "\n";
		}
		
		if (line.length() == 0) { //paragraphs
			count = 0;
			out_file << "\n\n";
		}
	}
}

int main() {
	string file_name;
	cout << "Enter the input filename: ";
	cin >> file_name;
	set_width(file_name);

	return 0;
}	
