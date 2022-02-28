#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'flippingMatrix' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */
void swap_r(vector<int> &arr)
{
    cout << "swap r" << endl;

    int n = arr.size() / 2;
    for (int c = 0; c < n; c++)
    {
        int temp = arr[c];
        arr[c] = arr[arr.size() - c - 1];
        arr[arr.size() - c - 1] = temp;
    }
}

void swap_c(vector<vector<int>> &matrix, int c)
{
    cout << "swap c " << c << endl;
    int n = matrix.size() / 2;
    for (int r = 0; r < n; r++)
    {
        int temp = matrix[r][c];
        matrix[r][c] = matrix[matrix.size() - r - 1][c];
        matrix[matrix.size() - r - 1][c] = temp;
    }
}
int flippingMatrix(vector<vector<int>> matrix)
{
    int n = matrix.size() / 2;
    int size = matrix.size();
    int result = 0;

    // for (int c = 0; c < size; c++)
    // {
    //     int sum1 = 0, sum2 = 0;
    //     for (int r = 0; r < n; r++)
    //     {
    //         sum1 += matrix[r][c];
    //         sum2 += matrix[size - r - 1][c];
    //     }
    //     if (sum2 > sum1)
    //         swap_c(matrix, c);
    // }

    // for (int r = 0; r < size; r++)
    // {
    //     for (int c = 0; c < size; c++)
    //     {
    //         // result += matrix[r][c];

    //         cout << matrix[r][c] << " ";
    //     }

    //     cout << endl;
    // }

    // for (int r = 0; r < size; r++)
    // {
    //     int sum1 = 0, sum2 = 0;
    //     for (int c = 0; c < n; c++)
    //     {
    //         sum1 += matrix[r][c];
    //         sum2 += matrix[r][size - c - 1];
    //     }
    //     if (sum2 > sum1)
    //         swap_r(matrix[r]);
    // }

    // for (int r = 0; r < size; r++)
    // {
    //     for (int c = 0; c < size; c++)
    //     {
    //         // result += matrix[r][c];

    //         cout << matrix[r][c] << " ";
    //     }

    //     cout << endl;
    // }
    int sum = 0;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            int max_r = max(matrix[r][c], matrix[r][size - c -1]);
            int max_c = max(matrix[size - r - 1][c], matrix[size - r - 1][size - c - 1]);
            result+= max(max_r, max_c);
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> matrix(2 * n);

        for (int i = 0; i < 2 * n; i++)
        {
            matrix[i].resize(2 * n);

            string matrix_row_temp_temp;
            getline(cin, matrix_row_temp_temp);

            vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

            for (int j = 0; j < 2 * n; j++)
            {
                int matrix_row_item = stoi(matrix_row_temp[j]);

                matrix[i][j] = matrix_row_item;
            }
        }

        int result = flippingMatrix(matrix);

        cout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
