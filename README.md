# Single Layer Perceptron From Scratch in C Language
The single-layer Perceptron is the simplest of the artificial neural networks (ANNs). It was developed by American psychologist Frank Rosenblatt in the 1950s.

# How It Works
The perceptron works by “learning” a series of weights, corresponding to the input features. These input features are vectors of the available data. For example, if we were trying to classify whether an animal is a cat or dog, x1 might be weight, x2 might be height, and x3 might be length. Each pair of weights and input features is multiplied together, and then the results are summed. If the summation is above a certain threshold, we predict one class, otherwise the prediction belongs to a different class. For example, we could set the threshold at 0. If the summation is greater than 0, the prediction is a 1 (dog), otherwise it’s a 0 (cat).
The final step is to check if our predictions were classified correctly. If they were not, then the weights are updated using a learning rate. This process continues for a certain number of iterations, known as “epochs.” The goal is to determine the weights that produce a linear decision boundary that correctly classifies the predictions.

# Function Used
## getDataVal(FILE *fp)
## initWeight()
## dotProduct(float *, float *)
## activationFunction(float, float)
## errorCheck(int, int)
## updateWeight(float, float, float, int)
## printValues(float *)
## printWeights(float *)
## TestSLP(float *)
## printIris(int)
ANN- Assignment University of Hyderabad
