#include<cstdio>
#include<sstream>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include "memory.h"
#include "pageTableEntry.h"
#include "pageTable.h"
#include "processTable.h"

using namespace std;


int hit_it = 0, miss_it = 0, access_it = 0, comp_miss = 0;
ProcessTable* process;
PageTable* pageTable;
Memory* memory;

void accessLoc(int numb){
  access_it++;
  numb = numb >> 10;
  PageTableEntry* pte = pageTable->getPTE(numb);
  if(pte == 0 || pte == NULL){
    pte = new PageTableEntry();
    pageTable->setPTE(numb, pte);
    comp_miss++;
  }
  if(pte->in_Momery()){
    hit_it++;
  }else{
    miss_it++;
    pte->swapToMemory(memory->getCurrent());
    memory->setFrame(memory->getFreeFrame(), pte);
  }

  //cout << "I am access: "<< numb << endl;
}
void switchThis(int numb){
  pageTable = process->getProcPT(numb);
  //cout << "I am switch: "<< numb << endl;
}
void newArray(int numb){
  process->setProcPT(numb, new PageTable());
  //cout << "I am new: "<< numb << endl;
}


int main(){
  process = new ProcessTable();
  memory = new Memory();
  string splitLine;
  //Reading the file
  freopen("VMInput.txt", "rb", stdin);
  //freopen("mytest.txt", "rb", stdin);
  string s;
  while(getline(cin, s)){
    std::string delim = " ";
    auto start = 0U;
    auto end = s.find(delim);
    string toDo = " ";
    string loc = " ";
    while (end != std::string::npos)
    {
        toDo = s.substr(start, end - start);
        start = end + delim.length();
        end = s.find(delim, start);
    }
    loc = s.substr(start, end);
    stringstream s(loc);
    int intLoc = 0;
    s >> intLoc;
    /*cout << "I am loc: "<< loc << endl;
    cout << "I am intLoc: "<< intLoc << endl;*/
    if(!toDo.compare("new")) {
      newArray(intLoc);
    }
    if(!toDo.compare("switch")) {
      switchThis(intLoc);
    }
    if(!toDo.compare("access")) {
      accessLoc(intLoc);
    }

  }
  cout << "Acess: "<< access_it << endl;
  cout << "Hits: "<< hit_it << endl;
  cout << "Misses: "<< miss_it << endl;
  cout << "Compulsory Misses: "<< comp_miss << endl;

  return 0;
}
