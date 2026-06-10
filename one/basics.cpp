#include <iostream>
#include<cmath>
using namespace std;
int main() {

/*
ASCII VALUES (Must Know)

Digits
'0' = 48
'1' = 49
...
'9' = 57

Uppercase Letters
'A' = 65
'B' = 66
...
'Z' = 90

Lowercase Letters
'a' = 97
'b' = 98
...
'z' = 122

Convert uppercase → lowercase:
if(c >= 'A' && c <= 'Z')
    c = c + 32;

Convert lowercase → uppercase:
if(c >= 'a' && c <= 'z')
    c = c - 32;

Special Characters
' '  = 32   (space)
'!'  = 33
'"'  = 34
'#'  = 35
'$'  = 36
'%'  = 37
'&'  = 38
'\'' = 39
'('  = 40
')'  = 41
'*'  = 42
'+'  = 43
','  = 44
'-'  = 45
'.'  = 46
'/'  = 47
':'  = 58
';'  = 59
'<'  = 60
'='  = 61
'>'  = 62
'?'  = 63
'@'  = 64

Most Important Relations

'A' = 65
'Z' = 90
'a' = 97
'z' = 122
'0' = 48
'9' = 57

'a' - 'A' = 32
'A' + 32 = 'a'
'a' - 32 = 'A'

'7' - '0' = 7
'0' + 7 = '7'

Checks Used in Coding

if(c >= 'A' && c <= 'Z')   // uppercase
if(c >= 'a' && c <= 'z')   // lowercase
if(c >= '0' && c <= '9')   // digit
*/

// Variable names/identifier
    // • unsigned int : Used for storing integers which will always be positive.
        // • 1 word will be allocated.
        // • Ordinary binary representation will be used.
    // • char : Used for storing characters or small integers.
        // • 1 byte will be allocated.
        // • ASCII code of characters is stored.
    // • float : Used for storing real numbers
        // • 1 word will be allocated.
        // • IEEE FP representation, 8 bits exponent, 24 bits significand.
    // • Double : Used for storing real numbers
        // • 2 words will be allocated.
        // • IEEE FP representation, 11 bits exponent, 53 bits significand.
    // • bool : Used for storing boolean values (true or false).
        // • 1 byte will be allocated.
        // • 0 for false, 1 for true.
    // • void : Used for functions that do not return a value.
        // • No memory is allocated for void type.


    unsigned int a = 10;
    char b = 'A';
    float c = 3.14;
    double d = 3.141592653589793;
    bool e = true;
    // Output the values of the variables
    cout << "Unsigned int: " << a << endl;
    cout << "Char: " << b << endl;
    cout << "Float: " << c << endl;
    cout << "Double: " << d << endl;
    cout << "Bool: " << e << endl;

// Rules regarding expressions
    // • Multiplication must be written explicitly.
    // • S = u t + 0.5 a t t; // not legal
    // • Multiplication, division have higher precedence than addition, subtraction
    // • Multiplication, division have same precedence
    // • Addition, subtraction have same precedence
    // • Operators of same precedence will be evaluated left to right.
    // • Parentheses can be used with usual meaning.
    // • Spaces can be put between operators and values as you like
    // s=u*t+0.5*a*t*t; s = u*t + 0.5*a*t*t; // both OK


    // Example of an expression
    float u = 5.0; // initial velocity
    float t = 2.0; // time
    float a_acc = 9.8; // acceleration
    float s = u * t + 0.5 * a_acc * t * t;
    cout << "Distance traveled: " << s << endl;
    // Example of operator precedence
    int x = 10;
    int y = 5;
    int result = x + y * 2; // multiplication has higher precedence than addition
    cout << "Result of x + y * 2: " << result << endl;
     // Example of using parentheses to change precedence
    result = (x + y) * 2; // addition is evaluated first due to parentheses
    cout << "Result of (x + y) * 2: " << result << endl;
    
// Evaluating “A op B” when A, B have different types
    // •If A,B have different data types: then they will be converted to
    // “more expressive” data type among the two:
    // •int/short/unsigned int are less expressive than float/double
    // •shorter types are less expressive than longer.
    // •The operation will then be performed, and the result will have
    // the more expressive type.
    // •For example, if you multiply int with float, you will get float.

    int intVal = 10;
    float floatVal = 3.14;  
    auto resultVal = intVal * floatVal; // int is converted to float, result is float
    cout << "Result of intVal * floatVal: " << resultVal << endl;

    // Example of mixed type expression
    double doubleVal = 2.71828;
    auto mixedResult = intVal + floatVal * doubleVal; // intVal is converted to double, floatVal is converted to double, result is double
    cout << "Result of intVal + floatVal * doubleVal: " << mixedResult << endl;
    // Example of boolean expression
    bool boolVal = true;
    auto boolResult = boolVal + intVal; // boolVal is converted to int (true becomes 1), result is int
    cout << "Result of boolVal + intVal: " << boolResult << endl;
    // Example of char expression
    char charVal = 'B';
    auto charResult = charVal + intVal; // charVal is converted to int (ASCII value of 'B' is 66), result is int
    cout << "Result of charVal + intVal: " << charResult << endl;
    // Example of mixed type expression with parentheses
    auto mixedParenResult = (intVal + floatVal) * doubleVal; // intVal is converted to double, floatVal is converted to double, result is double
    cout << "Result of (intVal + floatVal) * doubleVal: " << mixedParenResult << endl;
    //expensive datatypes= double > float > int > char > bool

// Blocks and Scope
    // • Code inside {} is called a block.
    // • Blocks are associated with repeats, but you
    // may create them otherwise too.
    // • You may declare variables inside any block.
    // New summing program:
    // • The variable term is defined close to
    // where it is used, rather than at the
    // beginning. This makes the program more
    // readable.
    // • But the execution of this code is a bit
    // involved.
    int n = 5; // number of terms
    float sum = 0.0; // initialize sum
    for (int i = 1; i <= n; i++) {
        float term = 1.0 / i; // calculate the term 1/i
        sum += term; // add the term to the sum
    }
    cout << "Sum of the series 1 + 1/2 + 1/3 + ... + 1/n: " << sum << endl;// The variable 'term' is defined inside the loop block, and it is only accessible within that block. This makes the code more organized and easier to read.

// Scope and Shadowing
// • Variables defined outside a block can be used inside the block, if no variable of the
// same name is defined inside the block.
// • If a variable of the same name is defined, then from the point of definition to the
// end of the block, the newly defined variable gets used.
// • The new variable is said to “shadow” the old variable.
// • The region of the program where a variable defined in a particular definition can be
// used is said to be the scope of the definition.
    int x1 = 10; // outer variable
    cout << "Outer x1: " << x1 << endl; // prints 10
    {
        int x1 = 20; // inner variable shadows outer variable
        cout << "Inner x1: " << x1 << endl; // prints 20
    }
    cout << "Outer x1 after block: " << x1 << endl; // prints 10, outer variable is unaffected by inner variable
    // Example of variable shadowing in a loop
    int sum2 = 0; // outer variable
    for (int i = 1; i <= 5; i++) {
        int sum2 = i * i; // inner variable shadows outer variable
        cout << "Inner sum2 (i*i): " << sum2 << endl; // prints squares of 1 to 5
    }
    cout << "Outer sum2 after loop: " << sum2 << endl; // prints 0, outer variable is unaffected by inner variable
    //break
//     • The condition of the while statement is
// given as true – body will always be
// entered.
// • If nextmark < 0:
// – the while loop execution will terminate
// – Execution continues from the statement after
// while, i.e. cout ...
// • Exactly what we wanted!
// – No need to copy code.
// • Some programmers do not like break
// statements because continuation condition
// gets hidden inside body, instead of being at
// the top.
// • Condition for breaking = compliment of
// condition for continuing loop
/*The continue statement
• The continue is another single word statement.
• If it is encountered in execution:
– The control directly goes to the beginning of the loop for the next
iteration,
– Statements from the continue to the end of the loop body are
skipped.*/
// Example of using break statement
    int count = 0;
    while (true) {
        cout << "Count: " << count << endl;
        count++;
        if (count >= 5) {
            break; // exit the loop when count reaches 5
        }
    }
    // Example of using continue statement
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue; // skip even numbers
        }
        cout << "Odd number: " << i << endl; // prints odd numbers from 1 to 10
    }
    
// Variables and data types
// • inf
// – Obtained by multiplying two large float variables
// – Or dividing by zero
// • nan
// – Zero by zero
// – sqrt(-1)
    // Example of inf and nan
    float inf = 1.0f / 0.0f; // results in infinity
    float nan = 0.0f / 0.0f; // results in NaN (Not a Number)
    cout << "Infinity: " << inf << endl;    
    cout << "NaN: " << nan << endl;
    // Example of checking for inf and nan
    if (inf > 1000.0f) {
        cout << "inf is greater than 1000" << endl;
    }
    // Note: NaN is not equal to anything, including itself
    if (nan != nan) {
        cout << "nan is not equal to itself" << endl;
    }
    //functions
    //     • If you are going to execute the same code several times, possibly with different values:
    // – Define a function that executes the code
    // – Call the function with appropriate values.
    // • Functions can have their own variables which are created in the activation area of the
    // function.
    // – Names can be same in the main program and in the function
    // • A function is like an independent program except that it gets some values (arguments)
    // from the calling program, and returns results to the calling program.
    // • Using functions makes your program “modular”.
    // – Easier to argue correctness, easier to understand, easier to debug.
    // Example of a function definition and call
    auto square = [](int x) { return x * x; }; // lambda function to calculate the square of a number
    int num = 5;
    int result = square(num);
    cout << "Square of " << num << " is " << result << endl;
    // Example of a function with multiple arguments
    auto add = [](int a, int b) { return a + b; }; // lambda function to add two numbers
    int a1 = 10;
    int b1 = 20;
    int sumResult = add(a1, b1);
    cout << "Sum of " << a1 << " and " << b1 << " is " << sumResult << endl;
    // Example of a function that returns a value
    auto factorial = [](int n) {
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    };
    int n1 = 5;
    int factorialResult = factorial(n1);
    cout << "Factorial of " << n1 << " is " << factorialResult << endl;

// Exchanging the values of two variables, attempt 1
// void exchange(int m, int n){
// int temp = m;
// m = n; n = temp;
// return;
// }
// main_program{
// int a=1, b=2;
// exchange(a,b);
// cout << a <<‘ ‘<<
//  b << endl;
// }
// • Does not work. 1, 2 will get printed.
// • When exchange is called, 1, 2 are
// placed into m, n.
// • Execution of exchange exchanges
// values of m,n.
// • Change in m,n does not affect the
// values of a,b of main_program.
// Reference parameters
                // void exchange(int &m, int &n){
                // int temp = m;
                // m = n; n = temp;
                // return;
                // }
                // main_program{
                // int a=1, b=2;
                // exchange(a,b);
                // cout << a <<‘ ‘<<
                //  b << endl;
                // }
// • & before the name of the parameter:
// • Says: “Do not allocate space for this
// parameter, but instead just use the
// variable from the calling program.”
// • When function changes m,n it is
// really changing a,b.
// • Such parameters are called reference
// parameters.
// • 2 1 will be printed, as expected.
    // Example of a function that exchanges the values of two variables using reference parameters
//cartesian to polar coordinates
    auto cartesianToPolar = [](float x, float y, float &r, float &theta) {
        r = sqrt(x * x + y * y); // calculate the radius
        theta = atan2(y, x); // calculate the angle in radians
    };
    float x = 3.0;
    float y = 4.0;  
    float r, theta;
    cartesianToPolar(x, y, r, theta);
    cout << "Cartesian coordinates: (" << x << ", " << y << ")" << endl;
    cout << "Polar coordinates: (r = " << r << ", theta = " << theta << " radians)" << endl;
    
    //  If we want to return more than one result we can do so by
    // using a reference parameter.
    // • If we use a reference parameter R in a function, and pass as
    // argument a variable A, then any change that the function
    // makes in R will be seen by the calling program as a change in A. 
    // • We can use reference parameters to return more than one result from a function.
    // Example of a function that returns multiple results using reference parameters
    auto calculateCircleProperties = [](float radius, float &area, float &circumference) {
        area = M_PI * radius * radius; // calculate the area of the circle
        circumference = 2 * M_PI * radius; // calculate the circumference of the circle
    };
    float radius = 5.0;
    float area, circumference;
    calculateCircleProperties(radius, area, circumference);
    cout << "Circle properties for radius " << radius << ":" << endl;
    cout << "Area: " << area << endl;
    cout << "Circumference: " << circumference << endl;
    // Example of a function that modifies a variable using reference parameters
    auto increment = [](int &value) {
        value++; // increment the value by 1
    };
    int num = 10;
    cout << "Before increment: " << num << endl;
    increment(num);
    cout << "After increment: " << num << endl;
    // Recursion
// • Recursion = The phenomenon of a function calling itself
// – Seems like we are defining the function in terms of itself
// – But no circularity if the arguments to the new call are different from
// the arguments in the original call.
// • Each call executes in its own activation frame.
// • Some call must return without another recursive call
// – Otherwise infinite recursion (error!)
// • In the body of gcd there was just one recursive call. We can
// have several calls if we wish
    // Example of a recursive function to calculate the factorial of a number
                                                                                    // auto factorialRecursive = [](int n) -> int {
                                                                                    //     if (n == 0) {
                                                                                    //         return 1; // base case: factorial of 0 is 1
                                                                                    //     } else {
                                                                                    //         return n * factorialRecursive(n - 1); // recursive case
                                                                                    //     }
                                                                                    // };
                                                                                    // int n2 = 5;
                                                                                    // int factorialRecursiveResult = factorialRecursive(n2);
                                                                                    // cout << "Factorial of " << n2 << " (recursive) is " << factorialRecursiveResult << endl;
                                                                                    
// To check if a recursive function is
// correct we should check
// 1. There are base cases and correct
// results are obtained for the base
// cases.
// 2. The level 1 recursive calls satisfy
// the preconditions.
// 3. The problem size reduces but
// cannot reduce indefinitely.
// 4. If the level 1 calls work correctly,
// the top level call will work
// correctly.
                // • We do not need to argue that the
                // level 1 calls work correctly.
                // • We dont even need to think about
                // calls made by level 1 calls.
                // • 1,2,3 ensure that the computation
                // will terminate eventually.
                // • 4 ensures that the correct result will
                // be returned.

    //                 data-type array-name[size];
    // • size also called length.
    // • array-name[index] gives indexth variable.
    // • Necessary: 0 <= index < size.
    // • Not just a collection of variables: Index may be given as an expression.
    // Example of an array declaration and usage
    const int size = 5;
    int arr[size]; // declare an array of integers with size 5
    // Initialize the array with values
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1; // assign values 1 to 5 to the array
    }
    // Output the values of the array
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; // print each element of the array
    }
    cout << endl;

// Pointers in functions                        // pass by pointer
                            // void CtoP(double x, double y,
                            //  double* pr, double* ptheta){
                            //  *pr = sqrt(x*x + y*y);
                            //  *ptheta = atan2(x,y);
                            //  return;
                            // }
                            // main_program{
                            //  double r, theta;
                            //  CtoP(1,1,&r,&theta);
                            //  cout << r <<‘ ‘
                            //  << theta << endl;
                            // }
// • main_program calls CtoP, supplying &r,
// &theta as third and fourth arguments.
// • This is acceptable because corresponding
// parameters have type double*.
// • The first step of the call copies the addresses of
// r,theta of the main_program into pr,
// ptheta of CtoP.
// • *pr means the variable whose address is in pr,
// in other words, the variable r of
// main_program.
// • Thus CtoP changes the variables of
// main_program.
// • Thus r becomes √2 = 1.41 and theta becomes
// π/4 = 0.79 and are printed.


// True Pass by Reference (C++)
        // void f(int& x) {
        //     x = 10;
        // }

        // int a = 5;
        // f(a);

// After the call:

// a == 10

// Passing arrays to a function
//                                 // int average(int a[], int n){
//                                 // float sum=0;
//                                 // for(int i=0; i<n; i++)
//                                 // sum = sum+a[i];
//                                 // return sum/n;
//                                 // }
//                                 // int main(){
//                                 // int b[4] = {0, 4, 2, 6};
//                                 // cout << average(b, 4) <<
//                                 // endl; // prints 3
//                                 // cout << average(b, 2) <<
//                                 // endl; // prints 2
//                                 // }
// When array is passed as an
// argument, its address is
// passed.
// If you change a[i], it will affect
// the array in the main function
// as well.
// If you need the length of the
// array in the function, it should
// be passed as a parameter as well.

// In general
// elemtype aname[alength];
// • Block of memory of length S*alength is allocated,
// S = size in bytes of a single elemtype variable.
// • aname = starting address of zeroth element = address of allocated
// block.
// • Value of aname cannot be changed.
// • Type of aname: elemtype *
// • Type of aname[i] : elemtype

    // Example of a function that calculates the average of an array of integers
    auto average = [](int a[], int n) -> float {
        float sum = 0.0;
        for (int i = 0; i < n; i++) {
            sum += a[i]; // add each element of the array to the sum
        }
        return sum / n; // return the average
    };

int q[4]={11,12,13,14}, r = 2;
cout << q << " " << r << " " << &r << endl;// q is the address of the first element of the array, r is the value of r, &r is the address of r
cout << q[0] <<" "<< &q[0] << endl; // q[0] is the value of the first element of the array, &q[0] is the address of the first element of the array
cout << q[1] << " " << &q[1] << endl; // q[1] is the value of the second element of the array, &q[1] is the address of the second element of the array
cout << q[2] << " " << &q[2] << endl; // q[2] is the value of the third element of the array, &q[2] is the address of the third element of the array
cout << q[3] << " " << &q[3] << endl; // q[3] is the value of the fourth element of the array, &q[3] is the address of the fourth element of the array

// Index out of range
// Our old array q
// int q[4];
// Address Used for
// 1004-7 q[0]
// 1008-11 q[1]
// 1012-15 q[2]
// 1016-19 q[3]
// q = 1004
// type of q = int*
// Suppose we execute:
// q[10] = 34;
//  Mechanical interpretation as per our rule:
// • variable of the type that q points to, stored at address q
// + 10*S where S is size of a single variable of the type
// that q points to.
// • variable of type int, stored at 1004 + 10*4 = 1044.
// • 34 will get stored in address 1044 which is not part of q!
// • Possibly some other variable will be written into!

                    // double avg(double* M, int n){
                    // double sum = 0;
                    // for(int i=0; i<n; i++)
                    // sum +=M[i];
                    // return sum/n;
                    // }
                    // int main(){
                    // double q[]={11,12,13,14};
                    // cout << avg(q, 4) << endl;
                    // }


// • Let us first check if this is a syntactically
// valid program, never mind what it does.
// • The types of the arguments to a call must
// match the types of the parameters.
// • The first parameter of avg has type double*
// • The first argument in the call is q, whose
// type is double*, because it points to the
// first element of a double array.
// • The second parameter is of type int, and 4
// in the call is indeed an int.

// Remarks
// • When you pass the name of an array in a function call, its value, the starting address
// of the array, is copied to the corresponding parameter.
// • But because we pass the starting address of the array, we are effectively enabling
// the function to pass the array.
// • Can say
                    // • “Array name is passed by value”
                    // • “Array elements are passed by pointer”
// • The interesting part is the [] operator: given the address of an array and an index
// it can get us to the corresponding element, even if the address belongs to a
// different activation frame.

// • The [] operator is defined in terms of pointer arithmetic and dereferencing.

// • q[i] is defined as *(q + i)

//character arrays 
// • A string is a sequence of characters terminated by a null character (’\0’).
// • A string can be stored in a character array.
// Example char array: 
char buffer[80];
// • First way to read into it:

//                                          cin >> buffer;

// • Reads one word (white space terminated) , stores it into buffer, terminated by ‘\0’.
// Suppose user types:
// C++ is nice (newline terminated)
// • Only C++ would go into buffer.
// Note: cin >> buffer does not mention length of buffer, only its starting address.
// • If user types more than 80 characters, there will be “index out of range”.
// – So allocate a large enough array.
// • Note: cin >> buffer; works only for char arrays.
// Example char array: 
char buffee[80];
// • Safe way to read into it:

//                                              cin.getline(char arr,size,delim);

// • Reads a line (terminated by newline) or at most 79 characters.
// • Stores them in buffee, terminated by ‘\0’. Safe.
// • Line read may contain spaces.
// Suppose user types
// C++ is nice (newline terminated)
// • C++ is nice would go into buffee followed by ‘\0’.

    // Write a function that takes two character strings and returns
    // • ‘=‘ if they are equal,
    // • ‘<‘ if the first string will appear before the second in the
    // lexicographic order,
    // • ‘>’ if the first string will appear after the second in the
    // lexicographic order.
                                    // char compareStrings(char* a, char* b) {//character array passing to function
                                    //     int i = 0;
                                    //     while (a[i] != '\0' && b[i] != '\0') { // loop until the end of either string
                                    //         if (a[i] < b[i]) {
                                    //             return '<'; // a comes before b
                                    //         } else if (a[i] > b[i]) {
                                    //             return '>'; // a comes after b
                                    //         }
                                    //         i++; // move to the next character
                                    //     }
                                    //     if (a[i] == '\0' && b[i] == '\0') {
                                    //         return '='; // both strings are equal
                                    //     } else if (a[i] == '\0') {
                                    //         return '<'; // a is shorter than b, so it comes before b
                                    //     } else {
                                    //         return '>'; // b is shorter than a, so a comes after b
                                    //     }
                                    // }

//two dimentional arrays
// • A two-dimensional array is an array of arrays.
// • For example, int a[3][4] is an array of 3 arrays, each of which is an array of 4 integers.
// • a[0], a[1], a[2] are the three arrays of 4 integers each.
// • a[0][0], a[0][1], a[0][2], a[0][3] are the four integers in the first array.
// • a[1][0], a[1][1], a[1][2], a[1][3] are the four integers in the second array.
// • a[2][0], a[2][1], a[2][2], a[2][3] are the four integers in the third array.
// • The memory layout of a two-dimensional array is row-major order, which means that the elements of the first row are stored in contiguous memory locations, followed by the elements of the second row, and so on.
// • The name of a two-dimensional array is a pointer to the first element of the first row, which is itself an array. For example, in int a[3][4], the name a is a pointer to the first element of the first row, which is an array of 4 integers. Therefore, a can be treated as a pointer to an array of 4 integers, and we can use pointer arithmetic to access the elements of the two-dimensional array. For example, a[i][j] can be accessed using pointer arithmetic as *(a + i) + j, which gives us the address of the j-th element in the i-th row.       
// Initialization possible:
int pqr[2][3]={{1,5,7},
                {13,6,2}}; 

char countries[3][20] = {"India", "Nepal", "China"};
// • Creates array countries with 3 rows each of 20 characters.
// • 2d array = collection of 1d arrays.
// • Thus countries[i] = array consisting of countries[i][0]...countries[i][19]
// • Row i of array is initialized using ith character string in rhs.
// • As usual, each character string implicitly includes a ‘\0’ following it.
// • Individual characters can be accessed in the usual manner, e.g. countries[1]
// [1] will be ‘e’.
cout << countries[2] << endl; // prints “China”
// For 2D arrays, the compiler must know the number of columns when passing them to a function.
// Example of a function that takes a 2D array as an argument and prints its elements
                        // void print2DArray(int arr[][3], int rows) {
                        //     for (int i = 0; i < rows; i++) {
                        //         for (int j = 0; j < 3; j++) {
                        //             cout << arr[i][j] << " "; // print each element of the 2D array
                        //         }
                        //         cout << endl; // new line after each row
                        //     }
                        // }

// A program that prints the command line

                                            // int main(int argc, char *argv[]){
                                            // for (int i=0; i<argc; i++)
                                            //  cout << argv[i] << endl;
                                            // }

// • We call main with a more elaborate signature as shown.
// • argc: gives the number of “words” typed on the command line
// • Interpretation of char *argv[]:
// – char x[] says x is an array of char
// – char* argv[] says argv is an array of char*.
// • argv has length argc.
// • Each element of argv is a pointer to each word typed on the command line.
// int main(int argc, char *argv[]){
// for (int i=0; i<argc; i++)
//  cout << argv[i] << endl;
// } 
// What happens when this program is invoked as ./a.out Math Biology
// • argc = 3
// • argv is an array of 3 elements
// • argv[0] contains the address of an 8 element char array containing “./a.out” followed
// by ‘\0’.
// • argv[1] contains the address of a 5 element char array containing “Math” followed by
// ’\0’.
// • argv[2]contains the address of an 8 element char array containing “Biology” followed
// by ’\0’.

// ========================
// C++ STRINGS (BEGINNER)
// ========================

// 1. What is a String?
// --------------------
// A string is a sequence of characters.

// Example:
// string s = "Hello";

// Indexes:
// H e l l o
// 0 1 2 3 4

// --------------------------------------------------

// 2. Taking Input
// ---------------

// Single Word:
// string s;
// cin >> s;

// Input:
// Hello

// Output:
// Hello

// Note:
// cin stops at space.

// --------------------------------------------------

// Full Line:
// string s;
// getline(cin, s);

// Input:
// Hello World

// Output:
// Hello World

// --------------------------------------------------

// 3. Accessing Characters
// ------------------------

// string s = "Hello";

// s[0] -> H
// s[1] -> e
// s[2] -> l

// Example:
// cout << s[0];

// Output:
// H

// --------------------------------------------------

// 4. Length of String
// --------------------

// string s = "Hello";

// s.length()
// s.size()

// Output:
// 5

// --------------------------------------------------

// 5. Traversing a String
// -----------------------

// Using Index:

// for(int i = 0; i < s.length(); i++)
// {
//     cout << s[i];
// }

// --------------------------------------------------

// Using Range-Based Loop:

// for(char c : s)
// {
//     cout << c;
// }

// --------------------------------------------------

// 6. Modifying Characters
// ------------------------

// string s = "Hello";

// s[0] = 'Y';

// Output:
// Yello

// --------------------------------------------------

// 7. Concatenation (Joining Strings)
// -----------------------------------

// string a = "Hello";
// string b = "World";

// string c = a + " " + b;

// Output:
// Hello World

// --------------------------------------------------

// 8. Comparing Strings
// ---------------------

// string a = "abc";
// string b = "abc";

// if(a == b)
// {
//     cout << "Equal";
// }

// Output:
// Equal

// --------------------------------------------------

// 9. Passing Strings to Functions
// --------------------------------

// Pass By Value:

// void print(string s)
// {
//     cout << s;
// }

// A copy of the string is created.

// --------------------------------------------------

// Pass By Reference:

// void print(string& s)
// {
//     cout << s;
// }

// No copy is created.
// More efficient for large strings.

// --------------------------------------------------

// 10. Useful Beginner Operations
// -------------------------------

// First Character:
// s[0]

// Last Character:
// s[s.length() - 1]

// Length:
// s.length()

// Check Empty:
// s.empty()

// --------------------------------------------------

// 11. Common Character Checks
// ----------------------------

// if(s[i] >= 'A' && s[i] <= 'Z')
//     -> Uppercase

// if(s[i] >= 'a' && s[i] <= 'z')
//     -> Lowercase

// if(s[i] >= '0' && s[i] <= '9')
//     -> Digit

// --------------------------------------------------

// ========================================
// IMPORTANT C++ STRING FUNCTIONS
// ========================================

// 1. substr()
// ----------------------------------------

// Purpose:
// Extract a part of a string.

// Syntax:
// s.substr(start, length)

// Example:

// string s = "Programming";

// cout << s.substr(3,4);

// Output:
// gram

// Indexes:
// P r o g r a m m i n g
// 0 1 2 3 4 5 6 7 8 9 10

// Starts at index 3 and takes 4 characters.

// Common Uses:
// - Longest Common Prefix
// - String Parsing
// - Extracting words

// ========================================

// 2. find()
// ----------------------------------------

// Purpose:
// Search for a character or substring.

// Syntax:
// s.find("text")

// Example:

// string s = "Programming";

// cout << s.find("gram");

// Output:
// 3

// Because "gram" starts at index 3.

// ----------------------------------------

// If Not Found:

// if(s.find("xyz") == string::npos)
// {
//     cout << "Not Found";
// }

// string::npos means the substring does not exist.

// Common Uses:
// - Searching words
// - Finding patterns
// - Find First Occurrence Problems

// ========================================

// 3. reverse()
// ----------------------------------------

// Header Required:

// #include <algorithm>

// Purpose:
// Reverse a string or array.

// Example:

// string s = "Hello";

// reverse(s.begin(), s.end());

// cout << s;

// Output:
// olleH

// ----------------------------------------

// Reverse Array:

// int a[] = {1,2,3,4,5};

// reverse(a, a+5);

// Result:
// 5 4 3 2 1

// Common Uses:
// - Reverse String
// - Palindrome Problems
// - Array Manipulation

// ========================================

// 4. sort()
// ----------------------------------------

// Header Required:

// #include <algorithm>

// Purpose:
// Sort elements in ascending order.

// Example:

// string s = "dcba";

// sort(s.begin(), s.end());

// cout << s;

// Output:
// abcd

// ----------------------------------------

// Sort Array:

// int a[] = {5,1,4,2,3};

// sort(a, a+5);

// Output:
// 1 2 3 4 5

// ----------------------------------------

// Descending Order:

// sort(s.rbegin(), s.rend());

// Example:

// string s = "abcd";

// sort(s.rbegin(), s.rend());

// Output:
// dcba

// Common Uses:
// - Valid Anagram
// - 3Sum
// - Sorting Problems

// ========================================

// QUICK REFERENCE
// ========================================

// Extract Part:
// s.substr(start,length)

// Search:
// s.find("text")

// Reverse:
// reverse(s.begin(), s.end())

// Sort Ascending:
// sort(s.begin(), s.end())

// Sort Descending:
// sort(s.rbegin(), s.rend())

// ========================================

return 0;
}                                                                                