# Leetcode
1
import csv  

# Define attributes and initialize hypothesis
attributes = [['Sunny', 'Rainy'], ['Warm', 'Cold'], ['Normal', 'High'], 
              ['Strong', 'Weak'], ['Warm', 'Cool'], ['Same', 'Change']]  
num_attributes = len(attributes)  
hypothesis = ['0'] * num_attributes  

# Read training data  
data = []  
with open('/content/enjoysport.csv', 'r') as file:  
    reader = csv.reader(file)  
    data = list(reader)  

# Initialize hypothesis with the first positive example  
for i in range(num_attributes):  
    hypothesis[i] = data[0][i]  

# Apply Find-S algorithm  
for row in data:  
    if row[num_attributes] == 'Yes':  
        for i in range(num_attributes):  
            if row[i] != hypothesis[i]:  
                hypothesis[i] = '?'  

# Print final hypothesis  
print("Maximally Specific Hypothesis:", hypothesis)  


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





































































