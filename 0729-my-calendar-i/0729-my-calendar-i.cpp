class MyCalendar {
public:
    set<pair<int, int>> bookings; // Store pairs of (start, end) times

    MyCalendar() {
    }

    bool book(int start, int end) {
        // Check if the new booking overlaps with existing bookings
        for (const auto& booking : bookings) {
            // If the new booking overlaps with an existing booking, return false
            if (start < booking.second && end > booking.first) {
                return false; // Overlapping condition
            }
        }
        
        // If no overlap, insert the new booking
        bookings.insert({start, end});
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
