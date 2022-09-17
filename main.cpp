#include <iostream>
#include <vector>
using namespace std;

void matrixVectorMult(vector<vector<pair<int, float>>> &numbers, vector<float> multVector){
    float finalResult[numbers.size()] = {0};
    int partialRes=0;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers[i].size(); j++){
            finalResult[i] += numbers[i][j].second*multVector[numbers[i][j].first]; 
        }
    }
    for(int i=0;i<numbers.size(); i++){
        cout << finalResult[i] << endl;
    }
    
}

void matrixMatrixMulti(vector<vector<pair<int, float>>> &numbers, vector<vector<pair<int, float>>> &source, int maxRow, int maxColumn){
    int finalRes[maxRow][maxColumn];
    for(int i=0; i<maxRow;i++){
        for(int j=0; j < maxColumn; j++){
            finalRes[i][j] = 0;
        }
    }
    
    for(int i=0; i < numbers.size(); i++){
        for(int k=0; k < numbers[i].size(); k++){
            for(int j=0; j < source[numbers[i][k].first].size(); j++){ // erro em source[k]
                //if(j >= source[numbers[i][k].first].size()){break;}
                finalRes[i][source[numbers[i][k].first][j].first] += numbers[i][k].second*source[numbers[i][k].first][j].second;
            }
        }
    }

    for(int i=0;i<maxRow;i++){
        for(int j=0; j<maxColumn;j++){
            printf("%d ", finalRes[i][j]);
        }
        printf("\n");
    }
}

int main(){
    
    int linha, col, linMt2, colMt2, k=0, z=0, opcao;
    system("cls");
    printf("Hello mate:)\n\n");

    while(1){
        printf("Choose an operation : \n\n -1- (Sparse Matrix - Vector Multiplication) \n -2- (Sparse - Sparse Matrix Multiplication) \n -3- (Sparse - Dense Matrix Multiplication)\n -0- (Exit)\n\nOption : ");
        scanf("%d", &opcao);
        system("cls");

        switch(opcao){

            case 1:

            {
            int op1;
            vector<float> multVector = {1,2,3,4};
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
                    //printf("%d - %f\n", testing.first, testing.second);
                }
                numbers.push_back(testVector);
            }
                matrixVectorMult(numbers, multVector);
                printf("\n-Any number- : Menu\n");
                    if(scanf("%d", &op1)){
                        system("cls");
                        break;
                    }

            }

            case 2: case 3:

            {
            int op2;
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
                    //printf("%d - %f\n", testing.first, testing.second);
                }
                numbers.push_back(testVector);
            }

                cin >> linMt2 >> colMt2;
                vector<vector<pair<int, float>>> segNumbers;

                for(int i=0; i<linMt2;i++){
                    vector<pair<int, float>> testVector;
                    for(int j=0; j<colMt2; j++){
                        scanf("%f", &matrizEsp[i][j]);
                        if(matrizEsp[i][j] != 0){
                            testing.first = j;
                            testing.second = matrizEsp[i][j];
                            testVector.push_back(testing);
                        }
                        //printf("%d - %f\n", testing.first, testing.second);
                    }
                    segNumbers.push_back(testVector);
                }
                matrixMatrixMulti(numbers, segNumbers, linha, colMt2);
                printf("\n(Any number) - Menu\n");
                if(scanf("%d", &op2)){
                    system("cls");
                    break;
                }
            }

            default:
            printf("Choose an right operation :(\n");
        }

    };
    /*for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers[i].size(); j++)
             printf("%d,%.1f", numbers[i][j].first,numbers[i][j].second);
        cout << endl;
    }
    */

    return 0;
}

