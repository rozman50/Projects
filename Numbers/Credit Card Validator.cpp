//VISA Credit Card Validator (found here: http://www.financetwitter.com/2014/08/cracking-sixteen-digits-credit-card-numbers-what-do-they-mean.html
//Link to picture: http://www.financetwitter.com/wp-content/uploads/2014/08/Cracking-Credit-Card-Numbers-Checking-Fake-Card-with-Last-Check-Digit.png

#include "stdafx.h"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vecInputCredidCardNumber;
	int input = 0;

	std::cout << "Please input your credit card number, digit by digit " << std::endl;

	//Inputing numbers
	for (size_t i = 0; i != 16; ++i) {
		std::cin >> input;
		vecInputCredidCardNumber.push_back(input);
	}

	//Checking if user inputed 16 numbers
	if (vecInputCredidCardNumber.size() != 16) {
		std::cout << "You haven't entered valid credit card number!" << std::endl;
		return 1;
	}

	int sum = 0;

	for (size_t j = 0; j != 16; ++j) {
		std::cout << vecInputCredidCardNumber[j] << std::endl;
		if (j % 2 == 0) {
			if ((vecInputCredidCardNumber[j] * 2) >= 10) {
				int number = vecInputCredidCardNumber[j] * 2;
				int tmp1;
				
				tmp1 = number % 10;
				number /= 10;
				sum += tmp1 + number;
			}
			else {
				sum += vecInputCredidCardNumber[j] * 2;
			}
			
			std::cout << "Sum of " << vecInputCredidCardNumber[j] << " is: " << sum << std::endl;
		}

		else {
			sum += vecInputCredidCardNumber[j];
		}

	}

	std::cout << "Sum is: " << sum << std::endl;


	//CHECKING IF SUM % 10 == 0
	
	if (sum % 10 == 0) {
		std::cout << "Your credit card is valid!" << std::endl;
	}
	else {
		std::cout << "Your credit card is not valid!" << std::endl;
	}
	
	
    return 0;
}

