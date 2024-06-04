#include <stdio.h>
#define N 11
int main(void)
{
    int n;
    double Lk, xx, ans, x[N], y[N];

    while(1){
        printf("ラグランジュの補間多項式\n");
        printf("補間点の個数を入力(1<n<10) n = ");
        scanf("%d", &n);
        if((n<=1)||(10<=n)) continue;
        printf("\n補間点の座標を入力\n");
        for(int i=1; i<=n; i++){
            printf("x[%d] = ", i);
            scanf("%lf", &x[i]);
            printf("y[%d] = ", i);
            scanf("%lf", &y[i]);
        }
        break;
    }
    printf("\n指定する点は x = ");
    scanf("%lf", &xx);
    ans = 0.0;

    /*L(x)を計算*/
    for(int k=1; k<=n; k++){
         Lk= 1.0;
        /*Lk(x)を計算*/
        for(int j=1; j<=n; j++){
            if(j != k){
                Lk *= (xx - x[j]) / (x[k]-x[j]);
            }
        }
        ans += Lk * y[k];
    }
    printf("\nx =%10.6lf における値 y =%10.6lf\n", xx, ans);
    return 0;
}