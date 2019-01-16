#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono; 

typedef long long ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

void logn(ll number){
    for(long long i=1;i<=number;i*=2){
        continue;
    }
}

void n(ll number){
    for(long long i=0;i<number;i++){
        continue;
    }
}

void nlogn(ll number){
    for(long long i=0;i<number;i++){
        for(long long j=1;j<=number;j*=2){
            continue;
        }
    }
}

void n2(ll number){
    for(long long i=0;i<number;i++){
        for(long long j=0;j<number;j++){
            continue;
        }
    }
}
void solve_hanoi(ll N, string from_peg, string to_peg, string spare_peg)
{
    if (N<1) {
        return;
    }
    if (N>1) {
        solve_hanoi(N-1, from_peg, spare_peg, to_peg);
    }
    // cout<< "move from " + from_peg + " to " + to_peg;
    if (N>1) {
        solve_hanoi(N-1, spare_peg, to_peg, from_peg);
    }
}

void exp2n(ll number){
    string a="A";
    string b="B";
    string c="C";
    solve_hanoi(number, a,b,c);
}

int main()
{
    fastio;
    
    ll number;
    cin>>number;

    auto start = high_resolution_clock::now();
    logn(number);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    
    start = high_resolution_clock::now();
    n(number);
    stop = high_resolution_clock::now(); 
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    
    start = high_resolution_clock::now();
    nlogn(number);
    stop = high_resolution_clock::now(); 
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    
    start = high_resolution_clock::now();
    n2(number);
    stop = high_resolution_clock::now(); 
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    
    start = high_resolution_clock::now();
    exp2n(number);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    
    return 0;
}