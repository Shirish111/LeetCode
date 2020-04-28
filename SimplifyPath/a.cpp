// Simplify Path

// Given an absolute path for a file (Unix-style), simplify it. Or in other
// words, convert it to the canonical path.

// In a UNIX-style file system, a period . refers to the current directory.
// Furthermore, a double period .. moves the directory up a level. For more
// information, see: Absolute path vs relative path in Linux/Unix

// Note that the returned canonical path must always begin with a slash /, and
// there must be only a single slash / between two directory names. The last
// directory name (if it exists) must not end with a trailing /. Also, the
// canonical path must be the shortest string representing the absolute path.

// Example 1:

// Input: "/home/"
// Output: "/home"
// Explanation: Note that there is no trailing slash after the last directory
// name. Example 2:

// Input: "/../"
// Output: "/"
// Explanation: Going one level up from the root directory is a no-op, as the
// root level is the highest level you can go. Example 3:

// Input: "/home//foo/"
// Output: "/home/foo"
// Explanation: In the canonical path, multiple consecutive slashes are replaced
// by a single one. Example 4:

// Input: "/a/./b/../../c/"
// Output: "/c"
// Example 5:

// Input: "/a/../../b/../c//.//"
// Output: "/c"
// Example 6:

// Input: "/a//b////c/d//././/.."
// Output: "/a/b/c"

// Tags: string_manipulation

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string simplifyPath(string &path) {
    int n = path.length();
    vector<string> v;
    stringstream ss(path);
    string s;
    while (getline(ss, s, '/')) {
      if (s == "" || s == ".") {
        continue;
      } else if (s == "..") {
        if (!v.empty()) {
          v.pop_back();
        }
      } else {
        v.push_back(s);
      }
    }
    string ans;
    for (auto &i : v) {
      ans.append("/" + i);
    }
    return ans == "" ? "/" : ans;
  }
};
void solve() {
  vector<string> tc = {
      "/home/",
      "/../",
      "/home//foo/",
      "/a/./b/../../c/",
      "/a/../../b/../c//.//",
      "/a//b////c/d//././/..",
      "///////RgQ/DCkMtxRQArpnS///./../.././////lU/HkOPFethUYRJYwGjzHMe/"
      "rJteBUS///IsKEnIQJ/../../hGXBMGFqtOjs/rmSJGOpIwm/CLuUcSXPiwjsK///"
      "uAmXcWR/./tTrlKBgzBlNEwF/OOpDjmMoTvaedK///./YYjtE///cH/KOmxKcGmWg/"
      "qGCOBeWiABLFqcIOmz/////./maSVbpF/./CWFbBs/qMzsrWxv/.././vvUmYui///"
      "KCVaRfmLpZOzberV/VHOA/jphGcKrSF/kJkDRYKtpUosUWVbD///"
      "gclGacfgDoPGdiXxPWyc/MZIcVQZzab/DIGNdzzS/qBPDkxjWjEQlv/Njfre/./hxoM/"
      "mKKOwBVEWZwjagOuWi/UuLHfsWzeWi/../QuopYsUtqgnqAiXwE/qgokdsKKhosJhdBiSjA/"
      "..///ANrXgVcSNejG/FIfSyTz/.///UZlMfMXBUmuCDhiVQf///kqdiy/aRxweiOpLcczy/"
      "RPed/e/zbO/././M/NxCFeiNOJI/../qfBhtXbBFuRBPQrYpTx///"
      "tZhVBcmIMlnygAKHKdcT///rQllOCPKsfmXOdMT/./xqXODEft/dOqZbqJ/uCii///../../"
      "fDWbSnpMzPd///./PS/.././//HIQJuNdVfdlpqBKA/wo/.././OhBzBcujoxcpY/"
      "EHrtJtqIsnhIUkqh///./../WKPXCkCl/FEncfxOdTdcBPMUAS/OYcSyadfthTntUAsjUm/"
      "././iTURgskcGXkmDKWLcis/KvNnwUvQcCBJ/UCNcxJzeOdaX/././..///tX///"
      "DfxuGi/"};
  Solution s;
  for (auto &i : tc) {
    cout << s.simplifyPath(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
