#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>

using namespace std;

// Derivata di funzioni elementari
string derivaFunzione(const string &funzione)
{
    if (funzione == "sin(x)")
        return "cos(x)";
    else if (funzione == "cos(x)")
        return "-sin(x)";
    else if (funzione == "exp(x)")
        return "exp(x)";
    else if (funzione == "ln(x)")
        return "1/x";
    else if (funzione == "tan(x)")
    {
        string derivata = "1/(cos(x))^2";
        return derivata;
    }
    if (funzione == "ctg(x)" || funzione == "cot(x)")
    {
        string derivata = "-1/(sin(x))^2";
        return derivata;
    }
    else
        return "Function not recognized";
}

// Derivata di polinomi di grado n (es: 3*x^2 + 2*x + 1)
string derivaPolinomio(const string &polinomio)
{
    string pol = polinomio;
    // Remove spaces
    pol.erase(remove(pol.begin(), pol.end(), ' '), pol.end());
    // Replace '-' with '+-' for splitting
    for (size_t i = 1; i < pol.size(); ++i)
    {
        if (pol[i] == '-' && pol[i - 1] != '^')
        {
            pol.insert(i, "+");
            ++i;
        }
    }
    istringstream iss(pol);
    string term, result;
    bool first = true;

    while (getline(iss, term, '+'))
    {
        if (term.empty())
            continue;
        size_t x_pos = term.find("x");
        if (x_pos == string::npos)
        {
            // Termine costante
            continue;
        }
        int coeff = 1, grado = 1;
        size_t coeff_end = term.find("*");
        if (coeff_end != string::npos)
            coeff = stoi(term.substr(0, coeff_end));
        else if (term[0] == '-' && x_pos == 1)
            coeff = -1;
        else if (x_pos == 0)
            coeff = 1;
        if (term.find("^") != string::npos)
            grado = stoi(term.substr(term.find("^") + 1));
        else
            grado = 1;

        int new_coeff = coeff * grado;
        int new_grado = grado - 1;

        if (!first && new_coeff >= 0)
            result += " + ";
        else if (!first && new_coeff < 0)
            result += " - ";
        first = false;

        if (new_grado == 0)
            result += to_string(abs(new_coeff));
        else if (new_grado == 1)
            result += to_string(abs(new_coeff)) + "*x";
        else
            result += to_string(abs(new_coeff)) + "*x^" + to_string(new_grado);
    }
    if (result.empty())
        result = "0";
    return result;
}

// Integrale indefinito di funzioni elementari (forma base, senza costante d'integrazione)
string integraFunzione(const string &funzione)
{
    if (funzione == "sin(x)")
        return "-cos(x)";
    else if (funzione == "cos(x)")
        return "sin(x)";
    else if (funzione == "exp(x)")
        return "exp(x)";
    else if (funzione == "ln(x)")
        return "x*ln(x) - x";
    else if (funzione == "tan(x)")
        return "-ln|cos(x)|";
    else if (funzione == "ctg(x)" || funzione == "cot(x)")
        return "ln|sin(x)|";
    else
        return "Function not recognized";
}

// Integrale indefinito di polinomi di grado n (es: 3*x^2 + 2*x + 1)
string integraPolinomio(const string &polinomio)
{
    string pol = polinomio;
    // Remove spaces
    pol.erase(remove(pol.begin(), pol.end(), ' '), pol.end());
    // Replace '-' with '+-' for splitting
    for (size_t i = 1; i < pol.size(); ++i)
    {
        if (pol[i] == '-' && pol[i - 1] != '^')
        {
            pol.insert(i, "+");
            ++i;
        }
    }
    istringstream iss(pol);
    string term, result;
    bool first = true;

    while (getline(iss, term, '+'))
    {
        if (term.empty())
            continue;
        size_t x_pos = term.find("x");
        int coeff = 1, grado = 0;
        size_t coeff_end = term.find("*");
        if (x_pos == string::npos)
        {
            // Termine costante
            coeff = stoi(term);
            grado = 0;
        }
        else
        {
            if (coeff_end != string::npos)
                coeff = stoi(term.substr(0, coeff_end));
            else if (term[0] == '-' && x_pos == 1)
                coeff = -1;
            else if (x_pos == 0)
                coeff = 1;
            if (term.find("^") != string::npos)
                grado = stoi(term.substr(term.find("^") + 1));
            else
                grado = 1;
        }

        int new_grado = grado + 1;
        double new_coeff = static_cast<double>(coeff) / new_grado;

        if (!first && new_coeff >= 0)
            result += " + ";
        else if (!first && new_coeff < 0)
            result += " - ";
        first = false;

        if (new_grado == 1)
            result += to_string(abs(new_coeff)) + "*x";
        else
            result += to_string(abs(new_coeff)) + "*x^" + to_string(new_grado);
    }
    if (result.empty())
        result = "C";
    else
        result += " + C";
    return result;
}

int myCalcSim()
{
    cout << "Symbolic calculation - Derivative and Integral\n";
    cout << "1. Derivative of elementary function\n";
    cout << "2. Derivative of polynomial\n";
    cout << "3. Integral of elementary function\n";
    cout << "4. Integral of polynomial\n";
    cout << "5. Derivative and Integral (Quotient Rule)\n";
    cout << "0. Exit\n";

    int choice;
    string input;
    while (true)
    {
        cout << "\nSelect option: ";
        if (!(cin >> choice))
        {
            cout << "Value not valid\n";
            cin.clear();
            cin.ignore();
            return (0);
        }
        cin.ignore();
        if (choice == 0)
        {
            cout << "Exit.\n";
            break;
        }
        switch (choice)
        {
        case 1:
            cout << "Enter elementary function (e.g.: sin(x), cos(x), exp(x), ln(x), tan(x), cot(x)): ";
            getline(cin, input);
            cout << "Derivative: " << derivaFunzione(input) << endl;
            break;
        case 2:
            cout << "Enter polynomial (e.g.: 3*x^2+2*x+1): ";
            getline(cin, input);
            cout << "Derivative: " << derivaPolinomio(input) << endl;
            break;
        case 3:
            cout << "Enter elementary function (e.g.: sin(x), cos(x), exp(x), ln(x), tan(x), cot(x)): ";
            getline(cin, input);
            cout << "Integral: " << integraFunzione(input) << endl;
            break;
        case 4:
            cout << "Enter polynomial (e.g.: 3*x^2+2*x+1): ";
            getline(cin, input);
            cout << "Integral: " << integraPolinomio(input) << endl;
            break;
        case 5:
        {
            cout << "Enter numerator polynomial (e.g.: 3*x^2+2*x+1): ";
            string num, den;
            getline(cin, num);
            cout << "Enter denominator polynomial (e.g.: x^2+1): ";
            getline(cin, den);
            cout << "Derivative (Quotient Rule): ("
                 << derivaPolinomio(num) << ")*(" << den << ") - (" << num << ")*(" << derivaPolinomio(den)
                 << ") / (" << den << ")^2" << endl;
            cout << "Integral: ∫(" << num << ")/(" << den << ") dx (not implemented, use partial fractions or substitution)" << endl;
            break;
        }
        default:
            cout << "Invalid option.\n";
            break;
        }
    }
    return 1;
}
