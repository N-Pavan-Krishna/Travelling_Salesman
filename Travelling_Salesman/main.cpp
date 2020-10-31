//
//  AdjacentMatrxi.cpp
//  GraphCreation
//
//  Created by Pavan Krishna Nandimandalam on 2019-02-21.
//  Copyright © 2019 Pavan Krishna Nandimandalam. All rights reserved.
//

/*  REFERENCE:
    I used brute force method to find the optimal solution for the given problem
    I took the below video from youtube for reference for generating n! combination of possible paths
    "106B Lecture: Backtracking (permute a string)"
 
 Constraints:
 1. I assumed given graph will contain HAMILTONIAN CYCLES
 2. As I am using brute force, the below code support only the graphs with 100 nodes only
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>

using namespace std;

int vertex=0;
int adjMatrix[100][100];
void global();
void Permutation(string,string);
int comb=1;
int sum =INT_MAX;
ofstream output;

int main(int argc, const char * argv[]) {
    // insert code here...
    if(argc!=3){
        cout << "Incorret number of arguments" << endl;
        return -1;
    }
    
    string input1= "0123";
    input1.size();
    input1.substr(0,1);
    
    ifstream input(argv[1]);
    output.open(argv[2]);
    
    if(!input){
        cout << "Cant read the input file" << endl;
        return -1;
    }
    
    if(!output){
        cout << "Can't create output file" << endl;
        return -1;
    }
    
    int testcase;
    //int vertex;
    int edges;
    int u,v,w;
    
    input >> testcase;
    
    for(int i=0;i<testcase;i++){
        //output << "Testcase:" << i << endl;
        input >> vertex;
        input >> edges;
        
        //int adjMatrix[vertex][vertex];
        
        for(int j=0;j<vertex;j++){
            
            for(int k=0;k<vertex;k++){
                adjMatrix[j][k]=0;
            }
        }
        
        for(int j=0;j<edges;j++){
            
            input >> u;
            input >> v;
            input >> w;
            
            adjMatrix[u][v] = w;
            adjMatrix[v][u] = w;
        }

        string inputString="";
        

        for(int i=0;i<vertex;i++){
        stringstream num;
        num << i;
            inputString=inputString + num.str();
        }
    
    //cout << inputString << endl;
        /*output << "input string:" << inputString << endl;
        
        for(int j=0;j<vertex;j++){
            
            for(int k=0;k<vertex;k++){
                output << adjMatrix[j][k] << " ";
            }
            
            output << endl;
        }*/
        
        Permutation(inputString,"");
        //cout << "MINIMUM PATH:" << sum << endl;
        output << sum << endl;
        sum = INT_MAX;
        comb=1;
        
    }
}

void Permutation(string input,string chosen){
    int x,y;
    if(input.empty()){
        //cout << "vertex:" << vertex << endl;
        //cout << chosen << endl;
        //cout << "combination:" << comb++ << endl;
        //cout << "chosen:" << chosen << endl;
        int sumTemp=0;
    //cout << input.at(0);
        for(int i=0;i<chosen.length();i++){
            if(i+1<chosen.length()){
        /*stringstream xvalue(chosen.substring(i,1));
        xvalue >> x;
        stringstream yvalue(chosen.substring(i+1,1));
        yvalue >> y;*/
        //cout << chosen.substr(i,1) << "-" << chosen.substr(i+1,1) << endl;

        x=chosen.at(i) - 48;
        //cout << "X:" << x << endl;
        y=chosen.at(i+1) - 48;
                sumTemp=sumTemp+adjMatrix[x][y];
                //cout << i << ":" << sumTemp << endl;
            }
            else{
        /*stringstream xvalue(chosen.substring(i,1));
        xvalue >> x;
        stringstream yvalue(chosen.substring(0,1));
        yvalue >> y;*/
                //cout << chosen.substr(i,1) << "-" << chosen.substr(0,1) << endl;
        
        x = chosen.at(i) - 48;
        y = chosen.at(0) - 48;
                sumTemp=sumTemp+adjMatrix[x][y];
                //cout << i << ":" << sumTemp << endl;
            }
        }
        if(sumTemp<sum){
            sum=sumTemp;
        }
        //cout << "sum Temp:" << sumTemp << endl;
    }
    
    else{
        
        for(int i=0;i<input.length();i++){
            char c = input[i];
            chosen += c;
            input.erase(i,1);
            
            Permutation(input,chosen);
            
            input.insert(i,1,c);
            chosen.erase(chosen.length()-1,1);
        }
    }
}

/*void global(){
    for(int j=0;j<vertex;j++){
        
        for(int k=0;k<vertex;k++){
            cout << adjMatrix[j][k] << " ";
        }
        
        cout << endl;
    }
    cout << vertex << endl;
}*/

