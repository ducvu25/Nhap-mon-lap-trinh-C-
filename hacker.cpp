#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;


string TaoTest(int n, int m){
	string s;
	for(int i=0; i<n; i++)
		s.push_back(char(rand()%9 + 48));
	for(int i=0; i<m; i++){
		int x = rand() %n;
		s[x] = rand() %100;
	}
	return s;
}
int TriSo(string s){
  	int triSo = 0;
  	for(int i=s.size()-1; i>=0; i--)
  		if(s[i] > 57 || s[i] < 48 || (s.size() >= 2 && s[0] == '0'))
  			return TriSo("260");
  		else
    	triSo += (s[i] - 48 + 1)*pow(10, s.size() - 1 - i);
  	return triSo;
}

vector<string> KQ(string s){
  	vector <string> kq;
  	if(s.size() < 4 || s.size() > 12)
  		return kq;
  	for(int i=0; i<s.size(); i++)
  		if(!(s[i] >= 48 && s[i] <= 57))
  			return kq;
  	int triSo = TriSo("255");
  	int start = s.size() / 4;
  	start--;
  	if(start == 0) start++;
  	for(int i1 = start; i1 <= s.size() - 2; i1++)
 		if(TriSo(s.substr(0, i1)) > triSo)
 			break;
 		else
    	for(int i2 = start; i2 <= s.size() - i1 - 1; i2++)
	   		if(TriSo(s.substr(i1, i2)) > triSo)
	   			break;
	   		else
	    		for(int i3 = start; i3 < s.size() - i2 - i1; i3++)
	    			//cout << s.substr(0, i1) + "." + s.substr(i1, i2) + "." + s.substr(i1 + i2, i3) + "." + s.substr(i1 + i2 + i3);
	    			if(TriSo(s.substr(i1 + i2, i3)) > triSo)
	    				break;
	    			else	if(TriSo(s.substr(i1 + i2 + i3)) <= triSo){
		  				string t = s.substr(0, i1) + "." + s.substr(i1, i2) + "." + s.substr(i1 + i2, i3) + "." + s.substr(i1 + i2 + i3);
		  				kq.push_back(t);
					}
	return kq;
}

// Bai 1
int main(){
	string s;
	cin >> s;
	vector <string> kq = KQ(s);
	cout << kq.size() << endl;
	for(int i=0; i<kq.size(); i++)
    		cout << kq[i] << endl;
	return 0;
}
//
//bool check(string s){
//    if(s.length() > 1 && s[0] == '0'){
//        return false;
//    }
//    return TriSo(s) <= TriSo("255");
//}
//int main(){
//	srand(time(0));
//	for(int test = 0; test < 120000; test++){
//		string s = TaoTest(test/10000 + 4, 1);
//		int length = s.length();
//	    vector<string> v;
//	    for(int a = 1; a <= 3; ++a){
//	        for(int b = 1; b <= 3; ++b){
//	            for(int c = 1; c <= 3; ++c){
//	                for(int d = 1; d <= 3; ++d){
//	                    if(a + b + c + d == length){
//	                        string s1 = s.substr(0, a);
//	                        string s2 = s.substr(a, b);
//	                        string s3 = s.substr(a + b, c);
//	                        string s4 = s.substr(a + b + c, d);
//	                        if(check(s1) && check(s2) && check(s3) && check(s4)){
//	                            v.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
//	                        }
//	                    }
//	                }
//	            }
//	        }
//	    }
//	    vector <string> kq = KQ(s);
//	     cout << test << "\t" << s << " " << v.size()  << " " << kq.size() << endl;
//	    if(kq.size() != v.size()){	
//	    	for(int i=0; i<v.size(); i++)
//	    		cout << v[i] << " ";
//	    	cout << endl;
//	    	for(int i=0; i<kq.size(); i++)
//	    		cout << kq[i] << " ";
//	    	break;
//		}
//	    for(int i = 0; i < v.size(); ++i){
//	    	cout << v[i] << " " << kq[i] << endl;
//	    	if(v[i] != kq[i])
//	    		break;
//	    }
//	    cout << endl;
//	}
//    return 0;
//}



