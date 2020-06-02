vector<string> fizzBuzz(int n) {
    if(n < 1) {
        return vector<string>();
    }
    vector<string> res;
    for(int i = 1; i <= n; ++i) {
        string tmp = "";
        if(i % 3 == 0) {
            tmp += "Fizz";
        }
        if (i % 5 == 0) {
            tmp += "Buzz";
        }
        if ((i % 3 != 0) && (i % 5 != 0)){
            tmp += to_string(i);
        }
        res.push_back(tmp);
    }

    return res;
}
