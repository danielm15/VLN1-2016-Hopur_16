# VLN1-2016-Hopur_16
Hópverkefni - Verklegt námskeið 1

## Presentation layer
Consists of ConsoleUI class that is responsible displaying data to the user and getting input from him. ConsoleUI has a master method that is `ConsoleUI::run()` and is responsible for starting the program and displaying menu to the user. Each case of the menu is broken down to its own method. If it is doing more then one thing than it is broken even more down into helper methods.

## Service Layer
For each model we have there is a service layer that is responsible for getting data from repositories and returning it back to UI layer. If there needs to be done some validation or other logic our service layer's is also responsible for that. Service layer doesn't care what kind of data storage we are using, it only cares that consistency is between every repository it talks to and if repository is swapped out for new data storage it should keep the same API

### Validation
We have separated our validation logic to each own classes that exists in validation folder in project root.

## Data layer
Same as for the service layer there exists a repository for each of the model we have. Each model can have many repository (one for each data storage we are using) but it should always have the same API. Data layer is responsible for talking to our data storage and returning data down to the service layer.

### Database connection
To prevent multiple connections to the database we have a database manager class that opens the connection on program startup. Each repository then connect to that socket to talk to the database. That manager then has a `void close()` method that closes that connection if needed.

## Project Management
We have divided our group down to smaller groups that is responsible for each layer. For example Daníel and Sæþór have mainly been contributing to the datalayer, Sigurður has been maintaining the service layer and dividing it up to each own responsibility while Jóhann Grétar and Olga have been developing the interface (ConsoleUI) and testing the application and fixing bug that comes up.

## Authors
 * Daníel Örn Melstað
 * Grétar Berg Þorkláksson
 * Jóhann Einar Ísaksson
 * Olga Ýr Georgsdóttir
 * Sigurður Gunnarsson
 * Sæþór Hallgrímsson
