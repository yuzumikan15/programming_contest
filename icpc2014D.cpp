#include <iostream>
#include <map>
#include <string> 
#include <vector>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
 
using namespace std;

string safter;
vector<string> ans;

void solve(int num, string current) { // num: where in the string (current) to check
	int len = current.length();
	char now_c = current[num]; // the character of No. num in the current string
	if (num + 1 > len) { // stop recursion and push_back the choice of the original string (answer)
	vector< string >::iterator cIter = find(ans.begin(), ans.end(), current);

		if( cIter == ans.end() ){ // do not push_back the same string
  			ans.push_back(current);
		}
		
	}
	else if (now_c != 'a' && now_c != 'z') { // characters other than 'a' and 'z'
		// find_first_of: returns -1 if there is no now_c in current
		long it = current.find_first_of (now_c); // the first place now_c appers in current
		long it_next = current.find_first_of(now_c + 1); // the first place the next alphabet of now_c appears
		bool it_b = (it < (long)num && it >= 0); // true if 'it' is before now_c
		bool it_next_b = (it_next < (long)num && it_next >= 0); // true if 'it_next' is before now_c
		// cout << "it_next: " << it_next << endl;
		// cout << "it_b: " << it_b << endl;
		// cout << "it_next_b: " << it_next_b << endl;
		if (it_next_b) {
			if (it_b) { // do not change current and go to the next character

				solve(num + 1, current); 
			}
		}
		else if (!it_next_b) { 
			if (it_b) { // there are two choices whether change or not
				solve(num + 1, current);
				current[num] = current[num] + 1;
				solve(num + 1, current);
			}
			else { // change current
				current[num] = current[num] + 1;

				solve(num + 1, current);
			}
		}
	} 
	else if (now_c == 'z') { 
		long it = current.find_first_of (now_c);
		bool it_b = (it < (long)num && it >= 0);
		if (it_b) { // do not change current and go to the next character
			solve(num + 1, current);
		}
	} 
	else if (now_c == 'a') {
		long it_next = current.find_first_of(now_c + 1);
		bool it_next_b = (it_next < (long)num && it_next >= 0);
		if (it_next_b) {
			solve(num + 1, current);
		} else {
			solve(num + 1, current);
			current[num] = current[num] + 1;
			solve(num + 1, current);
		}
	}

}

int main(int argc, const char * argv[]){

	while(cin >> safter, safter != "#") { // input and output
		init_ab();
		ans.clear();
		solve(0, safter);
		if (ans.empty()) {
			cout << "0" << endl;
		} else {
			sort(ans.begin(), ans.end());
			unsigned long long count = ans.size();
			cout << count << endl;
			if (count > 10) {
			for (int i = 0; i < 5; i++) {
				cout << ans[i] << endl;
			}
			for (int i = count - 5; i < count; i++) {
				cout << ans[i] << endl;
			}
		}
		else {
			for (int i = 0; i < count; i++) {
				cout << ans[i] << endl;
			}

		}
		}

	}
    return 0;
}
