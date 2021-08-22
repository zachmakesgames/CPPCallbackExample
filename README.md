# CPPCallbackExample
Sometimes in software it is necessary to callback to another function that can be changed at run time. With static and non-member functions this can be done very simply with C style function pointer passes. However since C++ is most commonly object oriented, passing function pointers between classes can be difficult. This code is an example of how the standard library functional library can make passing function pointers between classes very simple. This is a great way to avoid circular dependencies when one class requires full access to another, but the other class only requires minimal access as the example shows.

This example relies on C++ 11 to work properly.
