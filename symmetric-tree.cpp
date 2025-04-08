/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool fun(TreeNode* r1,TreeNode* r2){
        if(r1==NULL && r2!=NULL || r1!=NULL && r2==NULL){
            return false;
        }
        else if(r1==NULL && r2==NULL){
            return true;
        }
        else if(r1->val !=r2->val){
            return false;
        }
        return fun(r1->left,r2->right) && fun(r1->right,r2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL)){
            return false;
        }
        return fun(root->left,root->right);
        
    }
};
----------------------------------------------
    

import csv


def find_s_algorithm(filename):
    with open(filename, 'r') as file:
        data = list(csv.reader(file))

    
    if data[0][0].lower() in ["outlook", "attribute1"]:
        data.pop(0)

    print("\nTraining Data:")
    for row in data:
        print(row)

    num_attributes = len(data[0]) - 1  # Last column is the target class
    hypothesis = ['0'] * num_attributes

   
    for i in range(num_attributes):
        hypothesis[i] = data[0][i]

    
    for i in range(len(data)):
        if data[i][-1].lower() == "yes":  # If the example is positive
            for j in range(num_attributes):
                if data[i][j] != hypothesis[j]:
                    hypothesis[j] = '?'  # Generalize

        print(f"After example {i+1}: {hypothesis}")

    print("\nFinal Hypothesis:", hypothesis)

# Run the algorithm with a sample dataset
find_s_algorithm("enjoysport.csv")


----------------------------------------------------------------------------

import numpy as np

def candidate_elimination(concepts, target):
    num_attributes = len(concepts[0])
    
    
    specific_h = concepts[0].copy()
    
    general_h = [["?" for _ in range(num_attributes)] for _ in range(num_attributes)]
    
    print("\nInitial Specific Hypothesis:", specific_h)
    print("Initial General Hypothesis:", general_h)

    for i, example in enumerate(concepts):
        if target[i].lower() == "yes":  # Positive Example
            for j in range(num_attributes):
                if example[j] != specific_h[j]:
                    specific_h[j] = '?'  # Generalizing Specific Hypothesis
                    general_h[j][j] = '?'  # Updating General Hypothesis
        else:  # Negative Example
            for j in range(num_attributes):
                if example[j] != specific_h[j]:
                    general_h[j][j] = specific_h[j]  # Specialization step

        print(f"\nAfter example {i+1}:")
        print("Specific Hypothesis:", specific_h)
        print("General Hypothesis:", general_h)


    general_h = [h for h in general_h if h != ["?"] * num_attributes]

    print("\nFinal Specific Hypothesis:", specific_h)
    print("Final General Hypothesis:", general_h)


concepts = np.array([
    ['Sunny', 'Warm', 'Normal', 'Strong', 'Warm', 'Same'],
    ['Sunny', 'Warm', 'High', 'Strong', 'Warm', 'Same'],
    ['Rainy', 'Cold', 'High', 'Strong', 'Warm', 'Change'],
    ['Sunny', 'Warm', 'High', 'Strong', 'Cool', 'Change'],
    ['Rainy', 'Warm', 'High', 'Strong', 'Cool', 'Change']
])

target = np.array(['Yes', 'Yes', 'No', 'No', 'No'])


candidate_elimination(concepts, target)
----------------------------------------------------------------------------


import math  # Import math library for log calculations


data = [
    ['Sunny', 'Hot', 'High', 'Weak', 'No'],
    ['Sunny', 'Hot', 'High', 'Strong', 'No'],
    ['Overcast', 'Hot', 'High', 'Weak', 'Yes'],
    ['Rain', 'Mild', 'High', 'Weak', 'Yes'],
    ['Rain', 'Cool', 'Normal', 'Weak', 'Yes'],
    ['Rain', 'Cool', 'Normal', 'Strong', 'No'],
    ['Overcast', 'Cool', 'Normal', 'Strong', 'Yes'],
    ['Sunny', 'Mild', 'High', 'Weak', 'No'],
    ['Sunny', 'Cool', 'Normal', 'Weak', 'Yes'],
    ['Rain', 'Mild', 'Normal', 'Weak', 'Yes'],
    ['Sunny', 'Mild', 'Normal', 'Strong', 'Yes'],
    ['Overcast', 'Mild', 'High', 'Strong', 'Yes'],
    ['Overcast', 'Hot', 'Normal', 'Weak', 'Yes'],
    ['Rain', 'Mild', 'High', 'Strong', 'No']
]

attributes = ['Outlook', 'Temperature', 'Humidity', 'Wind']
target = 'PlayTennis'

df = [dict(zip(attributes + [target], row)) for row in data]


def entropy(values):
    total = len(values)
    return sum(-values.count(v) / total * math.log2(values.count(v) / total) for v in set(values))


def best_attribute(data, attrs):
    return max(attrs, key=lambda attr: 
               entropy([row[target] for row in data]) - 
               sum((len([r for r in data if r[attr] == val]) / len(data)) * 
                   entropy([r[target] for r in data if r[attr] == val]) 
                   for val in set(r[attr] for r in data)))

def id3(data, attrs):
   
    if len(set(row[target] for row in data)) == 1:
        return data[0][target]

    if not attrs:
        return max([row[target] for row in data], key=lambda v: [row[target] for row in data].count(v))

 
    best_attr = best_attribute(data, attrs)

  
    return {best_attr: {val: id3([r for r in data if r[best_attr] == val], [a for a in attrs if a != best_attr]) 
                        for val in set(r[best_attr] for r in data)}}


tree = id3(df, attributes)


def classify(tree, sample):
    if not isinstance(tree, dict):
        return tree  # If it's a leaf node, return the class
    attr = next(iter(tree))  # Get the attribute to check
    return classify(tree[attr].get(sample[attr], "Unknown"), sample)  # Move down the tree


sample = {'Outlook': 'Sunny', 'Temperature': 'Cool', 'Humidity': 'High', 'Wind': 'Strong'}
print("Decision Tree:", tree)
print("Classification:", classify(tree, sample))
----------------------------------------------------------------------------
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split


temperature = np.array([10, 15, 20, 25, 30, 35, 40, 45, 50]).reshape(-1, 1)  # Features (X)
revenue = np.array([100, 150, 200, 250, 300, 350, 400, 450, 500])  # Labels (Y)


X_train, X_test, y_train, y_test = train_test_split(temperature, revenue, test_size=0.2, random_state=0)


model = LinearRegression()
model.fit(X_train, y_train)


print("Slope (m):", model.coef_[0])
print("Intercept (b):", model.intercept_)


y_pred = model.predict(X_test)
print("Predicted Revenue:", y_pred)


plt.scatter(X_train, y_train, color='blue', label="Training Data")
plt.plot(X_train, model.predict(X_train), color='red', label="Regression Line")
plt.xlabel("Temperature (°C)")
plt.ylabel("Revenue ($)")
plt.title("Temperature vs Revenue (Training Data)")
plt.legend()
plt.show()


plt.scatter(X_test, y_test, color='blue', label="Actual Revenue")
plt.scatter(X_test, y_pred, color='red', label="Predicted Revenue")
plt.xlabel("Temperature (°C)")
plt.ylabel("Revenue ($)")
plt.title("Temperature vs Revenue (Testing Data)")
plt.legend()
plt.show()
----------------------------------------------------------------------------


import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split


age = np.array([18, 20, 22, 25, 30, 35, 40, 45, 50, 55, 60]).reshape(-1, 1)  # Features (X)
buy_product = np.array([0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1])  # Labels (0 = No Buy, 1 = Buy)


X_train, X_test, y_train, y_test = train_test_split(age, buy_product, test_size=0.2, random_state=0)


model = LogisticRegression()
model.fit(X_train, y_train)

y_pred = model.predict(X_test)
print("Predicted Buy Decision:", y_pred)


plt.scatter(X_train, y_train, color='blue', label="Training Data")
plt.scatter(X_test, y_test, color='green', label="Testing Data")
plt.plot(age, model.predict_proba(age)[:, 1], color='red', label="Binary Classifier Curve")
plt.xlabel("Age")
plt.ylabel("Buy Product (0 = No, 1 = Yes)")
plt.title("Age vs Product Purchase Decision")
plt.legend()
plt.show()



----------------------------------------------------------------------------
from sklearn.preprocessing import OneHotEncoder
import pandas as pd


data = {
    'Employee ID': [10, 20, 15, 25, 30],
    'Gender': ['M', 'F', 'F', 'M', 'F'],
    'Remarks': ['Good', 'Nice', 'Good', 'Great', 'Nice']
}

df = pd.DataFrame(data)
print("Original Employee Data:\n", df)


encoder = OneHotEncoder(sparse_output=False)
encoded_data = encoder.fit_transform(df[['Gender', 'Remarks']])

encoded_df = pd.DataFrame(encoded_data, columns=encoder.get_feature_names_out(['Gender', 'Remarks']))


df_encoded = pd.concat([df.drop(['Gender', 'Remarks'], axis=1), encoded_df], axis=1)

print("\nOne-Hot Encoded Employee Data:\n", df_encoded)
----------------------------------------------------------------------------
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import classification_report, confusion_matrix
from sklearn import datasets


iris = datasets.load_iris()
X = iris.data  # Features
y = iris.target  # Labels


print("\nFeatures: Sepal-Length, Sepal-Width, Petal-Length, Petal-Width")
print("\nLabels: 0 - Iris-Setosa, 1 - Iris-Versicolour, 2 - Iris-Virginica")


X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

k = 5  # Number of neighbors
knn = KNeighborsClassifier(n_neighbors=k)
knn.fit(X_train, y_train)


y_pred = knn.predict(X_test)


print("\nConfusion Matrix:\n", confusion_matrix(y_test, y_pred))
print("\nClassification Report:\n", classification_report(y_test, y_pred))

correct = (y_pred == y_test).sum()
wrong = (y_pred != y_test).sum()

print(f"\nCorrect Predictions: {correct}")
print(f"Wrong Predictions: {wrong}")




