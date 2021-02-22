[寻找数组的中心索引](https://leetcode-cn.com/problems/find-pivot-index/submissions/)

```
int pivotIndex(int* nums, int numsSize){
    int total=0;
    for(int i=0;i<numsSize;i++)
    {
        total+=nums[i];
    }
    //本来定义的leftSum与rightSum,但由于下面推导出来的关系，只需要leftSum
    //i从0开始,leftSum计算好一点，这写成sum好看，变量名而已
    //左边元素之和
    int sum=0;
    for(int i=0;i<numsSize;i++)
    {
        
        //leftSum+num[i]+rightSum=total;
        //leftSum==rightSum
        //2Sum+num[i]=total;
        
        //左边之和==右边之和，可以推到出，判断条件
        if(2*sum==total-nums[i])
        {
            return i;
        }
        //下一轮左边之和
        sum=sum+nums[i];
    }
    return -1;
}


```

[奇偶数组排序](https://leetcode-cn.com/problems/sort-array-by-parity/)

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int *B=(int*)malloc(sizeof(int)*ASize);
    int left=0;
    int right=ASize-1;
    //第一种方法：多开一个数组B，碰见偶数在B的前面开始往后放，碰见奇数在B的后面开始往前放
      //时间复杂度：O(N)   空间复杂度： O(N)
    // for(int i=0;i<ASize;i++)
    // {
    //     if(A[i]%2==0)
    //     {
    //         B[left]=A[i];
    //         left++;
    //     }
    //     else
    //     {
    //         B[right]=A[i];
    //         right--;
    //     }
    // }
    // *returnSize=ASize;
    // return B;
            //第二种：前后指针法（类似于快排左右指针的单趟思想，左边找奇数，右边找偶数，都找到在交换）
             //只进行了单趟所以时间复杂度O(logN),空间复杂度o(1)
   while(left<right)
   {
       //左边为奇数，右边为偶数交换
       if(A[left]%2==1 && A[right]%2==0)
       {
           //交换
            int temp=0;
            temp=A[left];
            A[left]=A[right];
            A[right]=temp;
       }
       //左边为偶数，或者右边为奇数，就不进行交换，针对这两种情况需要各自挪动
       else{
           
           if(A[left]%2==0)
           {
               left++;
           }
           if(A[right]%2==1)
           {
               right--;
           }

       }
   }
   *returnSize=ASize;
   return A;
}



```



[仅仅翻转字母](https://leetcode-cn.com/problems/reverse-only-letters/)

```
class Solution {
public:
    //是否为a-z,或者A-Z之间的字母
    bool isWord(char s)
    {
        if(s>='a' && s<='z' )
        {
            return true;
        }
        else if(s>='A' && s<='Z')
        {
            return true;
        }
        return false;
    }
    string reverseOnlyLetters(string S) {
        int left=0;
        int right=S.size()-1;
        while(left<right)
        {
            //左右两边不是字母就跨过
            if(!isWord(S[left]))
            {
                left++;
            }
            if(!isWord(S[right]))
            {
                right--;
            }
            //当两者都是字母时才翻转
            if(isWord(S[left])&&isWord(S[right]))
            {
            char s=' ';
            s=S[left];
            S[left]=S[right];
            S[right]=s;
            left++;
            right--;
            }
            
        }
        return S;

​    }
};


```

