#include <iostream>
#include <chrono>
using namespace std;

long int power(long long int a, long long int b, long long int mod)
{
    long long int t;
    if (b == 1)
        return a;
    t = power(a, b / 2, mod);
    if (b % 2 == 0)
        return (t * t) % mod;
    else
        return (((t * t) % mod) * a) % mod;
}

class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;
    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now()) {}
    void reset()
    {
        m_beg = clock_t::now();
    }
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

int main()
{
    long long int P, Y, a, A, b, B, ka, kb;

    // Обидві особи будуть узгоджені щодо відкритих ключів Y і P
    Y = 7;
    cout << "The value of Y: " << Y << endl;
    P = 11;
    cout << "The value of P: " << P << endl;

    Timer time;
    // Аліса вибере закритий ключ a
    A = 3;
    a = power(Y, A, P); // отримує згенерований ключ
    // Боб вибере закритий ключ b
    B = 6;
    b = power(Y, B, P); // отримує згенерований ключ
    // Генерація секретного ключа після обміну ключами
    ka = power(b, A, P);
    kb = power(a, B, P);
    double elapsedTime = time.elapsed();
    
    cout << "\nThe private key A for Alice: " << A << endl;
    cout << "Generated key a for Alice: " << a << endl;
    cout << "\nThe private key B for Bob: " << B << endl;
    cout << "Generated key a for Bob: " << b << endl;
    cout << "\nSecret key for the Alice is: " << ka << endl;
    cout << "Secret key for the Bob is: " << kb << endl;
    cout << "\nTime elapsed: " << elapsedTime << " seconds." << endl;

    return 0;
} 
