#include <iostream>
using namespace std;

int initial_x;
int r_x, r_y;
const int N = 20;
int table[20] = {450000, 265651, 140362, 71250, 35763, 17899, 8952, 4476, 2238, 1119, 560, 280, 140, 70, 35, 17, 9, 4, 2, 1};
void cordic(int, int, int);

int main() {
    initial_x = 6072529;
    cordic(initial_x, 0, 372372);
    //cout << initial_x << " " << r_x << " " << r_y << endl;
    return 0;
}

void cordic(int a, int b, int c){
    int r, s;
    int x = a;
    int y = b;
    int th = c;
    for(int k = 0; k < N; k ++){
        if (th >= 0){
            r = x - (y >> k);
            s = (x >> k) + y;
            x = r;
            y = s;
            th = th - table[k];
        }
        else{
            r = x + (y >> k);
            s = - (x >> k) + y;
            x = r;
            y = s;
            th = th + table[k];
        }
        cout << k << " " << th << " " << x << " " << y << endl;
    } 
    r_x = x;
    r_y = y;
}
