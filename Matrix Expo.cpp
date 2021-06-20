class Matrix {
public:
    int ar[5][5];
    Matrix operator*(Matrix x) {
        Matrix mat;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                mat.ar[i][j] = 0;
                for(int k=0; k<3; k++) {
                    mat.ar[i][j] += (ar[i][k] * x.ar[k][j]);
                }
            }
        }
        return mat;
    }
};
