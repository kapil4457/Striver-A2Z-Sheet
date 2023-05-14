#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mod 1000000007ll //998244353ll
#define mii map<int, int>
#define pii pair<int, int>
int power(int a,int b){int result =1; while(b>0){if(b%2) result*=a; a*=a;b/=2;} return result;}
using namespace std;

class FrequencyTracker {
public:
      // int *freq;
    vector<int>freq;
    map<int,int>ref;
    FrequencyTracker() {
        freq.resize(100001,0);
        ref[-1]=0;
     
        
    }
    
    
    void add(int number) {
        int tempFreq = freq[number]+1;
        if(freq[number]){
        ref[freq[number]]--;
         if(ref[freq[number]]==0){
            ref.erase(freq[number]);
        }
        }
        freq[number]++;
        ref[tempFreq]++;

       
        
    }
    
    void deleteOne(int number) {
        if(freq[number]){
            int currFreq = freq[number]-1;
            ref[freq[number]]--;
            if(ref[freq[number]]==0){
                ref.erase(freq[number]);
            }
            freq[number]--;
            if(currFreq!=0){
            ref[currFreq]++;
            }
     
        }
    }
    
    bool hasFrequency(int frequency) {
       if( ref.find(frequency)!=ref.end()){
           return true;
       }
        return false;
        // for(int i =0 ; i < 100001 ; i ++){
        //     if(freq[i]==frequency)return true;
        // }
        // return false;
    }
};

int main()
{

FrequencyTracker*obj = new FrequencyTracker();
obj->add(5);
obj->add(5);
cout<<obj->hasFrequency(1)<<endl;
cout<<obj->hasFrequency(2)<<endl;
obj->add(6);
obj->add(5);
obj->add(1);

 return 0;
}