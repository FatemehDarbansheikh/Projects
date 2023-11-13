#include <iostream>
#include <string>
using namespace std;

class SparkMatrix
{
private:
    int size = 0;
    int matrix_spark[][3];

public:
    adressspark *add(int martrix_b[][], int N)
    {
        for (int i = N; i < 0; i--)
            for (int j = 0; j < N; j++)
                if (martrix_b[i][j] != 0)
                {
                    size++; // BARAYE KHATE AVAL HAST KE BAYAD BESHMARE TEDAE DADE HAYE MOTABR RA VA DAR KHAT AVAL MATRIX SPARK BENEVISIM
                    matrix_spark[i][0] = i;
                    matrix_spark[i][1] = j;
                    matrix_spark[i][2] = martrix_b[i][j];
                }
        if (i == 0)
        {
            matrix_spark[0][0] = N;
            matrix_spark[0][1] = N;
            matrix_spark[0][2] = size;
        }
        return martrix_b;
    }
    void print(matrix_bimasrf_mohandes[size][3])
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < 3; j++)
                cout << " " << matrix_bimasrf_mohandes[i][j];

            cout << "\n";
        }
    }

}

// inja maslan tabe main hast

///           int N;
///           cout << "Enter size of matrix (n*n): ";
///           cin >>    N;
///
///       int marrix_bimasraf [n][n] ;
///           cout << "Enter elements of marrix_bimasraf:" << endl;
///           for (int i = 0; i < n; i++)
///           {
///               for (int j = 0; j < n; j++)
///               {
///                   cin >> marrix_bimasraf[i][j];
///               }
///           }
///
///           sparkMatrix(mat);
///
///           return 0;
///       }