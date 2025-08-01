// Online C++ compiler to run C++ program online
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    // Numeric Input Value for Choosing Switch Cases.
    int num;
    while (true)
    {
        cout << "Select the any of the case below.\n"
             << "1. Check Number is Even or Odd.\n"
             << "2. Covert Decimal Number to Binary Number.\n"
             << "3. Convert Binary Number to Decimal Number.\n"
             << "4. To Exit the code.\n";

        cin >> num;
        switch (num)
        {
        case 1:
        {
            // Case 1: Check if the Number is Even or Odd.
            // STEP - 1 : Perform AND of The Number.
            // STEP - 2 : Check the last bit.
            // STEP - 3 : if last bit is 1 Then Odd number else Even number.
            int n;
            cout << "Enter the Number" << endl;
            cin >> n;
            if (n & 1)
            {
                cout << n << " is an Odd Number" << endl;
            }
            else
            {
                cout << n << " is an even Number" << endl;
            }

            break;
        }

        case 2:
            // Case 2: Convert a decimal number to its binary representation.
            // STEP - 1 : We extract each bit using bitwise AND (`& 1`) and Each extracted bit is placed at the correct decimal position using `pow(10, i)` to build the binary number.
            // STEP - 2 : shift right (`>> 1`) to move through the number.
            // STEP - 3 : Increment i for decimal position.

            {
                int n, bit = 0, store = 0, i = 0;
                cout << "Enter any Decimal Number" << endl;
                cin >> n;
                int temp = n;
                while (temp)
                {
                    bit = temp & 1;
                    store = bit * (pow(10, i)) + store;
                    temp = temp >> 1;
                    i++;
                }
                cout << "Decimal Conversion of" << n << " is : " << store << endl;
                break;
            }

        case 3:
            // Case 3: Convert a binary number (entered as integer like 1010) to its decimal form.
            // STEP - 1: Extract the last digit using modulo 10 (`% 10`) to get each binary bit.
            // STEP - 2: If the bit is 1, add `2^i` to the answer to reflect its decimal value at position i.
            // STEP - 3: Divide by 10 to remove the last digit and increment `i` for position tracking.
            {
                int n, digit = 0, ans = 0, i = 0;
                cout << "Enter the Binary Number " << endl;
                cin >> n;
                while (n)
                {
                    digit = n % 10;
                    if (digit == 1)
                    {
                        ans = ans + pow(2, i);
                    }
                    n = n / 10;
                    i++;
                }
                cout << "Decimal Conversition of Given Number is :" << ans << endl;

                break;
            }
        case 4:
            cout << "Exit";
            return 0;

        default:
            cout << "Invalid Input";
            break;
        }
    }
    return 0;
}
