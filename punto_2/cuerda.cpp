#include <iostream>
#include <math.h>
using namespace std;

//funciones 
void u_in_v(double* u, double delta_x, double x_min, int n, double x);
void u_in_p(double* u, double delta_x, double x_min, int n);
void evoluciona(double* u_nuevo, double* u_presente, double* u_viejo, int n, double delta_x, double delta_t, double c);
void actualiza(double* u_nuevo, double* u_presente, double* u_viejo, int n);
void imprime(double* u, int n); 
// constantes para todo

double L = 100.0;
double T = 40.0;
double rho = 10.0;
double c = sqrt(T/rho);


void u_in_v(double* u, double delta_x, double x_min, int n){
  for (int i=0; i<n; i++){
    double x = x_min + i*delta_x;
       if(x <= 0.6*L){
	 u[i] = 1.25*x/L;
       }
	if(x > 0.8*L){
	  u[i] = 5 - (5*x/L);
	}
	cout<<u[i]<<" ";
    }
  cout<<endl;
}


void u_in_p(double* u, double delta_x, double x_min, int n){
  for (int i=0; i<n; i++){
    double x = x_min + i*delta_x;
       if(x <= 0.6*L){
	 u[i] = 1.25*x/L;
       }
	if(x > 0.8*L){
	  u[i] = 5 - (5*x/L);
	}
    }
}

void evoluciona(double* u_nuevo, double* u_presente, double* u_viejo, int n, double delta_x, double delta_t, double c){
  double delta_xc = delta_x *delta_x;
  double delta_tc = delta_t * delta_t;
  double c_c = c* c;
  double k = (delta_tc/delta_xc)*c_c;
  for (int i = 1; i<n-1; i++){
    u_nuevo[i] = (k*(u_viejo[i+1]-2.0*u_viejo[i]+u_viejo[i-1])) + 2*u_viejo[i] - u_presente[i];
  }  
}


void actualiza(double* u_nuevo, double* u_presente, double* u_viejo, int n){
  for (int i = 0; i<n; i++){
    u_viejo[i] = u_presente[i];
    u_presente[i] = u_nuevo[i];
  }
}

void imprime(double* u, int n){
  for (int i = 0; i<n;i++){
    cout<< u[i]<<" ";
  }
  cout<<endl;
}

int main(){
  
  double delta_x = 1, delta_t = 0.1;
  double x=0;
  double x_min = 0.0;
  int nx = L/delta_x + 1;
  int nt = T/delta_t +1;
  
  double *u_nuevo;
  double *u_viejo;
  double *u_presente;
  u_nuevo = new double[nx];
  u_viejo = new double[nx];
  u_presente = new double[nx];
  u_in_v(u_viejo,delta_x, x_min, nx);
  u_in_p(u_presente,delta_x, x_min, nx);

  //Frontera

  u_nuevo[0] =0;
  u_nuevo[nx-1] =0;
  
  for(int j = 1; j<nt;j++){
    if(j !=0 && j%20 ==0){
      imprime(u_viejo,nx);
    }

    evoluciona(u_nuevo, u_presente, u_viejo, nx, delta_x, delta_t, c);
    actualiza(u_nuevo,u_presente,u_viejo,nx);
  }
  return 0;
}
  
