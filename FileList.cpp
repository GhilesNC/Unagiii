#include <dirent.h>
#include <string>
#include <vector>

using namespace std;

vector<string> FileList(const char * path,const char * ext)
{
    vector<string> list;

    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir (path)) != NULL)
    {
        string str = ext;
        unsigned int len = str.size();
        while ((ent = readdir (dir)) != NULL)
        {
            str = ent->d_name;
            if (str.size()>=len && str.substr(str.size()-len)==ext) { list.push_back(str); }
        }
        closedir(dir);
    }
    else{
        perror ("Something went wrong opening chosen folder");
    }

    return list;
}