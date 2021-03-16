#include "Rsa.h"



int main()
{

	
	int a,b,p,q;
	
//#pragma region UserInput
//
//	//take two numbers for the rand function to create the prime numbers randomly
//
//	cout << "Enter a big # for the prime #A: ";
//	cin >> a;
//
//	cout << "Enter a big # for the prime #B: ";
//	cin >> b;
//
//	
//
//#pragma endregion

	//srand(time(NULL));
	//int countA = rand() % a;

	//cout <<countA<<endl;

	
	//int countB = rand() % b;

	//cout << countB<<endl;


	p = max_sieve_of_eratosthenes(100);
	q = max_sieve_of_eratosthenes(50);

	cout <<"p: "<< p << "q: "<<q<<endl;

	int n; //modulus for the both public and private key p*q

	n = modulus(p, q);

	

	int totient; // (p-1)*(q-1)

	totient = totuent(p, q);

	

	int e=public_key_exponent(totient); //e is public key exponent

	
	int d = private_key_exponent(totient, e);// d is the private key exponent




	
	string message;
	cout << "Enter your message... "<<endl;
	cout << ">>";
	cin >> message;
	
	double *encrypted_text=encryption(message, e, n);

	

	cout << endl;

	string decrypted_text = decryption(encrypted_text, d, n,message.length());

	

	delete encrypted_text;

	return 0;
}