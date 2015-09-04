//============================================================================
// Name        : HardwoodSellerC.cpp
// Author      : Ibrahim Atiya
// Version     : 1
// Copyright   : It's free
// Description : Main file for the Hardwood Seller
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;


void ReadInput(string &FileContent, string InputFileName)
{
        ifstream InputFile(InputFileName.data(), ifstream::in);                 
        ifstream::pos_type size;

        if(!InputFile)
        {
                cerr << "ERROR: Cannot open input file: " << InputFileName << "$
                exit(1);
        }
        char InputChar;
        InputFile.get (InputChar);                                              
        int NumChars = 0;
        while (InputFile)
        {
                NumChars++;
                InputFile.get (InputChar);
        }
        size = NumChars;    //*** Find file size
 char *buffer = new char[size]; // Allocate memory to store file contents

        InputFile.seekg(0, ios::beg);
        InputFile.read(buffer, size); // Read the file contents

        FileContent.clear();
        FileContent.append(buffer, buffer+size);

        delete [] buffer;    
        InputFile.close();
Return;
}


static string NextArg(string &S, string::size_type &p1, string::size_type &p2) 
{
        //what are not considered part of a word
        //static char delimiters[] = "\n:;";
        //the alphabet to use
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        if(p1 == string::npos)
                return string("");
        size_t beginning = S.find_first_of(alphabet, p1);
        size_t ending = S.find_first_of(alphabet, beginning);               
        p1 = ending; //
        p2 = ending;
        size_t LengthOfWord = ending-beginning; 
        if(p1 == string::npos)
                return string("");
        return (S.substr (beginning,LengthOfWord));
}

int main(int argc, char* argv [])
{
        string  fileContent,
                buyerName,
　　address,
　　date,
　　woodType,
　　woodAmount;
　　int amountOrder,
　　price,
　　priceCurrent,
　　totalPrice=0,
　　multiplier,
　　dTime,
　　sum = 0,
　　max = 0;

ReadInput(fileContent, argv[1]); // copies contents of file into this string
string::size_type p1=0, p2=0;
　　
　　buyerName = NextArg(fileContent, p1, p2);
　　address =NextArg(fileContent, p1, p2);
　　date = NextArg(fileContent, p1, p2);
　　
　　cout << “Buyer Name: “ << buyerName << ‘\n’;
　　cout << “Address of Delivery: “ << address << ‘\n’;
　　cout << “List of Wood purchased: \n”;
　　cout << “=-=-=-=-=-=-=-=-=-=-=-=-=-=-”;
　　
　　do
　　{
　　//figure out what type of wood
　　woodType = NextArg(fileContent, p1, p2);
　　if (woodType == “Cherry”)
　　{
　　dTime = 2.5;
　　price = 5.95;
　　}
　　else if (woodType == “Curly Maple”)
　　{
　　dTime = 1.5;  
　　price = 6;
　　}
　　else if (woodType == “Genuine Mahogany”)
　　{
　　dTime = 3;
　　price = 9.60;
　　}  
　　else if (woodType == “Wenge”)
　　{
　　dTime = 5;  
　　price = 22.35;
　　}
　　else if (woodType == “White Oak”)
　　{
　　dTime = 2.3;
　　price = 6.7;
　　}
　　else if (woodType == “Sawdust”)
　　{
　　dTime = 1;  
　　price = 1.5;
　　}
　　
　　cout << “Type: “ << woodType << ‘\t’;
　　
　　
　　amountOrder = stoi(fileContent, &p1);
　　//woodAmount = NextArg(fileContent, p1,p2);
　　if (amountOrder <= “100” )
　　multiplier = 1;
　　else if (amountOrder >= “101” && amountOrder <= “200”)
　　multiplier = 2; 
　　else if (amountOrder >= “201” && amountOrder <= “300”)
　　multiplier = 3; 
　　else if (amountOrder >= “301” && amountOrder <= “400”)
　　multiplier = 4; 
　　else if (amountOrder >= “401” && amountOrder <= “500”)
　　multiplier = 5;
　　else if (amountOrder >= “501” && amountOrder <= “1000”)
　　multiplier = 5.5; 
　　 
　　cout << “Amount: “ << amountOrder << “ BFs \t”;
　　
　　//calculate sum and total price
　　sum = multiplier * dTime; 
　　currentPrice = price*amountOrder;
　　
　　cout << “Price: $“ << currentPrice << ‘\n’; 
　　totalPrice += currentPrice;
　　//compare to max
　　if (sum > max)
　　 max = sum;
　　}
　　while(p1 != string::npos);
　　
　　cout << “Estimated Delivery Time: “ << max << “ hours\n”;
　　cout << “Total Price of Purchase: $” << totalPrice << ‘\n’;
　　
　　return 0;
　　
　　}//end main
