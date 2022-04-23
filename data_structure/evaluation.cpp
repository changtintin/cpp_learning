#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Stack{
    public:
        char item;
    public:
        void push(char itm);
};

void Stack::push(char itm){
    item = itm;
}

int opr_value(char opr){
    switch (opr){
        case '*':case '/':
            return 1;
            break;
        case '+':case '-':
            return 2;
            break;
        default:
            return 3;
            break;
    }
}

int compare(char opr_1, char opr_2){
    int a = opr_value(opr_1);
    int b = opr_value(opr_2);
    if(a == 3 || b == 3){
        return 2;
    }
    if(a > b)
        return 1;
    else if(a == b)
        return 2;
    else 
        return 3;
    
}

int num_optr(char item){
    switch (item){
        case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':case '0':
            return 1;
            break;
        case '+':case '-':case '*':case '/':
            return 2;
            break;
        case '(': 
            return 3;
            break;
        case ')':
            return 4;
            break;
        default:
            return 5;
            break;
    }
}

int main(){
    string expsn;
    cout << "Enter the expression" << endl;
    cin >> expsn;
    int expsn_len = expsn.length();
    int leng = expsn_len;
    char tmp_ary[leng];
    strcpy(tmp_ary, expsn.c_str() );
    Stack infix_stk[leng];
    cout << "str stack: ";
    for(int i = 0; i < expsn_len + 1; i++){
        infix_stk[i].item = tmp_ary[i];
        cout << infix_stk[i].item << " ";
    }
    cout << endl;

    cout << "infix stack: ";
    for(int i = 0; i < leng; i++){
        cout << infix_stk[i].item << " ";
    }
    cout << endl;

    int p_index = 0;
    int opr_index = 0;

    Stack optr_stk[20];
    Stack pfx_stk[leng];

    for(int i = 0; i < leng; i++){  // i = i_ptr
        cout  << "i = " << i << endl;
        if(num_optr(infix_stk[i].item) == 1){   //if item = number
            pfx_stk[p_index].push(infix_stk[i].item);
            cout << "pfx_stk[" << p_index << "]:" << pfx_stk[p_index].item<< endl;
            p_index ++;
        } 
        else if(num_optr(infix_stk[i].item) == 2 ){ //if item = operator '+ - * /'
            cout << "if item = operator + - * / " << endl;
            if(opr_index > 0 && (compare(infix_stk[i].item, optr_stk[opr_index - 1].item)) == 1){  // priority of optr_stk operator '+ - * /' is higher than infix_stk operator
                pfx_stk[p_index].push(optr_stk[opr_index - 1].item);
                opr_index = opr_index - 1;
                cout << "priority of optr_stk operator is higher than infix_stk operator: " << endl;
                p_index ++;
                optr_stk[opr_index].item = infix_stk[i].item;
                cout << "optr_stk[" << opr_index << "]:" << optr_stk[opr_index].item<< endl;
                opr_index ++;
            }
            else if(opr_index > 0 && (compare(optr_stk[opr_index].item, optr_stk[opr_index - 1].item)) == 0){  // priority of optr_stk operator '+ - * /' is lower than infix_stk operator
                optr_stk[opr_index].item = infix_stk[i].item;
                cout << "priority of optr_stk operator is not higher than infix_stk operator" << endl;
                cout << "optr_stk[" << opr_index << "]:" << optr_stk[opr_index].item<< endl;
                opr_index ++;
            }
            else if( opr_index > 0 && compare(infix_stk[i].item, optr_stk[opr_index - 1].item) == 2){  //priority are the same 
                if(optr_stk[opr_index - 1].item == '('){ //priority are the same  but not '('
                    optr_stk[opr_index].item = infix_stk[i].item;
                    cout << "nothing to compare or priority is the same" << endl;
                    cout << "optr_stk[" << opr_index << "]:" << optr_stk[opr_index].item<< endl;
                    opr_index ++;
                }
                else{
                    cout << "priority of optr_stk operator and infix_stk operator are the same" << endl;
                    pfx_stk[p_index].push(optr_stk[opr_index - 1].item);
                    cout << "optr_stk[" << opr_index << "]:" << optr_stk[opr_index].item<< endl;
                    opr_index = opr_index - 1;
                    p_index ++;
                    optr_stk[opr_index].item = infix_stk[i].item;
                    opr_index ++;
                }
                
            }
            else{  //nothing to compare
                optr_stk[opr_index].item = infix_stk[i].item;
                cout << "nothing to compare or priority is the same" << endl;
                cout << "optr_stk[" << opr_index << "]:" << optr_stk[opr_index].item<< endl;
                opr_index ++;
            }
        }
        else if(num_optr(infix_stk[i].item) == 3){  // item = '('
            optr_stk[opr_index].item = infix_stk[i].item;
            cout << "item = '(' " << endl;
            cout << "optr_stk[" << opr_index << "]:" << optr_stk[opr_index].item<< endl;
            opr_index ++;
        }
        else if(num_optr(infix_stk[i].item) == 4){ // item = ')'
            cout << "item = ')' " << endl;
            int ptr = opr_index - 1;
            while(ptr >= 0){
                if(optr_stk[ptr].item == '('){
                    opr_index --;
                    break;
                }
                cout << "optr_stk[" << ptr << "]:" << optr_stk[ptr].item<< endl;
                pfx_stk[p_index].push(optr_stk[ptr].item);
                cout << "pfx_stk[" << p_index << "]:" << pfx_stk[p_index].item<< endl;
                p_index ++;
                ptr --;
                opr_index --;
            }
        }
        if(i == leng - 1 && opr_index >= 0){
            cout << "last number of infix stack" << endl;
            for(int i = opr_index - 1; i >= 0; i--){
                cout << "optr_stk[" << i << "]:" << optr_stk[i].item<< endl;                
                pfx_stk[p_index].push(optr_stk[i].item);
                p_index ++;
            }
        }
        cout << "_________________________________________________" << endl;
    }
    cout << "postfix stack" << endl ;
    for(int i = 0; i < p_index; i++){
        cout << pfx_stk[i].item << " ";
    }
    cout << endl;

    
}