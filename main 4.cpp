//
//  main.cpp
//  Project
//
//  Created by Conghui Deng on 3/29/20.
//  Copyright © 2020 Conghui Deng. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class runLength{
public:
    int numRows,numCols,minVal,maxVal,whichMethod,zeroCnt;
    string nameEncodeFile;
    int row,col,length,color,leftEndPrint,rightEndPrint;
    int rowCnt,colCnt;
    
    
    void decodeMethod1(ifstream &en, ofstream &de){
        rowCnt=0;
        colCnt=0;
        while(rowCnt<numRows && !en.eof()){
            en>>row>>col>>color>>length;
            for(int i=0;i<length;i++)
                de<<color<<" ";
            colCnt+=length;
            if(colCnt>=numCols){
                de<<endl;
                colCnt=0;
                rowCnt++;
            }
                
        }
    }
    void decodeMethod4(ifstream &en, ofstream &de){
        rowCnt=0;
        colCnt=0;
        while(rowCnt<numRows && !en.eof()){
            en>>row>>col>>color>>length;
            while(row>rowCnt){
                for(int i=colCnt;i<numCols;i++){
                    de<<"0 ";
                    
                }
                colCnt=0;
                rowCnt++;
                de<<endl;
            }
            while(col>colCnt){
                de<<"0 ";
                colCnt++;
                
            }
            for(int j=0;j<length;j++){
                de<<color<<" ";
                colCnt++;
                if(colCnt>=numCols){
                    de<<endl;
                    colCnt=0;
                    rowCnt++;
                }
            }
        }
        while(rowCnt<numRows){
          
            while(colCnt<numCols){
                de<<"0 ";
                colCnt++;
            }
            colCnt=0;
            de<<endl;
            rowCnt++;
        }
       }
};

int main(int argc, char* argv[]){
    string nameEncodeFile=argv[1];
    ifstream encodeFile(nameEncodeFile);
    runLength *rl=new runLength;
    encodeFile>>rl->numRows;
    encodeFile>>rl->numCols;
    encodeFile>>rl->minVal;
    encodeFile>>rl->maxVal;
    encodeFile>>rl->whichMethod;
    string nameDecodeFile;
    nameEncodeFile.resize(nameEncodeFile.length()-4);
    nameDecodeFile=nameEncodeFile+"_Decoded.txt";
    
    ofstream decodeFile(nameDecodeFile);
    decodeFile<<rl->numRows<<" "<<rl->numCols<<" "<<rl->minVal<<" "<<rl->maxVal<<endl;
    switch(rl->whichMethod){
        case 1: rl->decodeMethod1(encodeFile,decodeFile);
            break;
        case 4: rl->decodeMethod4(encodeFile,decodeFile);
            break;
        default: decodeFile<<"error";cout<<"error";exit(0);
            
    }
    //cout<<nameDecodeFile;
    encodeFile.close();
    decodeFile.close();
}
