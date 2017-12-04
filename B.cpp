#include <bits/stdc++.h>
using namespace std;

int p;

long long int exp(int n, int m){
    if(m==0) return 1;
    if(m==1) return n;
    long long int x;
    if(m & 1){
        x=exp(n, (m-1)/2);
        x=(x*x)%p;
        x=(x*n)%p;
    }
    else{
        x=exp(n, m/2);
        x=(x*x)%p;
    }
    return x;
}

int main(void){

    long long int k, sum=0, cont=0;
    cin >> k >> p;
    vector< vector <long long int> > zyc;
    int aux;
    vector <long long int > vaux;
    for(int i=0; i<9; i++){
        aux=(11*(i+1))%p;
        sum=(sum+aux)%p;
        vaux.push_back(aux);
        cont++;
    }
    zyc.push_back(vaux);
    if(k<=9) cout << (11*(k*(k+1))/2)%p << "\n";
    else{
        long long int ant=9, act;
        long long int pot=10, ind=1;
        while(cont<k){
            pot=(pot*100)%p;
            ind=1;
            vaux.clear();
            while(ind <10 && cont<k){
                aux=(ind*(pot+1))%p;
                sum=(sum+aux)%p;
                vaux.push_back(aux);
                cont++;
                int s=zyc.size();
                for(int i=0; i<s && cont<k; i++){
                    int s1=zyc[i].size();
                    for(int j=0; j<s1 && cont<k; j++){
                        aux=(ind*(pot+1))%p;
                        aux=(aux+(zyc[i][j]*exp(10, s-i)))%p;
                        sum=(sum+aux)%p;
                        vaux.push_back(aux);
                        cont++;
                    }
                }
                ind++;
            }
            zyc.push_back(vaux);
        }
        cout << sum << "\n";
    }
    return 0;
}

