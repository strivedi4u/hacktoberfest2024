# Indexes in MongoDB

 They are specilized data structure that optimize data reterival speed in mongoDB.

- Indexes store a fraction of data in more searchable format.
- They enable mongoDB to locate data faster during query.
- Indexes are seperate from collection and there can exist multiple indexes in a collection.

### Managing indexes

* db.`<collection-name>.createIndex({field:1})`
  1. 1 is used for storing the index in asceding order.
  2. -1 is used for storing the index in desceding order.
* db.`<collection-name>.getIndexes();`
  1. _id is a default index in mongo.
* db.`<collection-name>.dropIndex({field:1})`
* db.`<collectio-name>.dropIndex("index_name")`

#### Creation of index
