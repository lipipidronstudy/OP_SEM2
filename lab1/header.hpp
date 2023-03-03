class circle {
public:
    int center[2][1];
    int r;
};

class Matrix {
public:
    int array[3][3];
};

void floatWithoutFirst(float &a);

void floatWithoutSecond(float *a);

void changeFirst(float &a);

void changeSecond(float *a);

void circleFirst(circle &a, int vector[2][1]);

void circleSecond(circle *a, int vector[2][1]);

void matrixFirst(Matrix &matrix, float a);

void matrixSecond(Matrix *matrix, float a);