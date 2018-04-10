

#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
float abv(float v){
if(v>=0)return v;
else return (-1)*v;
}
float** ab(float** l,float** u, int rozmiar_macierzy){
    float** A;

int i,j,k;

A=(float**)malloc((rozmiar_macierzy+1)*sizeof(float*));
for(i=0;i<=rozmiar_macierzy;++i){
    //*(A+i)=malloc((n+1)*sizeof(float));
    A[i]=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
}
for(i=1;i<=rozmiar_macierzy;++i){
    for(j=1;j<=rozmiar_macierzy;++j){
            A[i][j]=0;
        for(k=1;k<=rozmiar_macierzy;++k){
                //*(*(A+i)+j)=(*(*(l+i)+k))*(*(*(u+k)+j));
            A[i][j]+=l[i][k]*u[k][j];
        }
    }
}
return A;
}
float* av(float** l,float* v, int rozmiar_macierzy){
    float* A;

int i,j,k;

A=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));

for(i=1;i<=rozmiar_macierzy;++i){

            A[i]=0;
        for(k=1;k<=rozmiar_macierzy;++k){
                //*(*(A+i)+j)=(*(*(l+i)+k))*(*(*(u+k)+j));
            A[i]+=l[i][k]*v[k];//dobrze
        }

}
return A;
}

float** Tr(float** l, int rozmiar_macierzy){
    float** A;

float x;
int i,j,k;

A=(float**)malloc((rozmiar_macierzy+1)*sizeof(float*));
for(i=0;i<=rozmiar_macierzy;++i){
    //*(A+i)=malloc((n+1)*sizeof(float));
    A[i]=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
}

for(i=1;i<=rozmiar_macierzy;++i){
    for(j=1;j<=rozmiar_macierzy;++j){
           x=l[i][j];
           A[i][j]=l[j][i];
           l[j][i]=x;

    }
}
return A;
}

void wyswietl_macierz(float** m,char* nazwa_macierzy, int rozmiar_macierzy){
int i,j;
printf("%s:\n",nazwa_macierzy);
for(j=1;j<=rozmiar_macierzy;++j){
for(i=1;i<=rozmiar_macierzy;++i){
    printf(" %8.5f  ",m[j][i]);
}
printf("\n");

}
 printf("\n\n");
}
void wyswietl_wektor(float* m, char* nazwa_macierzy, int rozmiar_macierzy){
int i,j;
printf("%s:\n",nazwa_macierzy);
for(j=1;j<=rozmiar_macierzy;++j){

    printf(" %8.5f  ",m[j]);

printf("\n");

}
 printf("\n\n");
}

void przepisz_wartosci_macierzy(float** l,float** b, int rozmiar_macierzy){

int i,j,k;

for(i=1;i<=rozmiar_macierzy;++i){
    for(j=1;j<=rozmiar_macierzy;++j){

           l[i][j]=b[i][j];

    }
}

}
void przepisz_wartosci_wektora(float* l,float* v, int rozmiar_macierzy){

int i,j,k;

for(i=1;i<=rozmiar_macierzy;++i){

            l[i]=v[i];
        }
}


float norma_w(float* a,int rozmiar_wektora ){
int i;
float norma_kw=0;
float norma=0;


for(i=1;i<=rozmiar_wektora;++i){


            norma_kw+=a[i]*a[i];
        }


norma=sqrt(norma_kw);
return norma;


}
float* wektor_macierzy(float** A,int k,int rozmiar_macierzy){
    int i;
float*    g=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
for(i=1;i<=rozmiar_macierzy;++i){

g[i]=A[i][k];
}
return g;
}

void macierz_z_wektorow(float** Q,float*q,int k,int rozmiar_macierzy){
    int i;

for(i=1;i<=rozmiar_macierzy;++i){

Q[i][k]=q[i];
}

}

float* dzielenie_przez_liczbe(float* q,float f,int rozmiar_macierzy){
    int i;
float*    a=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
for(i=1;i<=rozmiar_macierzy;++i){
a[i]=q[i]/f;

}
return a;
}
float iloczyn_skalarny(float* v,float* w,int rozmiar_macierzy){
    int i;
float x=0;
for(i=1;i<=rozmiar_macierzy;++i){
x+=v[i]*w[i];
}
return x;
}

int main()
{
float f;
float il;
    int rozmiar_macierzy;

    printf("rozmiar macierzy: ");
    scanf("%d",&rozmiar_macierzy);

    int i,j,k,p;
    int j_max,j2,n,c;
float**a=(float**)malloc((rozmiar_macierzy+1)*sizeof(float*));
for(i=0;i<=rozmiar_macierzy;++i){
    *(a+i)=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
}
float**Q=(float**)malloc((rozmiar_macierzy+1)*sizeof(float*));
for(i=0;i<=rozmiar_macierzy;++i){
    *(Q+i)=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
}

float**R=(float**)malloc((rozmiar_macierzy+1)*sizeof(float*));
for(i=0;i<=rozmiar_macierzy;++i){
    *(R+i)=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
}

float**A_prim=(float**)malloc((rozmiar_macierzy+1)*sizeof(float*));
for(i=0;i<=rozmiar_macierzy;++i){
    *(A_prim+i)=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
}
float**A_l=(float**)malloc((rozmiar_macierzy+1)*sizeof(float*));
for(i=0;i<=rozmiar_macierzy;++i){
    *(A_l+i)=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
}
float**A_ll=(float**)malloc((rozmiar_macierzy+1)*sizeof(float*));
for(i=0;i<=rozmiar_macierzy;++i){
    *(A_ll+i)=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
}
float*q=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
float*a_i=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
float*a_j=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
float*aprim=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
float*q_k=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
float*q_i=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));

     for(i=1;i<=rozmiar_macierzy;i++){


        for(j=1;j<=rozmiar_macierzy;j++)
     {
       Q[i][j]=0;
       R[i][j]=0;
       A_l[i][j]=0;
        A_ll[i][j]=0;
       A_prim[i][j]=0;

      // e[i][j]=0;
     }
     }
     for(i=1;i<=rozmiar_macierzy;i++)
     {

       A_l[i][i]=1;
       A_ll[i][i]=1;
       //P[i][i]=1;
       aprim[i]=0;
       a_i[i]=0;
       a_j[i]=0;
       q[i]=0;
       q_i[i]=0;
     }


     for(j=1;j<=rozmiar_macierzy;j++){
            printf("Napisz elementy wiersza %d macierzy A: \n",j);
for(i=1;i<=rozmiar_macierzy;++i){
    scanf("%f",&a[j][i]);

}
     }
wyswietl_macierz(a,"A",rozmiar_macierzy);
int l;
float*tmp=(float*)malloc((rozmiar_macierzy+1)*sizeof(float));
int ii;
for(l=1;l<=100;l++){
        printf("numer iteracji  l = %d\n",l);
        //A_l=a;
        przepisz_wartosci_macierzy(A_l,a,rozmiar_macierzy);
int i;
q=wektor_macierzy( a, 1, rozmiar_macierzy);
macierz_z_wektorow(A_prim,q,1,rozmiar_macierzy);
    f=norma_w(q,rozmiar_macierzy );
        q=dzielenie_przez_liczbe( q,f,rozmiar_macierzy);
macierz_z_wektorow(Q, q,1,rozmiar_macierzy);
for (i=2;i<=rozmiar_macierzy;i++){
        a_i=wektor_macierzy( a, i, rozmiar_macierzy);
//aprim=a_i;
przepisz_wartosci_wektora(aprim,a_i,rozmiar_macierzy);
for(k=1;k<=i-1;++k){
    q_k=wektor_macierzy(Q,k,rozmiar_macierzy);
    il=iloczyn_skalarny(q_k,a_i,rozmiar_macierzy);
    tmp=dzielenie_przez_liczbe(q_k,1/il,rozmiar_macierzy);

    for( ii=1;ii<=rozmiar_macierzy;ii++){
        aprim[ii]-=tmp[ii];
    }

}
//q_i=aprim;
przepisz_wartosci_wektora(q_i,aprim,rozmiar_macierzy);
macierz_z_wektorow(A_prim,aprim,i,rozmiar_macierzy);
f=norma_w(aprim,rozmiar_macierzy );
q_i=dzielenie_przez_liczbe(q_i,f,rozmiar_macierzy);
macierz_z_wektorow(Q,q_i,i,rozmiar_macierzy);
}

for(i=1;i<=rozmiar_macierzy;i++){
        aprim=wektor_macierzy(A_prim,i,rozmiar_macierzy);
        R[i][i]=norma_w(aprim,rozmiar_macierzy);
    for(j=rozmiar_macierzy;j>i;j--){
        q_i=wektor_macierzy(Q,i,rozmiar_macierzy);
        a_j=wektor_macierzy(a,j,rozmiar_macierzy);
        R[i][j]=iloczyn_skalarny(q_i,a_j,rozmiar_macierzy);
    }

}
wyswietl_macierz(a,"A",rozmiar_macierzy);
wyswietl_macierz(Q,"Q",rozmiar_macierzy);
wyswietl_macierz(R,"R",rozmiar_macierzy);
wyswietl_macierz(ab(Q,R,rozmiar_macierzy),"A=QR?",rozmiar_macierzy);

A_ll=ab(R,Q,rozmiar_macierzy);
a=ab(Q,R,rozmiar_macierzy);

wyswietl_macierz(A_l,"A_l",rozmiar_macierzy);
wyswietl_macierz(A_ll,"A_ll",rozmiar_macierzy);

float diff=abv(A_l[1][1]-A_ll[1][1]);

for(i=2;i<=rozmiar_macierzy;i++){
    if(abv(A_l[i][i]-A_ll[i][i])>diff) diff=abv(A_l[i][i]-A_ll[i][i]);
}

if(diff<=pow(10,-8)){

    break;
}


przepisz_wartosci_macierzy(a,A_ll,rozmiar_macierzy);
     }


printf("\nWartosci wlasne macierzy A:\n");
for( i=1;i<=rozmiar_macierzy;i++){
printf("%.8f\n",A_l[i][i]);
}

printf("\n");



    return 0;
}
