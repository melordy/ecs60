//
//  huffman.cpp
//  
//
//  Created by Melody Chang on 2/10/16.
//
//


#include <iostream>
#include "BinaryTree.h"
#include <fstream>
#include <string>
#include "BinaryHeap.h"
using namespace std;


int main(int argc, char* argv[])
{
    ifstream file(argv[1]);
    char temp;
    int ascii;
    BinaryHeap<BinaryTree> heap(260);
    
    BinaryTree objArr[256];
    
    
    BinaryTree binInternal[256];
    int internalCount = 0;
    
    
    
    while(file.get(temp))
    {
        ascii = temp;
        (objArr[ascii]).count++;
        
        if(objArr[ascii].ch != temp)
            objArr[ascii].ch = temp;
        
        if(file.peek() == EOF)
            if(file.eof())
                break;
    }//while loop
    
    for(int i = 0; i < 256; i++)
        if(objArr[i].count)
            heap.insert(objArr[i]);
    /*
     while(!heap.isEmpty())
     {
     BinaryTree tmp1;
     heap.deleteMin(tmp1);
     tmp1.print();
     cout << endl;
     }
     */
    
    BinaryTree tmp[260];
    int tmpCount = 0;
    while(!heap.isEmpty())
    {
        
        heap.deleteMin(tmp[tmpCount]);
        heap.deleteMin(tmp[tmpCount+1]);
        
        
        binInternal[internalCount].setLeft(tmp[tmpCount].getPtr());
        binInternal[internalCount].setRight(tmp[tmpCount+1].getPtr());
        internalCount++;
        tmpCount += 2;
        if(heap.isEmpty())
            break;
        
        heap.insert(binInternal[internalCount-1]);
    }
    char encoding[260];
    binInternal[internalCount - 1].printTree(encoding, 0);
    return 0;
}