#include<stdio.h>
#include<conio.h>
#include<math.h>

#define N 3
#define EPS 0.00000001

float matr[N][N+1]={{-5, 1, 2, -4},
							{-2, 10, 3, 8},
                    {1, -1, 5, 0}};
void show();				/* ������� �� ����� ������� */
float ZEID(float out[]);	/* ������� ������� ������� ������� �������� */

void main()
{
	float out[N]={0};
   printf(" -- Matrix -- \n\n");
   show();
   ZEID(out);
   getch();
}

/* ������� �� ����� ������� */
void show()
{
	int i, j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<=N;j++)
			printf("%8.3f  ", matr[i][j]);
		printf("\n");
	}
}

/* ������� ������� ������� ������� �������� */
float ZEID(float out[])
{
	int i, j, k, step;
   float b[N], c[N][N], cx[N]={0}, norm_b=0, norm_c, tmp;
   /* �������� ������� � ���� �������� ��� �������� */
   for(i=0;i<N;i++)
   {
   	tmp=matr[i][i];
      for(j=0;j<=N;j++)
      	matr[i][j]/=tmp;
   }
   /* �������� ������� � � ������ � */
   for(i=0;i<N;i++)
   {
      for(j=0;j<N;j++)
			c[i][j]=matr[i][j];
      c[i][i]=0;
      b[i]=matr[i][N];
   }
   /* ������� ������� � �� ����� */
   printf("\n - Vector C -\n\n");
   for(i=0;i<N;i++)
   {
   	for(j=0;j<N;j++)
	   	printf("%6.3f  ", c[i][j]);
   	printf("\n");
   }
   /* ������� �� ����� ������ � */
   printf("\n - Vector B -\n\n");
   for(i=0;i<N;i++)
   	printf("%6.3f\n", b[i]);
   /* ���������� ����� ������� � */
   for(i=0;i<N;i++)
   	for(j=0;j<N;j++)
	   {
      	out[i]+=fabs(c[j][i]);
         norm_c=out[0];
         if(out[i]>norm_c) norm_c=out[i];
      }
   //if(norm_c>=1) { printf("Error!\nNorm C = %f\n", norm_c); getch(); return ; }
   /* ���������� ����� ������� � */
   for(i=0;i<N;i++)
		norm_b+=fabs(b[i]);
   /* ������� ����� */
   printf("\n Norm C = %5.3f\n Norm B = %5.3f", norm_c, norm_b);
   /* ������� ���-�� ����� */
   step=(log((1-norm_c)*EPS/norm_b )/log(norm_c))+1;
   printf("\n Number of steps = %d", step);
   /* ���������� ������� �������� ������� */
   for(i=0;i<step;i++)
   {
      for(j=0;j<N;j++) cx[j]=0;
   	for(j=0;j<N;j++)
         for(k=0;k<N;k++)
         {
	      	cx[j]+=c[j][k]*out[k];
   			out[j]=b[j]-cx[j];
         }
   }
   printf("\n\n - Vector otvetov - \n\n");
   for(i=0;i<N;i++) printf("x%d=%5.3f  ", i+1, out[i]);
	return 0;
}

