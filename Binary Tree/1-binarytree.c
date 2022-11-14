#include <stdio.h>
#include <stdlib.h>

struct bintree{

  int info;
  struct bintree* left;
  struct bintree* right;

};


struct bintree* getMostLeft(struct bintree* root){

   if(root == NULL){

	return NULL;

   }else if(root->left == NULL){

	return root;

   }

   return getMostLeft(root->left);
}

struct bintree* getMostRight(struct bintree* root){

   if(root == NULL){

           return NULL;

   }else if(root->right == NULL){

	   return root;

   }

   return getMostRight(root->right);
}

struct bintree* newtree(int x){

   struct bintree* t = (struct bintree*) malloc (sizeof(struct bintree));

   if(t != NULL){

      t->info = x;
      t->left = NULL;
      t->right = NULL;

      return t;
   }

   return NULL;

}

struct bintree* insert(struct bintree* b, int x){

   if(b == NULL){

      b = newtree(x);

   }else if(x > b->info){

      b->right = insert(b->right, x);

   }else if(x < b->info){

	 b->left = insert(b->left, x);

   }

   return b;

}


/*void reverse(struct bintree* b){


   if(b == NULL){
   	return;
   }


   struct bintree* l = b->left;
   b->left = b->right;
   b->right = l;

   reverse(b->left);

   reverse(b->right);

}
*/
struct bintree* delete(struct bintree* b, int x){
  if(b == NULL){
  	return NULL;
  }
  else if(x > b->info){

     b->right = delete(b->right, x);

  }else if(x < b->info){

	 b->left = delete(b->left, x);

  }else if(b->info == x){

	if(b->left == NULL && b->right != NULL){

		struct bintree* del = b;
		b = b->right;
		free(del);

    }else if(b->left != NULL && b->right == NULL){

		struct bintree* del = b;
		b = b->left;
		free(del);

    }else if(b->left != NULL && b->right != NULL){

		struct bintree* del = b;
		struct bintree* br = b->right;
		b = b->left;
		getMostRight(b)->right = br;
		free(del);

    }else{

    	b = NULL;

    }
  }

  return b;
}


void printTree(struct bintree* b){

   if(b == NULL){
   	return;
   }

   printf("\n%d",b->info);

   printTree(b->left);
   printTree(b->right);

}



int main(){

   struct bintree* b = NULL;

   b = insert(b,5);
   printf("\n After insertion of 5:\n");
   printTree(b);
   b = insert(b,1);
   printf("\n After insertion of 1:\n");
   printTree(b);
   b = insert(b,2);
   printf("\n After insertion of 2:\n");
   printTree(b);
   b = insert(b,3);
   printf("\n After insertion of 3:\n");
   printTree(b);
   b = insert(b,6);
   printf("\n After insertion of 6:\n");
   printTree(b);
   b = insert(b,7);
   printf("\n After insertion of 7:\n");
   printTree(b);

   //reverse(b);
   //printf("\n After tree reversal:\n");
   //printTree(b);
   b = delete(b,5);

   printf("\n After deletion of 5:\n");
   printTree(b);

   return 0;
}
