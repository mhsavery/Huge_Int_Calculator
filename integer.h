#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

static const int ARRAY = 40;

class HugeInteger{

        friend ostream operator<<(ostream&, const HugeInteger&);
        friend istream operator>>(istream&, HugeInteger&);

        private:
                int number[ARRAY];

        public:
                HugeInteger();
                HugeInteger(int operand[]);

                void output();
                void input(int operand[]);

                HugeInteger addition(HugeInteger op2);
                HugeInteger multiply(HugeInteger op2);
                bool isZero();
                bool isEqual(HugeInteger op2);
                bool notEqual(HugeInteger op2);
                bool greatEqual(HugeInteger op2);
                bool lessEqual(HugeInteger op2);

                bool operator==(HugeInteger op2);
                bool operator!=(HugeInteger op2);
                bool operator<=(HugeInteger op2);
                bool operator>=(HugeInteger op2);
                HugeInteger operator+(HugeInteger op2);
                HugeInteger operator*(HugeInteger op2);
};
