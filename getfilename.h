#include<dirent.h>
#include<vector>
#include<string>
using namespace std;
vector<string> getfile(string PATH)
{
    struct dirent *ptr;    
    DIR *dir;
    dir=opendir(PATH.c_str()); 
    vector<string> files;
    while((ptr=readdir(dir))!=NULL)
    {
        if(ptr->d_name[0] == '.')
            continue;
        files.push_back(ptr->d_name);
    }
    closedir(dir);
    return files;
}
//用于提取文件名,这里参考了https://blog.csdn.net/adong76/article/details/39432467