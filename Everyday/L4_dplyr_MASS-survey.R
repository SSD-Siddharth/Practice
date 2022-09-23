#Data Imputation:
# Consider the iris dataset, artificially induce 20 percentage of missing data, use mice package and associated methods to replace missing values and generate a complete dataset. Give all the steps.. 
#install.packages("mice")
library(mice)  #Install the required packages
data=iris
md.pattern(data) #Plots
#install.packages("VIM")
library(VIM)
aggr_plot <- aggr(data, col=c('navyblue','red'), numbers=TRUE, sortVars=TRUE, labels=names(data), cex.axis=.7, gap=3, ylab=c("Initally, Histogram of missing data","Pattern"))

#Inducing 20% of missing data, 
library(missForest)
library(ggplot2)
data.miss<-prodNA(data,noNA=0.2) #Generating 20% missing values at Random
#print(data.miss)
md.pattern(data.miss) #Plots
summary(data)

mice_imputes=mice(data.miss,m=7,method="rf") #Using Random
mice_imputes$method  #To check the algo model
summary(iris$disp)
mice_imputes$imp$disp # manually observeing/ select a imputed data set.. 
Imputed_data=complete(mice_imputes)# default first imputed data
Imputed_data=complete(mice_imputes,2) # gives 2nd out of 5 imputed data sets.. 


mice_plot <- aggr(data.miss, col=c('blue','red'),numbers=TRUE, sortVars=TRUE,
                    labels=names(data.miss), cex.axis=.7,
                    gap=3, ylab=c("Missing data","Pattern"))
#We can use dev.off(), if an error occurs during plotting the above graph.




# Data Manipulation using dplyr package
# Use the newsurvey data obtained by cleaning ‘na’ values in survey data of MASS package to do the following:
install.packages("dplyr")
library(dplyr) 
install.packages("MASS")
library(MASS)
surv=survey
sum(is.na(surv))
#percent missing values per variable
apply(surv, 2, function(col)sum(is.na(col))/length(col))
#removing all observations with NAs
df_clean <- surv %>% na.omit()  #Uses deplyr package
sum(is.na(df_clean))


#   1. Install the dplyr package and import it.
install.packages("dplyr")
library(dplyr) # for functions
#summary(surv)
sum(is.na(surv))
#Trying manually
surv1=filter(surv, Sex!='NA' & Age!='NA' & Wr.Hnd!='NA' & NW.Hnd!='NA' & W.Hnd!='NA' & Fold!='NA' & Pulse!='NA' & Clap!='NA' & Exer!='NA' & Smoke!='NA' & Height!='NA' & M.I!='NA')
sum(is.na(surv1))



# 2. Filter all male left handers.
surv1[surv1$Sex=='Male' & surv1$W.Hnd=='Left',c('Sex', 'Height','W.Hnd')]
#Using select
surv1%>%dplyr::select(Sex, W.Hnd) %>% filter(Sex=='Male' & W.Hnd=='Left')



# 3. Display all female right handers who keep right on top while clapping.

#surv1[surv1$Sex=='Female' & surv1$W.Hnd=='Right' & surv1$Clap=='Right',c('Sex', 'Height','Pulse','M.I')]
#filter(surv1, Sex=='Female' & W.Hnd=='Right' & Clap=='Right')
df_clean%>%
  dplyr::select(Sex, Wr.Hnd, NW.Hnd, W.Hnd, Clap, Height) %>%
  filter(Sex=='Female' & W.Hnd=='Right' & Clap=='Right')
#Direct select is popping 'unused arguments' as there might be another 
#select fn, so we'll use the whole dplyr::select



# 4. Display all students who never exercise.
#surv1[surv1$Exer=='None',c('Sex', 'Height')]
surv1%>%
  dplyr::select(Sex, Exer, Height, Age) %>%
  filter(Exer=='None')

# 5. Display only the gender, age and writing hand of the students.
surv1%>% 
  dplyr::select('Sex', Age, W.Hnd)

# 6. Display the age, pulse rate and writing hand span of female left handers.
#Wr.Hand gives the span
surv1%>% 
  filter(Sex=='Female' & W.Hnd=='Left')%>%
  dplyr::select(Age, Pulse, Wr.Hnd)

# Note: use dplyr::select while using select operator as dplyr package conflicts with MASS package



# More functions in dplyr package
# Use the newsurvey data obtained by cleaning ‘na’ values in survey data of MASS package to do the following:
#   1.	Install the dplyr package and import it.
install.packages("dplyr")
library(dplyr) 
library(MASS)
surv=survey
sum(is.na(surv))
surv1 <- surv %>% na.omit()  #Uses deplyr package, and cleaning 'na' values.
sum(is.na(surv1))

# 2.	Arrange all male left handers according to descending order of their heights.
surv1%>%arrange(desc(Height))%>%
  dplyr::select(Sex, W.Hnd, Height) %>%
  filter(Sex=='Male' & W.Hnd=='Left')
  


# 3.	Introduce a new column hand_span which contains the value as difference between the span of writing hand and non-writing hand and display it along with gender, writing hand and non-writing hand span.
surv1<-surv1%>%
  mutate(hand_span=Wr.Hnd-NW.Hnd)
#surv1
surv1 %>% dplyr::select(Sex, Wr.Hnd, NW.Hnd, hand_span)


# 4.	Display the average writing span ofmale and femaleleft handers.
#surv1%>% 
 # filter(Sex=="Female")%>%
 # dplyr::select(Sex,Wr.Hnd)
summarise(surv1%>% 
            filter(Sex=="Female")%>%
            dplyr::select(Sex,Wr.Hnd),
          FemaleLf_mean = mean(Wr.Hnd))
summarise(surv1%>% filter(Sex=="Male")%>%dplyr::select(Sex,Wr.Hnd),
          MaleLf_mean = mean(Wr.Hnd))

# 5.	Find the maximum pulse rate of male left and right handers.
#For max male, femalel 
#surv1%>%dplyr::select(Sex,W.Hnd,Pulse)%>%filter(Pulse==max(Pulse))  
print("For Male Left Handers: ")
surv1%>%dplyr::select(Sex,W.Hnd,Pulse)%>%filter(Sex=='Male', W.Hnd=='Left',Pulse==max(Pulse))
print("For Male Right Handers: ")
rght<-surv1%>%filter(Sex=='Male', W.Hnd=='Right')%>%dplyr::select(Sex,W.Hnd,Pulse)
rght%>%dplyr::select(Sex,W.Hnd,Pulse)%>%filter(Sex=='Male', W.Hnd=='Right',Pulse==max(Pulse))
#print("Another way:")
surv1 %>% group_by(W.Hnd) %>% slice(which.max(Pulse)) %>% dplyr::select(Sex,W.Hnd,Pulse)



