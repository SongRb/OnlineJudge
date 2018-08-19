class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx>sx&&ty>sy) if(tx>ty) tx%=ty; else ty%=tx;
        return sx==tx && (ty-sy)%sx==0 || sy==ty && (tx-sx)%sy==0;
    }
};