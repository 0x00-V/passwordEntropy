#include <iostream>
#include <string>
#include <cmath>


int poolSize(const std::string& p);
float entropyCalc(int l, int s);
std::string passwordStrength(float pass_entropy);
int main(int argc, char *argv[])
{
	if (argc <= 1) {
		std::cout << "Usage: ./entropy {password}" << std::endl;
		return 1;
	}

	std::string password = argv[1];

	int password_length = password.length();
	int pool_size = poolSize(password);
	float entropy = entropyCalc(password_length, pool_size);
	std::cout << "Your password is " << passwordStrength(entropy) << "\nEntropy: " << entropy << " bits" << std::endl;
	

	return 0;
}


int poolSize(const std::string& p)
{
	bool HL = false, HU = false, HD = false, HS = false;

	for (char c : p)
	{
		if (std::isprint(c) && !std::isspace(c)) {
			if (std::islower(c)) HL = true;
			else if (std::isupper(c)) HU = true;
			else if (std::isdigit(c)) HD = true;
			else HS = true; 
		}
		else {
			std::cout << "Your password contains an invalid character. Supported chars: a-z, A-Z, 0-9, and printable ASCII characters." << std::endl;
			return -1;
		}
	}

	int p_size = 0;
	if (HL) p_size += 26;
	if (HU) p_size += 26;
	if (HD) p_size += 10;
	if (HS) p_size += 32;
	
	return p_size;
}


float entropyCalc(int l, int s)
{
	float H = l * std::log2(s);
	return H;
}


std::string passwordStrength(float pe)
{
	if (pe <= 18.80) return "Very Weak";
	if (pe <= 37.60) return "Weak";
	if (pe <= 52.56) return "Reasonable";
	if (pe <= 80) return "Strong";
	if (pe > 80) return "Very Strong";
}