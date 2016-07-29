
/* OBJECTS */
var friends = {};
friends.bill = {
    firstName: "Bill",
    lastName: "Gates",
    number: "(206) 555-5555",
    address: ['One Microsoft Way', 'Redmond', 'WA', '98052']
};
friends.steve = {
    firstName: "Steve",
    lastName: "Jobs",
    number: "(408) 555-5555",
    address: ['1 Infinite Loop', 'Cupertino', 'CA', '95014']
};

var list = function (obj) {
    for (var prop in obj) {
        console.log(prop);
    }
};

var search = function (name) {
    for (var prop in friends) {
        if (friends[prop].firstName === name) {
            console.log(friends[prop]);
            return friends[prop];
        }
    }
};

list(friends);
search("Steve");

/* CLASSES */
function StaffMember(name, discountPercent) {
    this.name = name;  // Public member, var is private
    this.discountPercent = discountPercent;
}

var sally = new StaffMember("Sally", 5);
var bob = new StaffMember("Bob", 10);

// Create yourself again as 'me' with a staff discount of 20%
var me = new StaffMember("steph", 20);

var cashRegister = {
    total: 0,
    lastTransactionAmount: 0,
    add: function (itemCost) {
        this.total += (itemCost || 0);
        this.lastTransactionAmount = itemCost;
    },
    scan: function (item, quantity) {
        switch (item) {
            case "eggs": this.add(0.98 * quantity); break;
            case "milk": this.add(1.23 * quantity); break;
            case "magazine": this.add(4.99 * quantity); break;
            case "chocolate": this.add(0.45 * quantity); break;
        }
        return true;
    },
    voidLastTransaction: function () {
        this.total -= this.lastTransactionAmount;
        this.lastTransactionAmount = 0;
    },
    // Create a new method applyStaffDiscount here
    applyStaffDiscount: function (employee) {
        this.total -= (employee.discountPercent / 100) * this.total;
    }

};

cashRegister.scan('eggs', 1);
cashRegister.scan('milk', 1);
cashRegister.scan('magazine', 3);
// Apply your staff discount by passing the 'me' object 
// to applyStaffDiscount
cashRegister.applyStaffDiscount(me);

// Show the total bill
console.log('Your bill is ' + cashRegister.total.toFixed(2));

var age = prompt("What's your age");
if (age < 13) {
    console.log("osdkjfsodf");
}