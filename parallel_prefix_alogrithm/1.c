#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(int argc, char **argv)
{
	int size, rank;
	double a[64];
	int i;
	double *send;
	double *recv;
	double x_send;
	double x_recv;
	double x0;
	double sum_all;
	sum_all = 0.0;
	x0 = 0.5;
	

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	recv = (double *)malloc(64/size*sizeof(double));
	double x[64/size];
	double p[64/size];
	double *sum;

	if (rank ==0)
	{
		/* code */
		srand((long)time(NULL));
		printf("64 random numbers are:\n");
		for ( i = 0; i < 64; i++)
		{
			a[i] = rand()/(double)RAND_MAX;
			printf("%.6f  ",a[i]);
			if ((i+1)%8==0)
			{
				printf("\n");
			}
		}

	}

	send = a;
	MPI_Scatter(send, 64/size, MPI_DOUBLE, recv, 64/size, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	// for (int i = 0; i < 64/size; i++)
	// {
	// 	printf("Processer %d receive numbers are %f\n",rank, recv[i]);
	// }
	//printf("Processer %d receive numbers are %f\n",rank,*recv);
	MPI_Barrier(MPI_COMM_WORLD);
	if (rank == 0)
	{
		for (i = 0; i < 64/size; i++)
		{
			x[i] = pow(x0,i);
			// printf("%.6f\n",x[i]);
			/* code */
		}
	}

	else
	{
		for (i = 0; i < 64/size ; i++)
		{
			/* code */
			x[i] = pow(x0,i+1);
			// printf("%.6f\n",x[i]);
		}
	}

	x_send = x[64/size - 1];
	//printf("Processer %d send %f\n",rank,x_send);
	x_recv = 0.0;
	//x_recv = (double *)malloc(size*1*sizeof(double));
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Scan(&x_send, &x_recv, 1, MPI_DOUBLE, MPI_PROD, MPI_COMM_WORLD);

	//printf("Processer %d receive numbers are %f\n",rank,x_recv);
	MPI_Barrier(MPI_COMM_WORLD);

	for (i = 0; i < 64/size; i++)
	{
		p[i]= x_recv*x[i]/x_send;
		// p[i]= x_recv*x[i]*recv[i]/x_send;

		// printf("Processer %d got %f\n",rank, p[i]);
	}

	MPI_Barrier(MPI_COMM_WORLD);
	sum = (double *)malloc(64/size*sizeof(double));
	MPI_Reduce(p, sum, 64/size, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);

	if (rank == 0)
	{
		for (i = 0; i < 64/size; i++)
		{
			sum_all += sum[i];
			//printf("Total Sum is %lf\n", sum[i]);
		}
		printf("Total Sum is %lf\n", sum_all);
	}
	
	
	MPI_Finalize();
	return 0;
}