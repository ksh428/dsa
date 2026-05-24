//check whether a string is rotation of other string or not
bool rotations(string a,string b){
    if(a.size()!=b.size()) return false;
    string t=a+a;
    if(t.find(b)!=string::npos) return true;
    return false;
}

//check whether atring a is present in b as substring : b.inf(a)!=string::npos    ///LEARN REMEMBER
