#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
void generate(string PATH) {
	string ss;
	ifstream ipt(PATH);
	ofstream opt("input.txt", ios::trunc);
	while (ipt>>ss) {
		if (ss[0] == 'c') {
			int uorl = rand() % 2;
			int which = rand() % 26;
			char out;
			if (uorl) {
				out = 'A' + which;
				opt << out << endl;
			}
			else {
				out = 'a' + which;
				opt << out << endl;
			}
		}
		else if (ss[0] == 'i') {
			int min = 0;
			int max = 0;
			int temp = 1;
			int sig1 = 1;
			int sig2 = 1;
			for (int i = 4; i < ss.length() - 1; i++) {
				if (temp) {
					if (ss[i] == '-') {
						sig1 = -1;
					}
					else if (ss[i] == ',') {
						temp = 0;
					}
					else {
						min = min * 10 + ss[i] - '0';
					}
				}
				else {
					if (ss[i] == '-') {
						sig2 = -1;
					}
					else {
						max = max * 10 + ss[i] - '0';
					}
				}
			}
			min = min * sig1;
			max = max * sig2;
			if (max < min) {
				cout << "int range error";
				exit(-1);
			}
			int out = rand() % (max - min + 1) + min;
			opt << out << endl;
		}
		else if (ss[0] = 's') {
			int min = 0;
			int max = 0;
			int temp = 1;
			for (int i = 7; i < ss.length() - 1; i++) {
				if (temp) {
					if (ss[i] == ',') {
						temp = 0;
					}
					else {
						min = min * 10 + ss[i] - '0';
					}
				}
				else {
					max = max * 10 + ss[i] - '0';
				}
			}
			if (max < min) {
				cout << "string length error";
				exit(-1);
			}
			int length = rand() % (max - min + 1) + min;
			for (int i = 0; i < length; i++) {
				int uorl = rand() % 2;
				int which = rand() % 26;
				char out;
				if (uorl) {
					out = 'A' + which;
					opt << out;
				}
				else {
					out = 'a' + which;
					opt << out;
				}
			}
			opt << endl;
		}
		else {
			cout << "input type error";
			exit(1);
		}
	}
	ipt.close();
	opt.close();
	return;
}