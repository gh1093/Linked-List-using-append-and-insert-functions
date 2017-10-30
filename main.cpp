/*
 Author: Gabriel Hurtado
 Instructor: Dr. Hwang
 Class: Data Structures 
 Project: Project 2
 Date: 9/25/2017
 */

#include <iostream>
#include<cstring>
#include"student.h"
#include <stdio.h>
#include<string>
#include <cctype>

using namespace std;

//our append function: we feed it the root node of the linked list. 
void append(node *&root,student s)
{
    node *last=new node;
    last->stud=s;
    last->next=NULL;
    
    if(root==NULL)
    {
        root=new node;
        root=last;
        root->next=NULL;
    }
    else//if(root!=NULL)
    {
        node *temp=new node;
        temp=root;
       while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next=last;
        
    }
}
  void insertNode(node *&root,student s)
   {
    node *newentry=new node;
    newentry->stud=s;
    newentry->next=NULL;
    //if list is empty, s is root
    if(root==NULL)
    {
       // cout<<"WAAAA";
        root=new node;
        root=newentry;
        root->next=NULL;
        return; 
    }
    //newentry should come before head
    else if(newentry->stud.getName().compare(root->stud.getName())<0)
    {
        swapNodesRoot(root,newentry);   
        return;
    }
    else//if(root!=NULL)//newentry comes after the head
    {
        node *prev=new node;
        node *temp=new node;
        temp=root;
       while(temp->next!=NULL)
       {
           prev=temp;
           temp=temp->next;
           if(newentry->stud.getName().compare(temp->stud.getName())<0)
           {
               swapNodes(temp,newentry,prev);
               return;
           } 
           
        }
         temp->next=newentry;
        return;
    }
  }

int main(int argc, char** argv) {

    //Here we have the array of the 15 student records 
    
    student *arr=new student[15];
    arr[0]= student("Bob B.",1,"49 Hi Rd",3.5);
    arr[1]=student("Mark Mot",23,"123 blah st.",2.3);
    arr[2]=student("Sam Sosa",21,"1234 vegas st.",2.5);
    arr[3]=student("Bill Beeter",91,"22 ford st",2.2);
    arr[4]=student("Jesse Jot",66,"45 string st.",2.32);
    arr[5]=student("Tim Trunk",234,"909 hill st.",4.0);
    arr[6]=student("Mike Jordan",421,"834 cherry st.",2.9);
    arr[7]=student("Elvis Pres",83,"092 love st.",2.3);
    arr[8]=student("George Wash",43,"123 run st.",0.3);
    arr[9]=student("John Jones",72,"1934 hide st.",4.0);
    arr[10]=student("Sam Cassidy",32,"502 hider st.",3.6);
    arr[11]=student("Ryan Rooter",909,"678 circle st.",3.2);
    arr[12]=student("Chris Cryer",192,"432 avenue st.",1.2);
    arr[13]=student("Phil Foots",8472,"839 grave st.",2.09);
    arr[14]=student("Madison Monto",55,"303 winter st.",1.3);
    
    //this node is used for the linked list
    node *n;
    //we append every student record into the linked list
    cout<< "This is the array: \n";
    
    for(int a=0;a<15;a++)
    {
        append(n,arr[a]);
        cout<< arr[a].getName() << " "
        << arr[a].getAddr()<< " "
        << arr[a].getGPA()<< " "
        << arr[a].getID()<< " "
        <<endl;
  
    }
    //here we output all the info that was appended to the linked list
    cout<< "\nThis is the un-sorted linked list: \n";
    
    while(n!=NULL)
    {
        cout<< "name:"<< n->stud.getName()<< " -- >";
        n=n->next;
    }
    if(n==NULL)
        cout<<"NULL";
    string bb="Bob B";
    string cc="Bobb B";
  if(bb.compare(cc)<0)
        cout<<"ya";
 
    node *o=NULL;
    node *p=NULL;//for deletion 
    node *q=NULL;//for insertion
    for(int h=0;h<15;h++)
    {
        insertNode(p,arr[h]);
        insertNode(o,arr[h]);
        insertNode(q,arr[h]);
    }
    cout<<"\n\nSorted Linked List: \n";
    
    while(o!=NULL)
    {
        cout<< "name:"<< o->stud.getName()<< " -- >\n";
        o=o->next;
    }
    if(o==NULL)
        cout<<"NULL";
    
    int del;
    cout<<"\nWhich position would you like to delete?";
    cin>>del;
  
    deleteNode(p,del);
    deleteNode2(q,del);
    cout <<"\nAFTER DELETION:\n";
    while(p!=NULL){
        cout<< "name:"<< p->stud.getName()<< " -- >\n";
        p=p->next;
    }
    if(p==NULL)
        cout<<"NULL\n";
    
    char fname[15],lname[15];
    cout<<"Enter a student first name to insert: First and Last: ";
    cin>>fname>>lname;
    fname[0]=toupper(fname[0]);
    lname[0]=toupper(lname[0]);
    string fn(fname);
    string ln(lname);
  
    student *x=new student(fn+" "+ln,1,"49 Hi Rd",3.5);
   
    insertNode(q,*x);
   
     cout <<"\nAFTER Insertion:\n";
    while(q!=NULL){
        cout<< "name:"<< q->stud.getName()<< " -- >\n";
        q=q->next;
    }
     if(q==NULL)
         cout<<"NULL";
    
}

