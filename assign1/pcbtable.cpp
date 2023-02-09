/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.h
 * @author Lucas Gomes
 * @brief This is the implementation file for the PCBTable class.
 * // Remember to add sufficient comments to your code
 */

#include "pcbtable.h"

/**
 * @brief Construct a new PCBTable object of the given size (number of PCBs)
 *
 * @param size: the capacity of the PCBTable
 */
PCBTable::PCBTable(int size) {
   this->table.resize(size);//resize the vector to the given size value
   for(int i=0;i<table.size();i++)//initialize each index to nullptr
   {
    table[i]=nullptr;
   }
}

/**
 * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
 *
 */
PCBTable::~PCBTable() {
   for(int i=0;i<this->table.size();i++)//loop through all indexes of the table
   {
        if(table[i])//if the index has a pdb object/is not null, delete it and set to null
        {
            delete table[i];
            table[i]=nullptr;
        }  
   }
}

/**
 * @brief Get the PCB at index "idx" of the PCBTable.
 *
 * @param idx: the index of the PCB to get
 * @return PCB*: pointer to the PCB at index "idx"
 */
PCB* PCBTable::getPCB(unsigned int idx) {
    if(this->table.at(idx))//if there is a pointer at the given index, return the pointer
        return table.at(idx);
    return NULL;
}

/**
 * @brief Add a PCB to the PCBTable.
 *
 * @param pcb: the PCB to add
 */
void PCBTable::addPCB(PCB *pcb, unsigned int idx) {
    if(!this->table[idx])//if the requested index is not already full, add the PCB into that position
        this->table[idx]=pcb;
}
