# MONGODB

###### **It’s an open source document oriented NOSQL database management system. In which the data is stored in form of JSON.**

### Diffrence between SQL and NOSQL data base

#### SQL:

* It's a relational database.
* Store data in form of row and column
* suitable for application with well defined schema
* ex- mysql , postgresql

#### NOSQL:

* It's a non relational data base.
* Store data in form of document.
* ideal for application with dynamic or envolving data models
* ex- mongoDB , cassendra

# MongoDB community server:

If you are using the windows system then the mongoDB community server is already started when the mongodb community is installed but if you are a mac user then you need to start the mongoDB community server using the command.

```bash
brew services start mongodb-community
```

then Start the mongoDB shell using :

```bash
mongosh
```

Start interacting with the following commands:

```bash
show dbs  //to show all the data base

use "db-name" //to create a new DB or move to a db

show collections //to show the collections of a DB

db.createCollection("name") //to create a new collection in DB

db.name.drop() //to delete the drop thing

db.dropDatabase() //to delete the DB
```

- you will see the DB in the list of the output of the show dbs command until the db has atleast one collection or insert any document into the Db a collection is automatically created.

## Below is the example of the above:

![1719379358319](image/Readme/1719379358319.png)

## CRUD OPERATION IN DB

## - Inserting Documents in MongoDB:

1. To Insert one document
   db.`<collection-name>.insertOne({field1:value1,field2:value2 })`

   ![1719380268322](image/Readme/1719380268322.png)
2. To Insert more than one document :
   db.`<collection-name>.insertMany([ {.....}, {......}]) `

   ![1719380276068](image/Readme/1719380276068.png)

## - Reading Document in MongoDB:

For retriving information from the mongoDB we use find method from.

![1719381589596](image/Readme/1719381589596.png)

# *Operators in MongoDB*

## Comparision Operator in MongoDB:

1. $eq - equal to
2. $ne - not equal to
3. $gt - greater than
4. $gte - greater than equal to
5. $lt - less than
6. $lte - less than equal to
7. $in - include
8. $ni - not include

all the above operator are used to retrieve information from your database and below is the syntax for that.

```
db.<collection-name>.find({'fieldname':{op:vale}})
```

Here is the example of that:

![1719382348168](image/Readme/1719382348168.png)

## Introduction to cursors:

In MongoDB, a cursor is an object that allows you to iterate over the result set of a query. It provides various methods to traverse, manipulate, and control the query results.

1. count
2. limit
3. sort
4. skip

For example lets fetch all the document from the DB.

![1719390946099](image/Readme/1719390946099.png)

Now use the above methods:

![1719390966792](image/Readme/1719390966792.png)

![1719390975959](image/Readme/1719390975959.png)

![1719391022904](image/Readme/1719391022904.png)

## Logical Operator

we have four logical  operator with us that are $and , $ $or , $nor , $not  .

Syntax: {operator : [{cond 1 },{cond 2} ....}]}

1. $and - Perform a logical and operation  on an array of expression , where all expression must be true  for the document to be matched.

   ![1719392637873](image/Readme/1719392637873.png)
2. $or - Perform a logical or operation on an array of expression , where at least one  expression must be true for the document to be matched.

   ![1719392714470](image/Readme/1719392714470.png)
3. $nor - Perform a logical or operation on an array of expression , where none expression be true for the document to be matched.

   ![1719393083118](image/Readme/1719393083118.png)
4. $not -Perform a logical not operation on a specified expression , inverting the result.

   ![1719393312377](image/Readme/1719393312377.png)

## Complex expresssion

'$expr' operator allow to use aggrigation expression with in a query.

The $expr operator in MongoDB allows you to use aggregation expressions within a query to compare fields from the same document. It's particularly useful when you need to perform more complex comparisons or calculations involving document fields.

Syntax:

```
{$expr : {operator:[field,value]}}
```

One important thing to remember is the field should be prefix with $ sign.
// db.sales.find({$expr: {$gt: ['$price',1340] }})

So let's us take an example of a document which is given below:

![1719474412123](image/Readme/1719474412123.png)

Now we are using $expr operator to find the document:

![1719474471694](image/Readme/1719474471694.png)

here both the values are fields only for comparison thats why $ sign is used.

## Element Operator

In MongoDB, element operators are used to query documents based on the existence, type, and values of fields within the documents. These operators help you work with fields that are arrays, null, missing, or have specific data types.

* $exists: Matches documents that have a specific field, regardless of its value.

  ![1719474825906](image/Readme/1719474825906.png)
* $type: The $type operator filters documents based on the BSON data type of a field.
  // Basically we need to search or find the fields based on types (BSON Type) for example

  ![1719475051558](image/Readme/1719475051558.png)
* $size: It matches documents where the size of the array field matches a specified value.
  // Basically we need to search or find the fields based on size of array for example.

Syntax:

assume that your sales collection has a field name comments and it's an array and we need to sort only those document whose length is 2.

```
db.sales.find({comments: {$size:2}})
```

## Projection in MongoDB

It is useful when you want to show only specific data from a document.

* Including Specific Fields: To include only specific fields in the query result, you can use the projection with a value of 1 for the fields you want to include.
* Excluding Specific Fields:To exclude specific fields from the query result, you can use the projection with a value of 0 for the fields you want to exclude.
* We cannot include and exclude fields in the same query projection in MongoDB. It's either inclusion or exclusion, not both simultaneously.\

As we take an example which is given below:

![1719485544868](image/Readme/1719485544868.png)

![1719485555030](image/Readme/1719485555030.png)

Now you will see that we can perform exclusion and inclusion at the same time on any document .

![1719485984367](image/Readme/1719485984367.png)

## Embeded document (Dealing with Arrays & Object)

In this we used dot notation for the query of the data and it's used to check the data of any document which is present inside nested documents.

![1719486333976](image/Readme/1719486333976.png)

## $all vs $elementmatch

### $all Operator

 The $all operator selects documents where the value of a field is an array that contains all the specified elements.

**Syntax**

```
{ field: { $all: [ value1, value2, ... ] } }

```

To find products that have  "electronics", "battery" and "portable" in their tags array, use the $all operator:

![1719493869378](image/Readme/1719493869378.png)

### $elemMatch Operator

The $elemMatch operator matches documents that contain an array field with at least one element that matches all the specified query criteria.

**syntax**

```
{ field: { $elemMatch: { query1, query2, ... } } }
```

**Example**

Consider a collection students with the following documents:

![1719494671685](image/Readme/1719494671685.png)

To find students who have scored more than 80 in math, use the $elemMatch operator:

![1719494721254](image/Readme/1719494721254.png)

# Update operation in MongoDB

**updateOne**
The updateOne() method updates the first document that matches the filter criteria.

***Example***

![1719573544384](image/Readme/1719573544384.png)

* update the name of the product in the products collection where the name of the product is "product B"

![1719574582148](image/Readme/1719574582148.png)

**updateMany**
The updateMany() method updates all the documents that match the filter criteria.

***Example***

![1719574886385](image/Readme/1719574886385.png)

* update the targetPrice of all the product whose price is 12 in the sales collections.

![1719575028341](image/Readme/1719575028341.png)

# Renaming and Removing field in a document

#### Rename

- The rename() method renames the name of the field in a document.

***Example***

![1719575241086](image/Readme/1719575241086.png)

* Now we have to update the field name of the product from name to product of the sales collection.

![1719575500020](image/Readme/1719575500020.png)

#### Remove

- The unset() function is used to remove any field from a document.

***Example***

![1719575241086](image/Readme/1719575241086.png)

* we have to remove the field targetedPrice from  the sales collection.

![1719575869461](image/Readme/1719575869461.png)

# Updating arrays and Embedded Documents

##### Adding a new field in a document

```bash
db.collection.updateOne({filter},{$set:{"fieldName":"value"}})
```

##### deleting a new field in a document

```bash
db.collection.updateOne({filter},{$unset:{fieldName: 1}})
```

#### Embeded Document

- In this example we will know how to add a new field in a array of a document:

![1719576820673](image/Readme/1719576820673.png)

* Now we have to add the grade of a subject javascript of the student with the name Alice:

![1719576882974](image/Readme/1719576882974.png)

- In this example we will know how to add a new field in a array of a document:

![1719576820673](image/Readme/1719576820673.png)

* Now we have to remove the marks student with the name Alice from the grades array:

![1719577468017](image/Readme/1719577468017.png)

# Deletion in MongoDB

#### deleteOne

![1719577777448](image/Readme/1719577777448.png)

- We have to delete the product whose quantity = 10 from the sales collections

![1719577868717](image/Readme/1719577868717.png)

#### deleteMany

![1719578008980](image/Readme/1719578008980.png)

- We have to delete the product where the price is 12 from the sales collections

![1719578019502](image/Readme/1719578019502.png)
