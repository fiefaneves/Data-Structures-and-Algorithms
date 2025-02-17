#include <iostream>
#include <bits/stdc++.h>

#include "list.hpp"

using namespace std;

int main(){
	//create the list
	//create the stack
	int nCases;
	cin >> nCases;
	string op;
	int pos, val, pos1;
	for (int caseNo = 0; caseNo < nCases; caseNo++) {
		cin >> op;
		while (op != "END"){
			if (op=="ADD"){
				cin >> pos >> val;
				/* code */
			}
			else if (op == "DEL"){
				cin >> pos;
				/* code */
			}
			else if (op == "SPL"){
				cin >> pos;
				/* code */
			}
			else if (op == "MER"){
				cin >> pos >> pos1;
				/* code */
			}
			else if (op == "TRA"){
				cin >> pos;
				/* code */
			}
			cin >> op;
		}
		//clear list and stack for the next case
	}
}
