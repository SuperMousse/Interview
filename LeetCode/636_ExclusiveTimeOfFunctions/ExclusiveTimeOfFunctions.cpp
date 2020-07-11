// ["0:start:0","1:start:2","1:end:5","0:end:6"]

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> times(n, 0);
        stack<Log> stackLog;
        for(string log: logs) {
            // extract from log, log = "id:start/end:timestamp"
            int firstPos = log.find(':');
            string id = log.substr(0, firstPos);
            log = log.substr(firstPos + 1);
            int secondPos = log.find(':');
            string status = log.substr(0, secondPos);
            string timestamp = log.substr(secondPos + 1);
            // create log
            Log item(stoi(id), status, stoi(timestamp));
            if(item.status == "start") {
                stackLog.push(item);
            }
            else {
                //  assert(stackLog.top().id == item.id);
                int timeAdded = item.timestamp - stackLog.top().timestamp + 1;
                times[item.id] += timeAdded;
                stackLog.pop();

                if(!stackLog.empty()) {
                    // assert(stackLog.top().status == "start");
                    times[stackLog.top().id] -= timeAdded;
                }
            }
        }

        return times;
    }
private:
    struct Log {
        int id;
        string status;
        int timestamp;
        Log(int i, string& s, int t) : id(i), status(s), timestamp(t) {}
    };
};
