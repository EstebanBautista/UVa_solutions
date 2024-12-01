#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int casos, calles, numero, val, ans, mid;
    vector<int> familiares;
    
    scanf("%d", &casos);

    while (casos--){
        familiares.clear();
        ans = 0;

        scanf("%d", &calles);

        for (val = 0; val < calles; val++){
            scanf("%d", &numero);
            familiares.push_back(numero);
        }

        mid = (calles) / 2;
        sort(familiares.begin(), familiares.end());

        for (val = 0; val < familiares.size(); val++){
            ans += abs( familiares[mid] - familiares[val]);
        }

        printf("%d\n", ans);

    }

    return 0;
}