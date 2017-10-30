//
//  defragmenter.cpp
//  
//
//  Created by Melody Chang on 2/26/16.
//
//

#include "DefragRunner.h"
#include "mynew.h"
#include "defragmenter.h"
#include "QuadraticProbing.h"

using namespace std;

Defragmenter::Defragmenter(DiskDrive *diskDrive) {
    DirectoryEntry *directory = diskDrive->directory;
    DiskBlock *diskBlock;
    DiskBlock *diskBlock2;
    QuadraticHashTable<DiskBlock*> *swapTable = new QuadraticHashTable<DiskBlock*> (diskBlock, 100000);
    
    
    cout << "Capacity: " << diskDrive->getCapacity() << "\n"
    << "Number of Files: " << diskDrive->getNumFiles() << "\n";
    
    //int entry, next = 0;
    //int block = 2
    for (int entry, next =0, block = 2; entry < diskDrive->getNumFiles(); entry+=1) {
        
        next = directory[entry].getFirstBlockID();
        diskBlock = diskDrive->readDiskBlock(next);
        directory[entry].setFirstBlockID(entry + block);
        cout << "File " << entry << " ID: " << directory[entry].getFileID()
        << ", First Block ID: " << directory[entry].getFirstBlockID()
        << ", Size: " << directory[entry].getSize() << "\n";
        
        
        
        do {
            diskBlock2 = diskDrive->readDiskBlock(block);
            if(diskBlock != diskBlock2)	{
                (*swapTable).insert(diskBlock2);
            }
            diskDrive->writeDiskBlock(diskBlock2, next);
            next = diskBlock->getNext();
            
            if(next > 1 || next < 1) diskBlock->setNext(block +=1);
            diskDrive->writeDiskBlock(diskBlock, block+=1);
           
            delete diskBlock;
            delete diskBlock2;
            
            diskBlock = diskDrive->readDiskBlock(next);
        } while (next > 1 || next < 1);
    } 
    
    
}
