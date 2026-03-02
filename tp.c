#include <stdio.h>
void main()
{
    int r, c;
    printf("Enter the rows and the coloumns of the matrix.\n");
    scanf("%d%d", &r, &c);
    int mat[r][c];
    printf("Enter elements \n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("The matrix is : \n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    int nz = 0, z = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == 0)
                z++;
            else
                nz++;
        }
    }

    if (nz > z)
        printf("Not a sparse matrix\n");
    else
    {
        int k = 0;
        int sp[nz + 1][3];
        sp[0][0] = r;
        sp[0][1] = c;
        sp[0][2] = nz;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] != 0)
                {
                    sp[k + 1][0] = i;
                    sp[k + 1][1] = j;
                    sp[k + 1][2] = mat[i][j];
                    k++;
                }
            }
        }

        printf("The sparse matrix in 3-tuple format : \n");
        for (int i = 0; i <= nz; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d\t", sp[i][j]);
            }
            printf("\n");
        }
        int trans[nz + 1][3];
        trans[0][0] = sp[0][1];  
        trans[0][1] = sp[0][0];  
        trans[0][2] = sp[0][2];  
        int idx = 1;
        for (int col = 0; col < c; col++)
        {
            for (int i = 1; i <= nz; i++)
            {
                if (sp[i][1] == col)
                {
                    trans[idx][0] = sp[i][1]; 
                    trans[idx][1] = sp[i][0];
                    trans[idx][2] = sp[i][2];
                    idx++;
                }
            }
        }

        printf("Transpose of sparse matrix in 3-tuple format:\n");
        for (int i = 0; i <= nz; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d\t", trans[i][j]);
            }
            printf("\n");
        }
    }
}
