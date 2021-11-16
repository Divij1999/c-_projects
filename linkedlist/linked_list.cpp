#include<iostream>
using namespace std;

struct node{
  int data;
  node *link;
};


void insert(node* &head, node* &temp, int &n, int &p){
  temp=new node();
  temp->data=n;
  char check;
  if(p==1 || head==nullptr){   //If user in the beginning or if the list is empty
    if(head==nullptr && p!=1){
      cout<<"List is empty. Insert element in the beginning instead(y/n)?:";
      cin>>check;
      cout<<endl;
      if(check=='n')  //To check if the user wants to insert in the beginning instead if the list is empty
        return;
    }
    temp->link=head;
    head=temp;
  }
  else{
    node *traverse=head;
    for(size_t i=0;i!=p-2;++i){
      if(traverse->link==nullptr){   //To check if the user has entered a position greater than the amount of nodes in the list
        cout<<"Cannot insert element at "<<p<<" position.\n"
            <<"Would you like to insert element at "<<i+2<<" position instead(y/n)?"<<endl;
        cin>>check;
        if(check=='n'){
          return;
        }
        break;
      }
      traverse=traverse->link; //Moving forward in the list
    }
    temp->link=traverse->link;  //Insertin the element in the list
    traverse->link=temp;
  }
  temp=nullptr;
  char choice; //To check if user wants to enter another element
  cout<<"Enter again(y/n)?:";
  cin>>choice;
  if(choice=='y'){
    cout<<"Enter element and position:";
    cin>>n>>p;
    cout<<endl;
    return insert(head, temp, n, p);
  } 

  return;
}

void remove(node* &head, int &p){
  node* deleter=head->link;
  node* temp=head;
  for(size_t i=0;i!=p-2;++i){
    deleter=deleter->link;
    temp=temp->link;
  }
  temp->link=deleter->link;
  delete deleter;
  deleter=nullptr;
  temp=nullptr;
  char choice;
  cout<<"Delete again(y/n)?:";
  cin>>choice;
  if(choice=='y'){
    cout<<"Enter the position of node you want to remove:";
    cin>>p;
    cout<<endl;
    return remove(head, p);

  }
  return;
}

void print(node* head){
  node *temp=head;
  while(temp!=nullptr){
    cout<<temp->data<<" ";
    temp=temp->link;
   }
    cout<<"\n";

    return;
}

int main(){
  node* head=nullptr;
  node* temp=nullptr;
  int p, e, choice;
  char c;
  do{
    cout<<"1.Enter an element in list\n"<<"2.Print the list\n"<<"3.Remove a node\n"<<endl;
    cin>>choice;
    switch(choice){
      case 1: cout<<"Enter an element and the positon:";
              cin>>e>>p;
              cout<<endl;
              insert(head, temp, e, p);
              break;
      case 2: print(head);
              cout<<endl;
              break;
      case 3: cout<<"Enter the position of the node you want to remove:";
              cin>>p;
              cout<<endl;
              remove(head, p);
              break;
      default: cout<<"Enter a valid option.\n";
               break;
    }
    cout<<"Choose another option(y/n)?:";
    cin>>c;
    cout<<endl;
  }while(c!='n');

  return 0;
}