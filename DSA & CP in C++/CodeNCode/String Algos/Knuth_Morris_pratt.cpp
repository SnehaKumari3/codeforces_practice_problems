//cp algorithm

//prefix calculation
//trivial algorithm
/*
vector<int> prefix_func(string s){
    int n=(int)s.length();
    vector<int> pi(n);
    for(int i=0;i<n;i++){
        for(int k=0;k<=i;k++){
            if(s.substr(0,k)==s.substr(i-k+1,k));
        }
    }
    return pi;
}

vector<int> prefix_func(string s){
    int n=(int)s.length();
    vector<int> pi(n);
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j]){
            j=pi[j-1];
        }

        if(s[i]==s[j]){
            j++;
        }
        pi[i]=j;
    }
    return pi;
}

*/
