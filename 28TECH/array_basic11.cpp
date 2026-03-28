#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

istream &operator>>(istream &inp_stream, __int128 &val) {
  string str;
  inp_stream >> str;

  val = 0;

  __int128 sign = 1;
  int start_idx = 0;
  if (!str.empty() && str[0] == '-') {
    sign = -1;
    start_idx = 1;
  }

  int loop_limit = static_cast<int>(str.length());
  for (int i = start_idx; i < loop_limit; ++i) {
    if (str[i] < '0' || str[i] > '9') {
      val = 0;
      return inp_stream;
    }
    val = val * 10 + (str[i] - '0');
  }

  val *= sign;
  return inp_stream;
}

ostream &operator<<(ostream &out_stream, const __int128 &val) {
  if (val == 0) {
    return out_stream << "0";
  }

  __int128 tmp = val;
  bool is_negative = false;
  if (tmp < 0) {
    is_negative = true;
    tmp = -tmp;
  }

  string str = "";
  while (tmp > 0) {
    str += (tmp % 10) + '0';
    tmp /= 10;
  }

  if (is_negative) {
    str += '-';
  }

  reverse(str.begin(), str.end());
  return out_stream << str;
}

bool IsFibonacci(__int128 val) {
  if (val < 0)
    return false;
  if (val == 0 || val == 1)
    return true;

  __int128 first_fi = 0;
  __int128 second_fi = 1;
  __int128 current_fi;
  while (second_fi < val) {
    current_fi = first_fi + second_fi;
    first_fi = second_fi;
    second_fi = current_fi;
  }

  return second_fi == val;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int num;
  cin >> num;

  vector<__int128> vec(num);
  for (__int128 &ele : vec) {
    cin >> ele;
  }

  int res_cnt = 0;
  for (__int128 ele : vec) {
    if (IsFibonacci(ele)) {
      cout << ele << ' ';
      res_cnt++;
    }
  }
  if (res_cnt == 0) {
    cout << "NONE";
  }
}
