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
vector<int> v1,v2;
void fun(TreeNode *p,vector<int> &v1){
    if(p==NULL){
        return;
    }
    v1.push_back(p->val*9);
    fun(p->left,v1);
    v1.push_back(p->val*10);
    fun(p->right,v1);

}
void fun1(TreeNode *q,vector<int> &v2){
      if(q==NULL){
        return;
    }
    v2.push_back(q->val*9);
    fun(q->left,v2);
    v2.push_back(q->val*10);
    fun(q->right,v2);

    
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        fun(p,v1);
        fun1(q,v2);
        return v1==v2;
        
    }
};












1

import random
import csv
attributes=[["Sunny","Rainy"],["Warm","Cold"],["Normal","High"],["Strong","Weak"],["Warm","Cool"],["Same","Change"]]
num_attributes=len(attributes)
print("The most general hypothesis: ['?','?','?','?','?','?']")
print("The most general hypothesis: ['0','0','0','0','0','0']")
a=[]
print("The given training dataset: ")
with open('enjoysport.csv','r') as csvFile:
  reader=csv.reader(csvFile)
  for row in reader:
    a.append(row)
    print(row)
print("The initial value of hypothesis: ")
hypothesis=['0']*num_attributes
print(hypothesis)
for j in range(0,num_attributes):
  hypothesis[j]=a[0][j]
print("FIND-S: Finding a Maximality Specific Hypothesis")
for i in range(0,len(a)):
  if a[i][num_attributes]=="yes":
    for j in range(0,num_attributes):
      if a[i][j]!=hypothesis[j]:
        hypothesis[j]='?'
      else:
        hypothesis[j]=a[i][j]
  print("For training example no: {0} the hypothesis is ".format(i),hypothesis)
print("The Maximally Specific Hypothesis for a given training examples:")
print(hypothesis)

3
import pandas as pd
import math

# Function to calculate entropy
def entropy(data):
    counts = data.value_counts(normalize=True)  # Get class probabilities
    return -sum(counts * counts.apply(math.log2))  # Compute entropy

# Function to compute information gain
def information_gain(df, attribute, target):
    total_entropy = entropy(df[target])  # Entropy of the whole dataset
    weighted_entropy = sum((len(subset) / len(df)) * entropy(subset[target]) 
                           for _, subset in df.groupby(attribute))  # Weighted entropy
    return total_entropy - weighted_entropy  # Gain = total - weighted

# ID3 algorithm (recursive tree builder)
def id3(df, target, attributes):
    if len(df[target].unique()) == 1:  # If all labels are same, return label
        return df[target].iloc[0]
    if not attributes:  # If no attributes left, return majority label
        return df[target].mode()[0]
    
    # Choose best attribute with highest information gain
    best_attr = max(attributes, key=lambda attr: information_gain(df, attr, target))
    tree = {best_attr: {}}  # Create tree node

    for value, subset in df.groupby(best_attr):  # Split dataset
        tree[best_attr][value] = id3(subset, target, [a for a in attributes if a != best_attr])

    return tree

# Load dataset and run ID3
df = pd.read_csv('id3.csv')
attributes = list(df.columns.difference(["Answer"]))  # Get feature names
tree = id3(df, "Answer", attributes)

print("Decision Tree:")
print(tree)

output
Decision Tree:
{'Outlook': {'Sunny': {'Humidity': {'High': 'No', 'Low': 'Yes'}}, 
             'Overcast': 'Yes', 
             'Rainy': {'Windy': {'False': 'Yes', 'True': 'No'}}}}















import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# Sample data: House Size (sq. ft.) vs. Price ($1000s)
X = np.array([600, 800, 1000, 1200, 1400, 1600, 1800]).reshape(-1, 1)  # House sizes
y = np.array([150, 200, 250, 300, 350, 400, 450])  # House prices

# Create and train the Linear Regression model
regressor = LinearRegression().fit(X, y)

# Predict house prices and display model coefficients
print(f"Coefficient (m): {regressor.coef_[0]}")
print(f"Intercept (b): {regressor.intercept_}")

# Predict price for a house of 1100 sq. ft.
predicted_price = regressor.predict([[1100]])
print(f"Predicted Price for 1100 sq. ft. house: ${predicted_price[0]*1000:.2f}")

# Plot the regression line
plt.scatter(X, y, color='blue')
plt.plot(X, regressor.predict(X), color='red', )
plt.xlabel("House Size (sq. ft.)")
plt.ylabel("Price ($1000s)")
plt.title("House Price Prediction")


plt.show()











import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LogisticRegression

# Sample data: House Size (sq. ft.) vs. Affordable (0) / Expensive (1)
X = np.array([600, 800, 1000, 1200, 1400, 1600, 1800]).reshape(-1, 1)  # House sizes
y = np.array([0, 0, 0, 0, 1, 1, 1])  # 0 = Affordable, 1 = Expensive

# Create and train the Logistic Regression model
classifier = LogisticRegression().fit(X, y)


# Plot the Logistic Regression curve
X_range = np.linspace(500, 1900, 100).reshape(-1, 1)
y_prob = classifier.predict_proba(X_range)[:, 1]

plt.scatter(X, y, color='blue', )
plt.plot(X_range, y_prob, color='red',)
plt.xlabel("House Size (sq. ft.)")
plt.ylabel("Probability of Being Expensive")
plt.title("House Price Classification (Affordable vs. Expensive)")
plt.show()












#exp 8 , 9 
import pandas as pd
from sklearn.preprocessing import OneHotEncoder

# Sample Data
data = {'Employee ID': [10, 20, 15, 25, 30],
        'Gender': ['M', 'F', 'F', 'M', 'F'],
        'Remarks': ['Good', 'Nice', 'Good', 'Great', 'Nice']}

df = pd.DataFrame(data)
print("Original Data:\n", df)

# One-Hot Encoding
encoder = OneHotEncoder(sparse_output=False, drop='first')
encoded = encoder.fit_transform(df[['Gender', 'Remarks']])

# Convert to DataFrame
df_encoded = pd.DataFrame(encoded, columns=encoder.get_feature_names_out(['Gender', 'Remarks']))
df_final = pd.concat([df.drop(['Gender', 'Remarks'], axis=1), df_encoded], axis=1)

print("\nEncoded Data:\n", df_final)





11
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier

# Load dataset
iris = load_iris()
X, y = iris.data, iris.target  

# Split into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Train KNN classifier
knn = KNeighborsClassifier(n_neighbors=3)  
knn.fit(X_train, y_train)

# Make predictions
y_pred = knn.predict(X_test)

# Print correct and incorrect predictions
for i in range(len(y_test)):
    print(f"Actual: {y_test[i]}, Predicted: {y_pred[i]}, {'✔️ Correct' if y_test[i] == y_pred[i] else '❌ Wrong'}")















#exp 7
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.linear_model import LogisticRegression
from sklearn.preprocessing import LabelEncoder

# Load dataset & remove duplicates
iris = pd.read_csv("https://raw.githubusercontent.com/uiuc-cse/data-fa14/gh-pages/data/iris.csv").drop_duplicates()
X, y = iris.drop(columns=['species']), LabelEncoder().fit_transform(iris['species'])

# Train-Test Split & Model Training
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
model = LogisticRegression(max_iter=1000).fit(X_train, y_train)

# Compute Bias, Variance & Cross-Validation Accuracy
bias, variance = np.mean((y_test - model.predict(X_test)) ** 2), np.var(model.predict(X_test))
accuracy_cv = cross_val_score(model, X, y, cv=5, scoring='accuracy').mean()

print(f"Bias: {bias:.4f} | Variance: {variance:.4f} | CV Accuracy: {accuracy_cv:.4f}")

# Bias-Variance Tradeoff Graph
c = np.linspace(1, 10, 100)
plt.plot(c, (c - 3)**2, label='Bias²', color='blue')
plt.plot(c, np.log(c)*3, label='Variance', color='red')
plt.plot(c, (c - 3)**2 + np.log(c)*3, label='Total Error', color='green')
plt.axvspan(1, 2.5, color='blue', alpha=0.1, label='Underfitting')
plt.axvspan(7.5, 10, color='red', alpha=0.1, label='Overfitting')
plt.legend(), plt.show()














    10


    import numpy as np

# Input and Output Data (Normalized)
X = np.array([[2, 9], [1, 5], [3, 6]]) / 9
Y = np.array([[0.92], [0.86], [0.89]])

# Sigmoid Activation Function
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

# Derivative of Sigmoid
def sigmoid_derivative(x):
    return x * (1 - x)

# Initialize Weights and Biases
np.random.seed(1)
W1 = np.random.rand(2, 3)  # Weights for input to hidden layer
W2 = np.random.rand(3, 1)  # Weights for hidden to output layer

# Training
for _ in range(5000):
    # Forward Propagation
    hidden = sigmoid(np.dot(X, W1))
    output = sigmoid(np.dot(hidden, W2))

    # Backpropagation
    error = Y - output
    d_output = error * sigmoid_derivative(output)
    d_hidden = d_output.dot(W2.T) * sigmoid_derivative(hidden)

    # Update Weights
    W2 += hidden.T.dot(d_output) * 0.1
    W1 += X.T.dot(d_hidden) * 0.1

# Print Results
print("Predicted Output:\n", output)
























































