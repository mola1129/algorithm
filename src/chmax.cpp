/*
 * 最大値に更新する
 * @param a 最大値 (更新対象)
 * @param b 比較対象
 */
template <class T>
void chmax(T &a, const T b) {
  if (a < b) {
    a = b;
  }
}