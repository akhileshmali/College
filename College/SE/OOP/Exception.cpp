
#include <iostream>
using namespace std;
int main()
{
    string name;
    float weight;
    float height;
    float bmi;
    cout << "Please Enter your Name \n";
    cin >> name;
    cout << "Hello " << name << ", please enter your weight in Kg \n";
    cin >> weight;
    cout << "Thank you " << name << ", now please enter your height in meters \n";
    cin >> height;  
    bmi = weight/(height*height);
    cout << "Your BMI is: " << bmi <<"\n";
    
	float BMI_calculator(float weight, float height){
	if (height == 0){
	throw runtime_error("You attempted to calculate BMI with an invalid value of zero for height \n");
	}
	return weight/(height*height);
	 
	 
}
try{
        bmi = BMI_calculator(weight, height);
        cout << "Your BMI is: " << bmi <<"\n";
    }
    
catch (runtime_error&e){
        cout<< "Warning: "<< e.what();
    }
}
/*int main () {
	
  /*try
  {
    throw 20;
  }
  catch (int e)
  {
    cout << "An exception occurred. Exception Nr. " << e << '\n';
  }*/
  //int x;
/*cout << "Enter a number: ";
cin >> x;
while(cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Bad entry.  Enter a NUMBER: ";
    cin >> x;
}
cout << "x = " << x << endl;*/
/*cin.exceptions(ios_base::failbit);
try {
    cin >> value;
}
catch (ios_base::failure const& ex) {
    // deal with the error
}*/
//  return 0;
//}
