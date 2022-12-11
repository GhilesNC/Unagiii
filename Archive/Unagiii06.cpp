#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <windows.h>

#include "..\RandInt\RandInt.cpp"
#include "DirList.cpp"
#include "FileList.cpp"
#include "FilesList.cpp"
#include "AllFilesList.cpp"
#include "DisplayPath.cpp"

void Show(const char *, string);
void Show(const char *, vector<string>);
void Show(vector<string>, string, string);

int main()
{
    const char * Directory = ".";
    vector<const char *> Extensions{".3gp"/*Hachakoum*/,".avi",".flv",".m4v",".mkv",".mov",".mp4"};
    // vector<const char *> Extensions{".png",".jpg"};

    srand(time(NULL));
    unsigned int rnd;

    /* Getting the whole list of (Extension) files */
    vector<string> list = AllFilesList(Directory,Extensions);
    if (list.empty()) { return -1; }
    // Show("Whole (Extension) file list :",list);

    /* Choosing a (Extension) file */
    rnd = RandInt(0,list.size()-1);
    string choice = list[rnd];

    /* Creating system (run) command */
    string Command;
    Command.append("\"").append(choice).append("\"");
    // Show("Generated Path :",path);

    /* Show results */
    // Show(list,choice,list2,choice2,path);

    /* Display location + name */
    DisplayPath(choice);
    /* Running file */
    system(Command.c_str());

    return 0;
}

void Show(const char * title, string str)
{
    cout << title << endl;
    cout << str << endl;
}

void Show(const char * title, vector<string> vstr)
{
    cout << title << endl;
    for (const string & str : vstr)
        cout << str << endl;
}

void Show(vector<string> vstr2, string str2, string str3)
{
    cout << "Extension File list :" << endl;
    for (const string & str : vstr2)
        cout << str << endl;

    cout << "Extension File choice :" << endl;
    cout << str2 << endl;

    cout << "Generated Path :" << endl;
    cout << str3 << endl;
}
