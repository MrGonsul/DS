#include <iostream>
#include <Stack>
#include <String>

using namespace std;

// Method (As Check)

bool IsPair (char open , char close){

     if(open == '(' && close == ')')
           return true;
     else
        if (open == '[' && close == ']')
            return true;
     else
     if (open == '{' && close == '}')
        return true;
     else
        return false;

}

bool IsBalanced (string exp) { // exp Stands For Exponaltion Like -> [] {} ()

stack <char> s;
for (int i =0; i < exp.length(); i++ ){

    if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        s.push(exp[i]);
    else
        if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (s.empty() || !IsPair(s.top(),exp[i]))
                return false;
             else
               s.pop();

        }
}

return s.empty();
}

int main()
{
    string E;
    cout << "Enter An Expression : ";
    cin >> E;
    if(IsBalanced(E))
        cout << "Balanced" <<endl;
    else
        cout << "Not Balanced" <<endl;
    return 0;
}
