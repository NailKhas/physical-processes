#include <iostream>
#include <fstream>

int main() {
    std::ofstream fout;
    fout.open("file.txt");

    float x[10000];
    float v[10000];
    float xw[10000];
    float vw[10000];

    float dt = 0.1;//промежуток времени разбиения
    float w = 1; //частота

    x[0] = 640;
    xw[0] = 640;
    v[0] = 0;
    vw[0] = 0;

//w*w*x[i-1]*x[i-1]/2 + v[i-1]*v[i-1]/2 (удельная Энергия)    
    
////метод Эйлера
    for (int i = 1; i < 1000; i++) {
        x[i] = x[i - 1] + dt * v[i - 1];
        v[i] = v[i - 1] - dt * (w * w * x[i - 1]);
        fout <<x[i-1] << "\t" << dt * (i - 1) << "\n";
    }

//// метод Хойна
    for (int i = 1; i < 15; i++ ){
        xw[i] = x[i-1] + dt*v[i-1];
        vw[i] = v[i-1] - dt*(w*w*x[i-1]);

        x[i] = x[i-1] + (dt/2) * (v[i-1] + vw[i]);
        v[i] = v[i-1] - (dt/2)*(w*w*x[i-1] + w*w*xw[i]);
        fout <<x[i-1]<<"\t"<<dt*(i-1)<<"\n";
    }

    fout.close();
    return 0;
}
