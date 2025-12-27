using ll = long long;
using pii = pair<ll, int>;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
    // Min heap to track available rooms (sorted by room number)
        priority_queue<int, vector<int>, greater<int>> availableRooms;
      
        // Min heap to track busy rooms (sorted by end time, then room number)
        // Each pair contains: (end_time, room_number)
        priority_queue<pii, vector<pii>, greater<pii>> occupiedRooms;
      
        // Initialize all rooms as available
        for (int i = 0; i < n; ++i) {
            availableRooms.push(i);
        }
      
        // Counter for number of meetings held in each room
        vector<int> meetingCount(n);
      
        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());
      
        // Process each meeting
        for (auto& meeting : meetings) {
            int startTime = meeting[0];
            int endTime = meeting[1];
          
            // Free up rooms that have finished before current meeting starts
            while (!occupiedRooms.empty() && occupiedRooms.top().first <= startTime) {
                availableRooms.push(occupiedRooms.top().second);
                occupiedRooms.pop();
            }
          
            int assignedRoom = 0;
          
            // Case 1: There's an available room
            if (!availableRooms.empty()) {
                // Assign the lowest numbered available room
                assignedRoom = availableRooms.top();
                availableRooms.pop();
                occupiedRooms.push({endTime, assignedRoom});
            }
            // Case 2: All rooms are occupied, need to wait
            else {
                // Get the room that will be free earliest
                auto earliestFreeRoom = occupiedRooms.top();
                occupiedRooms.pop();
              
                assignedRoom = earliestFreeRoom.second;
                ll delayedEndTime = earliestFreeRoom.first + (endTime - startTime);
                occupiedRooms.push({delayedEndTime, assignedRoom});
            }
          
            // Increment meeting count for the assigned room
            ++meetingCount[assignedRoom];
        }
      
        // Find the room with most meetings (lowest numbered room in case of tie)
        int mostUsedRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (meetingCount[mostUsedRoom] < meetingCount[i]) {
                mostUsedRoom = i;
            }
        }
      
        return mostUsedRoom;
    }
};