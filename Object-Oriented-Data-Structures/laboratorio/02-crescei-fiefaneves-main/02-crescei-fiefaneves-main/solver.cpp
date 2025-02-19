#include <iostream>
#include <bits/stdc++.h>

#include "list.hpp"

using namespace std;

int main() {
	freopen("1.in", "r", stdin);

	int nCases;
	cin >> nCases;
	string op;
	int pos, val, pos1;
	LinkedList<SQ<int>*> l;
	l.append(new SQ<int>(QUEUE));
	for (int caseNo = 0; caseNo < nCases; caseNo++) {
		cin >> op;
		while (op != "END"){
			if (op == "ADD"){
				cin >> pos >> val;
				if (pos < l.size()){
					l[pos]->push(val);
				}
			}
			else if (op == "DEL"){
				cin >> pos;
				if (pos < l.size()){
					l[pos]->pop();
				}
			}
			else if (op == "SPL"){
				cin >> pos;
				if (pos < l.size()){
					l.insert(pos + 1, l[pos]->split());
				}
			}
			else if (op == "MER"){
				cin >> pos >> pos1;
				if (pos < l.size() && pos1 < l.size() && pos != pos1){
					l[pos]->merge(l[pos1]);
					l.remove(pos1);
				}
			}
			else if (op == "TRA"){
				cin >> pos;
				if (pos < l.size()){
					l[pos]->transform();
				}
			}
			cin >> op;
		}
		cout << "caso " << caseNo << ":";
		for (int i = 0; i < l.size(); i++) {
			cout << " ";
			if (l[i]->size() > 0) {
				cout << l[i]->peek();
			} else {
				cout << "?";
			}
		}
		cout << endl;
		l.clear();
		l.append(new SQ<int>(QUEUE));
	}
}
