#include"student.h"
#include<string>

using namespace std;

    student::student(){}
    //this constructor allows us to initialize private variables on the fly
    student::student(string name, int ID, string addr, double gpa)
    {
        this->name=name;
        this->ID=ID;
        this->addr=addr;
        this->gpa=gpa;
        
    }
    
    void student::setGPA(double gpa){
        this->gpa=gpa;
    }
    double student::getGPA(){
    return this->gpa;
    }
    void student::setName(string name){
        this->name=name;
    }
    string student::getName(){
    return this->name;
    }
    string student::getAddr(){
        return this->addr;
    }
    void student::setAddr(string addr){
        this->addr=addr;
    }
    void student::setID(int id)
    {
        this->ID=id;
    }
    int student::getID(){
        return this->ID;
    }
   struct node *root;
   //this allows a swap with the root. If y is less than x then pointers
   // are rearranged and y becomes the new root
   void swapNodesRoot(node *&x,node *&y)
   {
       y->next=x;
       x=y;
   }
   
   //this allows to us to rearrange nodes in the linkedlist. If y should be before
   //node x then this rearranges the pointers to keep the list sorted
   void swapNodes(node *&x, node *&y, node *&z) 
   {
       y->next=x;
       z->next=y;
   }
   void deleteNode(node *&p,int deletion)
   {
       node *start=new node;
       node *sub=new node;
       //start;
       sub=p;
       if(deletion==1)
       {
           p=p->next;
        return;
       }
       for(int a=1;;a++)
       {
         
           if(a==deletion)
           {
               start->next=sub->next;
               return;
           }
           start=sub;
           if(sub->next==NULL)
           {
           cout<<"That position does not exist!";
            return;
           }
               
           sub=sub->next;
           
       }
       
   }

    void deleteNode2(node *&p,int deletion)
   {
       node *start=new node;
       node *sub=new node;
       //start;
       sub=p;
       if(deletion==1)
       {
           p=p->next;
        return;
       }
       for(int a=1;;a++)
       {
         
           if(a==deletion)
           {
               start->next=sub->next;
               return;
           }
           start=sub;
           if(sub->next==NULL)
           {
           cout<<"That position does not exist!";
           }
               
           sub=sub->next;
           
       }
       
   }

    
   
