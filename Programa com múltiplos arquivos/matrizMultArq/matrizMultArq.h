#ifndef MATRIZMULTARQ_H_INCLUDED
#define MATRIZMULTARQ_H_INCLUDED

float** caloca(int l, int c);
void libera(int l, float **A );
void multiplica(float **A,float **B,float **C,int ca,int la,int cb);

#endif // MATRIZMULTARQ_H_INCLUDED
