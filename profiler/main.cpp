#include <print.h>
#include <scope_profiler.h>

int main() {
    int sum = 0;
    std::vector<int> arr;
    arr.resize(1000000);
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = i % 100;
    }

    // 以下为性能测试
    {
        sum = 0;
        ScopeProfiler _("下标遍历");
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }
        print(sum);
    }

    {
        sum = 0;
        ScopeProfiler _("range遍历");
        for (auto const &i: arr) {
            sum += i;
        }
        print(sum);
    }

    {
        sum = 0;
        ScopeProfiler _("迭代器遍历");
        for (auto it = arr.begin(); it != arr.end(); it++) {
            sum += *it;
        }
        print(sum);
    }

    {
        sum = 0;
        ScopeProfiler _("指针遍历");
        int *p = arr.data();
        int *end = p + arr.size();
        while (p != end) {
            sum += *p;
            p++;
        }
        print(sum);
    }
    printScopeProfiler();
    return 0;
}