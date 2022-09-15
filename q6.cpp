#include <iostream>
#include <vector>
 
using namespace std;

int main(){
    
    int linha, col, k=0, z=0;
    cin >> linha >> col;

    float matrizEsp[linha][col];

    pair<int, float> testing;
    vector<vector<pair<int, float>>> numbers;

    for(int i=0; i<linha;i++){
        vector<pair<int, float>> testVector;
        for(int j=0; j<col; j++){
            scanf("%f", &matrizEsp[i][j]);
            if(matrizEsp[i][j] != 0){
                testing.first = j;
                testing.second = matrizEsp[i][j];
                testVector.push_back(testing);
            }
            numbers.push_back(testVector);
            //printf("%d - %f\n", testing.first, testing.second);
        }
    }

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers[i].size(); j++)
             printf("--%f--", numbers[i][j].second);
        cout << endl;
    }
    /*for(int i=0; i<linha;i++){
        for(int j=0;j<col; j++){
            printf("%f ", matrizEsp[i][j]);
        }
        printf("\n");
    }
    */

    return 0;
}
