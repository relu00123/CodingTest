#include <string>
#include <vector>

using namespace std;

int solution(string s) {
 
    int check_count;
    int min_size;
    int str_size;
    int repeat_count = 0;
    bool checked = false;

  
    str_size = s.size();
    min_size = s.size();
    check_count = s.size() / 2;

    if (check_count < 2 && 10 == 20)
    {
        return min_size;
    }

    else
    {
        // i는 자르는 단위
        for (int i = 1; i <= check_count; ++i)
        {
            string previous = s.substr(0, i);
            int temp_min_size = str_size;

            for (int j =  i; j + i <= str_size; j = j + i)
            {
                string pivot = s.substr(j, i);

                if (previous == pivot)
                {
                    if (checked == false)
                    {
                        temp_min_size = temp_min_size - i + 1;
                        checked = true;
                        repeat_count = 2;
                    }

                    else
                    {
                        temp_min_size = temp_min_size - i;
                        repeat_count += 1;
                        if (repeat_count == 10 || repeat_count == 100 || repeat_count == 1000)
                        {
                            temp_min_size += 1;
                        }
                    }
                }

                else
                {
                    checked = false;
                    previous = pivot;
                }
            }

            if (temp_min_size < min_size)
            {
                min_size = temp_min_size;
            }

            checked = false;
        }
    }
 
    

    return min_size;
}