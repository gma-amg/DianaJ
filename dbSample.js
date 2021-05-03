var mySQLClient = require('mysql-js');
var properties = new mySQLClient.ConnectionProperties('mysql');
properties.user = 'user1';
properties.password = 'sekrit';
mySQLClient.openSession(properties, onOpenSession)