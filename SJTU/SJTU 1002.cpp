#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int test();

int test()
{
    srand(time(NULL));
    int tmpLength = 4, tmpWidth = 5;
    int length = tmpLength + 1, width = tmpWidth + 1;
    //length++;width++;
    //cin>>length>>width;
    int *area = new int[length * width];
    cout << "Input data:" << endl;
    for (int i = 0; i <= tmpLength; i++)
    {
        for (int j = 0; j <= tmpWidth; j++)
        {
            if (i == 0 || j == 0) area[i * (width) + j] = 0;
                //else if (i==0) area[i*width+j]=area[i*width+j-1]+tmp;
                //else if (j==0) area[i*width+j]=area[(i-1)*width+j]+tmp;
            else
            {
                int tmp;
                tmp = rand() % 10 + 1;
                cout << tmp << '\t';
                //cin>>tmp;
                area[i * width + j] =
                        area[(i - 1) * width + j] + area[i * width + j - 1] - area[(i - 1) * width + j - 1] + tmp;
                /*
                if(i==1&&j==5)
                {
                */
                //cout<<endl;
                //cout<<tmp<<endl;
                //cout<<area[(i-1)*width+j]<<'+'<<area[i*width+j-1]<<'-'<<area[(i-1)*width+j-1]<<'+'<<tmp<<'='<<area[i*width+j]<<'\t';
                //}
                //if(area[width+5]==0) cout<<"in this place"<<i<<'\t'<<j<<endl;
                //*/
            }
        }
        cout << endl;
    }


    cout << "2 Dimension Sum: " << endl;

    for (int i = 0; i <= tmpLength; i++)
    {
        for (int j = 0; j <= tmpWidth; j++)
            cout << area[i * width + j] << '\t';
        cout << endl;
    }


    int testL = 4, testW = 2;
    //cin>>testL>>testW;

    cout << "Test Result:" << endl;
    int maxResult = 0;
    /*
    if(testL>1&&testW>1)
    {
    */
    for (int i = testL; i <= tmpLength; i++)
    {
        for (int j = testW; j <= tmpWidth; j++)
        {
            int test = 0;
            /*
            if(i==0&&j==0) test=area[(i+testL-1)*width+j+testW-1];
            else if (i==0) test=area[(i+testL-1)*width+j+testW-1]-area[(i+testL-1)*width+j];
            else if (j==0) test=area[(i+testL-1)*width+j+testW-1]-area[i*width+j+testW-1];
            else
            */
            test = area[i * width + j] - area[(i - testL) * width + j] - area[i * width + j - testW] +
                   area[(i - testL) * width + j - testW];
            //cout<<test<<'='<<area[(i+testL-1)*width+j+testW-1]<<'-'<<area[i*width+j+testW-1]<<'-'<<area[(i+testL-1)*width+j]<<'+'<<area[i*width+j]<<'\t';
            cout << test << '\t';
            if (maxResult < test)
                maxResult = test;
        }
        cout << endl;
    }
    /*}
    else if(testL==1)
    {
    for(int i=testL;i<=tmpLength;i++)
    {
        for(int j=testW;j<=tmpWidth;j++)
        {
            int test=0;
            test= area[i*width+j]-area[i*width+j-testW];
            cout<<test<<'\t';
            if(maxResult<test)
                maxResult=test;
        }
        cout<<endl;
    }
    }
    else if(testW==1)
    {
    for(int i=testL;i<=tmpLength;i++)
    {
        for(int j=testW;j<=tmpWidth;j++)
        {
            int test=0;
            test= area[i*width+j]-area[(i-testL)*width+j];
            cout<<test<<'\t';
            if(maxResult<test)
                maxResult=test;
        }
        cout<<endl;
    }
    }
    /*
    else if (testL==1)
    {
    for(int i=0;i<=length-testL;i++)
    {
        for(int j=0;j<=width-testW;j++)
        {
            int test=0;
            test=area[i*width+j+testW-1]-area[i*width+j];
            cout<<test<<'\t';
            if(maxResult<test)
                maxResult=test;
        }
        cout<<endl;
    }
    }
    else if(testW==1)
    {
    for(int i=0;i<=length-testL;i++)
    {
        for(int j=0;j<=width-testW;j++)
        {
            int test=0;
            test=area[(i+testL-1)*width+j]-area[i*width+j];
            cout<<test<<'\t';

            if(maxResult<test)
                maxResult=test;
        }
        cout<<endl;
    }
    }
    */
    //cout<<"Result:"<<endl;
    cout << maxResult;
    return 0;
}

