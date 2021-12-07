/*
Написать две программы. Первая - копирует файл. Вторая - копирует содержимое
директории пофайлово с помощью первой программы в отдельных процессах.
*/
#include <fstream>
#include <iostream>

using namespace std;

void copy_file(string path_to_source, string path_to_destination);

int main(int argc, char const *argv[]){
	if (argc != 3){
		cout << "Usage: " << argv[0] << " <source_file> <destination_file>" << endl;
		exit(0);
	}

	string path_to_source = argv[1];
	string path_to_destination = argv[2];


	copy_file(path_to_source, path_to_destination);

	return 0;
}

void copy_file(string path_to_source, string path_to_destination) {
	string line;
    ifstream inp_file(path_to_source);
    ofstream out_file(path_to_destination);
 
    if(inp_file && out_file)
        while(getline(inp_file,line))
            out_file << line << "\n";
    
    inp_file.close();
    out_file.close(); 
}