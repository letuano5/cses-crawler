#include <bits/stdc++.h>

using namespace std;


const int N = 2e5 + 5;
const int S = 450;

struct Range {
  int l, r;
  int64_t sum;
  bool is_reversed;
  Range(int l = 0, int r = 0, int64_t sum = 0, bool is_reversed = 0) : l(l), r(r), sum(sum), is_reversed(is_reversed) {}
};

int n, q;
int a[N];
int new_a[N];
int64_t s[N];
Range segments[N];
int cnt_ranges;

// xây dựng lại các block trong a
void rebuild() {
  int cur = 0;
  for (int i = 1; i <= cnt_ranges; i++) {
    auto [l, r, sum, is_rev] = segments[i];
    if (is_rev) {
      for (int j = r; j >= l; j--) {
        new_a[++cur] = a[j];
      }
    } else {
      for (int j = l; j <= r; j++) {
        new_a[++cur] = a[j];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    a[i] = new_a[i];
    s[i] = s[i - 1] + a[i];
  }
  cnt_ranges = 0;
  for (int i = 1; i <= n; i += S) {
    segments[++cnt_ranges] = Range(i, min(n, i + S - 1), s[min(i + S - 1, n)] - s[i - 1], 0);
  }
}

void insert_seg(int pos, Range rng) {
  for (int i = cnt_ranges; i >= pos; i--) {
    segments[i + 1] = segments[i];
  }
  segments[pos] = rng;
  cnt_ranges++;
}

// tách block chứa `pos` thành 2 phần: từ đầu block chứa `pos` -> `pos` - 1, và từ `pos` -> cuối block chứa `pos`
// và trả về chỉ số của block chứa `pos`
int split(int pos) {
  int cur_low = -1, cur_high = 0;
  for (int i = 1; i <= cnt_ranges; i++) {
    auto [l, r, sum, is_rev] = segments[i];
    int len = r - l + 1;
    int next_low = cur_high + 1;
    int next_high = next_low + len - 1;
    cur_low = next_low;
    cur_high = next_high;
    // đang ở block bên trái `pos`
    if (next_high < pos) continue;
    if (next_low == pos) {
      return i;
    }
    Range range_left, range_right;
    int left_len = pos - next_low, right_len = next_high - pos + 1;
    if (!is_rev) {
      range_left = Range(l, l + left_len - 1, s[l + left_len - 1] - s[l - 1], 0);
      range_right = Range(l + left_len, r, s[r] - s[l + left_len - 1], 0);
    } else {
      range_left = Range(r - left_len + 1, r, s[r] - s[r - left_len], 1);
      range_right = Range(l, r - left_len, s[r - left_len] - s[l - 1], 1);
    }
    segments[i] = range_left;
    insert_seg(i + 1, range_right);
    return i + 1;
  }
  return cnt_ranges + 1;
}

void do_reverse(int l, int r) {
  // xuất phát từ điểm l
  int block_l = split(l);
  // kết thúc từ điểm r -> phải xoá điểm r+1
  int block_r = split(r + 1);
  for (int i = block_l; i < block_r; i++) {
    segments[i].is_reversed ^= 1;
  }
  reverse(segments + block_l, segments + block_r);
}

int64_t get_sum(int l, int r) {
  int block_l = split(l);
  int block_r = split(r + 1);
  int64_t ans = 0;
  for (int i = block_l; i < block_r; i++) {
    ans += segments[i].sum;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    new_a[i] = a[i];
  }
  rebuild();
  for (int i = 1; i <= q; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      do_reverse(l, r);
    } else {
      cout << get_sum(l, r) << "\n";
    }
    // mỗi truy vấn tạo ra tối đa hai đoạn mới
    // khi số đoạn thêm vào vượt quá sqrt(q), khởi tạo lại để đảm bảo số đoạn cần xét trong mỗi query không vượt quá 2 * sqrt(n)
    // số lần khởi tạo lại là q / sqrt(q) = sqrt(q), mỗi lần khởi tạo mất O(n) -> n * sqrt(q)
    if (i % S == 0) {
      rebuild();
    }
  }
  return 0;
}