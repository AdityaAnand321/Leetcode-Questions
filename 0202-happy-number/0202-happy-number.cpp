class Solution {
public:
    bool isHappy(int n) {
        set<int>ans;
        ans.insert(n);
        int b=n;

        while(true){
            
            b=sum(b);
            if(b==1)
            return true;

            if(ans.count(b))
            return false;
            else 
            ans.insert(b);

        }
        return false;

    }
    int sum(int n)
    {
        int s=0;
        while(n>0)
        {
                int a=n%10;
                s=s+a*a;
                n=n/10;
        }
        return s;
    }
};