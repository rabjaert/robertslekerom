#include <iostream>
using namespace std;
#include <algorithm> 

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int add(int number, int number2) {
    return number + number2;
}
int sub(int number, int number2) {
    return number - number2;
}
int divide(int number, int number2) {
    return number / number2;
}
int multiply(int number, int number2) {
    return number * number2;
}

void calculator() {
    char str[80];
    bool questions = false;
     int number, number2;
     std::string s = str;

  
    printf("What would you like to do?\n1.Add\n2.Substract\n3.Divide\n4.Multiply\n");
    scanf("%s", str);
    if(is_number) {
       // cout << "Please type in what you would like to do...";
       printf("Please type in what you would like to do...");
    }

    else if(s.empty()) {
        printf("Please type something.");
    }
    else {
    if(s == "Add") {
       
            printf("Please type in the two numbers you would like to add.\n");
            scanf("%d", number);
            printf("Please type in your second number\n");
            scanf("%d", number2);
            add(number, number2);
    }
}
}
  

 main()
{
  
  int array[] = {2,3,2,5,3,2,5,123,4213};
  int arrSize = sizeof(array)/sizeof(array[0]);
  //int test = 0;
    

   for (int k = 1; k <= sizeof(array)/sizeof(array[0]); k++) {
      
       cout << "Element: "  << k << " of " << arrSize <<  " elements \n";
   }
   
   calculator();
}








