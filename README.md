# Chicago-Crime-Analysis
An analysis of crime in Chicago using data from a .csv file. This program currently parses the database and matches the crime codes to the crime description and tells the user how many crime codes there are. Also it gets the date range of the database of crimes and gives data on how many crimes were committed and the corresponding collected data on the crimes. Lastly, it computes the top 5 crimes that were committed within the time period. 

To run the program enter in the 2 text files first crime-codes.txt and then crimes.txt. If you have a database of more recent Chicago crimes in this format you can use this program to analyze them. I will provide 2 different time periods of data I analyzed. 

The text files are in the format of:

crime-codes.txt: Code, PrimaryDescription, SecondaryDescription

crimes.txt: DateTime, Code, Arrested, Domestic, Beat, Ward, Community, Year

In the future I am working on adding several new features to improve runtime and allow a deeper analysis of the databases. I will be updating this as I add all of the new features. 

//TODO: TOP N Crimes 
//TODO: TOP N Crimes per area
//TODO: N Crime Codes 
//TODO: Match area name to area if possible
//TODO: Crimes that lead to most arrests
//TODO: Crimes that lead to least arrests
//TODO: Refactoring
//TODO: Event driven loop
//TODO: Improve runtime speed 
//TODO: Improve user-interaction texts 




