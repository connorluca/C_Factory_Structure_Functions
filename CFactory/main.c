/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Creates a dog with random ID and breed and prints it out, data is not stored simply deleted as it falls out of scope. 
 * 
 */
char *dogTypes[]={
    "Labrador",
    "Pitbull",
    "German Shepard",
    "Chihuaha",
    "Husky",
    "Malamute"
};
struct Dog{
    char name[];
    char owner[];
    char type[];
    int dogID;
};
int main(int argc, char** argv) {
    char *newOwners[] ={
        "Jimmy",
        "Jennifer",
        "Susan",
        "Joseph"
    };
    char *dogNames[] ={
        "sport",
                "lasi", "spot", "bolt"
    };
    for(int i=0; i< sizeof(newOwners); i++){
        struct Dog newDog = DogFactory(dogNames[i],newOwners[i]);
        PrintDogInformation(newDog);
       //write dog info to database or file here
    }
    return 0;
}
struct Dog DogFactory(char name[], char owner[]){
    //Owner and name are user inputs dogs will be generated a random integer to identify dog an given a random dog breed from a prebuilt list
    struct Dog dog;
    dog.dogID = srand();
    strcpy(dog.name, name);
    strcpy(dog.owner, owner);
    strcpy(dog.type, dogTypes[srand()%5]);//number to modulus by dependent on size of list          
    return dog;
}
void PrintDogInformation(struct Dog dog){
    printf("%s your dog %s is a %s, there ID is %d\n", dog.owner, dog.name,dog.type, dog.dogID);
}