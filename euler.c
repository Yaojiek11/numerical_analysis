#include <stdio.h>
#include <math.h>
#define N 20

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

    /*オイラー法*/
    for(int i=1; i<=N; i++){
        x[i] = x[i-1] + h;
        y[i] = y[i-1] + h*f(x[i-1], y[i-1]);
    }

    /*結果の出力*/
    printf("%6s %15s %15s \n", "x[i]", "calculated", "exact");
    for(int i=0; i<=N; i++){
        printf("%6.2lf %15.6lf %15.6lf \n", x[i], y[i], exact(x[i]));
    }
    return 0;
}
