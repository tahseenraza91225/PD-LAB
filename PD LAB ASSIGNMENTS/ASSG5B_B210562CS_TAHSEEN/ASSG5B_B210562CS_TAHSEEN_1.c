#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int key;
    struct Node*next;
};
struct Node*head=NULL;
struct Node* CREATE_NODE(){
        struct Node *x= (struct Node *)malloc(sizeof(struct Node));
        x->next=NULL;
        return x;
}
void LIST_DISPLAY(){
        if(head==NULL){
            printf("-1\n");
            return;
        }
        struct Node*temp=head;
        while(temp!=NULL){
            printf("%d ",temp->key);
            temp=temp->next;
        }
        temp=NULL;
        printf("\n");
}
struct Node*LIST_SEARCH(int x){
          struct Node*temp=head;
          while(temp!=NULL){
            if(temp->key==x)return temp;
            temp=temp->next;
          }
          return temp;
}
void LIST_INSERT_FRONT(int x){
       struct Node *temp=CREATE_NODE();
       temp->key=x;
       temp->next=head;
       head= temp;
       temp=NULL;
    
}
void LIST_INSERT_TAIL(int x){
    if(head==NULL){
        LIST_INSERT_FRONT(x);
        return;
    }
    struct Node *temp1=CREATE_NODE(),*temp2=head;
    temp1->key=x;
    temp1->next=NULL;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
    temp1=NULL,temp2=NULL;
}
void LIST_INSERT_AFTER(int x,int y){
     struct Node*foundAt=LIST_SEARCH(y);
     if(foundAt==NULL){
        printf("-1\n");
        return;
     }
     struct Node *temp=CREATE_NODE();
     temp->key=x;
     temp->next=foundAt->next;
     foundAt->next= temp;
     temp=NULL;
}
void LIST_INSERT_BEFORE(int x,int y){
         struct Node*foundAt=LIST_SEARCH(y);
         if(foundAt==NULL){
            printf("-1\n");
            return;
         }
         if(head->next==NULL){
            LIST_INSERT_FRONT(x);
            return;
         }
         // 
         struct Node*helper=head;
         while(helper->next!=foundAt){
               helper=helper->next;
         }
        LIST_INSERT_AFTER(x,helper->key);
}
void LIST_DELETE(int x){
        if(head==NULL){
            printf("-1\n");
            return;
        }
        if(head->next==NULL&&head->key==x){
            printf("%d\n",x);
            head=NULL;
            return;
        }
        struct Node*temp=head;
        while(temp->next!=NULL && temp->next->key!=x){
            temp=temp->next;    
        }
        if(temp->next==NULL){
            printf("-1\n");
            return;
        }
        printf("%d\n",x);
        struct Node*ptr=temp->next->next;
        temp->next->next=NULL;
        temp->next=ptr;
}
void LIST_DELETE_FRONT(){
      if(head==NULL){
        printf("-1\n");
        return;
      }
      printf("%d\n",head->key);
      struct Node*temp=head;
      head=head->next;
      temp->next=NULL;
}
void LIST_DELETE_LAST(){
      if(head==NULL){
        printf("-1\n");
        return;
      }
      if(head->next==NULL){
        printf("%d\n",head->key);
          head=NULL;
          return;
      }
      struct Node*temp=head;
      while(temp->next->next!=NULL){
            temp=temp->next;
      }
      printf("%d\n",temp->next->key);
      temp->next=NULL;
      temp=NULL;
}
void LIST_REVERSE(){
    if(head==NULL){
        printf("-1\n");
        return;
    }
    if(head->next==NULL){
        LIST_DISPLAY();
        return;
    }
   struct Node*prev=NULL,*curr=head,*next=curr->next;
   while(next!=NULL){
         curr->next=prev;
         prev=curr;
         curr=next;
         next=next->next;
   }
   curr->next=prev;
   head=curr;
   curr=NULL;
   next=NULL;
   prev=NULL;
   LIST_DISPLAY();    
}
int GET_LENGTH_OF_LIST(struct Node*head){
    int len=0;
    struct Node*temp=head;
    while(temp!=NULL){
         len++;
         temp=temp->next;
    }
    return len;
}
void LIST_REVERSE_EVEN(){
    int len=GET_LENGTH_OF_LIST(head);
    struct Node*even1,*even2;
    if(len<4){
       LIST_DISPLAY();
       return;
    }
    int idx=4;
    struct Node*temp=head->next;
    while(idx<=len){
        even1=temp;
        even2=even1->next->next;
        temp=even2;
        int dummy=even1->key;
        even1->key=even2->key;
        even2->key=dummy;
        idx+=2;
    }
    LIST_DISPLAY();
}

int main()
{
    char c,d;
    int x,y;
    struct Node *temp=NULL;
    while(1){
        scanf("%c",&c);
        scanf("%c",&d);
        if(d=='s')c='D';
        else if(d=='e')c='R';
        switch (c)
        {
        case 'f':
              scanf("%d",&x);
            LIST_INSERT_FRONT(x);
            break;
        case 't':
            scanf("%d",&x);
            LIST_INSERT_TAIL(x);
            break;
        case 'a':
            scanf("%d%d",&x,&y);
            LIST_INSERT_AFTER(x,y);
            break;
        case 'b':
            scanf("%d%d",&x,&y);
            LIST_INSERT_BEFORE(x,y);
            break;
        case 'd':
            scanf("%d",&x);
            LIST_DELETE(x);
            break;
        case 'i':
            LIST_DELETE_FRONT();
            break;
        case 'l':
            LIST_DELETE_LAST();
            break;
        case 's':
            scanf("%d",&x);
            temp=LIST_SEARCH(x);
            if(temp==NULL)printf("-1\n");
            else printf("1\n");
            break;
         case 'r':
            LIST_REVERSE();
            break;
         case 'D':
            LIST_DISPLAY();
            break;
         case 'R':
            LIST_REVERSE_EVEN();
            break;
         case 'e':
            exit(1);
        }
        scanf("\n");
    }
    return 0;
}
