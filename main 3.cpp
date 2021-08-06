//
//  main.cpp
//  Project
//
//  Created by Conghui Deng on 3/19/20.
//  Copyright © 2020 Conghui Deng. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class runLength{
public:
    int numRows,numCols,minVal,maxVal,whichMethod,zeroCnt;
    string nameEncodeFile;
    int row,col,length;
    void encodeMethod1(ifstream &in,ofstream &en){
                row=0;
        while(row<numRows){
                col=0;
                length=1;
        //        while(!in.eof()){
        int lastVal,nextVal;
        in>>lastVal;
        //        int origin=lastVal;
                en<<row<<" "<<col<<" "<<lastVal<<" ";
        while(col<numCols-1){
        col++;
        in>>nextVal;
        if(nextVal==lastVal)
                length++;
        else{
            en<<length<<endl;
            lastVal=nextVal;
            length=1;
            en<<row<<" "<<col<<" "<<lastVal<<" ";
        }
        }
        en<<length<<endl;
        row++;
        }

    }
    void encodeMethod4(ifstream &in,ofstream &en){
        row=0;
        col=-1;
        length=0;
//        while(!in.eof()){
        int lastVal=skipZero(in);
//        int origin=lastVal;
        en<<row<<" "<<col<<" "<<lastVal<<" ";
        length++;
        while(!in.eof()){
        int nextVal=skipZero(in);
        if (zeroCnt>0)
            lastVal=0;
        if(nextVal==lastVal)
            length++;
        else{
            en<<length<<endl;
            length=1;
            lastVal=nextVal;
            en<<row<<" "<<col<<" "<<nextVal<<" ";
        }
        }
        en<<length-1;
  //      }
    }
    int skipZero(ifstream &in){
        zeroCnt=0;
        int pixelVal=0;
        while(pixelVal==0 && !in.eof()){
            col++;
            in>>pixelVal;
            if(pixelVal==0)
                zeroCnt++;
            if(col>=numCols-1){
                col=-1;
                row++;
            }
        }
        return pixelVal;
    }
};

int main(int argc, const char *argv[]){
    ifstream inFile(argv[1]);
    runLength *rl=new runLength;
    inFile>>rl->numRows;
    inFile>>rl->numCols;
    inFile>>rl->minVal;
    inFile>>rl->maxVal;
    rl->whichMethod=*argv[2]-'0';
    stringstream ss;
    ss<<argv[1]<<"_EncodeMethod"<<rl->whichMethod<<".txt";
    ofstream encodeFile(ss.str());
    encodeFile<<rl->numRows<<" "<<rl->numCols<<" "<<rl->minVal<<" "<<rl->maxVal<<endl<<rl->whichMethod<<endl;
    switch(rl->whichMethod){
        case 1: rl->encodeMethod1(inFile,encodeFile);
            break;
        case 4: rl->encodeMethod4(inFile,encodeFile);
            break;
        default: encodeFile<<"error";
    }
    inFile.close();
    encodeFile.close();
}
