#include "exception.h"

class Rational{
    private:
        int numerator = 0;
        int denomenator = 1;
    public:
        Rational(){
            numerator = 0;
            denomenator = 1;
        };
        Rational(int a, int b){
            if (b == 0){
                throw DividebyZero("Denominator cannot 0");
            }
            numerator = a;
            denomenator = b;
        }
        Rational (const Rational& x){
            numerator = x.numerator;
            denomenator = x.denomenator;
        }
        ~Rational() = default;
        void set_numerator(int a){
            numerator = a;
        }
        void set_denominator(int b){
            if (b == 0){
                throw DividebyZero("Denominator cannot 0");
            }
            denomenator = b;
        }
        int read(FILE* fp){
            int a, b;
            if (fscanf(fp, "%d%d", &a, &b) != 2){
                if (!feof(fp)){
                    return 1;
                }
                return 2;
            }
            set_numerator(a);
            set_denominator(b);
            return 0;
        }

        void init(int a, int b){
            set_numerator(a);
            set_denominator(b);
            return;
        }

        void print(FILE*fp=stdout){
            fprintf(fp, "%d/%d", numerator, denomenator);
        }

        Rational& operator=(const Rational&) = default;  // Copy assignment

        Rational operator+(const Rational& other) const {
            Rational c;
            c.denomenator = denomenator * other.denomenator;
            c.numerator = numerator * other.denomenator + other.numerator * denomenator;
            return c;
        }

        Rational operator*(const Rational& other) const {
            Rational c;
            c.numerator = numerator * other.numerator;
            c.denomenator = denomenator * other.denomenator;
            return c;
        }

};