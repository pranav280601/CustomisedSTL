//generic programming
//STL
#include<iostream>
using namespace std;

//Singly Linear LL
template <typename T>
 struct    nodeDS
{
    T data;
    struct   nodeDS *next;
    struct   nodeDS *prev;

};

template <class T>
class SinglyLL
{
private:
    nodeDS <T>* first;
    int  iSize;
    
public:
    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T ,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};

template <class T>
 SinglyLL<T>::SinglyLL()
   {
       first = NULL;
        iSize = 0;
   }

template <class T>   
   void SinglyLL<T>::InsertFirst(T no)
   {
          nodeDS <T>*  newN = new    nodeDS<T>;  //  newN = (PNODE)malloc( iSizeof(NODE))
       
        newN->data = no;
        newN->next = NULL;
       
       if(first == NULL)
       {
           first =  newN;
       }
       else
       {
            newN->next = first;
           first =  newN;
       }
        iSize++;
   }

   template <class T>
   void SinglyLL<T>::InsertLast(T no)
   {
          nodeDS<T> *  newN = new    nodeDS<T>;  //  newN = (PNODE)malloc( iSizeof(NODE))
       
        newN->data = no;
        newN->next = NULL;
       
       if(first == NULL)
       {
           first =  newN;
       }
       else
       {
               nodeDS <T> * temp = first;
           
           while(temp->next != NULL)
           {
               temp = temp->next;
           }
           temp->next =  newN;
       }
        iSize++;
   }
   
   template <class T>
   void SinglyLL<T>::InsertAtPos(T no, int iPos)
{
  int  iSize=0,i=0;
      nodeDS<T>* newN= NULL;
      nodeDS<T>* temp= first;

   iSize=Count(first);
  
  if((iPos<1)||(iPos > iSize+1))//Filter for invalid position
  {
    cout<<"Invalid position\n";
    return;
  }

  if(iPos==1)// First position
  {
    InsertFirst(first,no);
  }
  else if(iPos==  iSize+1)//Last position
  {
    InsertLast(first,no);
  }
  else//In between position
  {
       nodeDS<T>* newN=new    nodeDS<T>;
    newN -> data= no;
    newN -> next=NULL;
    for(i=1;i< iPos-1;i++)
    {
        temp= temp -> next;
    } 
    newN -> next =temp-> next;
    temp -> next = newN;
  }
}

   template <class T>
   void SinglyLL<T>::DeleteFirst()
   {
           nodeDS<T> * temp = first;
       
       if(first != NULL)
       {
           first = first->next;
           delete temp;
           
            iSize--;
       }
   }
   
   template <class T>
   void SinglyLL<T>::DeleteLast()
   {
          nodeDS<T> * temp = first;
       
       if(first == NULL)
       {
           return;
       }
       else if(first->next == NULL)
       {
           delete first;
           first = NULL;
            iSize--;
       }
       else
       {
           while(temp->next->next != NULL)
           {
               temp = temp->next;
           }
           
           delete temp->next;
           temp->next = NULL;
            iSize--;
       }
   }
   
   template <class T>
   void SinglyLL<T>::DeleteAtPos(int iPos)
{
  int  iSize=0,i=0;
     nodeDS<T>* temp=first;
     nodeDS<T>* targeted=NULL;

   iSize=Count(first);
  
  if((iPos<1)||(iPos > iSize))//Filter for invalid position
  {
    cout<<"Invalid position\n";
    return;
  }

    if(iPos==1)// First position
  {
    DeleteFirst(first);
  }
  else if(iPos==  iSize)//Last position
  {
    DeleteLast(first);
  }
  else //In between position
  {
    for(i=1;i<iPos-1;i++)
    {
        temp= temp -> next;
    }
    targeted =temp -> next;
    temp -> next = targeted -> next;
    delete(targeted);
  }
}
   template<class T>
   void SinglyLL<T>::Display()
   {
          nodeDS<T>* temp = first;
       
       while(temp!= NULL)
       {
           cout<<temp->data<<"\t";
           temp = temp->next;
       }
       cout<<"\n";
   }
   
   template <class T>
   int SinglyLL<T>::Count()
   {
       return  iSize;
   }
//////////////////////////////////////////////////////////////////////////
//Singly Circular LL
template <class T>
class SinglyCL
{
private:
       nodeDS <T>* first;
       nodeDS <T>* last;
    int  iSize;
    
public:
    SinglyCL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T ,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};

template <class T>
 SinglyCL<T>::SinglyCL()
   {
       first = NULL;
       last  = NULL;
        iSize = 0;
   }

 template <class T>  
    void SinglyCL<T>::Display()
    {
            nodeDS <T>* temp  = first;
        
        if((first == NULL) && (last == NULL))
        {
            return;
        }
        
        do
        {
            cout<<"|"<<temp->data<<"|-> ";
            temp = temp->next;
        }while(temp != last->next);
        
        cout<<"\n";
    }

template <class T>
    int SinglyCL<T>:: Count()
    {
        return  iSize;
    }
    
    template <class T>
    void SinglyCL<T>::InsertFirst(T no)
    {
            nodeDS <T>*  newN = new     nodeDS<T> ;
        
         newN->data = no;
         newN->next = NULL;
        
        if((first == NULL) && (last == NULL))
        {
            first =  newN;
            last =  newN;
        }
        else
        {
             newN->next = first;
            first =  newN;
        }
        
        last->next = first;
         iSize++;
    }
    
    template <class T>
    void SinglyCL<T>::InsertLast(T no)
    {
            nodeDS <T>*  newN = new     nodeDS<T> ;
        
         newN->data = no;
         newN->next = NULL;
        
        if((first == NULL) && (last == NULL))
        {
            first =  newN;
            last =  newN;
        }
        else
        {
            last->next =  newN;
            last =  newN;
        }
        
        last->next = first;
         iSize++;
    }
    
    template <class T>
    void SinglyCL<T>::InsertAtPos(T no, int ipos)
    {
        if((ipos < 1) || (ipos > ( iSize+1)))
        {
            return;
        }
        
        if(ipos ==1)
        {
            InsertFirst(no);
        }
        else if(ipos ==  iSize+1)
        {
            InsertLast(no);
        }
        else
        {
                nodeDS <T>*  newN = new     nodeDS <T>;
            
             newN->data = no;
             newN->next = NULL;
            
                nodeDS <T>* temp = first;
            
            for(int i = 1; i < ipos-1; i++)
            {
                temp = temp->next;
            }
            
             newN->next = temp->next;
            temp->next =  newN;
            
             iSize++;
        }
    }
    
    template <class T>
    void SinglyCL<T>::DeleteFirst()
    {
        if((first == NULL) && (last == NULL))
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            first = first->next;
            delete last->next;
            last->next = first;
        }
         iSize--;
    }

    template <class T>
    void SinglyCL<T>::DeleteLast()
    {
            nodeDS <T>* temp = first;
        
        if((first == NULL) && (last == NULL))
        {
            return;
        }
        else if(first == last)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            while(temp->next != last)
            {
                temp = temp -> next;
            }
            
            delete last;
            last = temp;
                
            last->next = first;
        }
         iSize--;
    }
    
    template <class T>
    void SinglyCL<T>::DeleteAtPos(int ipos)
    {
        if((ipos < 1) || (ipos >  iSize))
        {
            return;
        }
        
        if(ipos ==1)
        {
            DeleteFirst();
        }
        else if(ipos ==  iSize)
        {
            DeleteLast();
        }
        else
        {
                nodeDS <T>* temp = first;
            for(int i = 1; i < ipos-1; i++)
            {
                temp = temp->next;
            }
            
                nodeDS <T>* targated = temp->next;
            
            temp->next = targated->next;    // temp->next = temp->next->next;
            delete targated;
            
             iSize--;
        }
        
    }
/////////////////////////////////////////////////////////////////////////
//Doubly Circular LL
template <typename T>
 struct nodeD
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;
};

template <class T>
class DoublyCL
{
private:
    nodeD <T>* first;
    nodeD <T>* last;
    int iSize;
    
public:
    DoublyCL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T ,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};

template <class T>
 DoublyCL<T>::DoublyCL()
   {
       first = NULL;
       last  = NULL;
       iSize = 0;
   }

template <class T>
void DoublyCL<T>:: InsertFirst(T No)
{
    nodeD<T>* newN = new nodeD<T>;

    newN->data = No;
    newN->next = NULL;
    newN->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newN;
        last = newN;
    }

    else
    {
        newN->next = first;
        first->prev = newN;
        first = newN;
    }
    last->next = first;
    first->prev = last;

    iSize++;
}

template <class T>
void DoublyCL<T>:: InsertLast(T No)
{
    nodeD<T>* newN = new nodeD<T>;

    newN->data = No;
    newN->next = NULL;
    newN->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newN;
        last = newN;
    }

    else
    {
        newN->prev = last;
        last->next = newN;
        last = newN;
    }
    last->next = first;
    first->prev = last;

    iSize++;
}

template <class T>
void DoublyCL<T> :: InsertAtPos(T No, int iPos)
{
    if((iPos < 1) || (iPos > iSize+1))
    {
        cout<<"Invalid position"<<endl;
        return; 
    }
    else if((iPos == 1))
    {
        InsertFirst(No);
    }
    else if(iPos == (iSize+1))
    {
        InsertLast(No);
    }
    else
    {
        nodeD<T>* newN = new nodeD<T>;
        newN->data = No;
        newN->next = NULL;
        newN->prev = NULL;

        nodeD<T>* temp = first;
        for(int i = 1; i < (iPos -1); i++)
        {
            temp = temp->next;
        }

        newN->prev = temp;
        newN->next = temp->next;
        newN->next->prev = newN;
        temp->next = newN;
        iSize++;
    }
}

template <class T>
void DoublyCL<T>:: DeleteFirst()
{
    if((first==NULL) && (last == NULL))
    {
        return;
    }
    else if((first == last))
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first; 
        first->prev = last;
    }
    iSize--;
}

template <class T>
void DoublyCL<T>:: DeleteLast()
{       
    if((first==NULL) && (last == NULL))
    {
        return;
    }
    else if((first == last))
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;
        last->next = first;
        first->prev = last;
    }
    iSize--;
}

template <class T>
void DoublyCL<T>:: DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iSize+1))
    {
        cout<<"Invalid position"<<endl;
        return; 
    }
    else if((iPos == 1))
    {
        DeleteFirst();
    }
    else if(iPos == (iSize))
    {
        DeleteLast();
    }
    else
    {
        nodeD<T>* temp = first;
        for(int i = 1; i < (iPos -1); i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iSize--;
    }   
}

template <class T>
void DoublyCL<T>:: Display()
{
    nodeD<T>* temp = first;

    for (int i = 1; i <=iSize; i++)
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////
//Doubly Linear LL

template <class T>
class DoublyLL
{
private:
    nodeD <T>* first;
    nodeD <T>* last;
    int iSize;
    
public:
    DoublyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T ,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};
template <class T>
 DoublyLL<T>::DoublyLL()
   {
       first = NULL;
       last  = NULL;
       iSize = 0;
   }

template <class T>
 void DoublyLL<T>:: Display()

{
   while(first !=NULL)
  {
    cout<<"|"<<first ->data<<"|->cl";
    first = first -> next;
  }
  cout<<"NULL\n";
}

template <class T>
 void DoublyLL<T>:: InsertFirst(T no)
{
   nodeD <T>*newN= new nodeD<T>;

   newN -> data=no;
   newN ->next=NULL;
   newN -> prev=NULL; 
   if(first == NULL)
   {
    first=newN;
   }
   else
   {
     newN -> next =first;
     (first)-> prev =newN;
     first=newN;
   }
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    nodeD <T>* temp=first;
   nodeD <T>*newN= new nodeD<T>;

   newN -> data=no;
   newN ->next=NULL;
   newN -> prev=NULL; 
   if(first == NULL)
   {
    first=newN;
   }
   else
   {
      while(temp -> next !=NULL)
      {
        temp = temp->next;
      }
      temp -> next= newN;
      newN->prev=temp;
   }
}

template <class T>
void DoublyLL<T>:: DeleteFirst()
{
    nodeD <T>* temp= first;
    if(first !=NULL) //LL  contains atleast 1 nodeD
    {
       first = (first) -> next;
       delete(temp);
       if(first != NULL)
       {
          (first) -> prev=NULL;
       }
    }
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    nodeD <T>* temp =first;
   if(first ==NULL)//LL  contains 0 nodeD
    {
     return;
    }
    else if((first) -> next ==NULL)//LL  contains atleast 1 nodeD
    {
        delete(first);
        first =NULL;
    }
    else //LL  contains more 1 nodeD
    {
        while(temp -> next!=NULL)
        {
            temp =temp->next;
        }
        temp->prev->next= NULL;
        delete(temp);
    }
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no,int iPos)
{
  int iSize=Count(first);
  int i=0;
  nodeD <T>* newN= NULL;
  nodeD <T>* temp= first;  

  if((iPos<1)||(iPos >iSize+1))//Filter for invalid position
  {
    cout<<"Invalid position\n";
    return;
  }
  else if(iPos==1)
  {
    InsertFirst(no);
  }
  else if(iPos==iSize+1)
  {
    InsertLast(no);
  }
  else
  {
    nodeD <T>*newN= new nodeD<T>;
     newN -> next =NULL;
     newN -> prev =NULL;
     newN -> data =no;
     for(i=1;i<iPos-1;i++)
     {
        temp =temp -> next;
     }
     newN ->next =temp-> next;
     newN ->next->prev=newN;
     temp-> next= newN;
     newN-> prev=temp;
  }
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
  int iSize=Count(first);
  int i=0;
  if((iPos<1)||(iPos >iSize))//Filter for invalid position
  {
    cout<<"Invalid position\n";
    return;
  }
  else if(iPos==1)
  {
    DeleteFirst(first);
  }
  else if(iPos==iSize)
  {
    DeleteLast(first);
  }
  else
  {
     nodeD<T>* temp = first;
    
      for(i=1;i<iPos-1;i++)
     {
        temp =temp -> next;
     }
     temp -> next=temp -> next->next;
     delete(temp -> next->prev);
     temp -> next->prev=temp;
  }
}
template <class T>
int DoublyLL<T>:: Count()
{
    return iSize;
}


//////////////////////////////////////////////////////////////////////////
int main()
{
/*SinglyLL <float>SLLfobj;
SinglyLL <double>SLLdobj;

SinglyLL <char>SLLcobj;
    int iret = 0;   
    obj.InsertFirst('C');
    obj.InsertFirst('B');
    obj.InsertFirst('A');
    obj.InsertLast('D');
    obj.InsertLast('E');
    obj.Display();
    iret = obj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";

    SinglyLL <int>SLLiobj;
    iobj.InsertFirst(30);
    iobj.InsertFirst(20);
    iobj.InsertFirst(10);
    iobj.InsertLast(40);
    iobj.InsertLast(50);
    iobj.Display();
    iret =iobj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";
   
    SinglyCL <float>SCLfobj;
    fobj.InsertFirst(30.1);
    fobj.InsertFirst(20.1);
    fobj.InsertFirst(10.1);
    fobj.InsertLast(40.1);
    fobj.InsertLast(50.1);
    fobj.Display();
    iret =iobj.Count();
    cout<<"Number of elemensts are : "<<iret<<"\n";

    SinglyCL <double>SCLdobj;

    SinglyCL <int>SCLiobj;

    SinglyCL <char>SCLcobj;


Doubly <char>DLLcobj;
Doubly <int>DLLiobj;
Doubly <float>DLLfobj;
Doubly <double>DLLdobj;
Doubly <char>DCLcobj;
Doubly <int>DCLiobj;
Doubly <float>DCLfobj;
Doubly <double>DCLdobj;
*/
    return 0; 
}





