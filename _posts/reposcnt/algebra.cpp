#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <stdexcept>
#include <complex>
namespace ublas = boost::numeric::ublas;

// Funzione per sommare due matrici
ublas::matrix<double> matrix_add(const ublas::matrix<double> &A, const ublas::matrix<double> &B)
{
    if (A.size1() != B.size1() || A.size2() != B.size2())
        throw std::invalid_argument("Dimensions not compatible for the sum");
    ublas::matrix<double> C(A.size1(), A.size2());
    C = A + B;
    return C;
}

// Funzione per moltiplicare due matrici
ublas::matrix<double> matrix_multiply(const ublas::matrix<double> &A, const ublas::matrix<double> &B)
{
    if (A.size2() != B.size1())
        throw std::invalid_argument("Dimension not compatible for multiply");
    ublas::matrix<double> C(A.size1(), B.size2());
    C = ublas::prod(A, B);
    return C;
}

// Funzione per calcolare la trasposta di una matrice
ublas::matrix<double> matrix_transpose(const ublas::matrix<double> &A)
{
    ublas::matrix<double> T(A.size2(), A.size1());
    std::size_t i = 0, j = 0;
    for (i = 0; i < A.size1(); ++i)
        for (std::size_t j = 0; j < A.size2(); ++j)
            T(j, i) = A(i, j);
    return T;
}

// Funzione per calcolare l'inversa di una matrice quadrata
bool matrix_inverse(const ublas::matrix<double> &input, ublas::matrix<double> &inverse)
{
    using namespace boost::numeric::ublas;
    typedef permutation_matrix<std::size_t> pmatrix;

    if (input.size1() != input.size2())
        throw std::invalid_argument("La matrice deve essere quadrata per l'inversa");

    matrix<double> A(input);
    pmatrix pm(A.size1());

    int res = lu_factorize(A, pm);
    if (res != 0)
        return false;

    inverse.assign(ublas::identity_matrix<double>(A.size1()));
    lu_substitute(A, pm, inverse);
    return true;
}

double matrix_determinant(const ublas::matrix<double> &A)
{
    using namespace boost::numeric::ublas;
    if (A.size1() != A.size2())
        throw std::invalid_argument("La matrice deve essere quadrata per il determinante");

    matrix<double> m(A);
    permutation_matrix<std::size_t> pm(m.size1());
    double det = 1.0;

    int res = lu_factorize(m, pm);
    if (res != 0)
        return 0.0;

    for (std::size_t i = 0; i < m.size1(); ++i)
        det *= m(i, i);

    // Count the number of row swaps
    int swaps = 0;
    for (std::size_t i = 0; i < pm.size(); ++i)
        if (i != pm(i))
            ++swaps;

    if (swaps % 2 != 0)
        det = -det;

    return det;
}
int myMatrix()
{
    using namespace std;
    using namespace ublas;

    try
    {
        // Chiede all'utente quale operazione eseguire
        cout << "Which operation?:\n";
        cout << "1. Sum\n";
        cout << "2. Product\n";
        cout << "3. Transpost\n";
        cout << "4. Inverse\n";
        cout << "5. Determinant\n";
        int choice;
        if (!(cin >> choice))
        {
            cerr << "Error: Introduce only numerical values." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;
        }

        size_t rows = 0, cols = 0;
        size_t rowsB = 0, colsB = 0;

        if (choice == 1 || choice == 2) // Sum or Product
        {
            cout << "Introduce number of rows and columns for matrix A:\n";
            if (!(cin >> rows >> cols))
            {
                cerr << "Error: Introduce only numerical values." << endl;
                cin.clear();
                return -1;
            }
            cout << "Introduce number of rows and columns for matrix B:\n";
            if (!(cin >> rowsB >> colsB))
            {
                cerr << "Error: Introduce only numerical values." << endl;
                cin.clear();
                return -1;
            }

            // Check dimensions for sum and product
            if (choice == 1 && (rows != rowsB || cols != colsB))
            {
                cout << "Error: For sum, matrices must have the same dimensions.\n";
                return 0;
            }
            if (choice == 2 && (cols != rowsB))
            {
                cout << "Error: For product, columns of A must equal rows of B.\n";
                return 0;
            }

            ublas::matrix<double> A(rows, cols), B(rowsB, colsB);
            cout << "Introduce the elements of matrix A:\n";
            for (size_t i = 0; i < rows; ++i)
                for (size_t j = 0; j < cols; ++j)
                {
                    cout << "A[" << i << "," << j << "]=";
                    if (!(cin >> A(i, j)))
                    {
                        cerr << "Error: Introduce only numerical values." << endl;
                        cin.clear();
                        return -1;
                    }
                }
            cout << "Introduce the elements of matrix B:\n";
            for (size_t i = 0; i < rowsB; ++i)
                for (size_t j = 0; j < colsB; ++j)
                {
                    cout << "B[" << i << "," << j << "]=";
                    if (!(cin >> B(i, j)))
                    {
                        cerr << "Error: Introduce only numerical values." << endl;
                        cin.clear();
                        return -1;
                    }
                }

            if (choice == 1)
            {
                auto C = matrix_add(A, B);
                cout << "\nA + B:\n"
                     << C << endl;
            }
            else
            {
                auto D = matrix_multiply(A, B);
                cout << "\nA * B:\n"
                     << D << endl;
            }
            return 1;
        }
        else if (choice == 3)
        {
            cout << "Introduce the number of rows and columns:\n";
            if (!(cin >> rows >> cols))
            {
                cerr << "Error: Introduce only numerical values." << endl;
                cin.clear();
                return -1;
            }
            ublas::matrix<double> A(rows, cols);
            for (size_t i = 0; i < rows; ++i)
                for (size_t j = 0; j < cols; ++j)
                {
                    cout << "A[" << i << "," << j << "]=";
                    if (!(cin >> A(i, j)))
                    {
                        cerr << "Error: Introduce only numerical values." << endl;
                        cin.clear();
                        return -1;
                    }
                }

            auto T = matrix_transpose(A);
            cout << "Transpost matrix of A:\n"
                 << T << endl;
            return 1;
        }
        else if (choice == 4)
        {
            cout << "Introduce size of square matrix:\n";
            cin >> rows;
            matrix<double> A(rows, rows);
            size_t i = 0, j = 0;
            for (i = 0; i < rows; ++i)
                for (j = 0; j < rows; ++j)
                {
                    cout << "A[" << i << "," << j << "]=";
                    cin >> A(i, j);
                }

            matrix<double> invA(rows, rows);
            if (matrix_inverse(A, invA))
            {
                cout << "Inverse matrix of A:\n"
                     << invA << endl;
                return 1;
            }
            else
            {
                cout << "A isn't invertible\n";
                return 0;
            }
        }
        else if (choice == 5)
        {
            cout << "Introduce size of square matrix:\n";
            cin >> rows;
            matrix<double> A(rows, rows);
            size_t i = 0, j = 0;
            for (i = 0; i < rows; ++i)
                for (j = 0; j < rows; ++j)
                {
                    cout << "A[" << i << "," << j << "]=";
                    cin >> A(i, j);
                }
            double det = matrix_determinant(A);
            cout << "Determinant of A: " << det << endl;
            return 1;
        }
        else
        {
            cout << "Operation not valid.\n";
            return 0;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
    catch (...)
    {
        std::cerr << "Unknown error occurred." << std::endl;
        return -1;
    }
}

int myEquations()
{

    using namespace std;
    using namespace ublas;

    size_t n;
    cout << "Introduce the number of equations/unknowns (n): ";
    if (!(cin >> n))
    {
        cerr << "Error: Introduce only numerical values." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }

    matrix<double> A(n, n);
    ublas::vector<double> b(n);

    cout << "Introduce the coefficients of the matrix A (n x n):" << endl;
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
        {
            cout << "A[" << i << "," << j << "]=";
            if (!(cin >> A(i, j)))
            {
                cerr << "Error: Introduce only numerical values." << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return -1;
            }
        }

    cout << "Introduce the terms of the vector b (n):" << endl;
    for (size_t i = 0; i < n; ++i)
    {
        cout << "b[" << i << "]=";
        if (!(cin >> b(i)))
        {
            cerr << "Error: Introduce only numerical values." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;
        }
    }

    permutation_matrix<std::size_t> pm(n);
    matrix<double> A_copy(A);
    int res = lu_factorize(A_copy, pm);
    if (res != 0)
    {
        cerr << "Error: The system cannot be solved (singular matrix)." << endl;
        return 0;
    }
    ublas::vector<double> x(b);
    lu_substitute(A_copy, pm, x);

    cout << "Solution vector x:" << endl;
    for (size_t i = 0; i < n; ++i)
        cout << "x[" << i << "] = " << x(i) << endl;

    return (1);
}

int myPolynomials()
{
    using namespace std;

    int n;
    cout << "Introduce the degree of the polynomials (n): ";
    if (!(cin >> n) || n < 0)
    {
        cerr << "Error: Introduce only non-negative numerical values." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }

    vector<double> A(n + 1), B(n + 1);
    cout << "Introduce the coefficients of the first polynomial (highest degree first):" << endl;
    for (int i = 0; i <= n; ++i)
    {
        cout << "A[" << i << "]=";
        if (!(cin >> A[i]))
        {
            cerr << "Error: Introduce only numerical values." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;
        }
    }
    cout << "Introduce the coefficients of the second polynomial (highest degree first):" << endl;
    for (int i = 0; i <= n; ++i)
    {
        cout << "B[" << i << "]=";
        if (!(cin >> B[i]))
        {
            cerr << "Error: Introduce only numerical values." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;
        }
    }

    // Remove leading zeros from B
    int degB = n;
    while (degB > 0 && fabs(B[n - degB]) < 1e-12)
        degB--;
    if (degB == 0 && fabs(B[n]) < 1e-12)
    {
        cerr << "Error: Division by zero polynomial." << endl;
        return -1;
    }

    vector<double> Q(n - degB + 1, 0.0);
    vector<double> R = A;

    for (int i = 0; i <= n - degB; ++i)
    {
        int idx = i;
        double coeff = R[idx] / B[0];
        Q[i] = coeff;
        for (int j = 0; j <= degB; ++j)
        {
            R[idx + j] -= coeff * B[j];
        }
    }

    cout << "Quotient polynomial coefficients (highest degree first):" << endl;
    for (size_t i = 0; i < Q.size(); ++i)
        cout << "Q[" << i << "] = " << Q[i] << endl;

    cout << "Remainder polynomial coefficients (highest degree first):" << endl;
    for (size_t i = 0; i < R.size(); ++i)
        if (i < degB)
            cout << "R[" << i << "] = " << R[i] << endl;

    return 1;
}

int mySolEq()
{
    using namespace std;

    int degree;
    cout << "Introduce the degree of the equation (n, max 3): ";
    if (!(cin >> degree) || degree < 1 || degree > 3)
    {
        cerr << "Error: Only degrees 1, 2, or 3 are supported." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }

    vector<double> coeffs(degree + 1);
    cout << "Introduce the coefficients (from highest degree to constant term):" << endl;
    for (int i = 0; i <= degree; ++i)
    {
        cout << "a[" << i << "] = ";
        if (!(cin >> coeffs[i]))
        {
            cerr << "Error: Introduce only numerical values." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;
        }
    }

    // Remove leading zeros
    int real_degree = degree;
    while (real_degree > 0 && fabs(coeffs[degree - real_degree]) < 1e-12)
        real_degree--;
    if (real_degree == 0 && fabs(coeffs[degree]) < 1e-12)
    {
        cerr << "Error: All coefficients are zero." << endl;
        return -1;
    }

    // Linear equation
    if (real_degree == 1)
    {
        double a = coeffs[0], b = coeffs[1];
        if (fabs(a) < 1e-12)
        {
            cerr << "Error: Not a valid linear equation." << endl;
            return -1;
        }
        double x = -b / a;
        cout << "Solution: x = " << x << endl;
        return 1;
    }

    // Quadratic equation
    if (real_degree == 2)
    {
        double a = coeffs[0], b = coeffs[1], c = coeffs[2];
        if (fabs(a) < 1e-12)
        {
            cerr << "Error: Not a valid quadratic equation." << endl;
            return -1;
        }
        double delta = b * b - 4 * a * c;
        cout << "Discriminant: " << delta << endl;
        if (delta > 0)
        {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Two real solutions: x1 = " << x1 << ", x2 = " << x2 << endl;
        }
        else if (fabs(delta) < 1e-12)
        {
            double x = -b / (2 * a);
            cout << "One real solution: x = " << x << endl;
        }
        else
        {
            double real = -b / (2 * a);
            double imag = sqrt(-delta) / (2 * a);
            cout << "Two complex solutions: x1 = " << real << " + " << imag << "i, x2 = " << real << " - " << imag << "i" << endl;
        }
        return 1;
    }

    // Cubic equation (Cardano's method)
    if (real_degree == 3)
    {
        double a = coeffs[0], b = coeffs[1], c = coeffs[2], d = coeffs[3];
        if (fabs(a) < 1e-12)
        {
            cerr << "Error: Not a valid cubic equation." << endl;
            return -1;
        }
        // Depressed cubic: x = t - b/(3a)
        double p = (3 * a * c - b * b) / (3 * a * a);
        double q = (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / (27 * a * a * a);
        double discriminant = (q * q) / 4 + (p * p * p) / 27;
        double offset = -b / (3 * a);

        if (fabs(discriminant) < 1e-12)
            discriminant = 0.0;

        if (discriminant > 0)
        {
            double sqrt_disc = sqrt(discriminant);
            double u = cbrt(-q / 2 + sqrt_disc);
            double v = cbrt(-q / 2 - sqrt_disc);
            double x1 = u + v + offset;
            cout << "One real solution: x = " << x1 << endl;
        }
        else if (discriminant == 0)
        {
            double u;
            if (q < 0)
                u = cbrt(-q / 2);
            else
                u = -cbrt(q / 2);
            double x1 = 2 * u + offset;
            double x2 = -u + offset;
            cout << "Multiple real solutions: x1 = " << x1 << ", x2 = x3 = " << x2 << endl;
        }
        else
        {
            double r = sqrt(-p * p * p / 27);
            double phi = acos(-q / (2 * r));
            double m = 2 * cbrt(r);
            double x1 = m * cos(phi / 3) + offset;
            double x2 = m * cos((phi + 2 * M_PI) / 3) + offset;
            double x3 = m * cos((phi + 4 * M_PI) / 3) + offset;
            cout << "Three real solutions:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
            cout << "x3 = " << x3 << endl;
        }
        return 1;
    }

    // This should not be reached due to degree check above
    cout << "Solving equations of degree > 3 is not supported." << endl;
    return 0;
}

int myComplex()
{
    using namespace std;

    complex<double> a, b;
    int choice;

    cout << "Complex Numbers Operations Menu:\n";
    cout << "1. Addition (a + b)\n";
    cout << "2. Subtraction (a - b)\n";
    cout << "3. Multiplication (a * b)\n";
    cout << "4. Division (a / b)\n";
    cout << "5. Modulus (|a|)\n";
    cout << "6. Argument (arg(a))\n";
    cout << "7. Conjugate (conj(a))\n";
    cout << "Choose an operation: ";
    if (!(cin >> choice))
    {
        cerr << "Error: Introduce only numerical values." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }

    if (choice >= 1 && choice <= 4)
    {
        cout << "Introduce real and imaginary part of a (separated by space): ";
        double re, im;
        if (!(cin >> re >> im))
        {
            cerr << "Error: Introduce only numerical values." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;
        }
        a = complex<double>(re, im);

        cout << "Introduce real and imaginary part of b (separated by space): ";
        if (!(cin >> re >> im))
        {
            cerr << "Error: Introduce only numerical values." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;
        }
        b = complex<double>(re, im);
    }
    else if (choice >= 5 && choice <= 7)
    {
        cout << "Introduce real and imaginary part of a (separated by space): ";
        double re, im;
        if (!(cin >> re >> im))
        {
            cerr << "Error: Introduce only numerical values." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1;
        }
        a = complex<double>(re, im);
    }
    else
    {
        cout << "Operation not valid." << endl;
        return 0;
    }

    switch (choice)
    {
    case 1:
        cout << "a + b = " << a + b << endl;
        break;
    case 2:
        cout << "a - b = " << a - b << endl;
        break;
    case 3:
        cout << "a * b = " << a * b << endl;
        break;
    case 4:
        if (abs(b) < 1e-12)
        {
            cerr << "Error: Division by zero." << endl;
            return -1;
        }
        cout << "a / b = " << a / b << endl;
        break;
    case 5:
        cout << "|a| = " << abs(a) << endl;
        break;
    case 6:
        cout << "arg(a) = " << arg(a) << " radians" << endl;
        break;
    case 7:
        cout << "conj(a) = " << conj(a) << endl;
        break;
    default:
        cout << "Operation not valid." << endl;
        return 0;
    }
    return 1;
}