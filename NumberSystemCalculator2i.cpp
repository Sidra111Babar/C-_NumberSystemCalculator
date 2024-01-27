//binary,octal,hexadecimal to decimal and vice versa, also a function (points Values)
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int binaryToDecimal(int binary){
	int base = 2;
	int exponent = 0;
	int decimalNumber = 0;
	int lastInteger;
	int remainingNumber;
	while ( binary > 0 ) {
		remainingNumber = binary/10;
		lastInteger = binary%10;
		decimalNumber = decimalNumber + (lastInteger * pow(base,exponent));
		binary = remainingNumber;
		exponent++;
	}
	return decimalNumber;      	
} 
int octalToDecimal(int octal){
	int base = 8;
	int exponent = 0;
	int decimalNumber = 0;
	int lastInteger;
	int remainingNumber;
	while ( octal > 0 ) {
		remainingNumber = octal/10;
		lastInteger = octal%10;
		decimalNumber = decimalNumber + (lastInteger * pow(base,exponent));
		octal = remainingNumber;
		exponent++;  
	}
	return decimalNumber;      	
} 
int hexadecimalToDecimal(string hex) {
    int decimalNumber = 0;
    int base = 16;
    int exponent = 0;

    for (int i = hex.size() - 1; i >= 0; i--) {
        char hexDigit = hex[i];
        int digitValue;

        if (hexDigit >= '0' && hexDigit <= '9') {
            digitValue = hexDigit - '0';
        } else if (hexDigit >= 'A' && hexDigit <= 'F') {
            digitValue = 10 + (hexDigit - 'A');
        } else if (hexDigit >= 'a' && hexDigit <= 'f') {
            digitValue = 10 + (hexDigit - 'a');
        } else {
            // Handle invalid input
            cout << "Invalid hexadecimal digit: " << hexDigit << endl;
            return -1; // Return an error value
        }

        decimalNumber += digitValue * pow(base, exponent);
        exponent++;
    }

    return decimalNumber;
}
double fbinaryTofDecimal(string fbinary){
	int base = 2;
    int exponent = 0;
    double decimalNumber = 0;

    // Convert integer part
    size_t dotPosition = fbinary.find('.');
    string integerPart = fbinary.substr(0, dotPosition);
    for (int i = integerPart.length() - 1; i >= 0; i--) {
        if (integerPart[i] == '1') {
            decimalNumber += pow(base, exponent);
        }
        exponent++;
    }

    // Convert fractional part
    exponent = -1; // Reset exponent for fractional part
    string fractionalPart = fbinary.substr(dotPosition + 1);
    for (size_t i = 0; i < fractionalPart.length(); i++) {
        if (fractionalPart[i] == '1') {
            decimalNumber += pow(base, exponent);
        }
        exponent--;
    }

    return decimalNumber;	
} 
double foctalTofDecimal(string foctal) {
    int base = 8;
    double decimalNumber = 0.0;
    int exponent = 0; // Initialize exponent for integer part

    size_t dotPosition = foctal.find('.');

    // Convert integer part
    string integerPart = foctal.substr(0, dotPosition);
    int integerValueofintegerPart = stoi(integerPart);

    while (integerValueofintegerPart > 0) {
        int lastDigit = integerValueofintegerPart % 10;
        decimalNumber += lastDigit * pow(base, exponent);
        integerValueofintegerPart /= 10;
        exponent++;
    }

    // Convert fractional part
    exponent = -1; // Reset exponent for fractional part
    string fractionalPart = foctal.substr(dotPosition + 1);
    double fractionalNumber = 0.0;
    double fractionalMultiplier = 1.0 / base; // To handle fractional part

    for (char digit : fractionalPart) {
        int digitValue = digit - '0';
        fractionalNumber += digitValue * fractionalMultiplier;
        fractionalMultiplier /= base;
    }

    decimalNumber += fractionalNumber;

    return decimalNumber;
}
double fhexadecimalTofDecimal(string& fhexadecimal) {
    int base = 16;
    int exponent = 0;
    double decimalNumber = 0.0;
    
    // Find the position of the decimal point
    size_t dotPosition = fhexadecimal.find('.');
    
    // Convert the part before the decimal point
    string beforePointValue = fhexadecimal.substr(0, dotPosition);
    for (int i = beforePointValue.size() - 1; i >= 0; i--) {
        char fhexachar = beforePointValue[i];
        int intTypeBeforePointValue;
        
        if (fhexachar >= '0' && fhexachar <= '9') {
            intTypeBeforePointValue = fhexachar - '0';
        }
        else if (fhexachar >= 'A' && fhexachar <= 'F') {
            intTypeBeforePointValue = 10 + (fhexachar - 'A');
        }
        else if (fhexachar >= 'a' && fhexachar <= 'f') {
            intTypeBeforePointValue = 10 + (fhexachar - 'a');
        }
        else {
            cout << "Invalid Hexadecimal Number";
            return -1;
        }
        
        decimalNumber += intTypeBeforePointValue * pow(base, exponent);
        exponent++;
    }
    
    // Reset exponent for the fractional part
    exponent = -1;
    
    // Convert the part after the decimal point
    string afterPointValue = fhexadecimal.substr(dotPosition + 1);
    for (size_t i = 0; i < afterPointValue.size(); i++) {
        char afterPointChar = afterPointValue[i];
        int intTypeAfterPoint;
        
        if (afterPointChar >= '0' && afterPointChar <= '9') {
            intTypeAfterPoint = afterPointChar - '0';
        }
        else if (afterPointChar >= 'A' && afterPointChar <= 'F') {
            intTypeAfterPoint = 10 + (afterPointChar - 'A');
        }
        else if (afterPointChar >= 'a' && afterPointChar <= 'f') {
            intTypeAfterPoint = 10 + (afterPointChar - 'a');
        }
        else {
            cout << "Invalid number";
            return 0;
        }
        
        decimalNumber += intTypeAfterPoint * pow(base, exponent);
        exponent--;
    }
    
    return decimalNumber;
}
 
int decimalToOctal(int decimalNum){
	int octal = 0; // Initialize the octal result
    int position = 1; // Position of the current octal digit

    while (decimalNum > 0) {
        int modular = decimalNum % 8;
        octal = octal + modular * position;
        position *= 10;
        decimalNum = decimalNum / 8;
    }

    return octal;


}
string decimalToBinary(int decimal) {
    string binary;
    while (decimal > 0) {
        int modular = decimal % 2;
        decimal = decimal / 2;
        string stringConversion = to_string(modular);
        binary += stringConversion;
    }

    // Reverse the binary string using a loop
    string reversedBinary;
    for (int i = binary.length() - 1; i >= 0; i--) {
        reversedBinary += binary[i];
    }

    return reversedBinary;
}
string decimalToHexadecimal(int decimal) {
    string hexadecimal; // Initialize as an empty string
    while (decimal > 0) {
        int modular = decimal % 16;
        decimal = decimal / 16;
        char charConversion;
        if (modular >= 10 && modular <= 15) {
            charConversion = 'A' + (modular - 10);
        } else {
            charConversion = '0' + modular;
        }
        // Append the character to the string
        hexadecimal += charConversion;
    }

    string reversehexadecimal;
    for (int i = hexadecimal.length() - 1; i >= 0; i--) {
        reversehexadecimal += hexadecimal[i];
    }
    return reversehexadecimal;
}
string fdecimalToBinary(double decimal) {
    string binary = "0.";
    const int maxIterations = 64; // Set a maximum number of iterations to avoid infinite loop

    for (int i = 0; i < maxIterations; i++) {
        decimal *= 2;
        int integerPart = floor(decimal);
        decimal -= integerPart;
        binary += to_string(integerPart);
        
        if (decimal == 0) {
            break; // Exit the loop when the fractional part becomes 0
        }
    }

    return binary;
}
string fdecimalToOctal(double decimal) {
    string binary = "0.";
    const int maxIterations = 64; // Set a maximum number of iterations to avoid infinite loop

    for (int i = 0; i < maxIterations; i++) {
        decimal *= 8;
        int integerPart = floor(decimal);
        decimal -= integerPart;
        binary += to_string(integerPart);
        
        if (decimal == 0) {
            break; // Exit the loop when the fractional part becomes 0
        }
    }

    return binary;
}
void octalToBinary(int octal) {
    int base = 8;
    int exponent = 0;
    int decimalNumber = 0;
    int lastInteger;
    int remainingNumber;
    
    // Convert octal to decimal
    while (octal > 0) {
        remainingNumber = octal / 10;
        lastInteger = octal % 10;
        decimalNumber = decimalNumber + (lastInteger * pow(base, exponent));
        octal = remainingNumber;
        exponent++;
    }

    // Convert decimal to binary
    string binary;
    while (decimalNumber > 0) {
        int modular = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        string stringConversion = to_string(modular);
        binary += stringConversion;
    }

    // Reverse the binary string using a loop
    string reversedBinary;
    for (int i = binary.length() - 1; i >= 0; i--) {
        reversedBinary += binary[i];
    }

    cout << reversedBinary;
}



int main(){
    system("Color 0b");
    
	
	char select;

	cout << "                            >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "                            >>                                                                                >>" << endl;
	cout << "                            >>                                                                                >>" << endl;
	cout << "                            >>                    Welcome to Number System Calculator                         >>" << endl;
	cout << "                            >>                                                                                >>" << endl;
	cout << "                            >>                                                                                >>" << endl;
	cout << "                            >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << endl;

		do{
	cout << "    *) Press A to convert a number from binary to decimal "                << endl;
	cout << "    *) Press B to convert a number from octal to decimal "                 << endl;
	cout << "    *) Press C to convert a number from Hexadecimal to decimal"            << endl;
	cout << "    *) Press D to convert a number from Fractional binary to decimal "     << endl;
	cout << "    *) Press E to convert a number from Fractional octal to decimal "      << endl;
	cout << "    *) Press F to convert a number from Fractional Hexadecimal to decimal" << endl;
	cout << "    *) Press G to convert a number from Decimal to Binary"                 << endl;
	cout << "    *) Press H to convert a number from Decimal to Octal"                  << endl;
	cout << "    *) Press I to convert a number from Decimal to Hexadecimal"            << endl;
	cout << "    *) Press J to convert a number from Fractional Decimal to Binary"      << endl;
	cout << "    *) Press K to convert a number from Fractional Decimal to Octal"       << endl;
	cout << "    *) Press L to convert a number from Octal to Binary"                   << endl;
	cout << "    *) Press M to convert a number from Binary to Octal"                   << endl;
	cout << "    *) Press N to convert a number from Binary to Hexadecimal"             << endl;
	cout << "    *) Press O to convert a number from Hexadecimal to Binary"             << endl;
	cout << "    *) Press P to convert a number from Octal to Hexadecimal"              << endl;
	cout << "    *) Press Q to convert a number from Hexadecimal to Octal"              << endl;
	cout << "     Press Z to end program " << endl;
	
	
	
	cin >> select;
	switch (select){
	case 'A': {
		system("cls");
		    int n;
			cout << "Enter Binary Number : " << endl;
	        cin>>n;
		cout << "Decimal number is : " << binaryToDecimal(n) << endl;
		break;
	}
	case 'B': {
		system("cls");
		int n;
		cout << "Enter Octal Number " << endl;
       	cin>>n;
		cout << "Decimal number is " << octalToDecimal(n) << endl;                   	
		break;
	}
	case 'C': {
		system("cls");
		string hexadecimal;
		cout << "Enter a Hexadecimal Number : "<< endl;
		cin >> hexadecimal;
		int decimalValue = hexadecimalToDecimal(hexadecimal);
    if (decimalValue != -1) {
        cout << "Decimal value is: " << decimalValue << endl;
    }

		break;
	}
	case 'D': {
		system("cls");
		string n;
		cout << "Enter Floating Point Binary Number " << endl;
       	cin>>n;
		cout << "Decimal number is " << fbinaryTofDecimal(n) << endl;
		break;
	}
	case 'E': {
		system("cls");
		string n;
		cout << "Enter Floating Point Octal Number " << endl;
       	cin>>n;
		cout << "Decimal number is " << foctalTofDecimal(n) << endl;
		break;
	}
	case 'F': {
		system("cls");
		
		string fhexadecimalNum;
		cout<<"Ended values of this result will roundoff";
        cout << "Enter a fractional hexadecimal Number to convert it into fractional decimal number" << endl;
        cin >> fhexadecimalNum;
	    cout << "Fractional Decimal number is: " << fhexadecimalTofDecimal(fhexadecimalNum) << endl;
    break;
       	
	}
	case 'G': {
		system("cls");
		int decimalNum;
		cout << "Enter a decimal number to convert it into binary " << endl;
        cin >> decimalNum;
        string binary = decimalToBinary(decimalNum);
        cout << "Note : Add 0s at start by itself" << endl;
        cout << "Binary representation: " << binary << endl;
    
       break;	
			
	}
	case 'H': {
		system("cls");
		int decimalN;
		cout << "Enter a decimal number to convert it into Octal " << endl;
		cin >> decimalN;
	    cout << "Octal number is " << decimalToOctal(decimalN) << endl;
        break;
		
	}
	case 'I': {
		system("cls");
		int decimalNum;
        cout << "Enter a decimal number to convert it into hexadecimal : ";
        cin >> decimalNum;
        cout << decimalToHexadecimal(decimalNum) << endl;
	
       	break;
	}
	case 'J': {
		system("cls");
	    double decimal;
        cout << "Enter a decimal Number : ";
        cin >> decimal;
        cout << "Note : Add 0s at start by itself" << endl;
        cout << "Binary Number is : " << fdecimalToBinary(decimal) << endl;
        break;	
	}
	case 'K': {
		system("cls");
		double decimal;
        cout << "Enter a decimal Number : ";
        cin >> decimal;
        cout << "Binary Number is : " << fdecimalToOctal(decimal) << endl;
       	break;
	}
	case 'L': {
		system("cls");
		
		int octal;
    cout << "Enter an Octal Number : ";
    cin >> octal;
    int decimal = octalToDecimal(octal);
    if (decimal != 0){
   	cout << "Binary Number is : " << decimalToBinary(decimal) << endl;
   }
    
       break;	
	}
	case 'M': {
		system("cls");
		
		int binary;
    cout << "Enter a binary Number : ";
    cin >> binary;
    
    int decimalNumber = binaryToDecimal(binary);
    
    cout << "Octal Number is : ";
    cout << decimalToOctal(decimalNumber) << endl;

       	break;
	}
	case 'N': {
		system("cls");
		
		int binary;
    cout << "Enter a binary Number : ";
    cin >> binary;
    int decimal = binaryToDecimal(binary);
    if(decimal !=0 ){
    	cout << "Hexadecimal Number is : " << decimalToHexadecimal(decimal) << endl;
	}
       	break;
	}
	case 'O': {
		system("cls");
		
		string hexadecimal;
    cout << "Enter a hexadecimal number: ";
    cin >> hexadecimal;

    int decimalNumber = hexadecimalToDecimal(hexadecimal);
    
    if (decimalNumber != -1) {
        cout << "Decimal Number is : " << decimalNumber << endl;
        cout << "Binary Number is : " << decimalToBinary(decimalNumber) << endl;
    }
       break;	
	}
	case 'P': {
		system("cls");
		int octal;
        cout << "Enter an Octal Number : ";
        cin >> octal;
        int decimal =  octalToDecimal(octal);
        if (decimal != -1){
	   
        cout << "Hexadecimal Number is : " << decimalToHexadecimal(decimal) << endl;
        
        
		}
		
       	break;
	}
	case 'Q': {
		system("cls");
		string hexadecimal;
        cout << "Enter a hexadecimal Number : ";
        cin >> hexadecimal;

    int decimalNum = hexadecimalToDecimal(hexadecimal);

    if (decimalNum != -1) {
        int octalNum = decimalToOctal(decimalNum);
        cout << "Octal Number is : " << octalNum << endl;
    }

		
       	break;
	}
	
		default: {
            cout << "Invalid choice." << endl;
        }
    }
}while (select  != 'Z');
	return 0;
}

