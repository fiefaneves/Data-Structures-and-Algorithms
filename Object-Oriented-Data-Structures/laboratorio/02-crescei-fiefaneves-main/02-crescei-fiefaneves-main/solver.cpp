#include <iostream>
#include <bits/stdc++.h>

#include "list.hpp"

using namespace std;

template <typename T>
int main(){
	freopen("1.in", "r", stdin);

	// SQ<auto> *sq = new SQ<auto>(QUEUE);
	SQ<T> *sq = new SQ<T>(QUEUE);
	int nCases;
	cin >> nCases;
	string op;
	int pos, val, pos1;
	for (int caseNo = 0; caseNo < nCases; caseNo++) {
		cin >> op;
		while (op != "END"){
			if (op=="ADD"){
				cin >> pos >> val;
				sq->push(pos, val);				
			}
			else if (op == "DEL"){
				cin >> pos;
				sq->pop(pos);
			}
			else if (op == "SPL"){
				cin >> pos;
				sq->split();
			}
			else if (op == "MER"){
				cin >> pos >> pos1;
				sq->merge();
			}
			else if (op == "TRA"){
				cin >> pos;
				sq->transform();
			}
			cin >> op;
		}
		cout << "Case " << caseNo << ": " << endl;

	}
}
