#include <dirent.h>
#include <string>
#include <vector>

using namespace std;

vector<string> FilesList(const char * path,vector<const char *> ext)
{
    vector<string> list;

    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir (path)) != NULL)
    {
        string str;
        unsigned int len[ext.size()];
        for (int i=0; i<ext.size(); i++)
        {
            str = ext[i];
            len[i] = str.size();
        }
        while ((ent = readdir (dir)) != NULL)
        {
            str = ent->d_name;
            for (int i=0; i<ext.size(); i++)
            {
                if (str.size()>=len[i] && str.substr(str.size()-len[i])==ext[i]) { list.push_back(str); break; }
            }
        }
        closedir(dir);
    }
    else{
        perror ("Something went wrong opening chosen subfolder");
    }

    return list;
}