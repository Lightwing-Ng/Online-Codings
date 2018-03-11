#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
using std::sort;
using namespace std;

typedef struct {
    double pos;
    double price;
} gas_station;

gas_station station[501];

bool cmp(gas_station a, gas_station b) {
    if (a.pos < b.pos)
        return true;
    else
        return false;
}

int main() {
    double C_max, D, Davg;
    int N;
    while (cin >> C_max >> D >> Davg >> N) {
        if (D == 0) {
            printf("0.00\n");
            continue;
        }
        memset(station, 0, sizeof(station));
        for (int i = 0; i < N; i++)
            cin >> station[i].price >> station[i].pos;
        sort(station, station + N, cmp);
        if (station[0].pos != 0) {
            cout << "The maximum travel distance = 0.00" << endl;
            continue;
        }
        double max_run_dis = C_max * Davg;

        int flag[3] = { 0 }; // flag[0]是否到达目的地；flag[1]，max_run_dis范围内是否有加油站；flag[2]max_run_dis范围内是否有油价更便宜的加油站
        int cur_index = 0;
        double remain_gas = 0;
        double total_cost = 0;
        while (flag[0] == 0) {
            flag[1] = 0, flag[2] = 0;
            double cheapest_price = 123123123;
            int cheapest_index = 0;
            for (int i = cur_index + 1; i < N; i++) {
                if ((station[i].pos - station[cur_index].pos) <= max_run_dis) {
                    flag[1] = 1;
                    if (station[i].price < station[cur_index].price) {
                        flag[2] = 1;
                        total_cost += ((station[i].pos - station[cur_index].pos) / Davg - remain_gas) * station[cur_index].price;
                        remain_gas = 0;
                        cur_index = i;
                        break;
                    }
                    if (station[i].price < cheapest_price) {
                        cheapest_price = station[i].price;
                        cheapest_index = i;
                    }
                } else {
                    break;
                }
            }
            if (flag[2] == 0 && (D - station[cur_index].pos) <= max_run_dis) {
                total_cost += ((D - station[cur_index].pos) / Davg - remain_gas) * station[cur_index].price;
                printf("%.2lf\n", total_cost);
                flag[0] = 1;
            }
            if (flag[1] == 1 && flag[2] == 0) {
                total_cost += (C_max - remain_gas) * station[cur_index].price;
                remain_gas = C_max - (station[cheapest_index].pos - station[cur_index].pos) / Davg;
                cur_index = cheapest_index;
            } else if (flag[1] == 0 && flag[0] == 0) {
                printf("The maximum travel distance = %.2lf\n", station[cur_index].pos + max_run_dis);
                flag[0] = 1;
            }
        }
    }
    return 0;
}

/*
//解法一
#include <algorithm>
#include <iostream>
using namespace std;

struct Station {
    double p;
    double d;
    bool operator<(const Station &a) const {
        return d < a.d;
    }
} buf[501];

struct Tank {
    double left;
    double cost;
    double d;
} tank;

int main() {
    double C_max, D, Davg;
    int N;
    while (cin >> C_max >> D >> Davg >> N) {
        for (int i = 0; i < N; ++i)
            cin >> buf[i].p >> buf[i].d;
        buf[N].d = D;
        buf[N].p = 0;
        double farest = C_max * Davg;
        sort(buf, buf + N);
        int i = 0;
        tank.left = 0;
        tank.cost = 0;
        tank.d = 0;
        if (buf[0].d != 0)
            cout << "The maximum travel distance = 0.00" << endl;
        else {
            while (i < N) {
                double lowest = buf[i].p;
                int index = i;
                for (int j = i + 1; j <= N && buf[j].d - buf[i].d <= tank.left * Davg; ++j) //找出油耗完前比当前站便宜的最低价站
                    if (buf[j].p < lowest) {
                        index = j;
                        lowest = buf[j].p;
                    }
                if (index != i) { //对应上述状态1，直接开过去加油
                    tank.left -= (buf[index].d - buf[i].d) / Davg;
                    i = index;
                    tank.d = buf[i].d;
                } else { //否则，找出满油箱可到达范围内最近的比当前站低价站
                    for (int j = i + 1; j <= N && buf[j].d <= buf[i].d + farest; ++j)
                        if (buf[j].p < lowest) {
                            index = j;
                            break;
                        }
                    if (index != i) { //对应上述状态2，加上刚好够的油开过去把油耗尽
                        tank.cost += ((buf[index].d - buf[i].d) / Davg - tank.left) * buf[i].p;
                        tank.left = 0;
                        i = index;
                        tank.d = buf[i].d;
                    } else { //否则，把油加满，然后找到满油箱可到达范围内次低价站
                        tank.cost += (C_max - tank.left) * buf[i].p;
                        tank.left = C_max;
                        double low = 1000000;
                        for (int j = i + 1; j <= N && buf[j].d <= buf[i].d + farest; ++j)
                            if (buf[j].p < low) {
                                index = j;
                                low = buf[j].p;
                            }
                        if (index != i) { //对应上述状态3，开到次低价站
                            tank.left -= (buf[index].d - buf[i].d) / Davg;
                            i = index;
                            tank.d = buf[i].d;
                        } else
                            break; //对应上述状态4，没有下一站
                    }
                }
            }
            if (i == N)
                printf("%.2lf\n", tank.cost);
            else
                printf("The maximum travel distance = %.2lf\n", tank.d + tank.left * Davg);
        }
    }
    return 0;
}
 */
