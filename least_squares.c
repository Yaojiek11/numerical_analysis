/*最小2乗法*/
/*プロットデータから回帰直線を求める*/
#include <stdio.h>
#define N 21

/*配列の平均値を求める*/
double expected(double x[], int n){
    double ave;
    double sum = 0;
    for(int i=0; i<n; i++){
        sum += x[i];
    }
    return sum/n;
}

/*分散を求める*/
double variance(double x[], double y[], double x_bar, double y_bar ,int n){
    double sum = 0;
    for(int i=0; i<n; i++){
        sum += (x[i] - x_bar) * (y[i] - y_bar);
    }
    return sum;
}

int main(void)
{
    int n;
    double x[N], y[N];
    double x_bar, y_bar; //平均値
    double Sx;           //xの分散
    double Sxy;          //x, yの共分散

    //求める回帰直線（y = ax+b）の係数
    double a, b;

    while(1){
        printf("データの個数は n = ");
        scanf("%d", &n);
        printf("\nデータを入力\n");
        for(int i=0; i<n; i++){
            printf("X[%d] = ", i);
            scanf("%lf", &x[i]);
            printf("Y[%d] = ", i);
            scanf("%lf", &y[i]);
        }

        x_bar = expected(x, n);
        y_bar = expected(y, n);

        Sxy = variance(x, y, x_bar, y_bar, n);
        Sx = variance(x, x, x_bar, x_bar, n);

        /*回帰直線の一般式を適用*/
        a = Sxy / Sx;
        b = y_bar - a*x_bar;

        printf("\n回帰直線を求めました.\n");
        printf("y = (%6.3lf)x + (%6.3lf)\n", a, b);   
    }
    return 0;
}