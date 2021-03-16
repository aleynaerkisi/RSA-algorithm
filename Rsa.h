#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;



#pragma region Extended-Basic Euclidean
//source : https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/

//euclidiean (normal)
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

//extended euclidiean
int gcdExtended(int a, int b, int* x, int* y)
{
	// Base Case 
	if (a == 0)
	{
		*x = 0;
		*y = 1;
		return b;
	}

	int x1, y1; // To store results of recursive call 
	int gcd = gcdExtended(b % a, a, &x1, &y1);

	// Update x and y using results of 
	// recursive call 
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

#pragma endregion




#pragma region Eratosthenes

int max_sieve_of_eratosthenes(int n)
{//to find prime numbers, return the max prime num in that range
		
	bool* prime;
	prime = new bool[n + 1];
	memset(prime, true, n + 1);
		
	for (int p = 2; p * p <= n; p++)
	{
		
		if (prime[p] == true)
		{
			
			for (int i = p * 2; i <= n; i += p)
				prime[i] = false;
		}
	}
	
	for (int p = n; p >= 2; p--)
	{
		if (prime[p])
		{
			return p;									
		}
	}

	
	return 4;
	
}


#pragma endregion


#pragma region RSA_Algorithm

int modulus(int a, int b)
{
	return a * b;
}


int totuent(int a, int b)
{
	return (a - 1) * (b - 1);
}

int public_key_exponent(int totient) // I changed this according to the definition in the algorithm so it is different than the popular ways
{
	
	//return 3;
	int e,count;
	count = 0;
	
	for (e = 2; e < totient; e++)
	{
		if (gcd(e, totient) == 1)
		{
			cout <<"e: "<< e<<endl;
			return e;

		}
	}
	
	//cout << e;

	/*gcd(e,totuent)==1
	1 < e < totuent*/
	/*if (e <= 1 || e >= totient || gcd(e, totient) != 1)
		return 3;
	
	*/


	//popular exponent 2^16+1

	/*if ((pow(2, 16) + 1) < totuent && gcd((pow(2, 16) + 1), totuent) == 1)
	{
		return pow(2, 16);
	}*/


	
}

int private_key_exponent(int totient,int e)
{
	int d;
	int y;
	int gcd_ext = gcdExtended(e, totient, &d, &y);

	while (d <= 0)
		d += totient;
	d = fmod(d,totient);


	return d;
}

double* encryption(string a,int e,int n)
{
	string cypher;
	double* b = new double[a.length()];

	
	cout << "encrypted text : ";
	double temp;
	for (int i = 0; i < a.length(); i++)
	{
		
		temp = pow(a[i], e);
		temp = fmod(temp,n);
		b[i] = temp;
		//b[i] =fmod( b[i],127);
		cout << char(b[i]);
	}

	cout << endl;

	

	

	

	
	
	
	return b;

}

string decryption(double* cypher, int d, int n,int length)
{
	string original;
	cout << "decrypted text : ";
	double temp;
	int exp = d;
	for (int i = 0; i < length; i++)
	{
		exp = d;
		temp = 1;
		while (exp != 0) {
			temp *= cypher[i];
			temp = fmod(temp, n);
			--exp;
		}



		/*for (int j = 0; j <= d; j++)
		{
			temp = temp * cypher[i];
			temp = fmod(temp, n);
		}*/


		//temp = pow(cypher[i], d);
		//temp = fmod( temp, n);
		//temp = fmod(temp, 127);
		cout << (char)temp;

	}

	cout << endl;
	
	
	

	return original;
}

#pragma endregion


