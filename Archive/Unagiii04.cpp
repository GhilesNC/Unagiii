#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <windows.h>

#include "..\RandInt\RandInt.cpp"
#include "DirList.cpp"
#include "FileList.cpp"
#include "FilesList.cpp"

void Show(const char *, string);
void Show(const char *, vector<string>);
void Show(vector<string>, string, vector<string>, string, string);

int main()
{
    const char * Directory = ".";
    vector<const char *> Extension{".mkv",".mp4",".avi",".mov",".3gp",".m4v",".flv"};
    // vector<const char *> Extension{".png",".jpg"};

    string path = Directory;

    srand(time(NULL));
    unsigned int rnd;

    /* Getting the (somewhat) list of subdirectories */
    vector<string> list = DirList(path.c_str());
    if (list.empty()) { return -1; }
    // Show("Directory list :",list);

    /* Randomly choosing a subdirectory */
    rnd = RandInt(0,list.size()-1);
    string choice = list[rnd];
    path.append("\\").append(choice);

    /* Getting the list of (Extension) files */
    vector<string> list2 = FilesList(path.c_str(),Extension);
    if (list2.empty()) { return -1; }
    // Show("Extension File list :",list2);

    /* Choosing a (Extension) file */
    rnd = RandInt(0,list2.size()-1);
    string choice2 = list2[rnd];
    path.append("\\").append(choice2);

    /* Creating system (run) command */
    string Command;
    Command.append("\"").append(path).append("\"");
    // Show("Generated Path :",path);

    /* Show results */
    // Show(list,choice,list2,choice2,path);

    /* Display location + name */
    cout << ">> About to open Folder : " << choice << endl;
    cout << "                   File : " << choice2 << endl << endl;
    Sleep(2000);
    cout << ">> Enjoy !" << endl;
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

void Show(vector<string> vstr, string str, vector<string> vstr2, string str2, string str3)
{
    cout << "Directory list :" << endl;
    for (const string & str : vstr)
        cout << str << endl;

    cout << "Directory choice :" << endl;
    cout << str << endl;

    cout << "Extension File list :" << endl;
    for (const string & str : vstr2)
        cout << str << endl;

    cout << "Extension File choice :" << endl;
    cout << str2 << endl;

    cout << "Generated Path :" << endl;
    cout << str3 << endl;
}
