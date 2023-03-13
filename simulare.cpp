#include <bits/stdc++.h>
using namespace std;

ifstream fin("sir.in");
ofstream fout("sir.out");

void adunare(int *v, int &x, int f) {
    x++;
    v[x] = f;
}

int suma(int l, int r, const int *v) {
  int sum = 0;
  for (int i = l; i <= r; i++)
    sum += v[i];
  return sum;
}

int elem_nenule(const int *v, int x) {
  int counter = 0;
  for (int i = 0; i < x; i++) {
    if (v[i] != 0)
      counter++;
  }
  return counter;
}

int el_max(const int *v, int n) {
  int max = 1;
  for (int i = 0; i < n; i++) {
    if (v[i] > max) {
      max = v[i];
    }
  }
  return max;
}

int main() {
  int n, q, r, l;
  fin >> n >> q;
  int x = n;
  int v[x];

  for (int i = 0; i < n; i++)
    fin >> v[i];
  for (int i = 1; i <= q; i++) {
    fin >> l >> r;
    int counter = 0;
    int k, max;
    while (true) {
      k = elem_nenule(v, n);
      max = el_max(v, n);
      if (max > r) {
        fout << suma(l, r, v) << "\n";
        break;
      } else if (k % 2 == 0)
        adunare(v, n, 0);
      else if (k % 2 == 1)
        adunare(v, n, max + 1);
      else
        cout << "OPAA!\n";
      counter++;
      cout << counter << "\n";
    }
  }
  fin.close();
  fout.close();
  return 0;
}
