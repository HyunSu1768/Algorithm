#include <iostream>
#include <set>
using namespace std;
int main(){
    string a; 
    cin >> a;

    set<string> se;


    string str ="";
    for(int i=0;i<a.size();i++){
        for(int j=i;j<a.size();j++){
            str +=a [j];
            se.insert(str);
        }
        str="";
    }
    cout << se.size();
}