#include <stdio.h>
#define N 10
int main(void){
    int n;
    double a[N][N], ans, t, x;
    while(1){
        printf("ニュートンの差商公式による補間\n");
        printf("補間点の個数nを入力(1<n<9) n = ");
        scanf("%d", &n);
        if((n <= 1) || (9 <= n)) continue;
        printf("\n補間点の座標を入力\n");
        for(int i=0; i<n; i++){
            printf("x[%d] = ", i);
            scanf("%lf", &a[i][0]);
            printf("y[%d] = ", i);
            scanf("%lf", &a[i][1]);
        }
        break;
    }

    /*各階差商の計算*/
    /*第j+1階差商をa[i][j+1]へ入れる*/
    for(int j=1; j<=n; j++){
        for(int i=0; i<=n-j; i++){
            a[i][j+1] = (a[i+1][j] - a[i][j]) / (a[i+j][0] - a[i][0]);
        }
    }

    while(1){
        printf("\n指定する点は x = ");
        scanf("%lf", &x);
        ans = a[0][1];
        t = 1;

        /*差商公式による計算*/
        for(int j=2; j<=n; j++){
            t *= (x - a[j-2][0]);
            ans += a[0][j] * t;
        }
        printf("\n f(%lf) =%10.6lf\n", x, ans);
    }
    return 0;
}