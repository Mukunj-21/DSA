// Problem : https://www.naukri.com/code360/problems/sorting-the-stack-recursively_1868989?leftPanelTabValue=PROBLEM

// recursive approach lagani hai ki isme humne pehle pura stack khali krna hai aur then push at right place with the help of helper
// helper me agar value sahi jagah h ya fir stack khali h to push krdo nahi to usme bhi tab tk pop krte jao jab tk sahi jagah ni aajati 
// then push the top element back to stack

void helper(stack<int>&s , int element){
    if(s.empty() || s.top()<=element){
        s.push(element);
        return;
    }
    int top = s.top();
    s.pop();
    helper(s ,element);
    s.push(top);
}
stack<int> sortStack(stack<int> &s)
{
	if(s.empty())
        return s;
    int top = s.top();
    s.pop();
    sortStack(s);
    helper(s , top);
    return s;
}