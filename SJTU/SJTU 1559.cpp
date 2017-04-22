#include <iostream>

using namespace std;

struct Point
{
    int x, y;

    Point() {}

    Point(int px, int py) : x(px), y(py) {}

    Point(const Point &p)
    {
        x = p.x;
        y = p.y;
    }

};

struct Answer
{
    int num = 0;
    int square = 0;

    Answer() {}

    Answer(int n, int s) : num(n), square(s) {}
};

Answer bestAnswer(-1, 100000);

void sol(Point pointH[], Point pointG[], int pointHTop, int pointGTop)
{
    if (pointHTop + 1 < bestAnswer.num)
        return;

    int square = 0;
    int num = 0;
    if (pointGTop == -1)
    {
        {
            int minX = 100000;
            int minY = 100000;
            int maxX = -100000;
            int maxY = -100000;

            for (int i = 0; i <= pointHTop; i++)
            {
                if (minX > pointH[i].x) minX = pointH[i].x;
                if (minY > pointH[i].y) minY = pointH[i].y;
                if (maxX < pointH[i].x) maxX = pointH[i].x;
                if (maxY < pointH[i].y) maxY = pointH[i].y;
            }
            square = (maxX - minX) * (maxY - minY);

        }
        if (bestAnswer.num < pointHTop + 1)
        {
            bestAnswer = Answer(pointHTop + 1, square);
        } else if (bestAnswer.num == pointHTop + 1 && bestAnswer.square > square)
        {
            bestAnswer = Answer(pointHTop + 1, square);
        }
        return;
    } else
    {
        Point leftPointH[500];
        int leftPointHTop = -1;
        Point rightPointH[500];
        int rightPointHTop = -1;
        Point upPointH[500];
        int upPointHTop = -1;
        Point downPointH[500];
        int downPointHTop = -1;

        Point leftPointG[500];
        int leftPointGTop = -1;
        Point rightPointG[500];
        int rightPointGTop = -1;
        Point upPointG[500];
        int upPointGTop = -1;
        Point downPointG[500];
        int downPointGTop = -1;


        Point &centG = pointG[0];
        for (int i = 0; i <= pointHTop; i++)
        {
            bool b1 = pointH[i].x <= centG.x;
            bool b2 = pointH[i].y <= centG.y;

            if (pointH[i].x > centG.x)
            {
                rightPointH[++rightPointHTop] = pointH[i];
            } else if (pointH[i].x < centG.x)
            {
                leftPointH[++leftPointHTop] = pointH[i];
            }


            if (pointH[i].y < centG.y)
            {
                downPointH[++downPointHTop] = pointH[i];
            } else if (pointH[i].y > centG.y)
            {
                upPointH[++upPointHTop] = pointH[i];
            }
        }

        for (int i = 1; i <= pointGTop; i++)
        {
            bool b1 = pointG[i].x <= centG.x;
            bool b2 = pointG[i].y <= centG.y;

            if (pointG[i].x > centG.x)
            {
                rightPointG[++rightPointGTop] = pointG[i];
            } else if (pointG[i].x < centG.x)
            {
                leftPointG[++leftPointGTop] = pointG[i];
            }

            if (pointG[i].y < centG.y)
            {
                downPointG[++downPointGTop] = pointG[i];
            } else if (pointG[i].y > centG.y)
            {
                upPointG[++upPointGTop] = pointG[i];
            }
        }

        sol(leftPointH, leftPointG, leftPointHTop, leftPointGTop);
        sol(rightPointH, rightPointG, rightPointHTop, rightPointGTop);
        sol(upPointH, upPointG, upPointHTop, upPointGTop);
        sol(downPointH, downPointG, downPointHTop, downPointGTop);
        return;
    }


}

int main()
{
    int N;
    cin >> N;

    Point pH[500];
    Point pG[500];

    int pHTop = -1;
    int pGTop = -1;


    for (int i = 0; i < N; i++)
    {
        int x, y;
        char type;
        cin >> x >> y >> type;
        if (type == 'H')
            pH[++pHTop] = Point(x, y);
        else
            pG[++pGTop] = Point(x, y);


    }
    sol(pH, pG, pHTop, pGTop);
    cout << bestAnswer.num << " " << bestAnswer.square << endl;
    //system("pause");
}