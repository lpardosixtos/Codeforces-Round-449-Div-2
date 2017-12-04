#include <bits/stdc++.h>

using namespace std;

int main(void){

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int l, r;
    char c1, c2;
    while(m--){
        cin >> l >> r >> c1 >> c2;
        for(int i=l-1; i<=r-1; i++){
            if(s[i]==c1) s[i]=c2;
        }
    }
    cout << s<< "\n";


    return 0;
}
