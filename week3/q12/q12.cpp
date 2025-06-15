//function to find all the possible combination that number could represent on keypadphone
vector<string> Solution::letterCombinations(string A) {
    // an empty vector to keep adding combinations
    vector <string> v = {""};
    // m stores the values for each digit
    map <int, string> m{
        {0, "0"},
        {1, "1"},
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };
    // iterate over A (each digit)
    for(auto& c : A){
        // convert to integer and store in i
        int i = c - '0';
        // a temp vector to store the vectors after adding the characters for the current digit
        vector <string> temp;
        // iterate over the vector v
        for(auto& v_i : v){
            // iterate over the string for the current digit
            for(auto& a : m[i]){
                // add the current character to the current vector
                temp.push_back(v_i + a);
            }
        }
        // replace v with temp, which has included the characters for the current digit
        v = temp;
    }
    // return the finall vector of strings
    return v;
}