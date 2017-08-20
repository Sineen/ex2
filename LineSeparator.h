

typedef struct vector vector;
void addVectors(int dim, vector* w , struct vector v);
vector multiplyVecScal(int dim, int scalar, struct vector v);
int getNumber(char*token);
void getVector(FILE* input , int dim , vector* v , int x);
int braket(int dim, vector* v, vector* w);
void algo(int dim, vector* wVector ,vector* v);
int getNumber(char *token);

