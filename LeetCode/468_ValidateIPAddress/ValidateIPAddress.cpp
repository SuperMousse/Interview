/*
给定一个字符串, 判断是否是有效的IPv4/v6地址, 返回"IPv4/IPv6/Neither"
IPv4: "x1.x2.x3.x4", 0 <= xi <= 255并且xi不能以0开头
      有效IPv4: "192.168.1.1", "192.168.1.0"
      无效IPv4: "192.168.01.1", "192.168.1.00", "192.168@1.1"
IPv6: "x1:x2:x3:x4:x5:x6:x7:x8", 1 <= xi.length <= 4, xi是16进制字符串, 包含小写字符 ('a' to 'f')或者大写字符 ('A' to 'F')
       并且xi不能以0开头
       有效IPv6: "2001:0db8:85a3:0000:0000:8a2e:0370:7334", "2001:db8:85a3:0:0:8A2E:0370:7334"
       无效IPv6: "2001:0db8:85a3::8A2E:037j:7334", "02001:0db8:85a3:0000:0000:8a2e:0370:7334"
 */

class Solution {
public:
    string validIPAddress(string IP) {
        return validIPv4(IP) ? "IPv4" : (validIPv6(IP) ? "IPv6" : "Neither");
    }
    bool validIPv4(string IP) {
        if (count(IP.begin(), IP.end(), '.') != 3) {
            return false;
        }
        vector<string> partStr = split(IP, '.');
        if (partStr.size() != 4) {
            return false;
        }
        for (string p : partStr) {
            // 子串是空的, 或者子串数目大于3, 或者子串有先导0
            if (p.empty() || p.size() > 3 || (p.size() > 1 && p[0] == '0')) {
                return false;
            }
            for (char c : p) {
                if (!isdigit(c)) {
                    return false;
                }
            }
            if (stoi(p) > 255) {
                return false;
            }
        }
        return true;
    }

    bool validIPv6(string IP) {
        if (count(IP.begin(), IP.end(), ':') != 7) {
            return false;
        }
        vector<string> partStr = split(IP, ':');
        if (partStr.size() != 8) {
            return false;
        }
        for (string p : partStr) {
            if (p.empty() || p.size() > 4) {
                return false;
            }
            for (char c : p) {
                // 如果某个字符不是数字, 那么这个字符需要是字母并且在A~F之间
                if (!isdigit(c) && (!isalpha(c) || toupper(c) > 'F')) {
                    return false;
                }
            }
        }
        return true;
    }
    vector<string> split(string s, char c) {
        vector<string> partStr;
        s += c;  // add an extra '0' for split
        while (!s.empty()) {
            int pos = s.find(c);
            if (pos == -1) {
                break;
            }
            else {
                partStr.push_back(s.substr(0, pos));
                s = s.substr(pos+1);
            }
        }
        return partStr;
    }
};
