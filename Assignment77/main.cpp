//This is Sheerin Chaudhary with assignment 7 for summer 2015
//This program is similar to assignment 5 which read scores1,score2,scores3 into read3array function from input file
//and then used function print1array to set each data 6 elements on each line and then used function findlargestscore to make a new array to find largest value of 3 arrays.
//This program adds two functions sort1array which sorta the 4 arrays and aretheredups which finds duplications in each array.
#include <iostream>
#include <fstream>
using namespace std;
const int SCORE=20;
void read3arrays( int[], int[], int[], int);
void print1array(int[],int);
void findlargestscores( int[], int[],int[],int[], int);
void sort1array( int[], int);
bool aretheredups( int [], int);

ifstream infile("assignment5input.txt");
ofstream outfile("assignment7output.txt");

int main()
{
    int score1[SCORE],score2[SCORE],score3[SCORE];
    int n;
    int largestscores[SCORE];
    cout<<"How many people have their credit scores calculated by three companies "<<endl<<endl;
    cin>>n;
    
    read3arrays(score1,score2,score3,n);
    outfile<<"The function print1array will print out the person's first credit scores for the company  "<<endl<<endl;
    print1array(score1,n);
    outfile<<endl<<endl;
    
    outfile<<"The function print1array will print out the person's second credit scores for the  company  "<<endl<<endl;
    print1array(score2,n);
    outfile<<endl<<endl;
    
    outfile<<"The function print1array will print out the person's third credit scores for the company   "<<endl<<endl;
    print1array(score3,n);
    outfile<<endl<<endl;
    
    findlargestscores(score1,score2,score3,largestscores, n);
    outfile<<"The function print1array will print out the largest score array for the credit scores "<<endl<<endl;
    
    print1array(largestscores,n);
    outfile<<endl<<endl;
    
    sort1array(score1,n);
    outfile<<"Here is the score 1 array in sorted order"<<endl<<endl;
    print1array(score1,n);
    outfile<<endl<<endl;
    
    sort1array(score2,n);
    outfile<<"Here is the score 2 array in sorted order"<<endl<<endl;
    print1array(score2,n);
    outfile<<endl<<endl;
    
    sort1array(score3,n);
    outfile<<"Here is the score 3 array in sorted order"<<endl<<endl;
    print1array(score3,n);
    outfile<<endl<<endl;
    
    sort1array(largestscores,n);
    outfile<<"Here is the largestscores array in sorted order"<<endl<<endl;
    print1array(largestscores,n);
    outfile<<endl<<endl;
    
    if(aretheredups( score1, n)){
        outfile<<"There are duplicates in score1 array"<<endl<<endl;
    }
    else
        outfile<<"There are no duplicates in score1 array"<<endl<<endl;
    outfile<<endl<<endl;
    
    if(aretheredups( score2, n)){
        outfile<<"There are duplicates in score2 array"<<endl<<endl;
    }
    else
        
        outfile<<"There are no duplicates in score2 array"<<endl<<endl;
    outfile<<endl<<endl;
    
    if(aretheredups( score3, n)){
        outfile<<"There are duplicates in score3 array"<<endl<<endl;
    }
    else
        outfile<<"There are no duplicates in score3 array"<<endl<<endl;
    outfile<<endl<<endl;
    
    if(aretheredups( largestscores, n)){
        outfile<<"There are duplicates in largestscores array"<<endl<<endl;
    }
    else
        outfile<<"There are no duplicates in largestscores array"<<endl<<endl;
    outfile<<endl<<endl;
    
    outfile<<endl<<endl;
    
    outfile.close();
    
    infile.close();
    
    return 0;
}

//Function read3arrays
//Input:
//  This function will be receiving a paramater value of k and arrays of cred1,cred2,and cred3.
//Process:
//  It will read the input file of k values of the three companies credit scores(cred1,cred2,cred3)
//Output:
//  It will print to the output file of the three credit scores arrays in column on each line.
void read3arrays( int cred1[], int cred2[], int cred3[], int k)
{
    int kpeople;
    for( kpeople=0; kpeople<k; kpeople++) {
        
        infile >> cred1 [kpeople];
        
        infile >>cred2 [kpeople];
        
        infile >>cred3 [kpeople];
        
        outfile<<cred1[kpeople]<<" "<<cred2[kpeople]<<" "<<cred3[kpeople]<<endl<<endl;
    }
    
    return;
}

//Function print1array
//Input:
//  This function will receive array num and integer k
//Process:
//  It will align each array in six elements on each line and send to outfile file
//Output:
//   It will send to output file of array num of six integers on each line
//  and align each other in columns.

void print1array( int num[], int k)
{
    
    for(int kpeople=0; kpeople<k; kpeople++) {
        
        if(kpeople%6==0)
            outfile<<endl<<endl;
        outfile<<" "<<num[kpeople]<<" ";
    }
    
    return;
    
}


//Function findlargestscores
//Input:
//  The function will receive three arrays of cred1,cred2,cred3, and integer k
//Process:
//  It will compare each array in every position with one another and compute a new array of bestscores
//  which will be the largest values of each position in the three companies
//Output:
//  It will print out to the main program a new set of array called bestscores with the largest
//values in each position of cred1,cred2,and cred3.

void findlargestscores( int cred1[], int cred2[], int cred3[], int bestscores[], int k)

{
    
    for( int kpeople=0; kpeople<k; kpeople++) {
        
        if(cred1[kpeople]>=cred2[kpeople])
            bestscores[kpeople]=cred1[kpeople];
        else
            bestscores[kpeople]=cred2[kpeople];
        
        if(bestscores[kpeople]<cred3[kpeople])
            bestscores[kpeople]=cred3[kpeople];
        
    }
    return;
}
//Function sort1array
//Input:
//  This function will receive array called sort and integer k
//Process:
//  It will organize the array's data values in ascending order use of pass and cand element
//Output:
//  It will make a new array of sorted data values and send to main program
void sort1array( int sort[],int k)
{
    int temp;
    
    for(int pass=0; pass<k-1; pass++)
        for(int cand=pass+1; cand<k; cand++ )
            if(sort[pass]>sort[cand]) {
                temp=sort[pass];
                sort[pass]=sort[cand];
                sort[cand]=temp;
            }
    
    
    
    return;
}

//Function aretheredups
//Input:
//  This function will receive an array called sorted and an integer k
//Process:
//  It will use boolean to tell whether the array's data values have duplications or not by
//computing false or true.
//Output:
//  It will return to the main program true if there are duplications and false if there is none.
bool aretheredups( int sorted[], int k)
{
    
    
    for( int pass=0; pass<k; pass++) {
        
        if(sorted[pass] == sorted[pass+1]){
            
            return true;
            
        }
    }
    
    
    return false;
    
}



