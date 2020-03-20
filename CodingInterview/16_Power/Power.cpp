
double Power(double base, int exponent) {

	if (equal(base, 0.0) && exponent < 0) {
		throw runtime_error("Invalid Input");
	}

	unsigned int absExponent = (unsigned int)(exponent);
	if(exponent < 0){
		absExponent = (unsigned int)(-exponent);
	}
	double result = PowerWithUnsignedExponentRecurrent2(base, absExponent);

	if (exponent < 0) {
		result = 1.0 / result;
	}
	return result;
}

double PowerWithUnsignedExponent(int base, unsigned int exponent) {
	double result = 1.0;
	int temp = base;
	while (exponent > 0) {
		if ((exponent & 0x1) != 0) {
			result *= base;
		}
		temp *= temp;
		exponent >>= 1;
	}
	return result;
}


double PowerWithUnsignedExponentRecurrent(int base, unsigned int exponent) {
	if (exponent == 0) {
		return 1.0;
	}
	if (exponent == 1) {
		return base;
	}

	double result = PowerWithUnsignedExponentRecurrent(base, exponent >> 1);
	result *= result;
	if ((exponent & 0x1) == 1) {
		result *= base;
	}
	return result;
}



double PowerWithUnsignedExponentRecurrent2(int base, unsigned int exponent) {
	if (exponent == 0) {
		return 1.0;
	}
	if (exponent == 1) {
		return base;
	}

	if ((exponent & 0x1) == 1) {
		return base * PowerWithUnsignedExponentRecurrent2(base, exponent - 1);
	}
	else {
		double result = PowerWithUnsignedExponentRecurrent2(base, exponent / 2);
		return result * result;
	}
}

bool equal(double a, double b) {
	double epsilon = 1e-15;
	if (abs(a - b) <= epsilon) {
		return true;
	}
	return false;
}




