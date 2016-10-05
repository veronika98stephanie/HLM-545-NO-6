 #include <iostream>
 #include <fstream>
 using namespace std;

 ofstream myFile;

 // Function prototypes
 void arrSelectSort(int *[], int);
 void showArray(const int [], int);
 void showArrPtr(int *[], int);

 void inputDonation (int []);

 int main()
 {
 const int NUM_DONATIONS = 15; // Number of donations

 // An array containing the donation amounts.
 int donations[NUM_DONATIONS] = {};
 cout<< " Please enter 15 donations amount "<<endl;
 inputDonation(donations);

 // An array of pointers to int.
 int *arrPtr[NUM_DONATIONS] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

 // Each element of arrPtr is a pointer to int. Make each
 // element point to an element in the donations array.
 for (int count = 0; count < NUM_DONATIONS; count++)
 arrPtr[count] = &donations[count];

 // Sort the elements of the array of pointers.
 arrSelectSort(arrPtr, NUM_DONATIONS);

 // Display the donations using the array of pointers. This
 // will display them in sorted order.
 myFile.open("jawaban.txt", ios_base::app);
 cout << "The donations, sorted in ascending order are: \n";
 myFile<<"The donations, sorted in ascending order are: \n";
 myFile.close();

 myFile.open("jawaban.txt", ios_base::app);
 showArrPtr(arrPtr, NUM_DONATIONS);
 myFile.close();

 // Display the donations in their original order.
 myFile.open("jawaban.txt", ios_base::app);
 cout << "The donations, in their original order are: \n";
 myFile<< "The donations, in their original order are: \n";
 myFile.close();

 myFile.open("jawaban.txt", ios_base::app);
 showArray(donations, NUM_DONATIONS);
 myFile.close();

 return 0;
 }

 //****************************************************************
 // Definition of function arrSelectSort. *
 // This function performs an ascending order selection sort on *
 // arr, which is an array of pointers. Each element of array *
 // points to an element of a second array. After the sort, *
 // arr will point to the elements of the second array in *
 // ascending order. *
 //****************************************************************

 void arrSelectSort(int *arr[], int size)
 {
 int startScan, minIndex;
 int *minElem;

 for (startScan = 0; startScan < (size - 1); startScan++)
 {
 minIndex = startScan;
 minElem = arr[startScan];
 for(int index = startScan + 1; index < size; index++)
 {
 if (*(arr[index]) < *minElem)
 {
 minElem = arr[index];
 minIndex = index;
 }
 }
 arr[minIndex] = arr[startScan];
 arr[startScan] = minElem;
 }
 }
 //***********************************************************
 // Definition of function showArray. *
 // This function displays the contents of arr. size is the *
 // number of elements. *
 //***********************************************************

 void showArray(const int arr[], int size)
 {
 for (int count = 0; count < size; count++){
 cout << arr[count] << " ";
 myFile<< arr[count] << " ";
 }  cout<<endl;
    myFile<<endl;
 }

 //***************************************************************
 // Definition of function showArrPtr. *
 // This function displays the contents of the array pointed to *
 // by arr. size is the number of elements. *
 //***************************************************************

 void showArrPtr(int *arr[], int size)
 {
 for (int count = 0; count < size; count++){
 cout << *(arr[count]) << " ";
 myFile<< *arr[count] << " ";
 }  cout<<endl;
    myFile<<endl;
 }

 void inputDonation(int don[]){
     for (int i=0;i<15;i++){
        cin >> don[i];
     }
 }

