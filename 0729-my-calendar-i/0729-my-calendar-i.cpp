class MyCalendar {
public:

    set<int> starts;
    set<int> ends;
    MyCalendar() {
        
    }

    void print() {
        cout << "starts:[ ";
        for(auto& v:starts) {
            cout<<v<< " ";
        }
        cout<< "]\nends:[ ";
        for(auto& v:ends) {
            cout<<v<< " ";
        }
        cout<< "]\n";
    }
    
    bool book(int start, int end) {
        // print();
        // cout<<"add [" <<start<<","<<end<<"] ";
        if (starts.find(start) != starts.end()) {
            // cout<<"false\n";
            return false;
        }
        if (starts.size() == 0 || start >= *ends.rbegin() || end <= *starts.begin()) {
            starts.insert(start);
            ends.insert(end);
            // cout<<"true\n";
            return true;
        }
        auto pos1 = ends.upper_bound(start);
        auto pos2 = starts.lower_bound(end);

        int index1 = distance(ends.begin(), pos1);
        int index2 = distance(starts.begin(), pos2);
        // cout<<"index1="<<index1<<",index2="<<index2<<"\n";
        if (index1 == index2){
            starts.insert(start);
            ends.insert(end);
            // cout<<"true\n";
            return true;
        }
        // cout<<"false\n";
        return false;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
