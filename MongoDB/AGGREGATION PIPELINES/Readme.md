# AGGREGATION PIPELINES

Aggegration pipelines is the process of performing transformations on document and combining them to produce computed result.

It consist of one or more stages that process  of performing transformation on documentation and combining them to produce computed result.

* Each stages perform diffrent operation on the documents.
* The document that are output from a stage will be passed to the next stage.
* An aggegration piplines can return result for group of document for document. for example - return the total average , minimum and maximum value.

```bash
db.<collection-name>.aggegrate()
```

## Aggegration pipelines example

```bash
db.orders.insertMany( [

   { _id: 0, name: "Pepperoni", size: "small", price: 19, quantity: 10, date: ISODate( "2021-03-13T08:14:30Z" ) }

    ,

   { _id: 1, name: "Pepperoni", size: "medium", price: 20,
     quantity: 20, date : ISODate( "2021-03-13T09:13:24Z" ) },


   { _id: 2, name: "Pepperoni", size: "large", price: 21,
     quantity: 30, date : ISODate( "2021-03-17T09:22:12Z" ) },


   { _id: 3, name: "Cheese", size: "small", price: 12,
     quantity: 15, date : ISODate( "2021-03-13T11:21:39.736Z" ) }
   
    ,
   { _id: 4, name: "Cheese", size: "medium", price: 13,
     quantity:50, date : ISODate( "2022-01-12T21:23:13.331Z" ) }
   
     ,
   { _id: 5, name: "Cheese", size: "large", price: 14,
     quantity: 10, date : ISODate( "2022-01-12T05:08:13Z" ) },
   { _id: 6, name: "Vegan", size: "small", price: 17,
     quantity: 10, date : ISODate( "2021-01-13T05:08:13Z" ) }
   
     ,
   { _id: 7, name: "Vegan", size: "medium", price: 18,
     quantity: 10, date : ISODate( "2021-01-13T05:10:13Z" ) }


] )

```

### Calculate Total Order Quantity

```bash


db.orders.aggregate([

   // Stage 1: Filter pizza order documents by pizza size

   {
      $match: { size: "medium" }
   },

   // Stage 2: Group remaining documents by pizza name and calculate total quantity
   
   {
      $group: { _id: "$name", totalQuantity: { $sum: "$quantity" } }
   }

] )

```

#### Example Output:

```bash 
[
   { _id: 'Cheese', totalQuantity: 50 },
   { _id: 'Vegan', totalQuantity: 10 },
   { _id: 'Pepperoni', totalQuantity: 20 }
]

```