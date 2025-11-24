class Solution {
public:
    int countPrimes(int n) {
        int arr[n+1];
        fill(arr,arr+n+1,1);

        arr[0]=0;
        if(n>=2)
        arr[1]=0;

        for(int i=2;i*i<n;i++)
        {
            if(arr[i])
            {
                for(int j=i*i;j<n;j+=i)
                arr[j]=0;
            }
        }

        int count=0;
        for(int i=2;i<n;i++)
        if(arr[i]==1)
        count++;

        return count;
    }
};