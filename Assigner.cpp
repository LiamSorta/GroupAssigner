#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

struct Group {
	vector<string> students;
};

int main() {

	int groupCount;
	int totalStudents = 0;
	int desiredGroups;
	int groupTotal = 0;
	vector<string> allStudents;
	vector<Group> allGroups;

	ifstream inFile("names.txt");
	ofstream outFile("groups.txt");

	cout << "Enter group sizes: ";
	cin >> desiredGroups;

	string line;

	while (getline(inFile, line)) {
		allStudents.push_back(line);
		totalStudents++;
	}

	groupTotal = totalStudents / desiredGroups;
	

	allGroups.resize(groupTotal);

	srand(time(NULL));
	int picker = 0;
	int s = 0;
	while(totalStudents != 0){
		for (int i = 0; i < allGroups.size(); i++) {
			
			if (totalStudents == 0){
				break;
			}
	
			picker = rand() % totalStudents;
			cout << allStudents[picker] << " students left: " << totalStudents << endl;
			allGroups[i].students.push_back(allStudents[picker]);
			allStudents.erase(allStudents.begin()+picker);
			totalStudents--;
			s++;
		}
	}
	
	for (int i = 0; i < allGroups.size(); i++) {
		outFile << "====================" << endl;
		outFile << "Group: " << (i+1) << endl << "====================" << endl;
		for (int b = 0; b < allGroups[i].students.size(); b++) {
			outFile << allGroups[i].students[b] << endl;
		}
		outFile << endl << endl;
	}
	

	inFile.close();
	outFile.close();
	system("pause");

}
