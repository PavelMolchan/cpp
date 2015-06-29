#include <iostream>
#include <cstring>
#include <io.h>
#include <direct.h>

using namespace std;

void copy(char* path1, char* path2)
{
	_finddata_t* dirinfo = new _finddata_t;
	char* pathmask = new char[strlen(path1) + 4];
	strcpy(pathmask, path1);
	strcat(pathmask, "\*.\*");
	long group = _findfirst(pathmask, dirinfo);
	int work = group;
	int count = 0;
	while (work != -1){
		if (count > 1){
			if (dirinfo->attrib&_A_SUBDIR){
				char* newpath1 = new char[strlen(path1) + strlen(dirinfo->name) + 2];
				strcpy(newpath1, path1);
				strcat(newpath1, dirinfo->name);
				char* newpath2 = new char[strlen(path2) + strlen(dirinfo->name) + 2];
				strcpy(newpath2, path2);
				strcat(newpath2, dirinfo->name);
				_mkdir(newpath2);
				strcat(newpath1, "\\");
				strcat(newpath2, "\\");
				copy(newpath1, newpath2);
			}
			else if (dirinfo->attrib&_A_ARCH || dirinfo->attrib&_A_NORMAL || dirinfo->attrib&_A_HIDDEN){
				cout << dirinfo->name << endl;
				char*	newpath1 = new char[strlen(path1) + strlen(dirinfo->name) + 1];
				strcpy(newpath1, path1);
				strcat(newpath1, dirinfo->name);
				char*	newpath2 = new char[strlen(path2) + strlen(dirinfo->name) + 1];
				strcpy(newpath2, path2);
				strcat(newpath2, dirinfo->name);
				FILE* src = fopen(newpath1, "rb");
				FILE* dest = fopen(newpath2, "wb");
				int size = 65536;
				char* dat = new char[size];
				long realsize;
				while (!feof(src)){
					realsize = fread(dat, sizeof(char), size, src);
					fwrite(dat, sizeof(char), realsize, dest);
				}
			}
		}
		work = _findnext(group, dirinfo);
		count++;
	}
	return;
};

void main(int argc, char* arg[])
{
	if (argc != 3){
		cout << "Command is not correct!" << endl;
	}
	else{
		copy(arg[1], arg[2]);
	}
}