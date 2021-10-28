#pragma once
#include <iostream>
#include <string>
#include <sstream> 
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
using namespace System::Drawing;

bool sortDscStoi(const pair<string, string> a, const pair<string, string> b) { //&
	return stoi(a.second) > stoi(b.second);
}

class Ranking {
private:
	ifstream rFile;
	ofstream cFile;
	vector <pair<string, string>> ranks;
public:
	Ranking() {
		loadRanks();
	}
	~Ranking() {
		rFile.close(); // Safe
		cFile.close(); // Safe
	}

	void loadRanks() {
		string line;
		rFile.open("rankings.txt");
		if (!rFile.is_open()) {
			cFile.open("rankings.txt");
			rFile.open("rankings.txt");
			cFile.close();
		}
		if (rFile.is_open()) {
			while (getline(rFile, line)) {
				addRank(line);
			}
		}
	}
	void saveRanks() {
		cFile.open("rankings.txt");
		for (pair<string, string>rank : ranks) {
			cFile << getString(rank);
		}
		cFile.close();
		rFile.close();
	}
	void addRank(string line) {
		string name, score, temp;
		stringstream ss(line);

		while (ss >> temp) {
			((!name.length()) ? name : score) = temp;
		}

		ranks.push_back(make_pair(name, score));
		sortRanks();
	}
	void addRank(pair<string, string>info) {
		ranks.push_back(make_pair(info.first, info.second));
		sortRanks();
	}
	void sortRanks() {
		sort(ranks.begin(), ranks.end(), sortDscStoi);
	}
	string getString(pair<string, string>rank) {
		return rank.first + " " + rank.second + "\n";
	}
	string getCompleteString() {
		string complete = "";
		for (pair<string, string>rank : ranks) {
			complete += getString(rank);
		}
		return complete;
	}
};