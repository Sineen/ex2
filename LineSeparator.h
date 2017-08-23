
/**
 *point is a list of numbers that are the vector
 * label is -1 if bad 1 if good and 0 if not have been labeled yet
 */
typedef struct vector vector;
/**
 * @param dim dimintion of the fieled
 * @param w  vector
 * @param v  vector
 * @return  nothing adds the value of v to w ( changes teh w value )
 */
void addVectors(int dim, vector* w , vector v);
/**
 * @param dim the dimintion of teh field we are working on
 * @param scalar scalar we want to multiply by teh vector
 * @param v vector
 * @return a vector taht is th e multiplication of scalar and vector linear way
 */
vector multiplyVecScal(int dim, int scalar, vector v);
/**
 * @param token from a line
 * @return the int vlaue of the token
 */
int getNumber(char*token);
/**
 * @param input  the file we got as input
 * @param dim teh dimintion
 * @param v pointer to the vector we want to add the parameters too
 * @param x  is a flag if we are inputting the input from learning it would be < 0 else
 * its just a vector not in learning
 */
void getVector(FILE* input , int dim , vector* v , int x);
/**
 * @param dim the dimintion of teh field we are working on
 * @param v vector
 * @param w vector
 * @return  1 if the braket is > 0 and -1 if <= 0
 */
int braket(int dim, vector* v, vector* w);
/**
 * @param dim the dimintion of teh field we are working on
 * @param wVector  the base vector
 * @param v a vector we want to culculate aginst the w
 * this function updated wVector to be the linear parser
 */
void algo(int dim, vector* wVector , vector* v);
/**
 * @param dim the dimintion of teh field we are working on
 * @param v the vector we want to check
 * @param w  teh base vector
 */
void labelAndPrint(int dim, vector* v, vector w);
