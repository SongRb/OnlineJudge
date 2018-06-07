class Solution {
public:
int countOccurence(const vector<int> &a, int left, int right, int element)
{
    int cnt = 0;
    for (int i = left; i <= right; i++)
    {
        if (a[i] == element)
        {
            cnt++;
        }
    }
    return cnt;
}

int getMajorityElement(vector<int> &a, int left, int right)
{
    if (left > right) return -1;
    if (left == right) return a[left];
    int mid = left + (right - left) / 2;
    int leftMajority = getMajorityElement(a, left, mid);
    int rightMajority = getMajorityElement(a, mid + 1, right);

    if (leftMajority != -1 && rightMajority != -1)
    {
        int leftNum = countOccurence(a, left, right, leftMajority);
        int rightNum = countOccurence(a, left, right, rightMajority);
        if (leftNum > (right - left + 1) / 2)
        {
            return leftMajority;
        }
        else if (rightNum > (right - left + 1) / 2)
        {
            return rightMajority;
        }
        else
        {
            return -1;
        }
    }
    else if(leftMajority == -1 && rightMajority == -1)
    {
        return -1;
    }
    else
    {
        int majority;
        if(rightMajority != -1)
            majority = rightMajority;
        else if(leftMajority!=-1)
            majority = leftMajority;
        int num = countOccurence(a, left, right, majority);
        if (num > (right - left + 1) / 2)
        {
            return majority;
        }
        else
        {
            return -1;
        }
    }
}

int majorityElement(vector<int> &a)
{
    return getMajorityElement(a,0,a.size()-1);
}
};