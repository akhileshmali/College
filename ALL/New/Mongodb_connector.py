import pymongo

client=pymongo.MongoClient()

database=client["mydb"]
collection=database["Student"]

def insertdata():
    n=int(input("Enter number of students:"))
    for i in range(n):
        name=input("Enter name:")
        roll=int(input("Enter Rollno:"))
        marks=int(input("Enter Marks:"))
        data={"name":name,"rollno":roll,"marks":marks}
        collection.insert_one(data)
    
def display():
    collection.find()

if __name__ == "__main__":
    insertdata()
    display()