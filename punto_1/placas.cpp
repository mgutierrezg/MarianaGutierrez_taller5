#include <iostream>
#include <math.h>
using namespace std;

//Constantes
double L = 5.0;
double l = 2.0;
double d = 1.0;
double h = 5.0/512.0;
double v0 = 100.0;
//int N = 2*pow((L/h),2.0);
int N = 1000;
int M = 512;
//Matrices y vectores M*M
double potencial[512][512];
double potencial_viejo[512][512];
double x[512];
double y[512];
double Ex[512][512];
double Ey[512][512];

//Metodos
void frontera();
void inicializa();
void relajacion();
void campoe();
void imprime();


void frontera(){
  for(int i =0; i< M; i++){
    potencial_viejo[0][i] = 0.0;
    potencial_viejo[i][0] = 0.0;
    potencial_viejo[M-1][i] = 0.0;
    potencial_viejo[i][M-1] = 0.0;
    potencial[i][0] = 0.0;
    potencial[i][M-1] = 0.0; 
  }
}

void inicializa(){ 
  for(int i =1; i<M-1;i++){
    x[i] = x[i-1] + h;
    for(int j=1; j<M-1;j++){
      y[j]= y[j-1] + h;
      if((x[i]<3.5) && (x[i]>1.5) && (y[i]>3.0-(h/2)) && (y[i]<3.0+(h/2))){
	potencial_viejo[i][j] = v0/2;
      }
      else if((x[i]<3.5) && (x[i]>1.5) && (y[i]>2.0-(h/2)) && (y[i]<2.0+(h/2))){
	potencial_viejo[i][j] = -v0/2;
	potencial[i][j] = -v0/2;
	  }
    }
    
  }
}

void actualiza(){
  for(int i = 0; i<M; i++){
    for(int j = 0; j<M;j++){
      potencial_viejo[i][j] = potencial[i][j];
    }
  }
}

void relajacion(){
  for(int k =0; k<N; k++){
    for(int i = 1; i<M-1;i++){
      for(int j = 1; j<M-1;j++){
	if((x[i]<3.5) && (x[i]>1.5) && (y[i]>3.0-(h/2)) && (y[i]<3.0+(h/2))){
	  potencial[i][j] = v0/2;
	}
	else if((x[i]<3.5) && (x[i]>1.5) && (y[i]>2.0-(h/2)) && (y[i]<2.0+(h/2))){
	  potencial[i][j] = -v0/2;
	}
	else{
	  potencial[i][j] = (potencial_viejo[i+1][j] + potencial_viejo[i][j+1] + potencial[i-1][j] + potencial[i][j-1])*0.25; //despeje de papel
	}
      }
    }
    actualiza();
  }
}

void campoe(){
  for( int i = 0; i<M-1;i++){
    for (int j =0; j<M-1;j++){
      Ex[i][j] = -((potencial[i][j-1] - potencial[i][j+1])/2*h);
      Ey[i][j] = (potencial[i-1][j] - potencial[i+1][j])/2*h;

    }
  }
}

void imprime(){
  for(int i = 510; i>0;i--){
    for(int j=1; j<M-1;j++){
      cout<<potencial[i][j]<<" " <<Ex[i][j]<<" "<<Ey[i][j]<<endl;
    }
  }
}

int main(){
  x[0] = 0.0;
  x[M-1] = L;
  y[0] = 0.0;
  y[M-1] = L;

  frontera();
  inicializa();
  relajacion();
  campoe();
  imprime();
  return 0;
}
