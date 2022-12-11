#include <dirent.h>
#include <string>
#include <vector>

using namespace std;

vector<string> DirList(const char * str)
{
    vector<string> list;

    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir (str)) != NULL)
    {
        while ((ent = readdir (dir)) != NULL)
        {
            string name = ent->d_name;
            if (name.find('.')==name.npos)
                list.push_back(name);
        }
        closedir(dir);
    }
    else
    {
        perror ("Something went wrong opening main folder");
    }

    return list;
}