#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <windows.h>

#include "..\RandStuff\RandInt.cpp"
#include "AllFilesList.cpp"
#include "DisplayPath.cpp"

void Show(const char *, string);
void Show(const char *, vector<string>);
void Show(vector<string>, string);

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

    /* Choosing a (Extension) file */
    rnd = RandInt(list.size());
    string choice = list[rnd];

    /* Creating system (run) command */
    string Command;
    Command.append("\"").append(choice).append("\"");

    /* Show results */
    // Show(list,choice);

    /* Display choice */
    DisplayPath(choice);

    /* Run file */
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
void Show(vector<string> vstr, string str)
{
    cout << "(Extension) File path list :" << endl;
    for (const string & str0 : vstr)
        cout << str0 << endl;

    cout << "(Extension) File choice path :" << endl;
    cout << str << endl;
}
