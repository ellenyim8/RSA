// Names: Kayla Tran & Ellen Yim
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std; 

int mod(int b, int e, int m){//function for modding
//m = the (mod m)
//e = the exponent
//b = the base #
  if(e == 1){
    return (b % m);
  }
  else if(e % 2 == 0){
    b = b % m;
    return mod(pow(b, 2), (e/2), m) % m;
  }
  else if(e % 2 == 1){
    b = b % m;
    return (b * mod(pow(b, 2), (e / 2), m)) % m;
  }
  return -1;
}

int inverse(int b, int n){
  for (int i = 1; i < n; i++){
    if (((b%n) * (i%n)) % n == 1){
      return i;
    }
  }
  return 0;
}

int GCD(int k, int o){
  if(o == 0){
    return k;
  }
  else{
    return GCD(o , k % o);
  }
}


int main() {
    int e,n, temp;
    cin >> e >> n; // first line input  P = (e, n) -> public key pair
    int m;
    cin >> m; // second line input   m = length of encoded message
    vector<int> msg;           //vector holds secret message
    
    for (int i = 0; i < m; i++) {
        cin >> temp;        // encoded message
        msg.push_back(temp);
    }

    int i = 2; 
    int p, q, p_one, q_one, phi; 
    double count; 
    while (i < n) {
        if (n % i != 0) {
            i++; 
        }
        else {
            p = i; 
            q = n / i; 
            break; 
        }
    }

    for(int i = 3; i <= sqrt(n); i = i + 2){
      if(n % i == 0){
        p = i;
        q = n / i;
        break;
      }
    }

    p_one = p - 1;  // (p-1) 
    q_one = q - 1;  // (q-1)
    phi = p_one * q_one; 

    //private key: d
    //double d ;//= mod(e, phi-2, phi);
    //d = inverse(e, phi); //solves for d

    /*for (int i = 0; i < m; i++) {
      int temps;
        temps = msg.at(i);
        cout << "hi: " << temps << endl;
        temps = mod(temps, d, n);
        cout << temps << endl << endl;
    */


    // check if public key is invalid 
    //p == e || q == e || phi == n || 
    if (GCD(e, phi) != 1 || p == q) {
      cout << "Public key is not valid!" << endl; 
      return 0;
    }
    else {  // if not invalid then decrypt message:
      int M;
      double d ;//= mod(e, phi-2, phi);

      d = inverse(e, phi);

      cout << p << " " << q << " " << phi << " " << d << endl;

      vector<int> coded_msg; 

      for (int i=0; i < m; i++) { 
          //M = C^d (mod n)
          //find M: C, d, n
          int C = msg.at(i); 
          M = mod(C, d, n);
          cout << M << " "; 
          coded_msg.push_back(M);
      }
      cout << endl; 

      //convert using : " " = 30, A = 3, B = 4, 
      int x = 3;
      
      for (int i=0; i<coded_msg.size(); i++) {
        if (coded_msg[i] == x) cout << "A"; 
        else if (coded_msg[i] == x+1) cout << "B";
        else if (coded_msg[i] == x+2) cout << "C";
        else if (coded_msg[i] == x+3) cout << "D";
        else if (coded_msg[i] == x+4) cout << "E";
        else if (coded_msg[i] == x+5) cout << "F";
        else if (coded_msg[i] == x+6) cout << "G";
        else if (coded_msg[i] == x+7) cout << "H";
        else if (coded_msg[i] == x+8) cout << "I";
        else if (coded_msg[i] == x+9) cout << "J";
        else if (coded_msg[i] == x+10) cout << "K";
        else if (coded_msg[i] == x+11) cout << "L";
        else if (coded_msg[i] == x+12) cout << "M";
        else if (coded_msg[i] == x+13) cout << "N";
        else if (coded_msg[i] == x+14) cout << "O";
        else if (coded_msg[i] == x+15) cout << "P";
        else if (coded_msg[i] == x+16) cout << "Q";
        else if (coded_msg[i] == x+17) cout << "R";
        else if (coded_msg[i] == x+18) cout << "S";
        else if (coded_msg[i] == x+19) cout << "T";
        else if (coded_msg[i] == x+20) cout << "U";
        else if (coded_msg[i] == x+21) cout << "V";
        else if (coded_msg[i] == x+22) cout << "W";
        else if (coded_msg[i] == x+23) cout << "X";
        else if (coded_msg[i] == x+24) cout << "Y";
        else if (coded_msg[i] == x+25) cout << "Z";
        else if (coded_msg[i] == x+26) cout << " ";
        else if (coded_msg[i] == x+27) cout << '"';
        else if (coded_msg[i] == x+28) cout << ".";
        else if (coded_msg[i] == x+29) cout << ",";
        else if (coded_msg[i] == x+30) cout << "'";
      }
      cout << endl; 
    }

}

/*

030 673 332 785 171 589 782 171 828 589 785 568
30 11 8 29 18 7 17 18 14 7 29 6 
"IF PEOPLE D 

782 785 713 782 813 785 123 589 828 673 589 487
17 29 16 17 22 29 4 7 14 11 7 24
O NOT BELIEV

589 785 813 890 243 813 785 733 243 813 890 589
7 29 22 10 3 22 29 15 3 22 10 7 
E THAT MATHE

733 243 813 673 422 769 785 673 769 785 769 673
15 3 22 11 5 21 29 11 21 29 21 11 
MATICS IS SI

733 171 828 589 291 785 673 813 785 673 769 785
15 18 14 7 32 29 11 22 29 11 21 29 
MPLE, IT IS 

782 713 828 482 785 123 589 422 243 500 769 589
17 16 14 27 29 4 7 5 3 23 21 7 
ONLY BECAUSE

785 813 890 589 482 785 568 782 785 713 782 813
29 22 10 7 27 29 6 17 29 16 17 22 
 THEY DO NOT

785 549 589 243 828 673 367 589 785 890 782 587
29 20 7 3 14 11 28 7 29 10 17 25 
 REALIZE HOW

785 422 782 733 171 828 673 422 243 813 589 568
29 5 17 15 18 14 11 5 3 22 7 6 
 COMPLICATED

785 828 673 332 589 785 673 769 777 030
29 14 11 8 7 29 11 21 31 30 
 LIFE IS."

*/

/* Input
The first line will have two values, e,n which represent the public key pair needed to decrypt the code.

The second line will have one value m which is the length of the encoded message.

The next m integers will represent the encoded message.

Take all the input in using standard input for the programming language you are using (i.e. for C++ it's cin).

Output
Output p, q, phi(n), and d. Note that it should be that p*q = n and phi(n) = (p-1)*(q-1).

Output the decoded message in integers.

Output the decoded message in characters. If the characters are in the English alphabet, make sure to print them out uppercase.

Output your solution using standard output for the programming language you are using (i.e. for C++ it's cout).
*/