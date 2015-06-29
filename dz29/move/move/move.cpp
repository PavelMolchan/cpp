#include <iostream>
#include <cstring>
#include <io.h>
#include <direct.h>

using namespace std;

void move(char* path1, char* path2)
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
				char* rempath1 = new char[strlen(path1) + strlen(dirinfo->name) + 1];
				strcpy(newpath1, path1);
				strcat(newpath1, dirinfo->name);
				strcpy(rempath1, path1);
				strcat(rempath1, dirinfo->name);
				char* newpath2 = new char[strlen(path2) + strlen(dirinfo->name) + 2];
				strcpy(newpath2, path2);
				strcat(newpath2, dirinfo->name);
				_mkdir(newpath2);
				strcat(newpath1, "\\");
				strcat(newpath2, "\\");
				move(newpath1, newpath2);
                			
			}
			else if (dirinfo->attrib&_A_ARCH || dirinfo->attrib&_A_NORMAL || dirinfo->attrib&_A_HIDDEN){
				char*	newpath1 = new char[strlen(path1) + strlen(dirinfo->name) + 1];
				strcpy(newpath1, path1);
				strcat(newpath1, dirinfo->name);
				char*	newpath2 = new char[strlen(path2) + strlen(dirinfo->name) + 1];
				strcpy(newpath2, path2);
				strcat(newpath2, dirinfo->name);
				rename(newpath1,newpath2);
			}
		}
		work = _findnext(group, dirinfo);
		count++;
	}
	int pos = strlen(path1) - 1;
	char* newpath = new char[pos];
	strncpy(newpath, path1, pos);
	newpath[pos] = '\0';
	_rmdir(newpath);
	return;
};

void main(int argc, char* arg[])
{
	if (argc != 3){
		cout << "Command is not correct!" << endl;
	}
	else{
		move(arg[1], arg[2]);
	}
}