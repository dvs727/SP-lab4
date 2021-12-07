/*
Написать две программы. Первая - копирует файл. Вторая - копирует содержимое
директории пофайлово с помощью первой программы в отдельных процессах.
*/
#include <fstream>
#include <iostream>
#include <dirent.h>
#include <unistd.h>

using namespace std;

#define DIRECTORY 4
#define FILE 8

void copy_directory(string path_to_source, string path_to_destination);
void copy_file(string path_to_source, string path_to_destination);


int main(int argc, char const *argv[]){
	if (argc != 3){
		cout << "Usage: " << argv[0] << " <source_directory> <destination_directory>" << endl;
		exit(0);
	}

	string path_to_source = argv[1];
	string path_to_destination = argv[2];

	copy_directory(path_to_source, path_to_destination);

	return 0;
}

void copy_directory(string path_to_source, string path_to_destination) {
	DIR *dir;
	struct dirent *ent;
	dir = opendir(path_to_source.c_str());
	while ((ent = readdir (dir)) != NULL){
		string name(ent->d_name); 
		if (name == "." || name == "..")
			continue;

		int type = ent->d_type;
		if (type & DIRECTORY)
			continue; // maybe recursive copy_directory?

		copy_file(
			path_to_source + "/" + name,
			path_to_destination + "/" + name
		);
	}

	closedir (dir);
}

void copy_file(string path_to_source, string path_to_destination) {
	if (fork() != 0)
		return;

	char* args[] = {
		(char*)"./copy_file",
		(char*)path_to_source.c_str(),
        (char*)path_to_destination.c_str(),
        (char*)NULL
	};

	execv(
		"./copy_file",
        args
	);
}
