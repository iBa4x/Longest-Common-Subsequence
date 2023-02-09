#include<bits/stdc++.h>
using namespace std;

int n; // size of sequence x
vector<char> x; // sequence x

int m; // size of sequence y
vector<char> y; // sequence y

// We asume that n >= m always to use this function

vector<char> sequence; // will always store a new subsequence of maximum size m
vector<char> longestCommonSubsequence; // will always store the last answer that found maximum size m

void findLongestCommonSubsequence(int xi = 0, int yj = 0){ // O(m*2^m)
    
	if(xi == n || yj == m){ // base case
        return;
    }

    findLongestCommonSubsequence(xi, yj+1); // first call

    int count = 0; // use to backtrack how many element added to the sequence.
    
    int i = xi;
    int j = yj;

    while(i != n && j != m){
        if(x[i] == y[j]){
            count++;
            sequence.push_back(x[i]);
            j++;
            findLongestCommonSubsequence(i+1, j); // second call
        }
        i++;
    }

    if(sequence.size() >= longestCommonSubsequence.size()){ // if the sequence is longer then the past sequence replace it.
        longestCommonSubsequence.clear();
        longestCommonSubsequence = sequence;
    }
    
    while(count > 0){ // clear the elements that had been added to the sequence
        sequence.pop_back();
        count--;
    }
}

int main(){
    clock_t z = clock();

    cin >> n >> m;
    x.resize(n);
    y.resize(m);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    for(int i = 0; i < m; i++){
        cin >> y[i];
    }

    findLongestCommonSubsequence();
	
	// print the longest common subsequence
	for(int i = 0; i < longestCommonSubsequence.size(); i++){
        cout << longestCommonSubsequence[i] << " \n"[i == longestCommonSubsequence.size()-1];
    }

    cerr << "Run Time : " << ((double)(clock() - z)/CLOCKS_PER_SEC) << endl; // used to show the run time of using the code
	
	return 0;
}
