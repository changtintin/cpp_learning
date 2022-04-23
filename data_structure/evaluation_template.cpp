#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template <class T,class T1>
class Stack{
    public:
        T item;
        T1 num;
    public:
        Stack();
        void push_ch(T itm);
        void push_int(T1 itm);
};

template <class T,class T1>
Stack<T,T1>::Stack(){
    item = 0;
    num = 0;
}

template <class T,class T1>
void Stack<T,T1>::push_ch(T itm){
    item = itm;
}

template <class T,class T1>
void Stack<T,T1>::push_int(T1 n){
    num = n;
}

template <class T>
T opr_value(T opr){
    switch (opr){
        case '(':
            return 4;
            break;
        case '*':case '/':
            return 1;
            break;
        case '+':case '-':
            return 2;
            break;
        default:
            return 3 ;
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
    else  // a < b
        return 3;
}

template<class T>
int num_optr(T item){    
    switch (item){
        case '0' ... '9':
            int result;
            result = item - 48;
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

bool number(int a){
    if(a < 100 && a > 0)
        return 1;
    else
        return 0;
} 

template<class T, class T1>
int calculate(T a, T b, T1 opr){
    switch(opr){
        case '+':
            return (a + b);
            break;
        case '-':
            return (a - b);
            break;
        case '*':
            return (a * b);
            break;
        case '/':
            return (a / b);
            break;
        default:
            return 0;
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

    Stack<char,int> infix_stk[leng];

    cout << "infix stack: ";
    for(int i = 0; i < leng; i++){
        infix_stk[i].item = tmp_ary[i];
        if(num_optr(tmp_ary[i]) == 1 && num_optr(tmp_ary[i+1]) == 1){
            infix_stk[i].num = ((tmp_ary[i] - 48) * 10) + (tmp_ary[i+1] -48);
            cout << infix_stk[i].num << " ";
            i++ ;
        }
        else if (num_optr(tmp_ary[i]) == 5 ){
            cout << endl << "Unvaliable expression: " << endl;
            exit(1);
        }
        else if(num_optr(tmp_ary[i]) == 1){
            infix_stk[i].num = tmp_ary[i] - 48;
            cout << infix_stk[i].num << " ";
        }
        else {
            infix_stk[i].push_ch(tmp_ary[i]);
            cout << infix_stk[i].item << " ";
        }
    }
    cout << endl;

    int p_index = 0;
    int opr_index = 0;
    int left_par = 0;
    int pr = 0;
    
    Stack<char,int> optr_stk[20];
    Stack<char,int> pfx_stk[leng];
    Stack<char,int> par_stk[20];

    for(int i = 0; i < leng; i++){  // i = i_ptr
        cout  << "i = " << i << endl;
        if(left_par == 1){ // item inside parentheses
            if(num_optr(infix_stk[i].item) == 4){ // item = ')'
                cout << "item = ')' " << endl;
                int j = pr - 1;
                while(j >= 0){ //都是下一項的index
                    if(par_stk[j].item == '('){
                        pr --;
                        break;
                    }
                    cout << "par_stk[" << j << "]:" << par_stk[j].item<< endl;
                    pfx_stk[p_index].push_ch(par_stk[j].item);
                    cout << "pfx_stk[" << p_index << "]:" << pfx_stk[p_index].item<< endl;
                    p_index ++;
                    pr --;
                    j--;
                }    
                left_par = 0;
            } 
            else{
                if(number(infix_stk[i].num) == 1 ){ // item = number
                    pfx_stk[p_index].push_int(infix_stk[i].num);
                    cout << "pfx_stk[" << p_index << "]:" << pfx_stk[p_index].num<< endl;
                    p_index ++;
                }
                else if(num_optr(infix_stk[i].item) == 2 ){ // item = operator
                    cout << "if item = operator + - * / " << endl;
                    if(pr > 0 && (compare(infix_stk[i].item, par_stk[pr - 1].item)) == 1){  // priority of optr_stk operator '+ - * /' is higher than infix_stk operator (push all)
                        cout << "priority of optr_stk operator is higher than infix_stk operator: " << endl;
                        int tmp = 0; // push 出幾個 opr
                        for(int j = pr - 1; j > -1; j--){
                            pfx_stk[p_index].push_ch(par_stk[j].item);
                            cout << "pfx_stk[" << p_index << "]:" << pfx_stk[p_index].item<< endl;
                            p_index ++;
                            tmp ++;
                        }
                        pr -= tmp;
                        par_stk[pr].push_ch(infix_stk[i].item);
                        cout << "par_stk[" << pr << "]:" << par_stk[pr].item<< endl;
                        pr ++;
                    }
                    else if(pr > 0 && (compare(infix_stk[i].item, par_stk[pr -1].item)) == 3){  // priority of optr_stk operator '+ - * /' is lower than infix_stk operator
                        par_stk[pr].push_ch(infix_stk[i].item);
                        cout << "priority of optr_stk operator is not higher than infix_stk operator" << endl;
                        cout << "par_stk[" << pr << "]:" << par_stk[pr].item<< endl;
                        pr ++;
                    }
                    else if( pr > 0 && compare(infix_stk[i].item, par_stk[pr - 1].item) == 2){  //priority are the same 
                        cout << "priority of optr_stk operator and infix_stk operator are the same" << endl;
                        pfx_stk[p_index].push_ch(par_stk[pr - 1].item);
                        cout << "pfx_stk[" << p_index << "]:" << pfx_stk[p_index].item<< endl;
                        pr = pr - 1;
                        par_stk[pr].push_ch(infix_stk[i].item);
                        p_index ++;
                        cout << "par_stk[" << pr << "]:" << par_stk[pr].item<< endl;
                        pr ++;
                    }
                    else{  //nothing to compare
                        par_stk[pr].push_ch(infix_stk[i].item);
                        cout << "nothing to compare or priority is the same" << endl;
                        cout << "par_stk[" << pr << "]:" << par_stk[pr].item<< endl;
                        pr ++;
                    }
                }
                else if(num_optr(infix_stk[i].item) == 4){ // item = ')'
                    pr = pr - 2;
                    cout << "item = ')' " << endl;
                    while(pr >= 0){ //都是下一項的index
                        cout << "par_stk[" << pr << "]:" << par_stk[pr].item<< endl;
                        pfx_stk[p_index].push_ch(par_stk[pr].item);
                        cout << "pfx_stk[" << p_index << "]:" << pfx_stk[p_index].item<< endl;
                        p_index ++;
                        pr --;
                    }
                    left_par = 0;
                    pr = 0;
                }    
            }
        }
        else{ // outside the parentheses
            if(number(infix_stk[i].num) == 1 ){   //if item = number
                pfx_stk[p_index].push_int(infix_stk[i].num);
                cout << "pfx_stk[" << p_index << "]:" << pfx_stk[p_index].num<< endl;
                p_index ++;
            } 
            else if(num_optr(infix_stk[i].item) == 2 ){ //if item = operator '+ - * /'
                cout << "if item = operator + - * / " << endl;
                if(opr_index > 0 && (compare(infix_stk[i].item, optr_stk[opr_index - 1].item)) == 1){  // priority of optr_stk operator '+ - * /' is higher than infix_stk operator (push all)
                    cout << "priority of optr_stk operator is higher than infix_stk operator: " << endl;
                    int tmp = 0; // push 出幾個 opr
                    for(int j = opr_index - 1; j > -1; j--){
                        pfx_stk[p_index].push_ch(optr_stk[j].item);
                        cout << "pfx_stk[" << p_index << "]:" << pfx_stk[p_index].item<< endl;
                        p_index ++;
                        tmp ++;
                    }
                    opr_index -= tmp;
                    optr_stk[opr_index].push_ch(infix_stk[i].item);
                    cout << "optr_stk[" << opr_index << "]:" << optr_stk[opr_index].item<< endl;
                    opr_index ++;
                }
                else if(opr_index > 0 && (compare(infix_stk[i].item, optr_stk[opr_index - 1].item)) == 3){  // priority of optr_stk operator '+ - * /' is lower than infix_stk operator
                    optr_stk[opr_index].push_ch(infix_stk[i].item);
                    cout << "priority of optr_stk operator is not higher than infix_stk operator" << endl;
                    cout << "optr_stk[" << opr_index << "]:" << optr_stk[opr_index].item<< endl;
                    opr_index ++;
                }
                else if( opr_index > 0 && compare(infix_stk[i].item, optr_stk[opr_index - 1].item) == 2){  //priority are the same 
                    if(optr_stk[opr_index - 1].item == '('){  //priority are the same  but not '('
                        optr_stk[opr_index].push_ch(infix_stk[i].item);
                        cout << "nothing to compare or priority is the same" << endl;
                        cout << "optr_stk[" << opr_index << "]:" << optr_stk[opr_index].item<< endl;
                        opr_index ++;
                    }
                    else{
                        cout << "priority of optr_stk operator and infix_stk operator are the same" << endl;
                        pfx_stk[p_index].push_ch(optr_stk[opr_index - 1].item);
                        cout << "pfx_stk[" << p_index << "]:" << pfx_stk[p_index].num<< endl;
                        cout << "optr_stk[" << opr_index -2  << "]:" << optr_stk[opr_index - 2 ].item<< endl;
                        opr_index = opr_index - 1;
                        p_index ++;
                        optr_stk[opr_index].push_ch(infix_stk[i].item);
                        opr_index ++;
                    }
                }
                else{  //nothing to compare
                    optr_stk[opr_index].push_ch(infix_stk[i].item);
                    cout << "nothing to compare or priority is the same" << endl;
                    cout << "optr_stk[" << opr_index << "]:" << optr_stk[opr_index].item<< endl;
                    opr_index ++;
                }
            }
            else if(num_optr(infix_stk[i].item) == 3){  // item = '(' no need to save it
                cout << "item = '(' " << endl;
                cout << "'(' is at" << opr_index << endl;
                left_par ++;
            }
        }

        if(i == leng - 1 && opr_index >= 0){
            cout << "last number of infix stack" << endl;
            for(int i = opr_index - 1; i >= 0; i--){
                cout << "optr_stk[" << i << "]:" << optr_stk[i].item<< endl;                
                pfx_stk[p_index].push_ch(optr_stk[i].item);
                p_index ++;
            }
        }
        cout << "_________________________________________________" << endl;
    }
    cout << "postfix stack" << endl ;
    for(int i = 0; i < p_index; i++){
        if(pfx_stk[i].item != 0)
            cout << pfx_stk[i].item << " ";
        else if(pfx_stk[i].num != 0)
            cout << pfx_stk[i].num << " ";
    }
    cout << endl; 

    Stack<char,int> ans[20];
    int a_idx = 0;
    for(int i = 0; i < p_index; i++){
        if(pfx_stk[i].item != 0)
            cout << "pfx: " << pfx_stk[i].item << endl;
        else if(pfx_stk[i].num != 0)
            cout << "pfx: " << pfx_stk[i].num << endl;

        if(pfx_stk[i].item != 0){  // item = opr 
            ans[a_idx].push_ch(pfx_stk[i].item);
            cout << "ans[" << a_idx << "]=" << ans[a_idx].item << endl;
            int tmp = calculate(ans[a_idx - 2].num, ans[a_idx - 1].num, ans[a_idx].item);
            a_idx -= 2;
            ans[a_idx].push_int(tmp);
            cout << "ans[" << a_idx << "]=" << ans[a_idx].num << endl;
            a_idx ++;
        }
        else if(pfx_stk[i].num != 0){ // item = num
            ans[a_idx].push_int(pfx_stk[i].num);
            cout << "ans[" << a_idx << "]=" << ans[a_idx].num << endl;
            a_idx ++;
        } 
        cout << " " << endl;
    }
    cout << "final answer: " << ans[0].num << endl;
}

