#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int rows=0, columns=0;

// Function to perform Gaussian elimination
void gaussianElimination(double **A, double *b, double *x, int n) {
    // Forward elimination
    for (int i = 0; i < n; i++) {
        // Find the maximum element in the current column
        double maxEl = fabs(A[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(A[k][i]) > maxEl) {
                maxEl = fabs(A[k][i]);
                maxRow = k;
            }
        }

        // Swap the maximum row with the current row
        for (int k = i; k < n; k++) {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }
        double tmp = b[maxRow];
        b[maxRow] = b[i];
        b[i] = tmp;

        // Make the elements below the current row zero
        for (int k = i + 1; k < n; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < n; j++) {
                A[k][j] -= factor * A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    // Back substitution
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}


double** createMatrix(int rows, int columns) 
{
    double** matrix = (double**)calloc(rows, sizeof(double*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)calloc(columns, sizeof(double));
    }
    return matrix;
}

double** matrix_transpose(double **matrix, int nr_rows, int nr_columns)
{
 double** transposed_matrix=createMatrix(nr_columns, nr_rows);
 
 //TODO: copy the matrix elements for cell (i,j) to cell (j,i) of the transposed_matrix
 
 return transposed_matrix;
}

bool is_transposed(double **mat1, int mat1_nr_rows, int mat1_nr_columns, double** mat2, int mat2_nr_rows, int mat2_nr_columns)
{
 if (mat1_nr_rows!=mat2_nr_columns || mat1_nr_columns!=mat2_nr_rows)
     return false;
 
 //TODO: check if cell (i,j) of mat1 is same as cell (j,i) in mat2
 
 return false;
}


void print_matrix(double **matrix, int nr_rows, int nr_columns)
{
 printf("size: %d,%d \n",nr_rows,nr_columns);
 for(int i=0; i<nr_rows; i++)
 {
  int j=0;
  for(j=0; j<nr_columns; j++)
    printf("%.2f ",matrix[i][j]);
  
  printf("\n");
     
 }  

}

double** manually_enter_a_matrix()
{
 printf("Enter the number of matrix rows   : ");
 scanf("%d",&rows);
 printf("Enter the number of matrix columns: ");
 scanf("%d",&columns);
 
 printf("Create matrix of size (%d,%d)\n",rows,columns);
 double** matrix=createMatrix(rows, columns);
 for(int i=0;i<rows;i++)
  for(int j=0;j<columns;j++)
   {
    printf("matrix element (%d,%d)=",i,j);
    scanf("%lf",&matrix[i][j]);
   }
   
 return matrix;
}


void test_matrix_transpose()
{
 printf("Compute a transposed matrix!\n");
 
 double** matrix=NULL;
 double** transposed_matrix=NULL;
 
 matrix=manually_enter_a_matrix(); 
 
 if (matrix!=NULL)
 {
  printf("Entered matrix is:\n");
  print_matrix(matrix, rows, columns); 
  printf("-------------------\n");
  }
 
 transposed_matrix=matrix_transpose(matrix, rows, columns);
   
 if(is_transposed(matrix,rows,columns,transposed_matrix,columns,rows))
   printf("Matrix tranpose worked!\n");
  else
   printf("Matrix tranpose did NOT work!\n");  
   
 if (transposed_matrix!=NULL)
 {
  print_matrix(transposed_matrix, columns, rows);
  free(matrix);
  free(transposed_matrix);
 }
}

double** return_orthogonal_matrix1()
{
 int size=3;
 double **mat1 = (double **)calloc(size, sizeof(double *));

 for (int i = 0; i < size; i++) 
    mat1[i] = (double *)calloc(size, sizeof(double));
    
 mat1[0][0]=1; 
 mat1[1][1]=mat1[2][2]=0.5;
 mat1[2][1]=sqrt(3)/2;
 mat1[1][2]=-mat1[2][1];
 
 return mat1;
}

double** return_orthogonal_matrix2()
{
 int size=3;
 double **mat2 = (double **)calloc(size, sizeof(double *));
 
 for (int i = 0; i < size; i++) 
    mat2[i] = (double *)calloc(size, sizeof(double));

 mat2[0][0]=1; 
 mat2[1][1]=mat2[2][2]=0.5;
 mat2[2][1]=-sqrt(3)/2;
 mat2[1][2]=-mat2[2][1];
 
 return mat2;
}

double** create_identity_matrix(int size)
{
 double** identity_matrix=createMatrix(size,size);
 
 for(int i=0;i<size;i++)
   identity_matrix[i][i]=1;
  
 return identity_matrix;
}


double** matrix_multiplication(double** mat1, int mat1_nr_rows, int mat1_nr_columns,double** mat2,int mat2_nr_rows, int mat2_nr_columns)
{
 //HOMEWORK: the naive implementation to multiply mat1 with mat2 = resulting matrix
 double **resulting_matrix = (double **)calloc(3, sizeof(double *));
 
 //add code here ...

 return resulting_matrix;
}

bool is_same_matrix(double** mat1, int mat1_nr_rows, int mat1_nr_columns,double** mat2,int mat2_nr_rows, int mat2_nr_columns)
{
 //HOMEWORK: check if mat1 and mat2 are the same, 
 // I recommend to subtract one from the other and check if the absolute difference (fabs function) is smaller then a threshold, e.g., 1e-3;
 
 return false;
}

bool test_matrix_multiplication()
{
 int size=3;
 double **identity_matrix=create_identity_matrix(size);
 double **mat1=return_orthogonal_matrix1();
 double **mat2=return_orthogonal_matrix2();
 
 double **resulting_matrix=matrix_multiplication(mat1, size, size, mat2, size, size);
 
 bool did_it_work=is_same_matrix(identity_matrix, 3, 3, resulting_matrix, size, size);
 
 return did_it_work;
}

int main()
{
 test_matrix_transpose();
 
 if(test_matrix_multiplication())
   printf("Matrix multiplication worked!\n");
 else
   printf("Matrix multiplication did NOT work!\n");
  
 return 0;
}





