class NumberContainers {

 unordered_map<int, int> in;         // Maps index -> number
 map<int, set<int>> ni;  // Maps number -> sorted set of indices


public:
    NumberContainers() {
        
    }
    

   void change(int index, int number) {

    if (in.count(index)) {      // 1,10      
        int oldNumber = in[index]; // oldnumber= 10
        ni[oldNumber].erase(index); // ni[10]=[2,3,5]
        if (ni[oldNumber].empty()) { // ni[10]=[] => remove 10
            ni.erase(oldNumber);
        }
    }


    in[index] = number;  // 2-> 10  1->10 3->10 5->10 // 1->20
    ni[number].insert(index); // 10->2,1,3,5 // 20->1
}

    
   int find(int number) {
    if (ni.count(number) && !ni[number].empty()) {  //to find the number in map
        return *ni[number].begin();
    }
    return -1;
}

};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */