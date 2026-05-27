#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Recipe{
    string recipeName;
    vector<string>recipeIngredients;
    vector<string>instructionSteps;
};

int main(){
    vector<Recipe>recipes;

    int menuChoice;
    bool running = true;

    while (running){
        cout << "\n=== Recipe Manager ===" << endl;
        cout << "1. Add Recipe" << endl;
        cout << "2. Display All Recipes" << endl;
        cout << "3. Search Recipes" << endl;
        cout << "4. Remove Recipe" << endl;
        cout << "5. Show Statistics" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter choice: ";
        cin >> menuChoice;
        cin.ignore();

        switch(menuChoice){
            case 1:{
                cout << "Add Recipe selected" << endl;

                Recipe newRecipe;

                cout << "What's the name of your new recipe? " << endl;
                getline(cin, newRecipe.recipeName);

                int ingredientCount;
                string ingredient;

                cout << "How many ingredients? " << endl;
                cin >> ingredientCount;
                cin.ignore();

                for (int i = 0; i < ingredientCount;i++){
                    cout << "Enter ingredient " << i + 1 << ": " << endl;
                    getline(cin, ingredient);

                    newRecipe.recipeIngredients.push_back(ingredient);
                }

                int stepCount;
                string step;

                cout << "How many instruction steps? ";
                cin >> stepCount;
                cin.ignore();

                for (int i = 0; i < stepCount;i++){
                    cout << "Enter step " << i + 1 << ": ";
                    getline(cin, step);

                    newRecipe.instructionSteps.push_back(step);
                }
            

                recipes.push_back(newRecipe);

                cout << "\nRecipe added!\n";

                break;
            }

            case 2:{
                cout << "Display selected" << endl;
                if (recipes.size() == 0){
                    cout << "No recipes saved yet." << endl;
                }
                else {
                    for (int i = 0; i < recipes.size(); i++){
                        cout << "\nRecipe " << i + 1 << ": " << recipes.at(i).recipeName << endl;

                        cout << "Ingredients" << endl;
                        for (int j = 0; j < recipes.at(i).recipeIngredients.size(); j++){
                            cout << j + 1 << ". " << recipes.at(i).recipeIngredients.at(j) << endl;
                        }

                        cout << "Steps: " << endl;
                        for (int j = 0; j < recipes.at(i).instructionSteps.size(); j++){
                            cout << j + 1 << ". " << recipes.at(i).instructionSteps.at(j) << endl;
                        }
                    }
                }
                break;
            }
            case 3:{
                cout << "Search selected" << endl;

                string search;
                bool found = false;

                cout << "Enter recipe name or ingredient to search: " << endl;
                getline(cin, search);

                for (int i = 0; i < recipes.size(); i++){
                    if (recipes.at(i).recipeName.find(search) != string::npos){
                        cout << "\nFound: " << recipes.at(i).recipeName << endl;
                        found = true;
                    }
                    for (int j = 0; j < recipes.at(i).recipeIngredients.size(); j++){
                        if (recipes.at(i).recipeIngredients.at(j).find(search) != string::npos){
                            cout << "\nFound: " << recipes.at(i).recipeName << endl;
                            found = true;
                            break;
                        }
                    }
                }
                if (!found){
                    cout << "No recipes found." << endl;
                }
                break;
            }
            case 4:{
                cout << "Remove recipe selected" << endl;

                if (recipes.size() == 0){
                    cout << "No recipes to remove." << endl;
                }
                else{
                    for (int i = 0; i < recipes.size(); i++){
                        cout << i + 1 << ". " << recipes.at(i).recipeName << endl;
                    }
                    
                    int removeChoice;
                    cout << "Enter the recipe number to remove: ";
                    cin >> removeChoice;
                    cin.ignore();

                    if (removeChoice < 1 || removeChoice > recipes.size()){
                        cout << "Invalid recipe number." << endl;
                    }
                    else{
                        recipes.erase(recipes.begin() + removeChoice - 1);
                        cout << "Recipe removed." << endl;
                    }
                }

                break;
            }
            case 5:{
                cout << "Show statistics selected" << endl;

                if (recipes.size() == 0){
                    cout << "No recipes saved yet." << endl;
                }
                else{
                    int totalIngredients = 0;
                    int totalSteps = 0;

                    for (int i = 0; i < recipes.size(); i ++){
                        totalIngredients += recipes.at(i).recipeIngredients.size();
                        totalSteps += recipes.at(i).instructionSteps.size();
                    }

                    cout << "\n=== Statistics ===" << endl;
                    cout << "Total recipes: " << recipes.size() << endl;
                    cout << "Total ingredients: " << totalIngredients << endl;
                    cout << "Total instruction steps: " << totalSteps << endl;
                    cout << "Average ingredients per recipe: " << static_cast<double>(totalIngredients) / recipes.size() << endl;
                    cout << "Average steps per recipe: " << static_cast<double>(totalSteps) / recipes.size() << endl;
                }

                break;
            }
            case 6:
                running = false;
                break;

            default:
                cout << "Invalid choice" << endl;
            
        }
    }

    
    return 0;
}

