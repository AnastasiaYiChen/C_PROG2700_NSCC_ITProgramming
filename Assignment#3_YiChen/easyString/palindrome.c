//
// Created by yichen on 2/16/20.
//


#include <stdbool.h>

bool palindrome(char *s){   //define a function that return boolean
    char *a = s;		//define a pointer
    int i = 0,j=0,k=0;
    while (*a != '\0'){     	//Use pointer a traversal string，count the numbers of string digits
        a++;
        i++;
    }
    a--;                     //the last string is '\0' minus one
    while (*s != '\0'){       //compare the two
        if (*s == *a){
            k++;
        }
        else{
            return 0;//If it isn't equivalence return false
        }
        s++;//pointer forward traversal
        a--;//pointer traversal backward
    }
    if (k == i){           //if k equal i return true
        return 1;
    }
}
