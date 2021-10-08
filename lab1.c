#include <stdio.h>
#include <string.h>
#define is_abc(c) (((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z')) 
 
int checkpalindrome(char *s)
{
    int i,c=0,n;
    n=strlen(s);
    for(i=0;i<n/2;i++)  
    {
        if(s[i]==s[n-i-1])
        c++;
 
    }
    if(c==i)
        return 1;
    else
        return 0;
}
 
char* remove_words(char* s){
    int   n;
    char* p, *i, *t = s;
    const char vs[] = "AaEeOoYyUuIi";
 
    for(p = s; *s; *s = *p){
        if(is_abc(*p)){
            n = 0;
            i = p;
            while(is_abc(*i)){
                if(strchr(vs, *i) == NULL)
                    ++n;
                ++i;
            }
 
            if(n & 1)
                p = i;
            else {
                while(p != i)
                    *s++ = *p++;
            }
            continue;
        }
        ++s;
        ++p;
    }
    return t;
}
 
int main(void){
    char s[1000];
    int i;
    printf("Enter  the string: ");
    fgets(s, sizeof(s), stdin);
    while(s[i]!=0 && s[i]!='\n') i++;
        s[i] = 0;
    if(checkpalindrome(s))
        printf("string is palindrome\n");
    else
        printf("string is not palindrome\n");

    puts( remove_words(s) );
    return 0;
}