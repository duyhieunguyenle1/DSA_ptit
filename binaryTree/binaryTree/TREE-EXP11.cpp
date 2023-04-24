et* constructTree(char postfix[]) { 
    stack<et *> st; //tao stack voi con tro node
    et *t, *t1, *t2;   
    // duyet tren bieu thuc hau to
    for (int i=0; i<strlen(postfix); i++) { 
        // neu la toan hang dua vao stach
        if (!isOperator(postfix[i])) { 
            t = new et(postfix[i]); 
            st.push(t); 
        } 
        else // neu la phep toan 
        { 
            t = new et(postfix[i]); //tao node t  
            // lay hai node tiep theo
            t1 = st.top(); st.pop();                     
            t2 = st.top(); st.pop();   
            //  tao thanh hai node con cua t 
            t->right = t1; 
            t->left = t2;   
            // dua bieu thuc con nay vao stack 
            st.push(t); 
        } 
    }   
    //  phan tu duy nhat con lai la goc cay bieu thuc
    t = st.top(); 
    st.pop();   
    return t; 
}

