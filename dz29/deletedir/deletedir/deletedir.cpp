#include <iostream>
#include <cstring>
#include <io.h>
#include <direct.h>

using namespace std;

void deletedir(char* path)
{
	_finddata_t* dirinfo = new _finddata_t;
	char* pathmask = new char[strlen(path) + 4];
	strcpy(pathmask, path);
	strcat(pathmask, "\*.\*");
	long group = _findfirst(pathmask, dirinfo);
	int work = group;
	int count = 0;
	bool flagall;
	while (work != -1){
		if (count > 1){
			if (dirinfo->attrib&_A_SUBDIR){
				char* newpath = new char[strlen(path) + strlen(dirinfo->name) + 2];
				strcpy(newpath,path);
				strcat(newpath, dirinfo->name);
				strcat(newpath, "\\");
				deletedir(newpath);
				
			}
			else if (dirinfo->attrib&_A_ARCH || dirinfo->attrib&_A_NORMAL || dirinfo->attrib&_A_HIDDEN || (dirinfo->attrib&_A_RDONLY&&flagall)){
				char*	newpath = new char[strlen(path) + strlen(dirinfo->name) + 1];
				strcpy(newpath, path);
				strcat(newpath, dirinfo->name);
				remove(newpath);
			}
			else if (dirinfo->attrib&_A_RDONLY&&!flagall){
				int des;
				do{
					cout << "Direction have read only file\n";
					cout << "Wat would you like todo\?(press \"1\" to delete this fie,\"2\" to skip this file";
					cout << "\"3\" to delete to all, \"4\" to abort this process\n";
					cin >> des;
					if (des == 1){
						char*	newpath = new char[strlen(path) + strlen(dirinfo->name) + 1];
						strcpy(newpath, path);
						strcat(newpath, dirinfo->name);
						deletedir(newpath);
					}
					else if (des == 3){
						flagall = true;
					}
					else if (des == 4){
						exit(0);
					}
					else{
						cout << "Wrong command!\nTry again\n";
					}
				}
				while (des <0 && des > 5);
			}
		}
		work = _findnext(group, dirinfo);
		count++;
	}
	int pos = strlen(path)-1;
	char* newpath = new char[pos];
	strncpy(newpath, path, pos);
	newpath[pos] = '\0';
	_rmdir(newpath);
	return;
};

void main(int argc, char* arg[])
{
	if (argc != 2){
		cout << "Command is not correct!" << endl;
	}
	else{
		deletedir(arg[1]);
	}
}