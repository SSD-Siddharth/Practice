# Lab assessment 5
# 1.	Correlation:
#   a.	Consider data set of your choice, Using R try to find the correlation coefficient between any two variables using the correlation methods( pearson, spearman, kendall)

# Longley's Economic Regression Data
data(longley)
dim(longley)
head(longley)
data=longley
data

# Observing the correlation between Employed and GNP.deflator(GrossNationProduct)
#pearson, 
pear<-cor.test(data$GNP.deflator, data$Employed, method="pearson")
pear
    # t is the t-test statistic value,
    # df is the degrees of freedom,
    # p-value is the significance level of the t-test.
    # conf.int is the confidence interval of the correlation coefficient at 95%;
    # sample estimates is the correlation coefficient (Cor.coeff = 0.97).
#Conclusion: It can be observed that 'Employed' and 'GNP.deflator' are significantly correlated. 
pear$estimate  # Directly extracting the correlation coeffieicient. 

#Spearman’s rho statistic is also used to estimate a rank-based measure of association
spear<-cor.test(data$GNP.deflator, data$Employed, method="spearman")

spear  #rho is the Spearman’s correlation coefficient.

#Kendall
kendl<-cor.test(data$GNP.deflator, data$Employed, method="kendall")
kendl   #tau is the Kendall correlation coefficent. 
# Observilt all three, 
cor.test(data$GNP.deflator, data$Employed, method=c("pearson", "kendall", "spearman"))

#Using Pearson, to see all the columns/variables correlation with respect to 'Employed'
pear2<-cor.test(data$GNP, data$Employed, method="pearson")
pear2$estimate  #GNP Vs.Employed 
pear3<-cor.test(data$Population, data$Employed, method="pearson")
pear3$estimate  #Population Vs. Employed
pear4<-cor.test(data$Armed.Forces, data$Employed, method="pearson")
pear4$estimate  #Armed.Forces Vs. Employed
pear5<-cor.test(data$Year, data$Employed, method="pearson")
pear5$estimate  #Year Vs. Employed


# b.	Plot the scatter plot to demonstrate the correlation between the variables
install.packages("ggpubr")
library("ggpubr")
ggscatter(data, x="GNP.deflator",y="Employed")
#Observing the 
ggscatter(data, x="GNP.deflator",y="Employed",
          color = "red",
          fill = "red",
  add = "reg.line", conf.int = TRUE, 
  cor.coef = TRUE, cor.method = "pearson",
  title="Correlation Between GNP.deflator Vs. Employed",
  xlab = "GNP.deflator", ylab = "Employed, Y-Dependent Var")+scale_color_manual(values=c('Yellow'))


# Other way
ggplot( data, aes( x=GNP.deflator, y=Employed ))+
  geom_point()+
  stat_cor(method = "pearson")

# c.	Produce all possible pair-wise plots of the variables present in the data set.
dim(data)

pairs(longley[,1:7], pch = 19)

#More detailed
install.packages("GGally")
library("GGally")

my_cols <- c("#00AFBB", "#E7B800", "#FC4E07")  
pairs(longley[,1:7], pch = 19,  cex = 0.5,
      col = my_cols[longley$GNP],
      lower.panel=NULL)
ggpairs(data)

#Scatter plot with correlation
# Scatterplot Matrices from the glus Package
install.packages("gclus")
library(gclus)
dta <- data # get data
dta.r <- abs(cor(dta)) # get correlations
dta.col <- dmat.color(dta.r) # get colors
# reorder variables so those with highest correlation
# are closest to the diagonal
dta.o <- order.single(dta.r)
cpairs(dta, dta.o, panel.colors=dta.col, gap=.5,
       main="Variables Ordered and Colored by Correlation" )



# d.	Try to fit a regression model for the variable pair in the data set. 
#Checking the normality,
hist(data$Unemployed)
data
library("ggpubr")
# Density plot, checking if the distribution is bell shaped or not. 
ggdensity(data$Employed, fill = "lightgray")
# QQ plot, quantile-quantile plot,
ggqqplot(data$Employed)# If the data are normal, the dots should be a straight line
#Now, after confirmation performing the linear regression.
lm1<-lm(data$Employed ~ data$GNP.deflator)
summary(lm1)
#As the P-value, is almost 0, it means it indicates that our the model fits the data well.


#Visuazling the results/Resgrssion line, 
ggplot(data, aes(x=GNP.deflator, y=Employed))+
  geom_point() + geom_smooth(method="lm", col="Green")+
  stat_regline_equation()



#Now, doing multiple regression
lm2<-lm(Employed ~ GNP+GNP.deflator+Unemployed+Armed.Forces+Population+Year, data=data)
summary(lm2)
#Check for homoscedasticity
par(mfrow=c(2,2))
plot(lm2)
par(mfrow=c(1,1))



# 2.	N-Fold cross validation:
#   Consider the PimaIndiansDiabetes, try to experiment the N cross validation technique in the above data set. Try to model methods like random forest or related methods and use 10 folds and present the results. 
# Note:	the package Mlbench holds pima Indian diabetes datset
# Caret  or any other related packages can be used to  build model. 

install.packages("mlbench")
library(mlbench)
data(PimaIndiansDiabetes)
df <- PimaIndiansDiabetes
head(df)

install.packages("tidymodels")
library(tidymodels)
install.packages("themis")
library(themis) #for, Simple recipe with ROSE
tidymodels_prefer()
#Splitting for 75/25 for training/testing
train_test_split <- initial_split(df, 0.75, strata = 'diabetes')
# Extract training data
train <- training(train_test_split)
test<-testing(train_test_split)
head(train)
tail(train)
head(test)



#Creating a 10 fold repeated Cross Validation splits
#Trying 3 repeats
cv_folds <- vfold_cv(train, v = 10, repeats = 3, strata = 'diabetes')

# Simple recipe with ROSE
rec <- recipe(diabetes ~ ., data = train) %>% step_rose(diabetes)
# Creating our Random Forest Model
model <- rand_forest(
  mode = 'classification',
  engine = 'randomForest',
  mtry = tune(),
  trees = tune(),
  min_n = tune()
)

# Defining workflow
wflow <- workflow(
  preprocessor = rec,
  spec = model
)


install.packages("caret")
library("caret")
# Performing CV(Cross Validation)
res <-
  tune_grid(
    object = wflow,
    resamples = cv_folds,
    control = control_grid(save_pred = TRUE)
  )


# Finding the best hyperparameters for the randomForest model
best_hyperparams <- select_best(res)

# Adding those hyperparams to the workflow
final_wflow <- finalize_workflow(wflow, best_hyperparams)

# Fitting the updated workflow to the whole train data
# Evaluating the  performance in the held-out test data
final_fit <- last_fit(final_wflow, train_test_split)

# Confusion matrix in the test data
cm=collect_predictions(final_fit) %>% 
  conf_mat(diabetes, .pred_class)
#Plotting it,
install.packages("ggplot2")
library(ggplot2)
autoplot(cm, type = "mosaic")
autoplot(cm, type = "heatmap")

col <- c("#ed3b3b", "#0099ff")

graphics::fourfoldplot(cm$table, color = col, conf.level = 0.95, margin = 1, 
                       main = paste("Random Forest Accuracy(",round(cm$overall[1]*100),"%)", sep = ""))

#Trying other way, Reference, https://rpubs.com/jvaldeleon/forest_repeat_cv
packages <- c('dplyr', 'ggplot2', 'caret')
##  Installing them if not yet installed
installed_packages <- packages %in% rownames(installed.packages())
if (any(installed_packages == FALSE)) {
  install.packages(packages[!installed_packages])
}
##  Load the packages into R session
invisible(lapply(packages, library, character.only = TRUE))
df
## Set seed for reproducibility
set.seed(123)
## Defining repeated cross validation with 10 folds and three repeats
repeat_cv <- trainControl(method='repeatedcv', number=10, repeats=3)
## Splitting the data so that we use 70% of it for training
train_index <- createDataPartition(y=df$diabetes, p=0.7, list=FALSE)

## Subset the data
training_set <- df[train_index, ]
testing_set <- df[-train_index, ]

cor_data <- cor(training_set[,setdiff(names(training_set), 'diabetes')])
#Numerical Correlation Matrix
cor_data
# Correlation matrix plots
corrplot::corrplot(cor_data)


#Creating the model
## Set seed for reproducibility
set.seed(123)

## Train a random forest model
forest <- train(
  
  # Formula. We are using all variables to predict Species
  diabetes~., 
  
  # Source of data; remove the Species variable
  data=training_set, 
  
  # `rf` method for random forest
  method='rf', 
  
  # Add repeated cross validation as trControl
  trControl=repeat_cv,
  
  # Accuracy to measure the performance of the model
  metric='Accuracy')

## Print out the details about the model
forest$finalModel

#Also checking the variable importance
## Get variable importance, and turn into a data frame
var_imp <- varImp(forest, scale=FALSE)$importance
var_imp <- data.frame(variables=row.names(var_imp), importance=var_imp$Overall)

## Create a plot of variable importancei
var_imp %>%
  
  ## Sort the data by importance
  arrange(importance) %>%
  
  ## Create a ggplot object for aesthetic
  ggplot(aes(x=reorder(variables, importance), y=importance)) + 
  
  ## Plot the bar graph
  geom_bar(stat='identity') + 
  
  ## Flip the graph to make a horizontal bar plot
  coord_flip() + 
  
  ## Add x-axis label
  xlab('Variables') +
  
  ## Add a title
  labs(title='Random forest variable importance') + 
  
  ## Some layout for the plot
  theme_minimal() + 
  theme(axis.text = element_text(size = 10), 
        axis.title = element_text(size = 15), 
        plot.title = element_text(size = 20), 
  )


##Checking the accuracy, Generating predictions
y_hats <- predict(
  
  ## Random forest object
  object=forest, 
  
  ## Data to use for predictions; remove the Species
  newdata=testing_set[, -9])

## Print the accuracy
accuracy <- mean(y_hats == testing_set$diabetes)*100
cat('Accuracy on testing data: ', round(accuracy, 2), '%',  sep='')





#Trying with graphs, 
#RF
model_forest <- caret::train(diabetes ~., data = training_set,
                             method = "ranger",
                             metric = "ROC",
                             trControl = trainControl(method = "cv", number = 10,
                                                      classProbs = T, summaryFunction = twoClassSummary),
                             preProcess = c("center","scale","pca"))
model_forest



#KNN, 10 fold
model_knn <- caret::train(diabetes ~., data = training_set,
                          method = "knn",
                          metric = "ROC",
                          tuneGrid = expand.grid(.k = c(3:10)),
                          trControl = trainControl(method = "cv", number = 10,
                                                   classProbs = T, summaryFunction = twoClassSummary),
                          preProcess = c("center","scale","pca"))

model_knn
#Model Comparison
model_list <- list(Random_Forest = model_forest,KNN = model_knn)
resamples <- resamples(model_list)

#box plot
bwplot(resamples, metric="ROC", title="S")




# prediction on Test data set
pred_rf <- predict(model_forest, testing_set)
# Confusion Matrix 
cm_rf <- confusionMatrix(pred_rf, testing_set$diabetes, positive="pos")

# Prediction Probabilities
pred_prob_rf <- predict(model_forest, testing_set, type="prob")

# Confusion Matrix for Random Forest Model
cm_rf
col <- c("#ed3b3b", "#0099ff")
graphics::fourfoldplot(cm_rf$table, color = col, conf.level = 0.95, margin = 1, 
                       main = paste("Random Forest Accuracy(",round(cm_rf$overall[1]*100),"%)", sep = ""))

#For, KNN
pred_knn <- predict(model_knn, testing_set)
# Confusion Matrix 
cm_knn <- confusionMatrix(pred_knn, testing_set$diabetes, positive="pos")


# Prediction Probabilities
pred_prob_knn <- predict(model_knn, testing_set, type="prob")
# ROC value
#roc_knn <- roc(testing_set$diabetes, pred_prob_knn$pos)

# Confusion matrix 
cm_knn

graphics::fourfoldplot(cm_knn$table, color = col, conf.level = 0.95, margin = 1, 
                       main = paste("KNN Accuracy(",round(cm_knn$overall[1]*100),"%)", sep = ""))
