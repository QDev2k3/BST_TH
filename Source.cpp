#include "Header.h"

int main() {
    int x,y,z,t;
    Node *tree = NULL;
    readData(tree);
    ifstream input;
    ofstream output;
    input.open("input.txt");
    input >> x >> y >> z >> t;


    
    output.open("output.txt", ios_base::trunc);


        // In cây sao cho nhận được một mảng giảm dần 
    printTree(tree,output);
    output << endl;


        // Số nguyên chứa số node thoả điều kiện
    int count = countNode(tree,x,y);
    output << count << endl;




        // In phần tử trái nhất của t
    Node *t_node = searchNode(tree,t);
    Node *t_left = searchLeft(t_node);
    output << t_left->data << endl;  



        // Số nguyên tố thoả yêu cầu 
    int prime[30] = {0};
    findPrime(tree,prime);
    for (int i=0; i<30; i++) {
        if (prime[i] != 0){
            output << i << endl;
            break;
        }
    }

        
        // In 1 hoặc 0. (tìm thấy hoặc không thấy).
    bool found = isFound(tree,z);
    output << found;


    cout << "(!) OUTPUT.TXT HAS BEEN UPDATED, PLEASE CHECK AGAIN (!)" << endl;
    system("pause");
    return 0;
}