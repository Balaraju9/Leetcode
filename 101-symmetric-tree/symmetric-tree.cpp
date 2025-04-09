/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool fun(TreeNode* r1,TreeNode* r2){
        if(r1==NULL && r2!=NULL || r1!=NULL && r2==NULL){
            return false;
        }
        else if(r1==NULL && r2==NULL){
            return true;
        }
        else if(r1->val !=r2->val){
            return false;
        }
        return fun(r1->left,r2->right) && fun(r1->right,r2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL)){
            return false;
        }
        return fun(root->left,root->right);
        
    }
};























------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
inputasoutput
%{
#include <stdio.h>
%}

%%
.   { printf("%s", yytext); }
\n  { printf("\n"); }
%%

int yywrap(void) {
    return 1;
}

int main(void) {
    yylex();
    return 0;
}
---------------------------------------------------------------------------------------------
%{
#include <stdio.h>
%}

%%
[\n\t ' ']  ;    // Ignore spaces, tabs, and newlines
.           { printf("%s", yytext); }  // Print everything else
%%

int yywrap() {
    return 1;
}

int main() {
    yyin = fopen("myfile.txt", "r");  // Open the input file
    if (!yyin) {
        printf("Error opening file!\n");
        return 1;
    }
    yylex();  // Run lexer
    fclose(yyin);  // Close file
    return 0;
}
---------------------------------------------------------------------------------------------
    pattern
%{
#include <stdio.h>
%}

%%
"int"|"char"|"for"|"if"|"while"|"then"|"return"|"do"   { printf("Keyword: %s\n", yytext); }
[\+\-\*/%]                                            { printf("Operator: %s\n", yytext); }
[(){};]                                               { printf("Special Character: %s\n", yytext); }
[0-9]+                                                { printf("Constant: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*                                { printf("Valid Identifier: %s\n", yytext); }
[^a-zA-Z0-9_]+                                        { printf("Invalid Identifier: %s\n", yytext); }
%%

int yywrap() {
    return 1;
}

int main() {
    yyin = fopen("input.txt", "r");  // Open input file
    if (!yyin) {
        printf("Error opening file!\n");
        return 1;
    }
    yylex();  // Run lexical analyzer
    fclose(yyin);  // Close file
    return 0;
}
---------------------------------------------------------------------------------------------
%{
#include <stdio.h>
int i = 0, id = 0;
%}

%%
[#].*[<].*[>]\n     {}  // Ignore preprocessor directives like #include<stdio.h>
[ \t\n]+            {}  // Ignore spaces, tabs, and newlines
\/\/.*\n            {}  // Ignore single-line comments (// ...)
\/\*(.|\n)*?\*\/    {}  // Ignore multi-line comments (/* ... */)

auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|
goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|
typedef|union|unsigned|void|volatile|while  
{ printf("Token: %d <keyword, %s>\n", ++i, yytext); }

[+\-\*\/%<>]        { printf("Token: %d <operator, %s>\n", ++i, yytext); }
[();{}]             { printf("Token: %d <special char, %s>\n", ++i, yytext); }
[0-9]+              { printf("Token: %d <constant, %s>\n", ++i, yytext); }
[a-zA-Z_][a-zA-Z0-9_]*  
{ printf("Token: %d <ID %d, %s>\n", ++i, ++id, yytext); }

[^a-zA-Z0-9_]+      { printf("ERROR: INVALID TOKEN %s\n", yytext); }
%%

int yywrap() {
    return 1;
}

int main() {
    yyin = fopen("input.txt", "r");  // Open input file
    if (!yyin) {
        printf("Error opening file!\n");
        return 1;
    }
    yylex();  // Run lexical analyzer
    fclose(yyin);  // Close file
    return 0;
}

---------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int n, m = 0;
char a[10][10], f[10];

void first(char c);
void follow(char c);

void follow(char c) {
    if (a[0][0] == c)
        f[m++] = '$'; // Add end marker if it's the start symbol

    for (int i = 0; i < n; i++) {
        for (int j = 2; j < strlen(a[i]); j++) {
            if (a[i][j] == c) {
                if (a[i][j + 1] != '\0')
                    first(a[i][j + 1]);
                else if (c != a[i][0])
                    follow(a[i][0]);
            }
        }
    }
}

void first(char c) {
    if (!isupper(c)) {
        f[m++] = c;
        return;
    }
    
    for (int k = 0; k < n; k++) {
        if (a[k][0] == c) {
            if (a[k][2] == '$')
                follow(a[k][0]);
            else if (islower(a[k][2]))
                f[m++] = a[k][2];
            else
                first(a[k][2]);
        }
    }
}

int main() {
    int z;
    char c, ch;
    
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions (use $ for epsilon):\n");
    
    for (int i = 0; i < n; i++)
        scanf("%s%c", a[i], &ch);

    do {
        m = 0;
        printf("Enter the element whose FIRST & FOLLOW is to be found: ");
        scanf(" %c", &c);  // Space before %c to ignore previous newline
        
        first(c);
        printf("FIRST(%c) = { ", c);
        for (int i = 0; i < m; i++)
            printf("%c ", f[i]);
        printf("}\n");
        
        m = 0;
        follow(c);
        printf("FOLLOW(%c) = { ", c);
        for (int i = 0; i < m; i++)
            printf("%c ", f[i]);
        printf("}\n");
        
        printf("Do you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d%c", &z, &ch);
    } while (z == 1);

    return 0;
}
-------------------------------------------------------------------------------------
%{
#include <stdio.h>
int i = 0, id = 0;
%}

%%
[#].*[<].*[>]\n     {}  // Ignore preprocessor directives (e.g., #include <stdio.h>)
[\t\n]+            {}  // Ignore spaces, tabs, and newlines
\/\/.*\n           {}  // Ignore single-line comments (// ...)
\/\*(.|\n)*?\*\/   {}  // Ignore multi-line comments (/* ... */)

auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|
for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|
typedef|union|unsigned|void|volatile|while  
{ printf("Token: %d <keyword, %s>\n", ++i, yytext); }

[+\-\*\/%<>]        { printf("Token: %d <operator, %s>\n", ++i, yytext); }
[();{}]             { printf("Token: %d <special char, %s>\n", ++i, yytext); }
[0-9]+              { printf("Token: %d <constant, %s>\n", ++i, yytext); }
[a-zA-Z_][a-zA-Z0-9_]*  
{ printf("Token: %d <ID %d, %s>\n", ++i, ++id, yytext); }

[^a-zA-Z0-9_]+      { printf("ERROR: INVALID TOKEN %s\n", yytext); }
%%

int yywrap() {
    return 1;
}

int main() {
    yyin = fopen("input.txt", "r");  // Open input file
    if (!yyin) {
        printf("Error opening file!\n");
        return 1;
    }
    yylex();  // Run lexical analyzer
    fclose(yyin);  // Close file
    return 0;
}
-------------------------------------------------------------------------------------
Recursive Descent Parser
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void E();   // Expression
void Ep();  // Expression Prime (Handles +)
void T();   // Term
void Tp();  // Term Prime (Handles *)
void check();

int count = 0, flag = 0;
char expr[100];

int main() {
    printf("\nEnter an Algebraic Expression: ");
    scanf("%s", expr);
    
    E();  // Start parsing from the Expression

    if ((strlen(expr) == count) && (flag == 0))
        printf("\nThe expression %s is valid\n", expr);
    else
        printf("\nThe expression %s is invalid\n", expr);

    return 0;
}

// E → T Ep
void E() {
    T();
    Ep();
}

// Ep → + T Ep | ε
void Ep() {
    if (expr[count] == '+') {
        count++;
        T();
        Ep();
    }
}

// T → check Tp
void T() {
    check();
    Tp();
}

// Tp → * check Tp | ε
void Tp() {
    if (expr[count] == '*') {
        count++;
        check();
        Tp();
    }
}

// check → id | (E)
void check() {
    if (isalnum(expr[count])) {  // If alphanumeric (identifier or number)
        count++;
    } 
    else if (expr[count] == '(') {  // If opening bracket, process sub-expression
        count++;
        E();
        if (expr[count] == ')')
            count++;
        else
            flag = 1;  // Unmatched parentheses error
    } 
    else {
        flag = 1;  // Invalid token
    }
}






 Loop Unrolling

#include <stdio.h>

#define TOGETHER 8  // Number of iterations unrolled together

int main(void) {
    int i = 0, entries = 15, repeat, left;

    repeat = entries / TOGETHER;  // Calculate full unrolled iterations
    left = entries % TOGETHER;    // Remaining iterations

    // Unrolled loop processing 8 iterations at a time
    while (repeat--) {
        printf("process(%d)\n", i);
        printf("process(%d)\n", i+1);
        printf("process(%d)\n", i+2);
        printf("process(%d)\n", i+3);
        printf("process(%d)\n", i+4);
        printf("process(%d)\n", i+5);
        printf("process(%d)\n", i+6);
        printf("process(%d)\n", i+7);
        i += TOGETHER;
    }

    // Process remaining iterations
    switch (left) {
        case 7: printf("process(%d)\n", i+6);
        case 6: printf("process(%d)\n", i+5);
        case 5: printf("process(%d)\n", i+4);
        case 4: printf("process(%d)\n", i+3);
        case 3: printf("process(%d)\n", i+2);
        case 2: printf("process(%d)\n", i+1);
        case 1: printf("process(%d)\n", i);
        case 0: break;
    }

    return 0;
}






Constant Propagation in C


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void input();
void output();
void change(int p, char *res);
void constant_propagation();

struct expr {
    char op[2], op1[5], op2[5], res[5];
    int flag;
} arr[10];

int n;

int main() {
    input();
    constant_propagation();
    output();
    return 0;
}

void input() {
    int i;
    printf("\nEnter the number of expressions: ");
    scanf("%d", &n);
    printf("\nEnter the expressions (operator operand1 operand2 result):\n");
    for (i = 0; i < n; i++) {
        scanf("%s %s %s %s", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
        arr[i].flag = 0;  // Mark as not optimized yet
    }
}

void constant_propagation() {
    int i, op1, op2, res;
    char res1[5];

    for (i = 0; i < n; i++) {
        if ((isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0])) || strcmp(arr[i].op, "=") == 0) {
            op1 = atoi(arr[i].op1);
            op2 = atoi(arr[i].op2);

            switch (arr[i].op[0]) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
                case '=': res = op1; break;
                default: continue;
            }

            sprintf(res1, "%d", res);
            arr[i].flag = 1;  // Mark as optimized
            change(i, res1);
        }
    }
}

void output() {
    int i;
    printf("\nOptimized Code:\n");
    for (i = 0; i < n; i++) {
        if (!arr[i].flag) {
            printf("%s %s %s %s\n", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
        }
    }
}

void change(int p, char *res) {
    int i;
    for (i = p + 1; i < n; i++) {
        if (strcmp(arr[p].res, arr[i].op1) == 0)
            strcpy(arr[i].op1, res);
        if (strcmp(arr[p].res, arr[i].op2) == 0)
            strcpy(arr[i].op2, res);
    }
}


 
