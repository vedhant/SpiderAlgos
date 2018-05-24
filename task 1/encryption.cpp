#include <bits/stdc++.h>
using namespace std;

int k;

string encrypt(string text){
    for(int i = 0;i<text.length();++i){
        if(isalpha(text[i])){
            if(islower(text[i])){
                if(int('z' - text[i]) >= k)
                text[i]+=k;
                else
                text[i] = 'a' - ('z' - text[i]) + k - 1;
            }
            else{
                if('Z' - text[i] >= k)
                text[i]+=k;
                else
                text[i] = 'A' - ('Z' - text[i]) + k - 1;
            }
        }
    }
    return text;
}

string decrypt(string text){
    for(int i = 0;i<text.length();++i){
        if(isalpha(text[i])){
           if(islower(text[i])){
                if(text[i] - 'a' >= k)
                text[i]-=k;
                else
                text[i] = 'z' + (text[i] - 'a') - k + 1;
            }
            else{
                if(text[i] - 'A' >= k)
                text[i]-=k;
                else
                text[i] = 'Z' + (text[i] - 'a') - k + 1;
            } 
        }
    }
    return text;
}

int main() {
	int n;
	cin>>n>>k;
	k %= 26;
	int i;
	for(i=0;i<n;++i){
	    string plaintext;
	    cin>>plaintext;
	    string ciphertext = encrypt(plaintext);
	    cout<<"ciphertext#"<<i+1<<":"<<ciphertext<<endl;
	}
	for(i=0;i<n;++i){
	    string ciphertext;
	    cin>>ciphertext;
	    string plaintext = decrypt(ciphertext);
	    cout<<"plaintext#"<<i+1<<":"<<plaintext<<endl;
	}
	return 0;
}
