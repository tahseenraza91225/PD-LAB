#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int key;
    struct Node*next,*prev;
};
struct Node*head=NULL,*last=NULL;
struct Node* CREATE_NODE(){
        struct Node *x= (struct Node *)malloc(sizeof(struct Node));
        x->next=NULL;
        x->prev=NULL;
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
       if(head==NULL){
          head=temp;
          last=temp;
          return;
       }
       temp->next=head;
       head->prev=temp;
       head= temp;
       temp=NULL;    
}
void LIST_INSERT_TAIL(int x){
    if(head==NULL){
        LIST_INSERT_FRONT(x);
        return;
    }
    struct Node *temp1=CREATE_NODE();
    temp1->key=x;
    last->next=temp1;
    temp1->prev=last;
    last=last->next;
}
void LIST_INSERT_AFTER(int x,int y){
     struct Node*foundAt=LIST_SEARCH(y);
     if(foundAt==NULL){
        printf("-1\n");
        return;
     }
      struct Node *temp=CREATE_NODE();
      temp->key=x;
     if(foundAt==last){
        last->next=temp;
        temp->prev=last;
        last=last->next;
        return;
     }
     temp->next=foundAt->next;
     temp->prev=foundAt;
     temp->next->prev=temp;
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
         struct Node *temp=CREATE_NODE();
         temp->key=x;
         foundAt->prev->next=temp;
         temp->prev=foundAt->prev;
         foundAt->prev=temp;
         temp->next=foundAt;
}
void LIST_DELETE(int x){
        
        struct Node*foundAt=LIST_SEARCH(x);
        if(foundAt==NULL){
            printf("-1\n");
            return;
        }
         printf("%d\n",x); 
        if(head->next==NULL){
            head=NULL;
            last=NULL;
            return;
        }
        
        if(foundAt==last){
            last=last->prev;
            last->next=NULL;
            foundAt->prev=NULL;
            return;
        }
        foundAt->next->prev=foundAt->prev;
        foundAt->prev->next=foundAt->next;
        foundAt->next=NULL;
        foundAt->prev=NULL;  
        foundAt=NULL;     
}
void LIST_DELETE_FRONT(){
      if(head==NULL){
        printf("-1\n");
        return;
      }
      printf("%d\n",head->key);
      if(head->next==NULL){
         head=NULL;
         last=NULL;
         return;
      }
      head=head->next;
      head->prev->next=NULL;
      head->prev=NULL;
}
void LIST_DELETE_LAST(){
      if(head==NULL){
        printf("-1\n");
        return;
      }
      printf("%d\n",last->key);
      if(head->next==NULL){
          head=NULL;
          last=NULL;
          return;
      }
      last=last->prev;
      last->next->prev=NULL;
      last->next=NULL;     
}
void LIST_REVERSE_NEGATIVE(){
    if(head==NULL||head->next==NULL){
        LIST_DISPLAY();
        return;
    }
    struct Node*i=head;
    struct Node*j=i->next;
    while(j!=NULL){
       if(j->key<0&&i->key<0){
            int temp=i->key;
            i->key=j->key;
            j->key=temp;
            i=j;
            j=j->next;
       }else if(i->key<0){
            j=j->next;
       }else{
        i=j;
        j=j->next;
       }
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
        else if(d=='n')c='N';
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
         case 'D':
            LIST_DISPLAY();
            break;
         case 'N':
            LIST_REVERSE_NEGATIVE();
            break;
         case 'e':
            exit(1);
        }
        scanf("\n");
    }
    return 0;
}
