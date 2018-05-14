
#include <iostream>
#include <math.h>
using std::cout;
using std::endl;


double dq1(double p);
double dp1(double q, float e);
double dq2(double p);
double dp2(double q1, double q2, float e);
void runge(double *q1, double *p1, double *q2, double *p2, float e);


double dq1(double p){
    return p;
}

double dp1(double q, float e){
    double a;
    a=(-2*q)/(pow(4*q*q+e*e, 3/2));
    return a;
}

double dq2(double p){
    return p;
}

double dp2(double q1, double q2, float e){
    double c, a, b;
    a=(q1-q2)/(pow(pow((q1-q2), 2)+pow(e/4, 2), 3/2));
    b=(q1+q2)/(pow(pow((q1+q2), 2)+pow(e/4, 2), 3/2));
    c=a-b;
    
    return c;
}

void runge(double *q1, double *p1, double *q2, double *p2, float e){
    double h=0.1;
    double q_1, p_1, q_2, p_2;
    
    q_1= *q1;
    p_1=*p1;
    q_2= *q2;
    p_2=*p2;
    
    
    //para q1 y p1
    double k1q1, k2q1, k3q1, k4q1;
    double k1p1, k2p1, k3p1, k4p1;
    
    k1q1=dq1(p_1);
    k1p1=dp1(q_1, e);
    k2q1=dq1(p_1+(h/2)*k1p1);
    k2p1=dp1(q_1+(h/2)*k1q1, e);
    k3q1=dq1(p_1+(h/2)*k2p1);
    k3p1=dp1(q_1+(h/2)*k2q1, e);
    k4q1=dq1(p_1+h*k3p1);
    k4p1=dp1(q_1+h*k3q1, e);
    
    
    //para q2 y p2
    double k1q2, k2q2, k3q2, k4q2;
    double k1p2, k2p2, k3p2, k4p2;
    k1q2=dq2(p_2);
    k1p2=dp2(q_1, q_2, e);
    k2q2=dq2(p_2+(h/2)*k1p2);
    k2p2=dp2(q_1+(h/2)*k1q1, q_2+(h/2)*k1q2, e);
    k3q2=dq2(p_2+(h/2)*k2p2);
    k3p2=dp2(q_1+(h/2)*k2q1, q_2+(h/2)*k2q2, e);
    k4q2=dq2(p_2+h*k3p2);
    k4p2=dp2(q_1+h*k3q1, q_2+h*k3q2, e);
    
    q_1=q_1+(h/6)*(k1q1+2*k2q1+2*k3q1+k4q1);
    p_1=p_1+(h/6)*(k1p1+2*k2p1+2*k3p1+k4p1);
    q_2=q_2+(h/6)*(k1q2+2*k2q2+2*k3q2+k4q2);
    p_2=p_2+(h/6)*(k1p2+2*k2p2+2*k3p2+k4p2);
    
    //modificar valores
    *q1=q_1;
    *p1=p_1;
    *q2=q_2;
    *p1=p_1;
    
}

int main() {
    float dt=0.006, e=0.001, a=1.0/(2*sqrt(2));
    float N=3000/dt;
    int i;
    double q1=a, p1=0, q2=-a, p2=0;
    double qpasado=q1;

    for(i=0; i<N;i++){
        runge(&q1, &p1, &q2, &p2, e);
        if(qpasado*q1<0){
            cout<<q2<<" "<<p2<<endl;
        }
    }
    
    return 0;
}








