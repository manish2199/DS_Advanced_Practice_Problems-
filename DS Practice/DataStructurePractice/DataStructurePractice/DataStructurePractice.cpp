#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include<algorithm> 
#include<sstream>  
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define MAX 1000
int Mem[1000];


template <typename T>
void Display( vector<T> vec)
{
    cout<<"[ ";
    for(int i=0; i<vec.size(); i++)
    {
        cout<<vec.at(i)<<" ";
    }
    cout<<"]"<<endl;
}


// Insert Element From 1 Vector to another 
void Insert(vector<int> vec1,vector<int> &vec2)
{
    for(int i=0; i<vec1.size(); i++)
    {
        vec2.push_back(vec1.at(i));
    }
}



// Display 2D Vector
template < typename T> 
void Display2DVector(vector<vector<T>> Vec2D)
{
    cout<<"Path - { ";
    for(int i=0; i<Vec2D.size(); i++)
    {
        cout<<"[";
        for(int j=0; j<Vec2D[i].size(); j++)
        {
            cout<<" "<<Vec2D.at(i).at(j);
        }
        cout<<" ] ";
    }
    cout<<" } "<<endl;
}



// Problem on Cyclic Sort ( Place elements at right index Constraints = [0,n] elements in vector ) 
void PrintArray(vector<int> vec)
{
    int j;
    for(int i =0; i<vec.size()-1; i++)
    {
        while( vec[i] != i+1 )
        {
            swap( vec.at(i) , vec.at(vec.at(i)-1) );
        }
    }

    Display(vec);
}


// Return Minimumn element vec
int getMinimum(vector<int> vec , int s , int e)
{
    int min = s;
    for(int i=s; i<=e; i++)
    {
        if(vec.at(i) < vec.at(min))
        {
            min = i;
        }
    }
    return min;
}

// Custom Sort Array 
void SortArray(vector<int> &vec , int k)
{
    int last=0;
    int min=0;
    for(int i=0; i<vec.size(); i++)
    {
        last = i + k;
        if(last > vec.size()-1)
        {
            last = vec.size()-1;
        }
        min = getMinimum(vec,i,last);
        swap(vec.at(i),vec.at(min));
    }
}



// Function to display stack 
void DisplayStack(stack<int> st)
{
    stack<int> s = st;

    cout<<"top->";
    while (!s.empty())
    {
        cout<<s.top()<<"-";
        s.pop();
    }
}


// Function to display elements in set 
void DisplaySet(unordered_set<string> us)
{
    for(auto i=us.begin(); i != us.end(); i++)
    {
        cout<<*i<<" ";    
    }
    cout<<endl;
}


// Find First Duplicate Occurance using maps
int GetFirstDupOccr(vector<int> vec)
{
    unordered_map<int,int> umap;

    for(int i=0;i<vec.size();i++)
    {
        umap[vec.at(i)]++;
    }

    for(int i =0;i<vec.size();i++)
    {
        auto it = umap.find(vec.at(i));
        if(it->second == 2)
        {
            return i+1;
            break;
        }
    }
    return 0;
}




// Union Of Array Problem ( Not Contain Duplicates ) 
int UnionOfArray(vector<int> vec1,vector<int> vec2)
{
    unordered_set<int> uset;

    for(int i=0; i<vec1.size(); i++)
    {
        uset.insert(vec1.at(i));        
        uset.insert(vec2.at(i));
    }

    return static_cast<int>(uset.size());
}


// Add Vector elements in unordered map 
void AddVecInSet(vector<int> vec,unordered_map<int,int> &umap)
{
    for(int i=0; i<vec.size(); i++)
    {
        umap[vec.at(i)]++;
    }
}

// Return Total Duplicate counts using maps
int GetDuplicateCount(unordered_map<int,int> umap)
{
    int count = 0;

    for(auto it=umap.begin(); it!=umap.end(); it++)
    {
        if(it->second > 1)
        {
            count++;
        }
    }
    return count;
}

// Find Intersectoins in two arrays
int GetIntersection(vector<int> vec1,vector<int> vec2)
{
    unordered_set<int> uset;

    for(int i=0; i<vec1.size(); i++)
    {
        uset.insert(vec1.at(i));
    }

    int count=0;

    for(int i=0; i<vec2.size(); i++)
    {
        if(uset.find(vec2.at(i)) != uset.end())
        {
            count++;
        }
    }
    return count;
}

// Find Subbarray using unord. map
bool IsSubarrayPresent(int sum,vector<int> vec)
{
    unordered_map<int,int> umap;

    // fill  umap with unique elements with occcur
    for(int i=0; i<vec.size(); i++)
    {
        umap[vec.at(i)]++;
    }


    for( auto iter = umap.begin(); iter!=umap.end(); iter++)
    {
        int key = sum - iter->first;
        int value = iter->second;
        
        if( key == iter->first)
        {
            if(value > 1)
            {
                return  true;
            }
        }
        else
        {
            if(umap.find(key) != umap.end())
            {
                return true;
            }
        }
    }
    return false;
}


// Find Subbarray of sum=0  using unord. set
bool IsSubarrayPresent(vector<int> vec)
{
    unordered_set<int> uset;
    
    int prefixSum = 0;
  
    for(int i=0; i<vec.size(); i++)
    {
        if( i == 0)
        {
            prefixSum = vec.at(0);
            uset.insert(vec.at(i));
        }
        else
        {
            prefixSum += vec.at(i);


            if(prefixSum == 0 || uset.find(prefixSum) != uset.end() )
            {
                return true;
            }
            else
            {
               uset.insert(prefixSum);
            }
        }
    }
    return false;
}


// Winner of Election Problem Leetcode Link - https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1
vector<string> winner(string arr[],int n)
{
    unordered_map<string,int> umap;
    
    for(int i=0; i<n; i++)
    {
        umap[arr[i]]++;
    }

    auto max = umap.begin();

    auto iter = umap.begin();
    iter++;

    while(iter!=umap.end())
    {
        if(iter->second > max->second)
        {
            max = iter;
        }
        if(iter->second == max->second)
        {
            if(iter->first < max->first)
            {
                max = iter;
            }
        }
        
        iter++;
    }
    stringstream ss;  
    ss<<max->second;  
    string s;  
    ss>>s;  
    vector<string> ansVec { max->first , s };

    return  ansVec;   
}


// Merge Sort Algorithm
void Merge(vector<int> &vec,int s , int mid, int e)
{
    int l1 = mid - s + 1;
    int l2 = e - mid;

    vector<int> vec1;
    vector<int> vec2;

    for(int i=0; i<l1; i++)
    {
        vec1.push_back(vec.at(i+s));
    }

    for(int i=0; i<l2; i++)
    {
        vec2.push_back(vec.at(i+mid+1));
    }

    int i=0;
    int j=0;
    int k=s;

    while( i<l1 && j<l2)
    {
        if(vec1.at(i) < vec2.at(j))
        {
           vec[k] = vec1.at(i);
            i++;
        }
        else
        {
            vec[k] = vec2.at(j);
            j++;
        }
        k++;
    }

    while (i<l1)
    {
        vec[k] = vec1.at(i);
        i++;k++;
    }

    while (j<l2)
    {
        vec[k] = vec2.at(j);
        j++;k++;
    }
}

void MergeSort(vector<int> &vec , int s , int e)
{
    if(s<e)
    {
        int mid = s + ( e - s)/2;

        MergeSort(vec,s,mid);
        MergeSort(vec,mid+1,e);

        Merge(vec,s,mid,e);
    }
}


// Find All Positive and negative pair
vector<int> PosNegPair(int a[], int n)
{
    // store all positive in ordered map
    map<int,int> omap;

    for(int i=0; i<n; i++)
    {
        if(a[i] >= 0)
        {
            omap[a[i]]++;
        }
    }
    
    // sotre all neg in unord map
    unordered_map<int,int> umap;
    
    for(int i=0; i<n; i++)
    {
        if(a[i] < 0)
        {
            umap[a[i]]++;
        }
    }
    
    // store pair in ans vec
    vector<int> ansVec;
    
    for( auto iter=omap.begin(); iter!=omap.end(); iter++)
    {
        auto key = umap.find(-(iter->first));

        if(key != umap.end())
        {
             int pairSize;
             if(iter->second < key->second)
             {
                 pairSize = iter->second;
             }
             else
             {
                 pairSize = key->second;
             }

            for (int i=0; i<pairSize; i++)
            {
                ansVec.push_back(key->first);
                ansVec.push_back(iter->first);
            }
       }
    }
    return ansVec;
}


// LeetCode Link - https://leetcode.com/problems/relative-sort-array/
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
{
    map<int,int> umap;

    for(int i=0; i<arr1.size(); i++)
    {
        umap[arr1.at(i)]++;
    }

    vector<int> ansArray;
    
    for(int i=0; i<arr2.size(); i++)
    {
        auto key = umap.find(arr2.at(i));

        if(key != umap.end())
        {
            int count = key->second;
            vector<int> t(count,key->first);
            ansArray.insert(ansArray.end(),t.begin(),t.end());
            umap.erase(key);
        }
    }
    
    while(!umap.empty())
    {
        auto key = umap.begin();
        int count = key->second;
        
        vector<int> t(count,key->first);
        ansArray.insert(ansArray.end(),t.begin(),t.end());
        umap.erase(key);
    }

    return ansArray;
}


// Sort string problem  leetcode - https://leetcode.com/problems/custom-sort-string/submissions/
string customSortString(string order, string s)
{
    unordered_map<char,int> umap;

    for(int i=0; i<s.length(); i++)
    {
        umap[s[i]]++;
    }
    
    string ansString;
    int count;
    for(int i=0; i<order.length(); i++)
    {
        auto key = umap.find(order[i]);

        if(key != umap.end())
        {
            count = 0;
            while(count < key->second)
            {
                ansString += key->first;
                count++;
            }
            umap.erase(key);
        }
    }

    while(!umap.empty())
    {
        auto key = umap.begin();
        
        count = 0;
        while(count < key->second)
        {
            ansString += key->first;
            count++;
        }
        umap.erase(key);
    }

    return  ansString;
}

// sort string using inbuilt method
string sortString(string str)
{
    string s= str;
    sort(s.begin(),s.end());
    return s;
}

// Group of Anagaram probmel Leetcode - https://leetcode.com/problems/group-anagrams/
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> ansList;

    unordered_map<string,vector<string>> umap;
    for(int i=0; i<strs.size(); i++)
    {
       string key = strs.at(i);
        sort(key.begin(),key.end());
        
        umap[key].push_back(strs.at(i));
    }

    for(auto iter = umap.begin(); iter!= umap.end(); iter++)
    {
        ansList.push_back(iter->second);
    }

    return  ansList;
}

// sort array based on frequency of element without using inbuilt sort 
vector<int> frequencySort(vector<int> &nums)
{
    unordered_map<int,int> umap;

    for( int i=0; i<nums.size(); i++)
    {
        umap[nums[i]]++;
    }

    map<int,vector<int>> omap;
    for( auto t = umap.begin(); t!= umap.end(); t++)
    {
       if(omap.find(t->second) == omap.end())
       {
           // means key is not present add new key
           omap[t->second].push_back(t->first);
       }
       else
       {
           // add in descen order
           omap[t->second].push_back(t->first);

           sort(omap[t->second].begin(), omap[t->second].end(), greater<int>());
       }
    }

    // add into ans vector
    vector<int> ans;
    for( auto iter = omap.begin(); iter!=omap.end(); iter++)
    {
           for(int k = 0; k<iter->second.size(); k++)
           {
              for(int i=0; i<iter->first; i++)
               {
                  ans.push_back(iter->second.at(k));
               }
           }
    }
    
    return ans;
}

// sort array based on frequency of element with using inbuilt sort 
vector<int> FrequencySort(vector<int> &nums)
{
    unordered_map<int,int> umap;

    for( int i=0; i<nums.size(); i++)
    {
        umap[nums[i]]++;
    }

    sort(nums.begin(),nums.end(),[&](int a,int b) { return umap[a]!=umap[b] ? umap[a] < umap[b] : a>b; } );
    
    return nums;
}





// All Posible Permutations using Recursion
void Permutations(vector<int> up,vector<int> p)
{
    if(up.empty())
    {
        Display(p);
        return;
    }

    int firstElement = up.at(0);

    vector<int> tempUP(up.begin() + 1, up.end());
    
    int size = p.size();
    for(int i=0;  i<=size; i++)
    {   
        vector<int> tf(p);
        tf.insert(tf.begin()+i,firstElement);
        
        Permutations( tempUP,tf);
    }
}

map<vector<int>,int> Map;
// Unique Posible Permutations using Recursion and map 
void Unique_Permutuations(vector<int> up,  vector<int> p)
{
    if(up.empty())
    {
        if(Map.find(p) == Map.end())
        {
            Map[p];
            Display(p);
        }
        return;
    }

    int first = up.at(0);

    vector<int> v2(up.begin()+1,up.end());
    int psize = p.size();
    
    for(int i=0; i<=psize; i++)
    {
        vector<int> tp(p);
        tp.insert(tp.begin()+i,first);
        Unique_Permutuations(v2,tp);
    }
}

// Print subset using recursion
void PrintSubset(vector<int> p, vector<int> up)
{
    if(up.empty())
    {
       if(Map.find(p) == Map.end())
       {
           Display(p);
           Map[p];
       }
        return;
    }

    int firstElement = up.at(0);
    
    vector<int> tempP(p);
    tempP.push_back(firstElement);

    vector<int> tempUP(up.begin()+1,up.end());

    PrintSubset(tempP,tempUP);
    PrintSubset(p,tempUP);
}


void CombAlgo(vector<int> ansVec,int p ,int n , int k)
{
    vector<int> prVec(ansVec.begin(),ansVec.end());
    prVec.push_back(p);

    if(prVec.size() == k || p > n)
    {
        if( prVec.size() == k && p <= n)
        {
           Display(prVec);
        }
        return;
    }
    
    
    for(int i=p; i < n; i++)
    {
        CombAlgo(prVec,i+1,n,k);
    }
}

// Combinations using Recursion
void combinations(int pr,int n , int k)
{
    if(pr >= 1)
    {
        vector<int> vec;
        CombAlgo(vec,pr,n,k);

        combinations(pr-1,n,k);
    }
}


// Return XOR of two num
int GetXOR(vector<int> vec)
{
    int num = 0;
    for(int i=0; i<vec.size(); i++)
    {
        num = vec[i] xor num;
    }
    return num;
}

// Return sum of xor in array 
int SubsetXORSum(vector<int> pr,vector<int> nums)
{
    // Your Code Here
    if(nums.empty())
    {
        return GetXOR(pr);
    }

    vector<int> vec (pr.begin(),pr.end());
    vec.push_back(nums.front());

    vector<int> num(nums.begin()+1,nums.end());
    
    int xorOfNum = SubsetXORSum(pr,num) + SubsetXORSum(vec,num); 

    return xorOfNum;
}

// Find anagram or not using Hashing technq.
bool IsAnagram(string inputStr1 , string inputStr2 )
{
    if(inputStr1.length() != inputStr2.length())
    {
        return  false;
    }
    
    int Hash1[26] = {};
    int Hash2[26] = {};
    for(int i=0; i<inputStr1.length(); i++)
    {
        Hash1[inputStr1[i] - 'A']++;
        Hash2[inputStr2[i] - 'A']++;
    }
    
    for(int i=0; i<inputStr1.length(); i++)
    {
        if(Hash1[inputStr1[i]-'A']  != Hash2[inputStr1[i] -'A'] )
        {
            return  false;
        }
    }
    
   return true;
}


// anagram or not in capital and small mixed strings
bool IsAnagramMixString(string inputStr1 , string inputStr2 )
{
    if(inputStr1.length() != inputStr2.length())
    {
        return  false;
    }

    
    int Hash1[52] = {};
    int Hash2[52] = {};
    
    for(int i=0; i<inputStr1.length(); i++)
    {
        // For String 2
        if(isupper(inputStr1[i]))
        {
           Hash1[inputStr1[i] - 'A']++;
        }
        else
        {
            Hash1[(inputStr1[i] -'a') +1]++;
        }

        // For String 2
        if(isupper(inputStr2[i]))
        {
            Hash2[inputStr2[i] - 'A']++;
        }
        else
        {
            Hash2[(inputStr2[i] -'a') +1]++;
        }
    }
    
    
    for(int i=0; i<inputStr1.length(); i++)
    {
        if(isupper(inputStr1[i]))
        {
            if(Hash1[inputStr1[i]-'A']  != Hash2[inputStr1[i] -'A'] )
            {
               return  false;
            }
        }
        else
        {
            if(Hash1[inputStr1[i]-'a' + 1 ]  != Hash2[inputStr1[i] -'a' + 1] )
            {
                return  false;
            }
        }
    }
    
    return true;
}



bool isAnagram(string s, string t)
{
   if(s.length() != t.length())
   {
       return  false;
   }

    int sum1 = 0;
    int sum2 = 0;
    

    int t2 = 0;
    int t1 = 0;
    for(int i=0; i<s.length(); i++)
    {
        // for string 1
        int temp1 = s[i] - 'A';
        sum1 += temp1;
        t1 += sum1;


        int temp2 = t[i] - 'A';
        sum2 += temp2;
        t2 += sum2;
    }

    if(t1/26 == 0 && t2/26 == 0)
    {
        return true;
    }
    return  false;
}


// Mobile keypad problem  using recursion leetcode - https://leetcode.com/problems/letter-combinations-of-a-phone-number/ 
void keypad(string proc, string unproc)  // "23"  abc ,def
 {
    if(unproc.empty())
    {
        cout<<proc<<endl;
        return;
    }

    int firstelement = unproc.at(0) - '0';

    for(int index = (firstelement-1)*3; index < ( firstelement * 3 ); index++)
   {
        char temp = (char)index + 'a';
        keypad(proc + temp,unproc.substr(1));
   }
}


// Count ways to reach first place ( row = 1,col = 1 )  // ( Cannot move in diagonal ) 
void CountWays(int row, int col,vector<vector<int>> path)
{
    vector<int> vec { row ,col };

    vector<vector<int>> tempPath(path.begin(),path.end());

    tempPath.push_back(vec);
    
    if(row == 1 && col == 1)
    {
        vector<int> vec { 1,1};
        path.push_back(vec);
        Display2DVector(path);
        return;
    }


    if(row == 1)
    {
         CountWays(1,col-1,tempPath);   
    }
    else if( col == 1)
    {
        CountWays(row-1,1,tempPath);   
    }
    else
    {
        CountWays(row,col-1,tempPath);

        CountWays(row-1,col,tempPath);
    }
}


// Count ways to reach first place ( row = 1,col = 1 )  // ( Cannot move in diagonal ) ( Using BackTracking ) 
void GoAllDirection(vector<vector<bool>> matrix , string path , int row , int col)
{
    
    if( row == matrix.size()-1 && col == matrix[0].size()-1)
    {
        cout<<path<<endl;
        return;
    }


    if(matrix[row][col] == false)
    {
        return;
    }

    matrix[row][col] = false;

    if(col < matrix[0].size()-1)
    {
        GoAllDirection(matrix,path+'R',row,col+1);
    }
    if(row < matrix.size()-1)
    {
        GoAllDirection(matrix,path+'D',row+1,col);
    }
    if(col > 0)
    {
        GoAllDirection(matrix,path+'L',row,col-1);
    }
    if(row > 0)
    {
        GoAllDirection(matrix,path+'U',row-1,col);
    }

    matrix[row][col] = true;
}



vector<string> GetNQueenStringBoard(vector<vector<string>> board)
{
    vector<string> ans;
    for(int i = 0; i<board.size(); i++)
    {
        vector<string> vec;
        string str;
        for(int j=0; j<board[0].size(); j++)
        {
            if(board[i][j] == "Q")
            {
                str += 'Q';
            }
            else
            {
                str += '.';
            }
        }
        ans.push_back(str);
    }
    return ans;
}


bool isSafe(vector<vector<string>> board , int row , int col)
{
    // check vertically
    for(int i =0; i<row; i++)
    {
        if(board[i][col] == "Q" )
        {
            return false;
        }
    }

    // CHECK left diagonal
    int maxLeft = min(row,col);
    for(int i=1; i<=maxLeft; i++)
    {
        if(board[row-i][col-i] == "Q")
        {
            return false;
        }
    }

    // check right diagonal
    int c = board[0].size()- col -1;
    int maxRight = min(row,c);
    for(int i=1; i<=maxRight; i++)
    {
        if(board[row-i][col+i] == "Q")
        {
            return false;
        }
    }

    return true;
}


 // N Queen problem using backtracking
vector<vector<string>> NQueen(vector<vector<string>> board, int row)
{ 
    if( row == board.size() )
    {
        vector<vector<string>> ansList;vector<string> ans = GetNQueenStringBoard(board);
        ansList.push_back(ans);
        return ansList;
    }

    vector<vector<string>> ans;
    for(int i=0; i<board[0].size(); i++)
    {
        if(isSafe(board,row,i))
        {
            board[row][i] = "Q";
            vector<vector<string>> a= NQueen(board,row+1);
            ans.insert(ans.begin(),a.begin(),a.end());
            board[row][i] = ".";
        }
    }
    return ans;
}

 vector<vector<string>> solveNQueens(int n)  
 {
    vector<vector<string>> board;
 
    for(int i=0; i<n; i++)
    {
        vector<string> vec1;
        for(int j=0; j<n; j++)
        {
            vec1.push_back(".");
        }
        board.push_back(vec1);
    }
    
    return  NQueen(board,0);
 }


void DisplayNKnights(vector<vector<bool>> matrix)
{
    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix.size(); j++)
        {
            if(matrix[i][j])
            {
                cout<<"K";
            }
            else
            {
                cout<<"X";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isValid(vector<vector<bool>> board, int r, int c)
{
    if( r >= 0 && r < board.size() && c >= 0 && c < board.size())
    {
        return true;
    }
    return false;
}

bool IsSafe(vector<vector<bool>> board,int r , int c)
{
    if(isValid(board,r-2,c-1))
    {
        if(board[r-2][c-1])
        {
            return false;
        }
    }

    if(isValid(board,r-2,c+1))
    {
        if(board[r-2][c+1])
        {
            return false;
        }
    }

    if(isValid(board,r-1,c-2))
    {
        if(board[r-1][c-2])
        {
            return false;
        }
    }

    if(isValid(board,r-1,c+2))
    {
        if(board[r-1][c+2])
        {
            return false;
        }
    }
    return true;
}

// N Knights problem using backtracking
void NKnights(vector<vector<bool>> board ,int row , int col , int knight)
{
    if(knight == 0)
    {
        DisplayNKnights(board);
        return;
    }

    if(row == board.size()-1 && col == board.size())
    {
        return;
    }
    
    if(col == board.size() )
    {
        NKnights(board,row+1,0,knight);
        return;
    }

    if(IsSafe(board,row,col))
    {
        board[row][col] = true;
        NKnights(board,row,col+1,knight-1);
        board[row][col] = false;
    }

    NKnights(board,row,col+1,knight);
}


void PrintPermutuations(string p , string up)
{
    if(up.empty())
    {
        cout<<p<<endl;
        return;
    }

    char firstChar = up[0];

    for(int i=0; i<=p.length(); i++)
    {
        string first = p.substr(0,i);
        string second = p.substr(i,p.length());

        PrintPermutuations(first+firstChar+second,up.substr(1));
    }
}

bool IsEven(int number)
{
    return number % 2;
}



// Sort Squared Array 
vector<int> sortedSquares(vector<int>& nums)
{
    // if array contains only positive elements
    if(nums.at(0) >= 0 && nums.at(nums.size()-1) >= 0 )
    {
        for(int i=0; i<nums.size(); i++)
        {
            nums[i] = pow(nums.at(i),2);
        }
        return nums;
    }

    // if array contains only negative elements
    if(nums.at(0) < 0 && nums.at(nums.size()-1) < 0 )
    {
        int i=0;int j= nums.size()-1;
        while(i<=j)
        {
            if(i==j)
            {
                nums[i] = pow(nums.at(i),2);
            }
            else
            {
                nums[i] = pow(nums.at(i),2);
                nums[j] = pow(nums.at(j),2);     
            }

            swap(nums.at(i),nums.at(j));
            i++;j--;
        }
        return nums;
    }

    // if array contains both negative and positive
    // vector<int> ansVector;
    int n = nums.size();
    int* ansArray = new int[n];

    
    int ptr1 = 0;
    int ptr2 = nums.size()-1;

    int last = nums.size()-1;
    
    while(ptr1 <= ptr2)
    {
        if(abs(nums.at(ptr1)) < abs(nums.at(ptr2)) )
        {
            ansArray[last] = pow(nums.at(ptr2),2);
            ptr2--;
            last--;
        }
        else
        {
            ansArray[last] = pow(nums.at(ptr1),2);
            ptr1++;
            last--;
        }
    }

    vector<int> ans;
    for(int i=0; i<n; i++)
    {
        ans.push_back(ansArray[i]);
    }

    delete[] ansArray;
    return ans;   
}


// Moore's Voting Algorithm to Find Majority Element 
int majorityElement(vector<int> vec)
{
    // Find The Element which in majority
    int maj = 0; int count = 1;
    for(int i=0; i<vec.size(); i++)
    {
        if(vec.at(maj) == vec.at(i))
        {
            count ++;
        }
        else
        {
            count--;
        }

        if(count == 0)
        {
            maj = i;
            count = 1;
        }
    }

    // Check If that element is in majority ( > size/2 ) or not
    count = 1;
    for(int i=0; i<vec.size(); i++)
    {
        if(vec.at(i) == vec.at(maj))
        {
            count++;
            if(count > vec.size()/2)
            {
                return vec.at(i);
            }
        }
    }
    return -1; 
}


int MaxMinSumDiff(vector<int> vec, int m)
{
   sort(vec.begin(),vec.end());
    int minSum=0,maxSum = 0; 

    for(int i=0,j=vec.size()-1; i<vec.size()-m; i++,j--)
    {
        minSum += vec.at(i);
        maxSum += vec.at(j);
    }
    return maxSum-minSum;
}



// Trie
class Node
{
public :
     unordered_map<char,Node*> umap; 
     bool DoesStringOver;
};

class Trie
{
private:
    Node* rootNode;
    
public:
    Trie() 
    {
        rootNode = NULL;
    }
    
    void insert(string word) 
    {
        // if trie is empty
        Node* tempNode = new Node();
        if(rootNode == NULL)
        {
            for(int i=0; i<word.length(); i++)
            {
                Node* new_node = new Node();
                
                if( i == 0)
                {
                    new_node->DoesStringOver = false;
                    new_node->umap[word[i]] = tempNode;
                    rootNode = new_node;    
                }
                else
                {
                    Node* newTempNode = new Node();

                    new_node = tempNode;
                    
                    tempNode = newTempNode;
                    
                    new_node->DoesStringOver = false;
                    new_node->umap[word[i]] = tempNode;
                }
            }
        }
        // if trie is not empty
        else
        {
            tempNode = rootNode;
            for(int i=0; i<word.length(); i++)
            {
                
                if(tempNode->umap.find(word[i]) != tempNode->umap.end() )
                {
                    // means current char is present move to next node
                    tempNode = tempNode->umap[word[i]];
                }
                else
                {   
                    Node* newNode = new Node();  

                    tempNode->umap[word[i]] = newNode;

                    tempNode = newNode;
                }
            }
        }
        tempNode->DoesStringOver = true;
    }

    
    bool search(string word) 
    {
        // if trie is empty
        if( rootNode == NULL)
        {   
            return false;
        }

        Node* temp = rootNode;
        bool isPresent = temp->DoesStringOver;
        for(int i=0; i<word.length(); i++)
        {
            if( temp->umap.find(word[i]) == temp->umap.end() )
            {
                // means curr char is not present in trie
                return false;
            }        

            temp = temp->umap[word[i]];
            isPresent = temp->DoesStringOver;
        }

        return isPresent;
    }
    
    bool startsWith(string prefix) 
    {
        // if trie is empty
        if(rootNode == NULL)
        {
            return false;
        }
        
        bool isCharPresent = true;
        Node* temp = rootNode;
        for(int i=0; i<prefix.length(); i++)
        {
            if( temp->umap.find(prefix[i]) != temp->umap.end() )
            {
                temp = temp->umap[prefix[i]];
            }
            else
            {
                isCharPresent = false;
                break;
            }
        }
        return  isCharPresent;
    }

    Node* getRootNode()
    {
        return rootNode;
    }
};



bool isStringLexFirst(string str1,string str2)
{
    for(int i=0; i<str1.length(); i++)
    {
        if(str1[i] < str2[i] )
        {
            return true;
        }
        else if(str1[i] > str2[i] )
        {
            return false;
        }
    }
    // means both string are same;
    return true;
}

//  Complete Longest String Problem  ( Difficulty Level - Hard )  link = https://www.codingninjas.com/codestudio/problems/complete-string_2687860?leftPanelTab=1  
 void getLongestCompleteString(string foundedString,string &CompleteString , Node* currNode , Node* rootNode )
{
    if( currNode->umap.empty() && currNode->DoesStringOver)
    {
        // means we found our possible ans
        if(CompleteString.empty())
        {
            CompleteString = foundedString;
            return ;
        }
        else
        {
            // check which string have greater length
            if( foundedString.length() > CompleteString.length())
            {
                // ans is founded string
                CompleteString = foundedString;
                return;
            }
            else if(  foundedString.length() < CompleteString.length() )
            {
                // ans not neet to modify 
                return;
            }
            else
            {
                // means both length is similar then check by lex. order 
                if(isStringLexFirst(foundedString,CompleteString))
                {
                    // ans is founded string
                    CompleteString = foundedString;
                    return;
                }
                else
                {
                    // ans not need to modify 
                    return;
                }
            }
               
        }
    }
        
    if(!currNode->DoesStringOver && currNode != rootNode )
    {
        // if we encounter false then dont modify the ans
        return;
    }


    // check whether to make recursion call or not
    if(currNode->umap.size() == 1)
    {
        string temp = foundedString;
        char ch = currNode->umap.begin()->first;
        temp += ch;
        getLongestCompleteString(temp,CompleteString,currNode->umap[ch],rootNode) ;
    }
    else
    {
        // means more than one char present at given node
        // make recursion call to find all possible strings
        for(auto iter = currNode->umap.begin(); iter!= currNode->umap.end(); iter++)
        {
            string temp1 = foundedString ;
            char ch1 = iter->first;
            temp1 += ch1;
            getLongestCompleteString(temp1,CompleteString,currNode->umap[ch1],rootNode);
        }
    }
}


string completeString(vector<string> a)
{
    // Write your code here.

    // Build the trie of given strings 
    Trie* trie = new Trie();
    for(int i=0; i<a.size(); i++)
    {
        trie->insert(a[i]);
    }

    string FoundedString = "";
    string CompleteString;

    Node* currnode = trie->getRootNode();
    getLongestCompleteString(FoundedString,CompleteString,currnode,currnode);

    return CompleteString;
}





// Breadth First Search To Detect The Loop inside Graph
bool IsPresentLoop(queue<pair<int,int>> &q,int node,vector<int> adj[],vector<bool> &visited)
{
    bool isPresent = false;
    
    q.push( { node,-1 } );
    visited[node] = true;

    // First is Current Node    second is its Parent Node
   while (!q.empty())
   {
       int first = q.front().first;
       int second = q.front().second;
       q.pop();

       for(int i=0; i<adj[first].size(); i++)
       {
           if(!visited[adj[first][i]])
           {
               q.push( { adj[first][i],first} );
               visited[adj[first][i]] = true;
           }
           else
           {
               if(adj[first][i] != second)
               {
                   isPresent = true;
                   break;
               }
           }
       }
   }
    return isPresent; 
}


// Depth First Search To Detect The Loop inside Graph
void IsPresentLoop(bool &isPresent,int parentNode,int currNode,vector<int> adj[],vector<bool> &visited)
{
    
    visited[currNode] = true;

    for(int i=0; i<adj[currNode].size(); i++)
    {
        if(visited[adj[currNode][i]] && parentNode != adj[currNode][i] )
        {
            isPresent = true;
            break;
        }
        if(visited[adj[currNode][i]])
        {
            continue;
        }
        IsPresentLoop(isPresent,currNode,adj[currNode][i],adj,visited);   
    }
}



int main()
{
    vector<int> adj[8];

    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[3].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[2].push_back(5);
    adj[5].push_back(2);
    adj[4].push_back(5);
    adj[5].push_back(4);
    adj[6].push_back(5);
    adj[5].push_back(6);
    adj[6].push_back(7);
    adj[7].push_back(6);

    // adj[1].push_back(2);
    // adj[2].push_back(1);
    // adj[2].push_back(5);
    // adj[5].push_back(2);
    // adj[5].push_back(6);
    // adj[6].push_back(5);
    // adj[6].push_back(7);
    // adj[7].push_back(6);
    

    vector<bool> visited ( 8,false);

    // queue<pair<int,int>> q;


    bool ispresent = false;
    for(int i=1; i<8; i++)
    {
        // By BFS
        if(!visited[i])
        {
            IsPresentLoop(ispresent,-1,i,adj,visited);
            if(ispresent)
            {
                break;
            }
        }
    }

    cout<<ispresent;
}









