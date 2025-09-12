#include <iostream>
#include <complex>
#include <cmath>
#include <vector>
#include <string.h>
#include <string>
extern bool StartSave;
void saveToFile(const char *nome, std::string msg, bool toVideo);

// Funzione zeta di Riemann (s = parte reale + i * parte immaginaria)
std::complex<double> zeta(const std::complex<double> &s)
{
    double real_part = s.real();
    double imaginary_part = s.imag();
    if (real_part <= 1)
    { // Per evitare problemi con la serie divergente
        return std::complex<double>(0, 0);
    }
    std::complex<double> result = 0;
    int n = 1;
    while (std::abs(result) < 1e-6)
    { // Soglia per la precisione
        result += 1.0 / std::pow(std::abs(n), s.real());
        n++;
    }
    return result;
}

// Funzione che cerca zeri della funzione zeta (approccio numerico)
// Usando un metodo iterativo per trovare zeri
void find_zeros(double real_start, double real_end, double imaginary_start, double imaginary_end, int iterations)
{

    std::string msg;
    msg.clear();
    if (StartSave)
    {

        msg = "Zeros of the Riemann's zeta in [" + std::to_string(real_start) + "," + std::to_string(real_end) + "]x[" + std::to_string(imaginary_start) + "," + std::to_string(imaginary_end) + "]:\n";

        (void)saveToFile("saveToFile.txt", msg, false);
    }

    for (int i = 0; i < iterations; ++i)
    {
        for (int j = 0; j < iterations; ++j)
        {
            std::complex<double> s = std::complex<double>(real_start + (real_end - real_start) * i / iterations,
                                                          imaginary_start + (imaginary_end - imaginary_start) * j / iterations);
            std::complex<double> z = zeta(s);
            if (std::abs(z.real()) < 1e-6 && std::abs(z.imag()) < 1e-6)
            {
                std::cout << "Zer (approximate ): " << s << std::endl;
                if (StartSave)
                {
                    msg.clear();
                    msg = "Zero (approximate ): " + std::to_string(s.real()) + "i" + std::to_string(s.imag()) + "\n";
                    (void)saveToFile("saveToFile.txt", msg, false);
                }
            }
        }
    }
}
