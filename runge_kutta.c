#include <stdio.h>
#include <math.h>
#define N 50

/*関数f(x, y)の定義*/
double f(double x, double y){
    double ff = pow(x, 2) - y;
    return ff;
}

/*厳密解*/
double exact(double x){
    double t = pow(x, 2) - 2*x + 2;
    return t;
}

int main(void){
    double x[N+1];
    double y[N+1];
    double x0 = 0.0;    //初期条件x[0]
    double y0 = 2.0;    //初期条件y[0]
    double h;   //区間幅
    x[0] = x0;
    y[0] = y0;

    printf("区間幅を入力\n");
    scanf("%lf", &h);

    /*ルンゲクッタ法*/
    double k1, k2, k3, k4;
    //2次
    for(int i=1; i<=N; i++){
        k1 = h * f(x[i-1], y[i-1]);
        k2 = h * f(x[i-1] + h, y[i-1] + k1);
        x[i] = x[i-1] + h;
        y[i] = y[i-1] + (k1 + k2)/2.0;
    }

    //4次
    /*for(int i=1; i<=N; i++){
        k1 = h * f(x[i-1], y[i-1]);
        k2 = h * f(x[i-1] + h/2.0, y[i-1] + k1/2.0);
        k3 = h * f(x[i-1] + h/2.0, y[i-1] + k2/2.0);
        k4 = h * f(x[i-1] + h, y[i-1] + k3);
        x[i] = x[i-1] + h;
        y[i] = y[i-1] + (k1 + 2*k2 + 2*k3 + k4)/6.0;
    }*/

    /*結果の出力*/
    printf("%6s %15s %15s \n", "x[i]", "calculated", "exact");
    for(int i=0; i<=N; i++){
        printf("%6.2f %15.6f %15.6f \n", x[i], y[i], exact(x[i]));
    }

    return 0;
}
