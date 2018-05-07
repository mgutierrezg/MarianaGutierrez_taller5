#include <iostream>
#include <math.h>

using namespace std;

//declaramos las variables

//declaramos las funciones
double dq1(double p1);
double dp1(double q1);
double dq2(double p2);
double dp2(double q1, double q2);


//Funciones de las dos ecuaciones diferenciales 
double dq1(double p1){
  return p1;
}

double dq2(double p2){
  return p2;
}

double dp1(double q1){
  double e = pow(10.0,-3.0);
  double parente = (4*q1*q1) + (e*e);
  double denominador = pow(parente,1.5);
  double p = 2*q1/denominador;
  return -p;
}

double dp2(double q1, double q2){
  double e = pow(10.0,-3.0);
  double t = 0.0;
  double resta = q1-q2;
  double resta_cuadrado = pow(resta,2);
  double suma = q1 + q2;
  double suma_cuadrado = pow(suma,2);
  double paren1 = resta_cuadrado + ((e*e)/4);
  double denom1 = pow(paren1,1.5);
  double paren2 = suma_cuadrado + ((e*e)/4);
  double denom2 = pow(paren2,1.5);
  double px = (resta/denom1) - (suma/denom2);
  return px;
}

int main(){

  double a = 1.0/(2.0*sqrt(2.0));
  double q1 = a;
  double p1 = 0;
  double q2 = -a;
  double p2 = 0;
  double h  = 0.006;
  double N = 3000.0/h;
  
  for(int i = 0; i<N; i++){

  double kp1_1, kp1_2, kp1_3, kp1_4;
  double kq1_1, kq1_2, kq1_3, kq1_4;
  double kp2_1, kp2_2, kp2_3, kp2_4;
  double kq2_1, kq2_2, kq2_3, kq2_4;

  double q0 = q1;
  
  kq1_1 = dq1(p1);
  kq2_1 = dq2(p2);
  kp1_1 = dp1(q1);
  kp2_1 = dp2(q1,q2);

  kq1_2 = dq1(p1 + kp1_1*h/2);
  kq2_2 = dq2(p2 + kp2_1*h/2);
  kp1_2 = dp1(q1 + kq1_1*h/2);
  kp2_2 = dp2(q1 + kq1_1*h/2 , q2 + kq2_1*h/2);

  kq1_3 = dq1(p1 + kp1_2*h/2);
  kq2_3 = dq2(p2 + kp2_2*h/2);
  kp1_3 = dp1(q1 + kq1_2*h/2);
  kp2_3 = dp2(q1 + kq1_2*h/2 , q2 + kq2_2*h/2);
  
  kq1_4 = dq1(p1 + kp1_3*h);
  kq2_4 = dq2(p2 + kp2_3*h);
  kp1_4 = dp1(q1 + kq1_3*h);
  kp2_4 = dp2(q1 + kq1_3*h , q2 + kq2_3*h);

  
  p1 += (h/6.0) * (kp1_1 + 2*kp1_2 + 2*kp1_3 + kp1_4);
  p2 += (h/6.0) * (kp2_1 + 2*kp2_2 + 2*kp2_3 + kp2_4);
  
  q1 += (h/6.0) * (kq1_1 + 2*kq1_2 + 2*kq1_3 + kq1_4);
  q2 += (h/6.0) * (kq2_1 + 2*kq2_2 + 2*kq2_3 + kq2_4);


  if((q0<0.0 && q1>0.0)||(q0>0.0 && q1<0.0)){
  }
  cout << q2 << "  " << p2 <<  endl; 

  }
  return 0;
}
