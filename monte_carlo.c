#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    double pi;
    double x, y, z;     //座標
    int count;          //円の内部点の数
    int max;    //点の最大数

    /*初期化*/
    srand(time(NULL));

    /*max=1のときを計算*/
    max = 1;
    count = 0;
    for(int i=0; i<max; i++){
        /*0.0～1.0の間でランダムに値を座標値を取得*/
        x = (double)rand()/RAND_MAX;
        y = (double)rand()/RAND_MAX;
        z = x*x + y*y;

        /*内部点カウント*/
        if(z<1)
            count++;
    }
    /*円周率を計算・出力*/
    pi = (double)count / max*4;
    printf("%d %lf\n", max, pi);

    for(max=10; max<=100000; max+=10){
        count = 0;
        for(int i=0; i<max; i++){
        /*0.0～1.0の間でランダムに値を座標値を取得*/
        x = (double)rand()/RAND_MAX;
        y = (double)rand()/RAND_MAX;
        z = x*x + y*y;

        /*内部点カウント*/
        if(z<1)
            count++;
        }
        /*円周率を計算・出力*/
        pi = (double)count / max*4;
        printf("%d %lf\n", max, pi);
    }
    return 0;
}