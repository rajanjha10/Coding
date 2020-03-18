# Problem
Thomas, a computer scientist that works with DNA sequences, needs to compute longest common subsequences of given pairs of strings. Consider an alphabet Σ of letters and a word w = a<sub>1</sub> a<sub>2</sub> …a<sub>r</sub>, where a<sub>i</sub> ∈ Σ, for i = 1, 2, …,r. A subsequence of w is a word x = a<sub>i1</sub> a<sub>i2</sub> …a<sub>is</sub> such that 1 ≤ i<sub>1</sub> < i<sub>2</sub> < … < i<sub>s</sub> ≤ r. Subsequence x is a segment of w if i<sub>j+1</sub> = i<sub>j + 1</sub>, for j = 1,2, …,s-1. For example the word ove is a segment of the word lovely, whereas the word loly is a subsequence of lovely, but not a segment.

A word is a common subsequence of two words w<sub>1</sub> and w<sub>2</sub> if it is a subsequence of each of the two words. A longest common subsequence of w<sub>1</sub> and w<sub>2</sub> is a common subsequence of w<sub>1</sub> and w<sub>2</sub> having the largest possible length. For example, consider the words w<sub>1</sub> = lovxxelyxxxxx and w<sub>2</sub> = xxxxxxxlovely. The words w<sub>3</sub> = lovely and w<sub>4</sub> = xxxxxxx, the latter of length 7, are both common subsequences of w<sub>1</sub> and w<sub>2</sub>. In fact, w<sub>4</sub> is their longest common subsequence. Notice that the empty word, of length zero, is always a common subsequence, although not necessarily the longest.

In the case of Thomas, there is an extra requirement: the subsequence must be formed from common segments having length K or more. For example, if Thomas decides that K=3, then he considers lovely to be an acceptable common subsequence of lovxxelyxxxxx and xxxxxxxlovely, whereas xxxxxxx, which has length 7 and is also a common subsequence, is not acceptable. Can you help Thomas?

### Input
The input contains several test cases. The first line of a test case contains an integer K representing the minimum length of common segments, where 1 ≤ K ≤ 100. The next two lines contain each a string on lowercase letters from the regular alphabet of 26 letters. The length l of each string satisfies the inequality 1 ≤ l ≤ 10<sup>3</sup>. There are no spaces on any line in the input. The end of the input is indicated by a line containing a zero.

### Output
For each test case in the input, your program must print a single line, containing the length of the longest subsequence formed by consecutive segments of length at least K from both strings. If no such common subsequence of length greater than zero exists, then 0 must be printed.

### Example
>Input:<br/>
3<br/>
lovxxelyxxxxx<br/>
xxxxxxxlovely<br/>
1<br/>
lovxxelyxxxxx<br/>
xxxxxxxlovely<br/>
3<br/>
lovxxxelxyxxxx<br/>
xxxlovelyxxxxxxx<br/>
4<br/>
lovxxxelyxxx<br/>
xxxxxxlovely<br/>
0<br/>

>Output:<br/>
6<br/>
7<br/>
10<br/>
0<br/>

#### `<Problem link>` : <https://www.spoj.com/problems/SAMER08D/>
<br/>
<details>
  <summary>Solution Approach</summary>
  
  ######
  
  The problem is a combination of longest common subsequence and longest common substring problem. Make sure you know these two before reading further.
  
  The only difference between the standard problem and the modified version is that the number of common characters we take at a time has a lower bound, which is the value **k**. We will use a 2d array dp[][]. We must always take k or more common characters to add the subsequence we will be building via dp.
  
  So the relation `dp[i][j] = dp[i-1][j-1] + 1` if x\[i]==y\[j] is now invalid because this takes just 1 character into the subsequence. In place of this, we need to iterate backwards as long as we get common characters greater than **k** and build dp[][] accordingly. 
  
  Hence the relation comes to be:<br/>
  `dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-x][j-x] + x)` **(x: k .... s1[x]!=s2[x])**
  
  We can preprocess the length of the common substring to answer upper bound of x.
  
  ###### Reducing Time complexity:
  
  The time complexity of above technique is `O(N^3)`. We can reduce the time complexity to `O(N^2)` by taking two different dp[][] tables. dp[][][0] and dp[][][1].
  
  dp[i][j][0] denotes the length of LCS which follows the constraint that each segment of LCS except the last one is of length>=k and the last segment of it can be of any length>=0 but it should end at index i,j of two string 's1' and 's2' respectively.
		
  dp[i][j][1] denotes the length of LCS which strictly follows the constraint given by problem that each segment of it will be of length>=K
  
  The combination of two tables helps in generating lcs according to the constraints and get rid of any suffix characters that do not satisfy the constraints for each (i, j). 
  
  ### References
  
  >https://discuss.codechef.com/t/help-with-problem-samer08d-dna-sequences/13802/2<br/>
  
</details>
