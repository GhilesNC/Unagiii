#include <dirent.h>
#include <string>
#include <vector>

using namespace std;

void Show(const char *, string);

vector<string> AllFilesList(const char * path,vector<const char *> ext)
{
    vector<string> list;
    vector<string> part;

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

        if (readdir(dir) == NULL) { readdir(dir); perror ("Something went wrong opening subfolder"); }
        if (readdir(dir) == NULL) { readdir(dir); perror ("Something went wrong opening subfolder"); }

        string sub;
        while ((ent = readdir (dir)) != NULL)
        {
            str = ent->d_name;
            sub = path;
            sub.append("\\").append(str);

            if (opendir(sub.c_str()))
            {
                part = AllFilesList(sub.c_str(),ext);
                list.insert(list.end(),part.begin(),part.end());
                continue;
            }

            for (int i=0; i<ext.size(); i++)
            {
                if (str.size()>=len[i] && str.substr(str.size()-len[i])==ext[i])
                {
                    list.push_back(sub);
                    break;
                }
            }
        }
        closedir(dir);
    }
    else
    {
        perror ("Something went wrong opening subfolder");
    }

    return list;
}
