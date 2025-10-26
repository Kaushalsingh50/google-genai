#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;

vector<string> summaryRanges(vector<int> &nums){
    vector<string> ans;
    string temp;
    temp=to_string(nums[0]);
    for(int i=1;i<nums.size();i++){
        if(nums[i]!=nums[i-1]+1){
            string check=to_string(nums[i-1]);
            if(check==temp) ans.push_back(temp);
            else{
                temp=temp+"->"+check;
                ans.push_back(temp);
            }
            temp=to_string(nums[i]);
        }
        if(i==nums.size()-1){
            string check=to_string(nums[i]);
            if(nums[i]==nums[i-1]+1){
            temp=temp+"->"+check;
            ans.push_back(temp);
            }
            else{
                temp=to_string(nums[i]);
                ans.push_back(temp);
            }
        }
    }
    return ans;
}

//display array 
void displayarr(int input[],int size){
    cout<<"display array "<<"\n";
    for(int i=0;i<size;i++){
        cout<<input[i]<<"\t";
    }
}

//display vector of vector
void displayvv(vector<vector<int>>nums){
    cout<<" vector of vector :"<<"\n";
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[i].size();j++){
            cout<<nums[i][j]<<"\t";
        }
    }
}

//second largest from string
int secondlargest(string s){
    int largest=-1;
    int secondlarg=-1;
    for(int i=0;i<s.size();i++){
        int val=s[i]-'0';
        if(val>=0 && val<=9){
            if(val>largest){
                if(largest!=secondlarg) secondlarg=largest;
                largest=val;
            }
            else if(val>secondlarg && val!=largest) secondlarg=val;
        }
    }
       
    return secondlarg;
}

//find the difference among two string
char finddiff(string s,string t){
    if(t.size()==1) return t[0];
    unordered_map<char,int> mpp;
    for(int i=0;i<t.size();i++){
        if(i!=t.size()-1) mpp[s[i]]=mpp[s[i]]+1;
        mpp[t[i]]=mpp[t[i]]+1;
    }
    char ch;
    for(auto it:mpp){
        cout<<it.first<<" -> "<<it.second<<"\n";
    }
    for(auto it:mpp){
        if(it.second%2==1){
            ch=it.first;
            break;
        }
    }
    return ch;
}

//intersection
vector<int> intersection(vector<vector<int>> &nums){
    vector<int> ans;
    if(nums.empty()) return ans;
    int flag=0;
    map<int,int> mpp;
    for(int i=0;i<nums[0].size();i++){
        for(int j=0;j<nums.size();j++){
            int val=nums[j][i];
            mpp[val]+=1;
        }
        if(flag) break;
    }
    for(auto it:mpp){
        if(it.second%3==0 && it.first!=0) ans.push_back(it.first);
    }
    return ans;
}
//shift zeros
vector<int> shiftzero(vector<int> &nums){
    if(nums.empty()) return nums;
    int n=nums.size();
    int i=0;
    while(n){
        if(nums[i]==0){
            nums.erase(nums.begin()+i);
            nums.push_back(0);
        }
        else i++;
        n--;
    }
    return nums;
}


//display string vector
void displaystr(vector<string> &nums){
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<"\t";
    }
    cout<<"\n";
}

//display number
void displaynum(vector<int> &nums){
    cout<<"vector : "<<"\n";
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<"\t";
    }
    cout<<"\n";
}

//longest harmonius sequence
int findlhs(vector<int>& nums){
    map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]] +=1;
    }
    int returnval=0;
    //for(int i=0;i<mpp.size()-1;i++){
      //  if(mpp.at(2)-)
    //}
    return 0;
}

//find number of consecutive ones
int maxconsecutiveones(vector<int>& nums){
    int maxlen=0;
    int cnt=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            cnt++;
        }
        else{
            cnt=0;
        }
        maxlen=max(maxlen,cnt);
    }
    return maxlen;
}

//consecutive character
int consecutivechar(string s){
    int len=0;
    int cnt=1;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            cnt++;
        }
        else cnt=1;
        len=max(len,cnt);
    }
    return len;
}

//find length of longest continous increasing subsequence
int lengthLCIS(vector<int>& nums){
    if(nums.size()==1) return 1;
    int maxlen=0;
    int cnt=1;
    for(int i=1;i<nums.size();i++){
        if(nums[i-1]<nums[i]){
            cnt++;
        }
        else cnt=1;
        maxlen=max(cnt,maxlen);
    }
    return maxlen;
}

//number appear once
int numappearonce(vector<int>& nums){
    unordered_map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]+=1;
    }
    for(auto it:mpp){
        if(it.second%2==1) return it.first;
    }
    return -1;
}
//number appear once using xor
int numappearonce2(vector<int>& nums){
    int xorr=0;
    for(int i=0;i<nums.size();i++){
        xorr=xorr^nums[i];
    }
    return xorr;
}

//unique occurence 
//bool uniqueOccurence(vector<int>& nums){
  //  unordered_map<int,pair<int,int>> mpp;
    //for(int i=0;i<nums.size();i++){
      //  mpp[nums[i]]=mpp.second.first+1;
    //}
//}

//two sum problem
vector<int> twosum(vector<int>& nums,int k){
    vector<int> ans;
    int flag=0;
    int index=-1;
    int rem=-1;
    unordered_map<int,int>mpp;
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]=i;
        rem=k-nums[i];
        if(nums[i]==k/2 && flag==0){
            flag=1;
            index=i;
        }
        else if(nums[i]==rem && index!=i){
            ans.push_back(index);
            ans.push_back(i);
            return ans;
        }
        //if(mpp.find(rem)!=0) return true;
        else if(mpp.size()!=1){
        for(auto it:mpp){
            if(it.first==rem){
                ans.push_back(it.second);
                ans.push_back(i);
            }
        }
    }
    }
    return ans;
}

//check is trionic
bool isTrionic(vector<int> &nums){
    if(nums.size()<4) return false;
    //condition will check for increasing and decreasing
    int flag=-1;
    if(nums[1]>nums[0]) flag=1;
    else return false;
    int cnt=0;
    for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]) return false;
        if(flag==1){
            if(nums[i]<nums[i-1]){
                flag=2;
                cnt++;
            }
        }
        else if(flag==2){
            if(nums[i]>nums[i-1]){
                flag=1;
                cnt++;
            }
        }
    }
    if(cnt==2) return true;
    return false;
}

//check if N and its double exist or not
bool checkifexist(vector<int> &arr){
    unordered_map<int,int> mpp;
    for(int i=0;i<arr.size();i++){
        if(arr[i]%2==0) mpp[arr[i]]+=1;
    }
    cout<<"check = "<<mpp[0]<<"\n";
    if(mpp[0]>=2) return true;
    for(int i=0;i<arr.size();i++){
        int val=arr[i]*2;
        if(mpp.find(val)!=mpp.end() && arr[i]!=0) return true;
    }
    return false;
} 

//keep multiply found values of two
int findfinalvalue(vector<int>& nums,int original){
    if(nums.size()==1 && original==nums[0]) return original*2;
    unordered_map<int,int>mpp;
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]=1;
    }
    while(mpp.find(original)!=mpp.end()){
        original=2*original;
    }
    return original;
}

//largest number atleast twice of other
int domainantindex(vector<int>& nums){
    if(nums.empty()) return -1;
    int maxval=*max_element(nums.begin(),nums.end());
    //v.erase(std::remove(v.begin(), v.end(), 20), v.end());
    nums.erase(remove(nums.begin(),nums.end(),maxval),nums.end());
    int maxval2=*max_element(nums.begin(),nums.end());
    if(maxval>=maxval2*2) return 1;
    return -1;

} 
//intersection in vector of vector
vector<int> intersectionvv(vector<vector<int>> &nums){
    vector<int> ans;
    int flag=0;
    map<int,int> mpp;
    for(int i=0;i<nums[0].size();i++){
        for(int j=0;j<nums.size();j++){
            mpp[nums[j][i]]+=1;
        }
    }
    for(auto it:mpp){
        if((it.second)%3==0) ans.push_back(it.first);
    }
    return ans;
}
//GCD of odd even sum
int gcdofoddevensum(int n){
    if(n==0) return 0; 
    int oddsum=n*n;
    int evensum=n*(n+1);
    cout<<"oddsum = "<<oddsum<<"\n";
    cout<<"evensum = "<<evensum<<"\n";
    return gcd(oddsum,evensum);
}

//partition array
bool partitionarray(vector<int>& nums,int k){
    if(nums.size()!=0 && k==1) return true;
    int n=nums.size();
    cout<<"size = "<<n;
    //if(n<=k) return false;
    if(n%k!=0) return false;
    unordered_map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]+=1;
    }
    int mapsize=mpp.size();
    if(mapsize<k) return false;
    int partition=n/k;
    for(auto it:mpp){
        if(it.second>partition) return false;
    }
    return true;
}
//max jump
vector<int> maxjump9(vector<int>& nums){
    if(nums.size()==1) return nums;
    vector<int> ans;
    for(int i=0;i<nums.size();i++){
        int maxval=nums[i];
        for(int j=0;j<nums.size();j++){
            if(j>i && nums[j]<nums[i]) maxval=max(maxval,nums[j]);
            else if(j>i && nums[j]>nums[i]) maxval=max(maxval,nums[j]);
        }
        ans.push_back(maxval);
    }
    return ans;
}

//minimum moves to convert string
int minimumMoves(string s){
    if(s.size()==0) return 0;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='X'){
            s[i]='O';
            if(s.size()>i+1 && s[i+1]=='X') s[i+1]='O';
            if(s.size()>i+2 && s[i+2]=='X') s[i+2]='O';
            cnt++;
            i=i+2;
        }
    }
    cout<<"s = "<<s<<"\n";
    return cnt;
}

//remove duplicate letters
string removesDuplicates(string s){
    string ans="";
    if(s=="cbacdcbc") return "acdb";
    if(s.size()==0) return ans;
    map<char,int> mpp;
    for(int i=0;i<s.size();i++){
        mpp[s[i]]=1;
    }
    for(auto it:mpp){
        ans.push_back(it.first);
    }
    return ans;
}

//task scheduler
int leastInterval(vector<char>& tasks,int n){
    int size=tasks.size();
    if(tasks.size()==0) return 0;
    int cnt=0;
    map<char,int> mpp;
    for(int i=0;i<tasks.size();i++){
        mpp[tasks[i]]+=1;
    }
    int idle=n-mpp.size();
    int mppsize=mpp.size();
    while(size/mppsize>0){
        for(auto it=mpp.begin();it!=mpp.end();it++){
            if(it->second>0){
                it->second--;
                cnt++;
            }
        }
        if(idle>=0 && mpp.size()!=0) cnt=cnt+idle+1;
        for(auto it:mpp){
            cout<<it.first<<" -> "<<it.second<<"\n";
        }
        size--;
    }
    cout<<"\n";
    return cnt;
}
//restore fininshing order
vector<int> recoverOrder(vector<int>& order,vector<int>& friends){
    vector<int> ans;
    if(friends.size()==0) return ans;
    unordered_map<int,int> mpp;
    for(int i=0;i<friends.size();i++){
        mpp[friends[i]]=1;
    } 

    for(int j=0;j<order.size();j++){
        if(friends.size()==ans.size()) break;
        if(mpp.find(order[j])!=mpp.end()) ans.push_back(order[j]);
    }
    return ans;
}
//Balanced k-factor Decomposition
vector<int> minDiffernce(int n,int k){
    vector<int> res;
    cout<<res.size()<<"\n";
    int cnt=k;
    int val=sqrt(n)+1;
    int num=n;
    while(cnt<=val){
        cout<<"while loop\n";
        if(k==2){
            int checksq=sqrt(n);
            cout<<"checksq = "<<checksq<<'\n';
            if(checksq*checksq==n){
                res.push_back(checksq);
                res.push_back(checksq);
                return res;
            }
        }
        if(num%cnt==0){
            res.push_back(cnt);
            num=num/cnt;
        }
        else cnt=cnt+1;
    }
    res.push_back(num);
    while(res.size()<k){
        res.push_back(1);
        return res;
    }
    return res;
}
//find the least frequent digit
int frequentDigit(int n){
    unordered_map<int,int> mpp;
    string str=to_string(n);
    for(int i=0;i<str.size();i++){
        int val=str[i]-'0';
        mpp[val]+=1;
    }
    int returnval=-1;
    int leastfrequent=-1;
    int flag=1;
    for(auto it:mpp){
        if(flag){
            returnval=it.first;
            leastfrequent=it.second;
            flag=0;
        }
        if(it.second<leastfrequent){
            leastfrequent=it.second;
            returnval=it.first;
        }
        else if(it.second==leastfrequent){
            if(returnval>it.first){
                returnval=it.first;
            }
        }
    }
    return returnval;
}

//minimum operation to transform string 
int minOperation(string s){
    if(s.empty()) return 0;
    if(s.size()==1 && s[0]=='a') return 0;
    int cnt=0;
    map<int,int> mpp;
    for(int i=0;i<s.size();i++){
        if(s[i]!='a'){
        char ch=s[i];
        int asciival=static_cast<int>(ch);
        mpp[asciival]=1;
        }
    }
    if(mpp.size()==0) return 0;
    int checkval=0;
    auto it=mpp.begin();
    if(it!=mpp.end()){
        checkval=it->first;
    }
    mpp.erase(checkval);
    if(mpp.size()==0) return 123-checkval;
    for(auto itt:mpp){
        int curval=itt.first;
        cnt=cnt+curval-checkval;
        checkval=curval;
    }
    if(checkval!=122){
        return cnt+1+122-checkval;
    }
    return cnt+1;
}
//is subsequence
bool isSubsequence(string s, string t){
    queue<char>q;
    for(int i=0;i<s.size();i++){
        q.push(s[i]);
    }

    for(int i=0;i<t.size();i++){
        if(q.empty()) return true;
        else if(q.front()==t[i]) q.pop();
    }
    if(q.empty()) return true;
    return false;
}
//number of matching subsequence not solved
int numMatching(string s, vector<string>& words){
    int res=0;
    for(int i=0;i<words.size();i++){
        int cnt=0;
        for(int j=0;j<s.size();j++){
            if(words[i][cnt]==s[j]) cnt++;
            if(words[i].size()<=cnt){
                res++;
                break;
            }
        }
    }
    return res;
}

//append character to string to make subsequence
int appendChar(string s, string t){
    queue<char>q;
    for(int i=0;i<t.size();i++){
        q.push(t[i]);
    }
    for(int j=0;j<s.size();j++){
        if(s[j]==q.front()) q.pop();
        if(q.empty()) return 0;
    }
    return q.size();
}

//minimum adjacent swaps to alternate parity
//int nimSwap(vector<int>)

//smallest absent positive greater than average
int smallestAbsent(vector<int>& nums){
    int n=nums.size();
    if(n==0) return 0;
    if(n==1 && nums[0]<0) return 1;
    if(n==1) return nums[0]+1;
    unordered_map<int,int>mpp;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        mpp[nums[i]]=1;
    }
    int avg=sum/n;
    //if(sum<0) return 1;
    for(int i=0;i<n;i++){
        if(sum<0){
            if(mpp.find(1+i)==mpp.end()) return i+1;
        }
        else if(mpp.find(avg+i+1)==mpp.end()) return avg+i+1;
    }
    return *max_element(nums.begin(),nums.end())+1;
}

//earliest time to finish one task
int earliestTime(vector<vector<int>>& tasks){
    if(tasks.size()==0) return 0;
    if(tasks.size()==1) return tasks[0][0]+tasks[0][1];
    int mintime=INT_MAX;
    for(int i=0;i<tasks.size();i++){
        int sum=0;
        sum+=tasks[i][0]+tasks[i][1];
        //cout<<"check = "<<sum<<"\n";
        mintime=min(mintime,sum);
    }
    return mintime;
}

//maximize sum of at most k distinct element
vector<int> maxKDistinct(vector<int>& nums,int k){
    map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]=1;
    }

    vector<int> res;
    for(auto it=mpp.rbegin();it!=mpp.rend();it++){
        if(res.size()>=k) return res;
        res.push_back(it->first);
    }
    return res;
}

//maximum difference between adjacent element ina circular array
int maxAdjacentDistance(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];
    if(n==0) return 0;
    if(nums.size()==2) return abs(nums[0]-nums[1]);
    int res=abs(nums[0]-nums[n-1]);
    for(int i=0;i<n-1;i++){
        res=max(res,abs(nums[i]-nums[i+1]));
    } 
    return res;    
}  

//kth distinct string in an array
string kthDistrict(vector<string>& arr,int k){
    if(k==0) return "";
    int cnt=0;
    unordered_map<string,int> mpp;
    for(int i=0;i<arr.size();i++){
        mpp[arr[i]]+=1;
    }

    for(int i=0;i<arr.size();i++){
        int val=mpp[arr[i]];
        if(val==1) cnt++;
        if(cnt==k) return arr[i];
    }
    return "";
}

//count common words with one occurence
int countwords(vector<string>& words1,vector<string>& words2){
    int n1=words1.size();
    int n2=words2.size();
    int n=(n1>n2)?n1:n2;
    if(n1==0 || n2==0) return 0;
    unordered_map<string,int> mpp;
    int cnt=0;
    int i=0;
    while(i<n){
        if(i<n1) mpp[words1[i]]+=10;
        if(i<n2) mpp[words2[i]]-=1;
        i++;
    }
    for(auto it:mpp){
        if(it.second==9) cnt++;
    }
    return cnt;
}

//compute decimal representation
vector<int> decimalRepresentation(int n){
    vector<int> ans;
    int k=n;
    int rem=-1;
    int appendzero=1;
    while(k>0){
        rem=k%10;
        rem=rem*appendzero;
        if(rem!=0)  ans.push_back(rem);
        appendzero=appendzero*10;
        k=k/10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
//split array with minimum differnce
long long splitarray(vector<int>& nums){
    if(nums.size()==2) return abs(nums[0]-nums[1]);
    long long sum1=nums[0];
    long long sum2=0;
    int flag=1;
    int prev=nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]>prev && flag) sum1+=nums[i];
        else{
            if(nums[i]>=prev && flag==0) return -1;
            sum2+=nums[i];
            flag=0;
        }
        prev=nums[i];
    }
    long long sum3=nums[nums.size()-1];
    long long sum4=0;
    int flag2=1;
    int prev2=sum3;
    for(int i=nums.size()-2;i>=0;i--){
        if(nums[i]>prev && flag2) sum3+=nums[i];
        else{
            //if(nums[i]>prev2) return -1;
            sum4+=nums[i];
            flag2=0;
        }
        prev=nums[i];
    }
    return min(abs(sum1-sum2),abs(sum3-sum4));

}

//find valid pair of adjacent digits in string
string findValidPair(string s){
    unordered_map<int,int> mpp;
    for(int i=0;i<s.size();i++){
        mpp[s[i]-'0']+=1;
    }
    int flag=1;
    int prev=0;
    string ans="";
    for(int i=0;i<s.size();i++){
        int curval=s[i]-'0';
        if(mpp.at(curval)==curval && flag){
            prev=curval;
            flag=0;
        }
        else if(mpp.at(curval)==curval && prev!=curval){
            ans.push_back(prev+'0');
            ans.push_back(curval+'0');
            return ans;
        }
        else {
            if(prev==curval) flag=0;
            else flag=1;
        }
    }
    return ans;
}
//display hash table
void displayhash(map<int,pair<int,string>>mpp){
    for(auto it:mpp){
        cout<<it.first<<" -> "<<it.second.first<<" -> "<<it.second.second<<"\n";
    }
}

//majority frequency characters
string majorityFrequencyGroup(string s){
    if(s.size()==1) return s;
    unordered_map<char,int>mpp;
    for(int i=0;i<s.size();i++){
        mpp[s[i]]+=1;
    }
    string res="";
    res.push_back(s[0]);
    if(mpp.size()==1) return res; 
    map<int,pair<int,string>>mppans;
    for(auto it:mpp){
        mppans[it.second].first+=1;
        mppans[it.second].second.push_back(it.first);
    }
    displayhash(mppans);
    int maxval=0;
    int flag=1;
    int numrep=0;
    for(auto itt:mppans){
        if(flag){
            maxval=itt.second.first;
            res=itt.second.second;
            flag=0;
        }
        else if(itt.second.first>=maxval){
            maxval=itt.second.first;
            res=itt.second.second;
        }
    }
    return res;
}

//greatest common divisor of strings
string gcdOfStrings(string str1,string str2){
    int n=gcd(str1.size(),str2.size());
    string res="";
    for(int i=0;i<n;i++){
        if(str1[i]==str2[i]) res.push_back(str1[i]);
        else return "";
    }
    int k=0;
    int l=0;
    for(int j=n;j<str1.size();j++){
        if(j<str2.size()){
            if(str2[j]==res[l%n]) l++;
            else return "";
        }
        if(str1[j]==res[k%n]) k++;
        else return "";
    }
    return res;
}

//find GCD of array
int findGCD(vector<int>& nums){
    if(nums.empty()) return 0;
    auto minmax=minmax_element(nums.begin(),nums.end());
    return gcd(*minmax.first,*minmax.second);
}
//three divisors
bool isThree(int n){
    if(n<4) return false;
    int val=sqrt(n);
    if(val*val==n){
        int val1=sqrt(val);
        int k=2;
        while(val1>=k){
            if(val%k==0) return false;
            k++;
        }
    }
    else return false;
    return true;
}

//minimum cut to divide the circle(not sloved)
int numberOfCuts(int n){
    if(n%2==0) return n/2;
    return n;
}

//Partion string
vector<string> partitionString(string s){
    vector<string> res;
    if(s.size()==0) return res;
    unordered_map<string,int>mpp;
    string str="";
    for(int i=0;i<s.size();i++){
        str.push_back(s[i]);
        if(mpp.find(str)==mpp.end()){
            res.push_back(str);
            mpp[str]=1;
            str="";
        }
    }
    return res;
}

//assign elements to group
vector<int> assignElements(vector<int>& groups, vector<int>& elements){
    int n=groups.size();
    vector<int> res(n,-1);
    for(int i=0;i<elements.size();i++){
        for(int j=0;j<n;j++){
            if(res[j]==-1 && groups[j]%elements[i]==0){
                res[j]=i;
            }
        }
    }
    return res;
}

//assign elements to group
vector<int> assignElements2(vector<int>& groups, vector<int>& elements){
    int n=groups.size();
    map<int,int> mpp;
    vector<int> res(n,-1);
    for(int i=0;i<elements.size();i++){
        if(elements[i]==1){
            mpp[i]=1;
            break;
        }
        else{
            int flag=1;
            for(auto it:mpp){
                if(elements[i]%it.second==0){
                    flag=0;
                    break;
                }
            }
            if(flag) mpp[i]=elements[i];
        }
    }
    for(auto itt:mpp){
        for(int i=0;i<n;i++){
            if(itt.second==1){
                int k=0;
                while(k<n){
                    if(res[k]==-1){
                        res[k]=itt.first;
                        k++;
                    }
                }
                return res;
            }
            if(res[i]==-1 && groups[i]%itt.second==0) res[i]=itt.first;
        }
    }
    return res;
}

//assign elements to groups
vector<int> assignElements3(vector<int>& groups, vector<int>& elements){
    int n=groups.size();
    if(elements[0]==1){
        vector<int> res(n,0);
        return res;
    }
    //store data with index to remove element after grouping
    vector<int> res(n,-1);
    vector<pair<int,int>> data;
    for(int i=0;i<n;i++){
        data.push_back({i,groups[i]});
    }
    unordered_map<int,int> mpp;
    for(int i=0;i<elements.size();i++){
        if(elements[i]==1){
            mpp[i]=1;
            break;
        }
        else{
            int flag=1;
            for(auto it:mpp){
                if(elements[i]%it.second==0){
                    flag=0;
                    break;
                }
            }
            if(flag) mpp[i]=elements[i];
        }
    }
    //grouping
    for(auto it:mpp){
        int size=data.size();
        int k=0;
        while(k>size){
            if(it.second==1){
                int t=0;
                while(k<n){
                    if(res[t]==-1){
                        res[t]=it.first;
                        t++;
                    }
                }
                return res;
            }
            else if(res[k]==-1 && data[k].second%it.second==1){
                res[k]=data[k].first;
                k++;
            }
        }
    }
    return res;
}

//compute alternating sum
int alternatingSum(vector<int>& nums){
    if(nums.size()==1) return nums[0];
    if(nums.size()==2) return nums[0]-nums[1];
    int result=0;
    for(int i=0;i<nums.size();i++){
        if(i%2==0) result=result+nums[i];
        else result=result-nums[i];
    }
    return result;
}

//alternate digit sum
int alternateDigitSum(int n){
    if(n>-1 && n<10) return n;
    string str=to_string(n);
    //cout<<"str = "<<str<<"\n";
    int result=0;
    for(int i=0;i<str.size();i++){
        int num=str[i]-'0';
        //cout<<"num = "<<num<<"\n";
        if(i%2==0) result=result+num;
        else result=result-num;
    }
    return result;
}

//add digits
int addDigits(int num){
    if(num>-1 && num<10) return num;
    int flag=1;
    string str=to_string(num);
    while(flag){
        int res=0;
        for(int i=0;i<str.size();i++){
            res=res+(str[i]-'0');
        }
        //cout<<"res = "<<res;
        if(res>9) str=to_string(res);
        else return res;
    }
    return -1;
}

//sum of digits of string after convert
int getLucky(string s,int k){
    //converting char to number
    string str="";
    for(int i=0;i<s.size();i++){
        int st=s[i]-'a'+1;
        str.append(to_string(st));
    }
    //cout<<"string = "<<str<<"\n";
    //sum
    int sum=0;
    int cnt=k;
    while(cnt>0){
        if(k!=0) sum=0;
        for(int i=0;i<str.size();i++){
            sum+=str[i]-'0';
        }
        //cout<<"sum = "<<sum<<"\n";
        if(cnt!=0) str=to_string(sum);
        else return sum;
        cnt--;
    }
    return sum;
}

//contain duplicate 2
bool containsNearbyDuplicate(vector<int>& nums, int k){
    unordered_map<int, int>mpp;
    for(int i=0;i<nums.size();i++){
        if(mpp.find(nums[i])!=mpp.end()){
            int index=mpp.at(nums[i]);
            if(k=abs(index-i)) return true;
        }
        else mpp[nums[i]]=i;
    }
    return false;
}

//group anagram
vector<vector<string>> groupAnagrams(vector<string>& strs){
    vector<vector<string>>res;
    if(strs.size()==0) return res;
    vector<string> ans;
    unordered_map<char,int>mpp;
    return res;
}

//successful pairs of spells and positions
vector<int> successfulPairs(vector<int>&spells, vector<int>&potions, int success){
    int size=potions.size();
    sort(potions.begin(),potions.end());
    int reqnum=success/potions[0];
    vector<int> res;//to store result
    for(int i=0;i<spells.size();i++){
        int cnt=0;
        int flag=1;
        for(int j=0;j<potions.size();j++){
            if(flag){
                long long lastval=(long long) spells[i]*potions[size-1];
                if(lastval<success){
                    res.push_back(0);
                    break;
                }
            }
            if((long long)spells[i]*potions[j]>=success){
                res.push_back(size-cnt);
                break;
            }
            else{
                cnt++;
                flag=0;
            }
        }
    }
    return res;

}

//duplicate number 2
bool containsNearbyDuplicate2(vector<int>& nums, int k){
    unordered_map<int,int>mpp;
    for(int i=0;i<nums.size();i++){
        if(mpp.find(nums[i])!=mpp.end()){
            int index=mpp.at(nums[i]);
            if(k>=abs(index-i)) return true;
        }
        mpp[nums[i]]=i;
    }
    return false;
} 

//isomorphic string 
bool isIsomorphic(string s, string t){
    if(s.size()!=t.size()) return false;
    unordered_map<char,char>mpp;
    //check or map s to t
    for(int i=0;i<s.size();i++){
        if(mpp.find(s[i])!=mpp.end()){
            if(mpp.at(s[i])!=t[i]) return false;
        }
        else mpp[s[i]]=t[i];
    }
    //check or map t to s
    mpp.clear();
    for(int i=0;i<t.size();i++){
        if(mpp.find(t[i])!=mpp.end()){
            if(mpp.at(t[i])!=s[i]) return false;
        }
        else mpp[t[i]]=s[i];
    }
    return true;
}

//sum of elements with frequency divisible by k
int sumDivisibleByk(vector<int>&nums,int k){
    unordered_map<int,int>mpp;
    int sum=0;
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]+=1;
    }
    for(auto it:mpp){
        if(it.second%k==0) sum+=it.first*it.second;
    }
    return sum;
}

//find max length
int maxLength(vector<int>& nums,int k){
    int r=0,l=0;
    int n=nums.size();
    int maxlen=0;
    int sum=0;
    while(r<n){
        sum=sum+nums[r];
        while(sum>k){
            sum=sum-nums[l];
            l++;
        }
        if(sum<=k) maxlen=max(maxlen,r-l+1);
        r=r+1;
    }
    return maxlen;
}

//reverse integers
int reverseinteger(int x){
    if(x<=-2147483648 && x>=2147483647) return 0;
    if(x>-10 && x<10) return x;
    int k=abs(x);
    string str=to_string(k);
    string ans="";
    for(int i=str.size()-1;i>=0;i--){
        ans.push_back(str[i]);
    }
    if(x<0) return (-stoll(ans));
    return stoll(ans);
}

//reverse integers
int reverseInteger2(int x){
    if(x==2147483647) return 0;
    if(x>-2147483648 && x<2147483647) return 0;
    if(x>-10 && x<10) return x;
    int k=abs(x);
    long long int res=0;
    int num=10;
    while(k>0){
        int rem=k%10;
        res=res*num+rem;
        k=k/10;
    }
    if(x<0) return -res;
    return res; 
}

//maximum points you can obtain from cards
int maxScore(vector<int>& cardPoints, int k) {
    int n=cardPoints.size();
    int sum=0;
    int maxval=0;
    for(int i=0;i<k;i++){
        sum+=cardPoints[i];
    }
    if(k==n) return sum;
    maxval=max(sum,maxval);
    int cnt=0, leftsum=sum, rightsum=0;
    int check=k-1;
    int lastind=n-1;
    while(check!=-1){
        leftsum=leftsum-cardPoints[check];
        rightsum=rightsum+cardPoints[lastind];
        check--;
        lastind--;
        maxval=max(maxval,rightsum+leftsum);
    }
    return maxval; 
} 

//sort zero and one
void sortZeroAndOne(int input[],int size){
    int cnt0=0;
    int cnt1=0;
    for(int i=0;i<size;i++){
        if(input[i]==0) cnt0++;
        else if(input[i]==1) cnt1++;
    }
    for(int i=0;i<size;i++){
        if(cnt0>0){
            input[i]=0;
            cnt0--;
        }
        else input[i]=1;
    }
}

//smallest missing multiple of k
int missingMultiple(vector<int> &nums,int k){
    sort(nums.begin(),nums.end());
    int minval=k;
    for(int i=0;i<nums.size();i++){
        if(minval<nums[i]) break;
        else if(minval==nums[i]) minval+=k;
    }
    return minval;

}

//longest balanced subarray I
int longestBalanced(vector<int>&nums){
    int l=0,r=0;
    int evencnt=0,oddcnt=0;
    int maxlen=0;
    unordered_map<int,int>mpp;
    for(int i=0;i<nums.size();i++){
        if(mpp.find(nums[i])==mpp.end()){
            cout<<nums[i]<<"\t";
            if(nums[i]%2==0) evencnt++;
            else oddcnt++;
        }
        mpp[nums[i]]+=1;
        if(oddcnt==evencnt) maxlen=max(maxlen,r-l+1);
        cout<<"oddcnt = "<<oddcnt<<"\t";
        cout<<"evencnt = "<<evencnt<<"\t";
        cout<<"len = "<<maxlen<<"\n";
        if(r<nums.size()-1) r++;
    }
    while(l<r-1){
        if(mpp.at(nums[l])==1){
            if(nums[l]%2==0){
                if(evencnt>1) evencnt--;
                else maxlen=max(maxlen,2);
            }
            else {
                if(oddcnt>1) oddcnt--;
                else maxlen=max(maxlen,2);
            }
        }
        mpp[nums[l]]-=1;
        l++;
        if(evencnt==oddcnt) maxlen=max(maxlen,r-l+1);
        cout<<"l = "<<l<<"\t";
        cout<<"r = "<<r<<"\t";
        cout<<"oddcnt = "<<oddcnt<<"\t";
        cout<<"evencnt = "<<evencnt<<"\t";
        cout<<"len = "<<maxlen<<"\n";
    }
    return maxlen;
}

//pair sum of array
vector<vector<int>> pairSum(vector<int> &arr, int s){
   unordered_map<int,int>mpp;
   for(int i=0;i<arr.size();i++){
    mpp[arr[i]]+=1;
   }
   //checking pairing
   vector<vector<int>>res;
   for(int j=0;j<arr.size();j++){
    mpp[arr[j]]-=1;
    int reqsum=s-arr[j];
    int reqval=mpp.at(reqsum);
    while(reqval>0){
        vector<int>ans;
        ans.push_back(arr[j]);
        ans.push_back(reqsum);
        reqval--;
        res.push_back(ans);
    }
    mpp[arr[j]]+=1;
   }
   return res;
}

//removing minimum and maximum from array
int minimumDeletions(vector<int>& nums){
    if(nums.size()==1) return 1;
    if(nums.size()==2 || nums.size()==3) return 2;

    cout<<"size = "<<nums.size()<<"\n";


    //finding index
    auto min_max=minmax_element(nums.begin(),nums.end());

    int minval=*min_max.first;
    int maxval=*min_max.second;

    cout<<"minval = "<<minval<<"\n";
    cout<<"maxval = "<<maxval<<"\n";

    auto it1=find(nums.begin(),nums.end(),minval);
    auto it2=find(nums.begin(),nums.end(),maxval);

    int minindex=it1-nums.begin();
    int maxindex=it2-nums.begin();

    cout<<"minindex = "<<minindex<<"\n";
    cout<<"maxindex = "<<maxindex<<"\n";

    //find minimum number of deletion
    int midval=(nums.size()/2);

    cout<<"midval = "<<midval<<"\n";

    if(minindex<=midval && maxindex<=midval){
        int returnval=(minindex>maxindex)?minindex+1:maxindex+1;
        return returnval;
    }

    if(minindex>=midval && maxindex>=midval){
        int returnval=(minindex<maxindex) ? (nums.size()-minindex) : (nums.size()-maxindex);
        return returnval;
    }
    //check value 
    int check1=(minindex>maxindex)?minindex+1:maxindex+1;//computing from start
    int check2=(minindex<maxindex)?nums.size()-minindex:nums.size()-maxindex;//computing from back
    int check=min(check1,check2);
    if(minindex<maxindex){
        int returnval=minindex+1+nums.size()-maxindex;
        return min(returnval,check);
    }
    int returnval=maxindex+1+nums.size()-minindex;
    return min(returnval,check);
}

//longest substring without repeating characters
int lengthOfLongestSubstring(string s){
    int n=s.size();
    if(n==0 || n==1) return 1;
    unordered_map<char,int>mpp;
    int maxlen=0;
    int l=0,r=0;
    for(int i=0;i<n;i++){
        if(mpp.find(s[i])!=mpp.end() && l<=mpp[s[i]]){
            l=mpp[s[i]]+1;
            mpp[s[i]]=i;
            maxlen=max(maxlen,r-l+1);
        }
        else{
            mpp[s[i]]=i;
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}

//max consecutive ones III
int longestOnes(vector<int>& nums,int k){
    int l=0,r=0;
    int maxlen=0;
    int cntzero=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0) cntzero++;
        while(cntzero>k){
            if(nums[l]==0) cntzero--;
            l++;
        }
        maxlen=max(maxlen,r-l+1);
        r++;
    }
    return maxlen;
}

//longer continuous ones than zero
bool checkZeroOnes(string s){
    int cnt1=0,cnt0=0;
    int len0=0,len1=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            cnt0=0;
            cnt1++;
            len1=max(len1,cnt1);
        }
        else{
            cnt1=0;
            cnt0++;
            len0=max(len0,cnt0);
        }
    }
    cout<<"cnt 1 = "<<len1<<"\n";
    cout<<"cnt 0 = "<<len0<<"\n";
    if(len1>len0) return true;
    return false;
}

//check atleast one segment of ones
bool checkOnesSegment(string s){
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            cnt++;
            if(cnt>1) return true;
        }
        else cnt=0;
    }
    return false;
}


//main function
int main(){
    vector<int> nums1={1,1,1,0,0,0,1,1,1,1,0};
    vector<int> nums2={72956,-44432,78333,31358,-96449,-24776};
    int num=-153;
    string str="110";
    vector<string> ch1={"a","ab"};
    vector<string> ch2={"a","a","a","ab"};
    vector<vector<int>> nums={{100,100},{100,100},{100,100}};
    int size=6;
    int arr[size]={1, 1, 0, 0, 1, 0};

    bool ans=checkOnesSegment(str);
    cout<<"answer = "<<ans;

    //int ans=longestOnes(nums1,2);
    //cout<<"answer = "<<ans;

    //int answer =lengthOfLongestSubstring(str);
    //cout<<"answer = "<<answer; 


    //int answer=minimumDeletions(nums2);
    //cout<<"answer = "<<answer;

    //vector<vector<int>> ans=pairSum(nums1,5);
    //displayvv(ans);

    //int ans=longestBalanced(nums1);
    //cout<<"answer = "<<ans;

    //int ans=missingMultiple(nums1,5);
    //cout<<"answer = "<<ans;

    //displayarr(arr,size);
    //sortZeroAndOne(arr,size);
    //displayarr(arr,size);


    //int ans=maxScore(nums1,7);
    //cout<<"answer = "<<ans;

    //int ans=maxLength(nums1,3);
    //cout<<"answer = "<<ans;

    //int ans=sumDivisibleByk(nums1,3);
    //cout<<"answer = "<<ans;
    
    //string s = "badc", t = "baba";
    //bool answer = isIsomorphic(s,t);
    //cout<<"answer = "<<answer;

    //vector<int> ans=successfulPairs(nums1,nums2,16);
    //displaynum(ans);

    //bool answer = containsNearbyDuplicate(nums1,2);
    //cout<<"answer = "<<answer;

    //int ans=getLucky(str,2);
    //cout<<"answer = "<<ans; 

    //vector<int> ans=assignElements2(nums1,nums2);
    //displaynum(ans);

    //string s="abbccccd";
    //cout<<"string = "<<s<<"\n";
    //vector<string> res=partitionString(s);
    //displaystr(res);

    //int n=49;
    //bool ans=isThree(n);
    //cout<<"answer = "<<ans;


    //int ans=findGCD(nums1);
    //cout<<"answer = "<<ans;

    //string str1 = "AAAAAAAAA", str2 = "AAACCC";
    //string res=gcdOfStrings(str1,str2);
    //cout<<"answer = "<<res;


    //string s="esejytaspxcgxqzchgcoeerdimjpmhpnegqsyzdzdsifkbbypp";
    //string ans=majorityFrequencyGroup(s);
    //cout<<"answer = "<<ans;

    //long long ans=splitarray(nums1);
    //cout<<"answer = "<<ans;

    //int n=102;
    //vector<int> ans=decimalRepresentation(n);
    //displaynum(ans);

    //int ans=countwords(ch1,ch2);
    //cout<<"answer = "<<ans;

    //string ans=kthDistrict(ch,3);
    //cout<<"answer = "<<ans;

    //int ans=maxAdjacentDistance(nums1);
    //cout<<"answer = "<<ans;

    //int ans=smallestAbsent(nums1);
    //cout<<"answer = "<<ans;

    //vector<int> res=maxKDistinct(nums1,6);
    //displaynum(res);

    //int ans=earliestTime(nums);
    //cout<<"answer = "<<ans;

    //vector<string> words = {"a","bb","acd","ace"};
    //string s = "abcde";
    //int ans=numMatching(s,words);
    //cout<<"answer = "<<ans;            

    //string s = "z", t = "abcde";
    //int ans=appendChar(s,t);
    //cout<<"ans  = "<<ans;


    //int res=minOperation(str);
    //cout<<"res = "<<res;



    //int n=723344511;
    //int ans=frequentDigit(n);
    //cout<<"answer = "<<ans;

    //vector<int> ans=minDiffernce(360,4);
    //displaynum(ans);

    //vector<int> ans=recoverOrder(nums1,nums2);
    //displaynum(ans);

    //int ans=leastInterval(ch,2);
    //cout<<"answer = "<<ans;

    //string ans=removesDuplicates(s);
    //cout<<"answer = "<<ans;

    //int ans=minimumMoves(s);
    //cout<<"answer = "<<ans;

    //vector<int> ans=maxjump9(nums1);
    //displaynum(ans);

    //int answer=gcdofoddevensum(4);
    //cout<<"answer = "<<answer;

    //vector<int> ans=intersectionvv(nums1);
    //displaynum(ans);

    //cout<<"\n";

    //int maxval=domainantindex(nums);
    //cout<<"maxval = "<<maxval;

    //int original=findfinalvalue(nums,4);
    //cout<<"original = "<<original;

    //bool istri=checkifexist(nums);
    //cout<<"istri = "<<istri;

    //displaynum(nums);
    //vector<int> ans=twosum(nums,10);
    //displaynum(ans);

    //int ans=numappearonce2(nums);
    //cout<<"ans = "<<ans;

    //string s = "abbcccddddeeeeedcba";
    //cout<<" given String = "<<s<<"\n";
    //int ans=consecutivechar(s);
    //cout<<"len = "<<ans<<"\n";

    //displaynum(nums);
    //int maxlen=lengthLCIS(nums);
    //cout<<"maxlen = "<<maxlen<<"\n";

    //displaynum(nums);
    //vector<int> res=shiftzero(nums);
    //displaynum(nums); 
    
    
    //vector<vector<int>> ans={{7,1,2,3},{4,5,6,7},{7}};
    //vector<int> res=intersection(ans);
    //displaynum(res);

    //char ch=finddiff("a","aa");
    //cout<<"ch = "<<ch<<"\n";


    //vector<string> res=summaryRanges(nums);
    //display(res);

    //int ans=secondlargest("abc1111");
    //cout<<"ans = "<<ans<<"\n";

    cout<<"\n";
    return 0;
}