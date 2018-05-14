#include <iostream>
#include <math.h>

using std::cout;
using std::endl;
double uini(double x, int L);
void avanza(float c, double *act, double *sig, float N, float k);
void actualiza(float N, double *act, double *sig);


//ecuacion de onda, condiciones iniciales
double uini(double x, int L){
    double valor;
    if(x<=0.8*L){
        valor=(1.25*x)/L;
    }
    else{
        valor=(5-5*x)/L;
    }
    return valor;
}


//siendo t=0 para avanzar en x
void avanza(float c, double *act, double *sig, float N, float k){
    int i;
    for(i=0; i<N; i++){
        sig[i]=0.5*k*(act[i+1]-2*act[i]+act[i-1]);
    }
}

void actualiza(float N, double *act, double *sig){
    int i;
    for(i=0; i<N; i++){
        act[i]=sig[i];
    }
}

int main() {
    int T=40, rho=10, L=100;
    int tmax=200, xmin=0, xmax=L;
    float dt=0.01, dx=0.1, c=pow(T/rho, 1/2);
    float N=(xmax-xmin)/(dx+1);
    float k=pow(c*dt/dx, 2);
    double t=0.0;
    
    
    double *act, *sig;
    act= new double[N];
    sig=new double[N];
    
    while(t<tmax){
        int i;
        
        for(i=0; i<N; i++){
            avanza(c, act, sig, N, k);
            actualiza(N, act, sig);
            cout<<t<<" "<<act[i]<<endl;
        }
        t+=dt;
    }
    
    return 0;
}
