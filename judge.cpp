#include"inputgenerate.h"
#include"getfilename.h"
#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
    ofstream eql("equal.csv",ios::out);
    ofstream ineq("inequal.csv",ios::out);
    eql<<"file1"<<','<<"file2"<<endl;
    ineq<<"file1"<<','<<"file2"<<endl;
    vector<string> groupname = getfile("./input");
    for(int i=0;i<groupname.size();i++){
        string curpath="./input/"+groupname[i];
        string PATH=curpath+"/stdin_format.txt";
        vector<string>filename=getfile(curpath);
        for(int i=0;i<filename.size();i++){
            if(filename[i][filename[i].size()-1]=='t'){
                continue;        
            }
            for(int j=i+1;j<filename.size();j++){
                if(filename[j][filename[j].size()-1]=='t'){
                    continue;    
                }
                bool eq=1;
                for(int k=0;k<5;k++){
                    srand(time(NULL)+k);
                    generate(PATH);
                    string command1="g++ "+curpath+'/'+filename[i];
                    system(command1.c_str());
                    system("timeout 0.1s ./a.out <input.txt >ouput1.txt");
                    string command2="g++ "+curpath+'/'+filename[j];
                    system(command2.c_str());
                    system("timeout 0.1s ./a.out <input.txt >ouput2.txt");
                    ifstream opt1("output1.txt");
                    ifstream opt2("output2.txt");
                    char c1,c2;
                    while((c1=opt1.get())!=EOF ||(c2=opt2.get())!=EOF ){
                        if(c1!=c2){
                            eq=0;
                            break;
                        }
                    }
                    if(eq==0){
                        break;
                    }
                }
                string place1=curpath+'/'+filename[i];
                string place2=curpath+'/'+filename[j];
                if(eq){
                    eql<<place1<<','<<place2<<endl;
                }
                else{
                    ineq<<place1<<','<<place2<<endl;
                }
            }
        }
    }
}