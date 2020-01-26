# Problem

A Little Elephant and his friends from the Zoo of Lviv like candies very much.

There are **N** elephants in the Zoo. The elephant with number **K (1 ≤ K ≤ N)** will be happy if he receives at least **A<sub>K</sub>** candies. There are **C** candies in all in the Zoo.

The Zoo staff is interested in knowing whether it is possible to make all the **N** elephants happy by giving each elephant at least as many candies as he wants, that is, the **K<sup>th</sup>** elephant should receive at least **A<sub>K</sub>** candies. Each candy can be given to only one elephant. Print Yes if it is possible and No otherwise.

### Input
The first line of the input file contains an integer **T**, the number of test cases. **T** test cases follow. Each test case consists of exactly 2 lines. The first line of each test case contains two space separated integers **N** and **C**, the total number of elephants and the total number of candies in the Zoo respectively. The second line contains **N** space separated integers **A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>**.

### Output
For each test case output exactly one line containing the string **Yes** if it possible to make all elephants happy and the string **No** otherwise. Output is case sensitive. So do not print **YES** or **yes**.

### Constraints
1 ≤ T ≤ 1000

1 ≤ N ≤ 100

1 ≤ C ≤ 10<sup>9</sup>

1 ≤ A<sub>K</sub> ≤ 10000, for K = 1, 2, ..., N

### Example
>Input:<br/>
2<br/>
2 3<br/>
1 1<br/>
3 7<br/>
4 2 2<br/>

>Output:<br/>
Yes<br/>
No

### Explanation
**Case 1.** We can give one candy to the first elephant and two candies to the second elephant and make them both happy. Hence the answer is **Yes**. Alternatively we can give one candy to each elephant and left one candy for ourselves but they again will be happy.

**Case 2.** Even if we give four candies to the first elephant and two candies to the second elephant we will have only one candy left and can not make last elephant happy since he needs two candies for his happiness. Hence the answer is **No**.

#### `<Problem link>` : <https://www.codechef.com/problems/LECANDY>
<br/>
<details>
  <summary>Solution Approach</summary>
  
  ### References
  
  >https://discuss.codechef.com/t/lecandy-editorial/275<br/>
  
</details>
<br/>
<details>
  <summary>Code</summary>
  
  ###
  
  ``` cpp
  #include<bits/stdc++.h>
#define LL long long
#define M 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]; cout<<endl;
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n;
        LL c, a;
        cin>>n>>c;
        for(int i=0; i<n; i++){
            cin>>a;
            c-=a;
        }
        if(c<0)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;    
}

  ```
</details>