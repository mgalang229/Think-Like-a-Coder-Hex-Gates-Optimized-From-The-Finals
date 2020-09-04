#include <bits/stdc++.h>

using namespace std;

string ns, s;

void hexToBinary() {
	for(int j = 0; j < (int) ns.size(); ++j) {
		if(ns[j]=='0') s += "0000";
		else if(ns[j] == '1') s += "0001";
		else if(ns[j] == '2') s += "0010";
		else if(ns[j] == '3') s += "0011";
		else if(ns[j] == '4') s += "0100";
		else if(ns[j] == '5') s += "0101";    
		else if(ns[j] == '6') s += "0110";
		else if(ns[j] == '7') s += "0111";
		else if(ns[j] == '8') s += "1000";
		else if(ns[j] == '9') s += "1001";
		else if(ns[j] == 'A'||ns[j]=='a') s += "1010";
		else if(ns[j] == 'B'||ns[j]=='b') s += "1011";
		else if(ns[j] == 'C'||ns[j]=='c') s += "1100";
		else if(ns[j] == 'D'||ns[j]=='d') s += "1101";
		else if(ns[j] == 'E'||ns[j]=='e') s += "1110";
		else if(ns[j] == 'F'||ns[j]=='f') s += "1111";
	}
}

void test_case() {
	int h, l;
	cin >> h >> l;
	string unlock[h], lock[l];
	for(int i = 0; i < h; ++i) {
		cin >> unlock[i];
	}
	for(int i = 0; i < l; ++i) {
		cin >> lock[i];
	}
	bool p[17];
	memset(p, false, sizeof(p));
	for(int i = 0; i < h; ++i) {
		ns += unlock[i];
		hexToBinary();
		int b[1000], id=0;
		memset(b, 0, sizeof(b));
		reverse(s.begin(), s.end());
		for(int j=0; j < (int) s.size(); ++j) {
		    if(s[j] == '1') b[id+1]++;
		    id++;
        }
        int cnt2 = 0;
        for(int j = 0; j <= id; ++j) {
            if(b[j] == 1) p[cnt2] = true;
            cnt2++;
        }
        ns = s = "";
	}
	cout << "BULBS: ";
	for(int i = 0; i < 17; ++i) {
		if(p[i]) cout << "BULB" << i << " ";
	}
	cout << "\n";
	for(int i = 0; i < l; ++i) {
		ns += lock[i];
		hexToBinary();
		int b[1000], id = 0;
		memset(b, 0, sizeof(b));
		reverse(s.begin(), s.end());
		for(int j = 0; j < (int) s.size(); ++j) {
		    if(s[j] == '1') b[id+1]++;
		    id++;
		}
		int cnt2 = 0;
		for(int j = 0; j <= id; ++j) {
		    if(b[j] == 1) p[cnt2] = false;
		    cnt2++;
		}
		ns = s = "";
    	}
	for(int i = 1; i < 17; ++i) {
		if(i < 10) {
			if(p[i] && i < 10) cout << "DOOR 0" << i << ": true";
			else cout << "DOOR 0" << i << ": false";
		}
		else {
			if(p[i] && i >= 10) cout << "DOOR " << i << ": true";
			else cout << "DOOR " << i << ": false";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//int T;
	//cin >> T;
	//for (int nr = 1; nr <= T; ++nr) {
		//test_case();
	//}
	test_case();
	return 0;
}
