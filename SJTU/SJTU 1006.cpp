#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int test(int *, int);

int helper(int *, int, int);

int Main()
{
    srand(time(NULL));
    for (int j = 0; j < 100; j++)
    {

        int sizeA;
        sizeA = rand() % 10 + 4;
        //cin>>sizeA;
        int *data = new int[sizeA];
        int *data2 = new int[sizeA];
        int maxP = 0, minP = 0;
        for (int i = 0; i < sizeA; i++)
        {
            int tmp;
            //cin>>tmp;
            tmp = 2 * (rand() % 100) - 100;
            data2[i] = tmp;
            if (i == 0) data[0] = tmp;
            else data[i] = tmp + data[i - 1];
            if (data[maxP] < data[i]) maxP = i;
            //if(data[minP]>data[i]) minP=i;
        }

        int tmpR = 0;
        int minS = 10000000;
        for (int j = 1; j < sizeA; j++)
        {
            if (minS > data[j - 1])minS = data[j - 1];
            if ((data[j] - minS) > tmpR)tmpR = data[j] - minS;
        }


        /*
        if(maxP>minP)
            tmpR=data[maxP]-data[minP];
    else{

    }

        int result=0;
        result=tmpR>data[maxP]?tmpR:data[maxP];

        if(result<=0) cout<<"Game Over";
        else cout<<result;
        */

        int result = 0;
        result = tmpR > data[maxP] ? tmpR : data[maxP];
        int compRes = test(data2, sizeA);
        //if(result!=compRes)
        //{cout<<"Wrong:"<<compRes<<'\t'<<result<<endl;
        //cout<<"Original Array:"<<endl;
        cout << sizeA << endl;
        for (int i = 0; i < sizeA; i++)
            cout << data2[i] << '\t';
        cout << endl;
        cout << result << endl;
        cout << endl;

        //else cout<<result<<endl;

    }
    return 0;
}

int test(int *data2, int sizeA)
{
    int maxR = -100;
    for (int i = 0; i < sizeA; i++)
        for (int j = i; j < sizeA; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += data2[k];
            if (maxR < sum) maxR = sum;
        }
    return maxR;
}

/*
int helper(int *a, int low, int high)
{
    int maxP=low,minP=low;
    for(int i=low;i<high;i++)
    {
        if(a[maxP]<a[i]) maxP=i;
        if(a[minP]>a[i]) minP=i;
    }

    if(maxP>minP) return a[maxP]>(a[maxP]-a[minP])?a[maxP]:(a[maxP]-a[minP]);
    else
    {
        int tmp;
        for(int i=low;i<maxP;i++)
            if((a[maxP]-a[i])>tmp) tmp=a[maxP]-a[i];
        for(int i=minP+1;i<high;i++)
            if((a[i]-a[minP])>tmp) tmp=a[i]-a[minP];
        int d=helper(a, maxP, minP);
        return tmp>d?tmp:d;
    }
}
*/
